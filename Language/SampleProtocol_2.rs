/*
    Adding login/logout workflow
*/

protocol SampleProtocol(2.0)
{
    message LoginRequest
    {
        string Name;
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
        send login(LoginRequest)
        {
            recv onLoginAccept(LoginAccept)
            {
            }
            or recv onLoginReject(LoginReject)
            {
                return;
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
    }

    processor Server()
    {
        recv onLogin(LoginRequest)
        {
            send (LoginAccept)
            {
            }
            or send (LoginReject)
            {
                return;
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