/*
    Adding subscribe/unsubscribe workflow
*/

protocol SampleProtocol(4.0)
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

    message LoginAccept
    {
    }

    message LoginReject
    {
        string Text;
    }

    message Logout
    {
    }

    message SubscribeRequest
    {
    }

    message SubscribeAccept
    {
    }

    message SubscribeReject
    {
        string Text;
    }

    message UnsubscribeRequest
    {
    }

    message UnsubscribeAccept
    {
    }

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

    processor Client()
    {
        send loginPublic(LoginPublicRequest)
        {
            recv onPublicLoginAccept(LoginAccept)
            {
            }
            or recv onPublicLoginReject(LoginReject)
            {
                return;
            }
        }
        or send loginPrivate(LoginPrivateRequest)
        {
            recv onPassword(PasswordRequest)
            {
                send (PasswordResponse)
                {
                    recv onPrivateLoginAccept(LoginAccept)
                    {
                    }
                    or recv onPrivateLoginReject(LoginReject)
                    {
                        return;
                    }
                }
            }
        }

        loop
        {
            @L1 send subscribe(SubscribeRequest)
            {
                recv onSubscribeAccept(SubscribeAccept)
                {
                }
                or recv onSubscribeReject(SubscribeReject)
                {
                    continue;
                }
                or recv onLogout(Logout)
                {
                    return;
                }
            }
            or send logout(Logout)
            {
                recv (Logout)
                {
                    return;
                }
            }
            or recv onLogout(Logout)
            {
                return;
            }

            @L2 recv onSnapshot(SnapshotRefresh)
            {
                repeat;
            }        
            or send unsubscribe(UnsubscribeRequest)
            {
                recv (SnapshotRefresh)
                {
                    repeat;
                }
                or recv (UnsubscribeAccept)
                {
                }
                or recv onLogout(Logout)
                {
                    return;
                }
            }
            or send logout(Logout)
            {
                recv (SnapshotRefresh)
                {
                    repeat;
                }
                or recv (Logout)
                {
                    return;
                }
            }
            or recv onLogout(Logout)
            {
                return;
            }
        }
    }

    processor Server()
    {
        recv onLoginPublic(LoginPublicRequest)
        {
            send (LoginAccept)
            {
            }
            or send (LoginReject)
            {
                return;
            }
        }
        or recv onLoginPrivate(LoginPrivateRequest)
        {
            send (PasswordRequest)
            {
                recv onPassword(PasswordResponse)
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
            recv onSubscribe(SubscribeRequest)
            {
                send (SubscribeAccept)
                {
                }
                or send (SubscribeReject)
                {
                    continue;
                }
            }
            or recv onLogout(Logout)
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
            or recv onUnsubscribe(UnsubscribeRequest)
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
            or recv onLogout(Logout)
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
