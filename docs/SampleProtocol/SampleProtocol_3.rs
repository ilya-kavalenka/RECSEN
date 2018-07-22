/*
    Adding secure login workflow
*/

protocol SampleProtocol(3,0)
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

        recv Snapshot(SnapshotRefresh)
        {
            repeat;
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
    };

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

        send (SnapshotRefresh)
        {
            repeat;
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
        or send (Logout)
        {
            return;
        }
    }
}