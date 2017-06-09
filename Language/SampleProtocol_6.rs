/*
    Adding per-symbol subscribe/unsubscribe workflow
*/

protocol SampleProtocol(6,0)
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

    message SymbolRequest
    {
        string Symbol;
    }

    message SymbolResponse
    {
        string Symbol;
    }

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
        SnapshotRefreshEntry[] Entries;
    }

    message NewsRequest;

    message NewsResponse;

    message SubscribeNewsRequest : NewsRequest;

    message SubscribeNewsAccept : NewsResponse;

    message SubscribeNewsReject : NewsResponse;

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

    message Logout;

    bloc ClientLoginPublic()
    {
        recv PublicLoginAccept(LoginAccept)
        {
        }
        or recv PublicLoginReject(LoginReject)
        {
            disconnect;
        }
    }

    bloc ClientLoginPrivate()
    {
        recv Password(PasswordRequest)
        {
            send (PasswordResponse)
            {
                recv PrivateLoginAccept(LoginAccept)
                {
                }
                or recv PrivateLoginReject(LoginReject)
                {
                    disconnect;
                }
            }
        }
    }

    bloc ClientLogout()
    {
        recv (SymbolResponse, NewsResponse)
        {
            repeat;
        }
        or recv (Logout)
        {
            disconnect;
        }
    }

    processor Client()
    {
        send LoginPublic(LoginPublicRequest)
        {
            ClientLoginPublic();
        }
        or send LoginPrivate(LoginPrivateRequest)
        {
            ClientLoginPrivate();
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
            ClientLogout();
        }
        or recv Logout(Logout)
        {
            return;
        }
    }

    processor SymbolClient(string) : Client
    (
        SymbolRequest.Symbol,
        SymbolResponse.Symbol
    ) 
    {
        send SubscribeSymbol(SubscribeSymbolRequest)
        {
            recv SubscribeSymbolAccept(SubscribeSymbolAccept)
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
            recv (SnapshotRefresh)
            {
                repeat;
            }
            or recv (UnsubscribeSymbolAccept)
            {
                return;
            }
        }
    }

    processor NewsClient() : Client
    (
        NewsRequest,
        NewsResponse
    ) 
    {
        send SubscribeNews(SubscribeNewsRequest)
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
            recv (NewsNotification)
            {
                repeat;
            }
            or recv (UnsubscribeNewsAccept)
            {
                return;
            }
        }
    }

    bloc ServerLoginPublic()
    {
        send (LoginAccept)
        {
        }
        or send (LoginReject)
        {
            disconnect;
        }
    }

    bloc ServerLoginPrivate()
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
                    disconnect;
                }
            }
        }
    }

    bloc ServerLogout()
    {
        send (SymbolResponse, NewsResponse)
        {
            repeat;
        }
        or send (Logout)
        {
            disconnect;
        }
    }

    processor Server()
    {
        recv LoginPublic(LoginPublicRequest)
        {
            ServerLoginPublic();
        }
        or recv LoginPrivate(LoginPrivateRequest)
        {
            ServerLoginPrivate();
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
            ServerLogout();
        }
        or send (Logout)
        {
            return;
        }
    }

    processor SymbolServer(string) : Server
    (
        SymbolRequest.Symbol,
        SymbolResponse.Symbol
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

    processor NewsServer() : Server
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
