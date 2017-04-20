/*
    Adding news subscribe/unsubscribe workflow
*/

protocol SampleProtocol(5.0)
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

    message Logout;

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
        int32 Orders;
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
            or recv (Logout)
            {
            }
        }
        or recv onLogout(Logout)
        {
        }
    }

    processor SymbolClient() : Client
    (
        SymbolRequest,
        SymbolResponse
    ) 
    {
        send subscribeSymbol(SubscribeSymbolRequest)
        {
            recv onSymbolSubscribeAccept(SubscribeSymbolAccept)
            {
            }
            or recv onSubscribeSymbolReject(SubscribeSymbolReject)
            {
                return;
            }
        }

        recv onSnapshot(SnapshotRefresh)
        {
            repeat;
        }
        or send unsubscribeSymbol(UnsubscribeSymbolRequest)
        {
            recv (SnapshotRefresh)
            {
                repeat;
            }
            or recv (UnsubscribeSymbolAccept)
            {
            }
        }
    }

    processor NewsClient() : Client
    (
        NewsRequest,
        NewsResponse
    ) 
    {
        send subscribeNews(SubscribeNewsRequest)
        {
            recv onSubscribeNewsAccept(SubscribeNewsAccept)
            {
            }
            or recv onSubscribeNewsReject(SubscribeNewsReject)
            {
                return;
            }
        }

        recv onNews(NewsNotification)
        {
            repeat;
        }
        or send unsubscribeNews(UnsubscribeNewsRequest)
        {
            recv (NewsNotification)
            {
                repeat;
            }
            or recv (UnsubscribeNewsAccept)
            {
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
     
        recv (SymbolRequest, NewsRequest)
        {
            repeat;
        }
        or send (SymbolResponse, NewsResponse)
        {
            repeat;
        }
        or recv onLogout(Logout)
        {
            send (SymbolResponse, NewsResponse)
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

    processor SymbolServer() : Server
    (
        SymbolRequest,
        SymbolResponse
    ) 
    {
        recv onSubscribeSymbol(SubscribeSymbolRequest)
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
        or recv onUnsubscribeSymbol(UnsubscribeSymbolRequest)
        {
            send (SnapshotRefresh)
            {
                repeat;
            }
            or send (UnsubscribeSymbolAccept)
            {
            }
        }
    }

    processor NewsServer() : Server
    (
        NewsRequest,
        NewsResponse
    ) 
    {
        recv onSubscribeNews(SubscribeNewsRequest)
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
        or recv onUnsubscribeNews(UnsubscribeNewsRequest)
        {
            send (NewsNotification)
            {
                repeat;
            }
            or send (UnsubscribeNewsAccept)
            {
            }
        }
    }
}
