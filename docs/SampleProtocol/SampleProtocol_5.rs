/*
    Adding news subscribe/unsubscribe workflow
*/

protocol SampleProtocol(5,0)
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

    message SymbolRequest;

    message SymbolResponse;

    message SubscribeSymbolRequest : SymbolRequest;

    message SubscribeSymbolAccept : SymbolResponse;

    message SubscribeSymbolReject : SymbolResponse
    {
        string Text;
    }

    message UnsubscribeSymbolRequest : SymbolRequest;

    message UnsubscribeSymbolAccept : SymbolResponse;

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

    message SnapshotRefresh : SymbolResponse
    {
        string Symbol;
        SnapshotRefreshEntry[] Entries;
    }

    message NewsRequest;

    message NewsResponse;

    message SubscribeNewsRequest : NewsRequest;

    message SubscribeNewsAccept : NewsResponse;

    message SubscribeNewsReject : NewsResponse
    {
        string Text;
    }

    message UnsubscribeNewsRequest : NewsRequest;

    message UnsubscribeNewsAccept : NewsResponse;

    enum NewsSeverity
    {
        Critical,
        Warning,
        Information
    }

    message NewsNotification : NewsResponse
    {
        NewsSeverity Severity;
        string Header;
        string Text;
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

        send (SymbolRequest, NewsRequest)
        {
            repeat;
        }
        or recv (SymbolResponse, NewsResponse)
        {
            repeat;
        }
        or send Logout(Logout)
        {
            recv (SymbolResponse, NewsResponse)
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

    proc SymbolClient() : Client
    (
        SymbolRequest,
        SymbolResponse
    ) 
    {
        send SubscribeSymbol(SubscribeSymbolRequest)
        {
            recv SymbolSubscribeAccept(SubscribeSymbolAccept)
            {
            }
            or recv SubscribeSymbolReject(SubscribeSymbolReject)
            {
                return;
            }
        }

        recv Snapshot(SnapshotRefresh)
        {
            repeat;
        }
        or send UnsubscribeSymbol(UnsubscribeSymbolRequest)
        {
            recv Snapshot(SnapshotRefresh)
            {
                repeat;
            }
            or recv UnsubscribeSymbolAccept(UnsubscribeSymbolAccept)
            {
                return;
            }
        }
    }

    proc NewsClient() : Client
    (
        NewsRequest,
        NewsResponse
    ) 
    {
        send SsubscribeNews(SubscribeNewsRequest)
        {
            recv SubscribeNewsAccept(SubscribeNewsAccept)
            {
            }
            or recv SubscribeNewsReject(SubscribeNewsReject)
            {
                return;
            }
        }

        recv News(NewsNotification)
        {
            repeat;
        }
        or send UnsubscribeNews(UnsubscribeNewsRequest)
        {
            recv News(NewsNotification)
            {
                repeat;
            }
            or recv UnsubscribeNewsAccept(UnsubscribeNewsAccept)
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
     
        recv (SymbolRequest, NewsRequest)
        {
            repeat;
        }
        or send (SymbolResponse, NewsResponse)
        {
            repeat;
        }
        or recv Logout(Logout)
        {
            send (SymbolResponse, NewsResponse)
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

    proc SymbolServer() : Server
    (
        SymbolRequest,
        SymbolResponse
    ) 
    {
        recv SubscribeSymbol(SubscribeSymbolRequest)
        {
            send (SubscribeSymbolAccept)
            {
            }
            or send (SubscribeSymbolReject)
            {
                return;
            }
        }

        send (SnapshotRefresh)
        {
            repeat;
        }
        or recv UnsubscribeSymbol(UnsubscribeSymbolRequest)
        {
            send (SnapshotRefresh)
            {
                repeat;
            }
            or send (UnsubscribeSymbolAccept)
            {
                return;
            }
        }
    }

    proc NewsServer() : Server
    (
        NewsRequest,
        NewsResponse
    ) 
    {
        recv SubscribeNews(SubscribeNewsRequest)
        {
            send (SubscribeNewsAccept)
            {
            }
            or send (SubscribeNewsReject)
            {
                return;
            }
        }

        send (NewsNotification)
        {
            repeat;
        }
        or recv UnsubscribeNews(UnsubscribeNewsRequest)
        {
            send (NewsNotification)
            {
                repeat;
            }
            or send (UnsubscribeNewsAccept)
            {
                return;
            }
        }
    }
}
