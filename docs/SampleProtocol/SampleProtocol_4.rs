/*
    Adding subscribe/unsubscribe workflow
*/

protocol SampleProtocol(4,0)
{
    message LoginPublicRequest
    {
        string Name;
    }

    message LoginPrivateRequest
    {
        string Name;
    }

    message PasswordRequest
    {
        bytes Token;
    }

    message PasswordResponse
    {
        bytes EncodedToken;
    }

    message LoginAccept;

    message LoginReject
    {
        string Text;
    }

    message Logout
    {
        string Text;
    }

    message SubscribeRequest;

    message SubscribeAccept;

    message SubscribeReject
    {
        string Text;
    }

    message UnsubscribeRequest;

    message UnsubscribeAccept;

    enum Side
    {
        Bid,
        Ask
    }

    group SnapshotRefreshEntry
    {
        Side Side;
        int32 Qty;
        double Price;
        int32? Orders;
    }

    message SnapshotRefresh
    {
        string Symbol;
        SnapshotRefreshEntry[] Entries;
    }

    proc Client()
    {
        send LoginPublic(LoginPublicRequest)
        {
            recv PublicLoginAccept(LoginAccept)
            {
            }
            or recv PublicLoginReject(LoginReject)
            {
                return;
            }
        }
        or send LoginPrivate(LoginPrivateRequest)
        {
            recv Password(PasswordRequest)
            {
                send PasswordResponse(PasswordResponse)
                {
                    recv PrivateLoginAccept(LoginAccept)
                    {
                    }
                    or recv PrivateLoginReject(LoginReject)
                    {
                        return;
                    }
                }
            }
        }

        loop
        {
            @L1 send Subscribe(SubscribeRequest)
            {
                recv SubscribeAccept(SubscribeAccept)
                {
                }
                or recv SubscribeReject(SubscribeReject)
                {
                    continue;
                }
                or recv Logout(Logout)
                {
                    return;
                }
            }
            or send Logout(Logout)
            {
                recv Logout(Logout)
                {
                    return;
                }
            }
            or recv Logout(Logout)
            {
                return;
            }

            @L2 recv Snapshot(SnapshotRefresh)
            {
                repeat;
            }        
            or send Unsubscribe(UnsubscribeRequest)
            {
                recv Snapshot(SnapshotRefresh)
                {
                    repeat;
                }
                or recv UnsubscribeAccept(UnsubscribeAccept)
                {
                }
                or recv Logout(Logout)
                {
                    return;
                }
            }
            or send Logout(Logout)
            {
                recv Snapshot(SnapshotRefresh)
                {
                    repeat;
                }
                or recv Logout(Logout)
                {
                    return;
                }
            }
            or recv Logout(Logout)
            {
                return;
            }
        }
    }

    proc Server()
    {
        recv LoginPublic(LoginPublicRequest)
        {
            send (LoginAccept)
            {
            }
            or send (LoginReject)
            {
                return;
            }
        }
        or recv LoginPrivate(LoginPrivateRequest)
        {
            send (PasswordRequest)
            {
                recv Password(PasswordResponse)
                {
                    send (LoginAccept)
                    {
                    }
                    or send (LoginReject)
                    {
                        return;
                    }
                }
            }
        }
     
        loop
        {
            recv Subscribe(SubscribeRequest)
            {
                send (SubscribeAccept)
                {
                }
                or send (SubscribeReject)
                {
                    continue;
                }
            }
            or recv Logout(Logout)
            {
                send (Logout)
                {
                    return;
                }
            }
            or send (Logout)
            {
                return;
            }

            send (SnapshotRefresh)
            {
                repeat;
            }
            or send (Logout)
            {
                return;
            }
            or recv Unsubscribe(UnsubscribeRequest)
            {
                send (SnapshotRefresh)
                {
                    repeat;
                }
                or send (UnsubscribeAccept)
                {
                }
                or send (Logout)
                {
                }
            }
            or recv Logout(Logout)
            {
                send (SnapshotRefresh)
                {
                    repeat;
                }
                or send (Logout)
                {
                    return;
                }
            }
        }
    }
}
