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

    message Logout
    {
        string Text;
    }

    bloc ClientLoginPublic()
    {
        send LoginPublic(LoginPublicRequest)
        {
            recv PublicLoginAccept(LoginAccept)
            {
            }
            or recv PublicLoginReject(LoginReject)
            {
                disconnect;
            }
        }
    }

    bloc ClientLoginPrivate()
    {
        send LoginPrivate(LoginPrivateRequest)
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
                        disconnect;
                    }
                }
            }
        }
    }

    bloc ClientLogout()
    {
        send Logout(Logout)
        {
            recv (SymbolResponse, NewsResponse)
            {
                repeat;
            }
            or recv Logout(Logout)
            {
                disconnect;
            }
        }
    }

    proc Client()
    {
        ClientLoginPublic()
        {
        }
        or ClientLoginPrivate()
        {
        }

        send (SymbolRequest, NewsRequest)
        {
            repeat;
        }
        or recv (SymbolResponse, NewsResponse)
        {
            repeat;
        }
        or ClientLogout()
        {
        }
        or recv Logout(Logout)
        {
            return;
        }
    }

    proc SymbolClient(string) : Client
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

        recv NewsCritical(NewsNotification : Severity == NewsSeverity.Critical)
        {
            repeat;
        }
        or recv NewsWarning(NewsNotification : Severity == NewsSeverity.Warning)
        {
            repeat;
        }
        or recv NewsInformation(NewsNotification : Severity == NewsSeverity.Information)
        {
            repeat;
        }
        or send UnsubscribeNews(UnsubscribeNewsRequest)
        {
            recv NewsCritical(NewsNotification : Severity == NewsSeverity.Critical)
            {
                repeat;
            }
            or recv NewsWarning(NewsNotification : Severity == NewsSeverity.Warning)
            {
                repeat;
            }
            or recv NewsInformation(NewsNotification : Severity == NewsSeverity.Information)
            {
                repeat;
            }
            or recv UnsubscribeNewsAccept(UnsubscribeNewsAccept)
            {
                return;
            }
        }
    }

    bloc ServerLoginPublic()
    {
        recv LoginPublic(LoginPublicRequest)
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

    bloc ServerLoginPrivate()
    {
        recv LoginPrivate(LoginPrivateRequest)
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
    }

    bloc ServerLogout()
    {
        recv Logout(Logout)
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
    }

    proc Server()
    {
        ServerLoginPublic()
        {            
        }
        or ServerLoginPrivate()
        {            
        }
     
        recv (SymbolRequest, NewsRequest)
        {
            repeat;
        }
        or send (SymbolResponse, NewsResponse)
        {
            repeat;
        }
        or ServerLogout()
        {
        }
        or send (Logout)
        {
            return;
        }
    }

    proc SymbolServer(string) : Server
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

        send (NewsNotification : Severity == NewsSeverity.Critical)
        {
            repeat;
        }
        or send (NewsNotification : Severity == NewsSeverity.Warning)
        {
            repeat;
        }
        or send (NewsNotification : Severity == NewsSeverity.Information)
        {
            repeat;
        }
        or recv UnsubscribeNews(UnsubscribeNewsRequest)
        {
            send (NewsNotification : Severity == NewsSeverity.Critical)
            {
                repeat;
            }
            or send (NewsNotification : Severity == NewsSeverity.Warning)
            {
                repeat;
            }
            or send (NewsNotification : Severity == NewsSeverity.Information)
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
