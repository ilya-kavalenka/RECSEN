/*
    Adding secure login workflow
*/

protocol SampleProtocol(3.0)
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

        recv onSnapshot(SnapshotRefresh)
        {
            repeat;
        }
        or send logout(Logout)
        {
            recv (SnapshotRefresh)
            {
                repeat;
            }
            or recv (Logout)
            {
            }
        }
        or recv onLogout(Logout)
        {
        }
    };

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

        send (SnapshotRefresh)
        {
            repeat;
        }
        or recv onLogout(Logout)
        {
            send (SnapshotRefresh)
            {
                repeat;
            }
            or send (Logout)
            {
            }
        }
        or send (Logout)
        {
        }
    }
}