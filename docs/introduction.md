# Introduction

The RECSEN language is designed to serve as a protocol definition. The protocol workflow essentially consists of data and control flows. It is useful to introduce language features through evolution of a sample communication protocol from its basic form to a real-life version. The sample protocol is used by market data subscribers to receive updates from a market data publisher. 

### Sample Protocol 1

[SampleProtocol_1.rs](http://github.com/ilya-kavalenka/RECSEN/blob/master/docs/SampleProtocol/SampleProtocol_1.rs?raw=true) represents the most basic version of the protocol. The only message type defined is SnapshotRefresh which has two fields. The string Symbol field contains id of the symbol the snapshot message relates to and the Entries field contains the symbol bids and asks (or the order book).

```
message SnapshotRefresh
{
    string Symbol;
    SnapshotRefreshEntry[] Entries;
}
```

The Entries field is actually a variable size array of elements of group type SnapshotRefreshEntry. A group is a set of fields used to define arrays or to reuse fields across messages.

```
group SnapshotRefreshEntry
{
    Side Side;
    int32 Qty;
    double Price;
    int32? Orders;
}
```

The Side enumeration is another example of a user-defined data type.

```
enum Side
{
    Bid,
    Ask
}
```

The Client procedure defines a repeatable receive SnapshotRefresh message operation named Snapshot. The client is not allowed to send messages.

```
proc Client()
{
    recv Snapshot(SnapshotRefresh)
        repeat;
}
```

Similarly the Server procedure defines an unnamed repeatable send SnapshotRefresh message operation. The server may not receive messages.

```
proc Server()
{
    send (SnapshotRefresh)
        repeat;
}
```

In this version of the protocol the client connects to the server and the server immediately starts sending the client snapshot messages until the client disconnects. 

### Sample Protocol 2

Let us add a basic client login/logout workflow to the protocol. [SampleProtocol_2.rs](http://github.com/ilya-kavalenka/RECSEN/blob/master/docs/SampleProtocol/SampleProtocol_2.rs?raw=true) adds four new message types as well as additional statements to the Client and Server procedures. 

```
message LoginRequest
{
    string Name;
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
```

Initially the only thing the client is allowed to do is to send a LoginRequest message. Initially the client may not receive any messages. In response to the LoginRequest message the client may receive either a LoginAccept or LoginReject message from the server. The client is not allowed to send any messages until it receives a response. The return statement defines a termination of the control flow in response to the LoginReject message. The control flow continues outside the login operation if the LoginAccept message is received from the server. 

```
send Login(LoginRequest)
{
    recv LoginAccept(LoginAccept)
    {
    }
    or recv LoginReject(LoginReject)
    {
        return;
    }
}
```

Once logged in the client may receive any number of SnapshotRefresh messages or a Logout message from the server. The client is also allowed to send own Logout message to the server. It is not allowed to receive or send other messages (e.g. LoginRequest) at this stage of the communication. After a Logout message is sent by the client it may still receive SnapshotRefresh messages until the confirming Logout message is received from the server. Upon receive of a Logout message from the server the client control flow terminates.

```
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
```

In this version of the protocol the client and server may send and receive messages. The client and server procedures define what messages are allowed to send and may be received at every stage of the client and server communication.

### Sample Protocol 3

Now let us add a client authentication workflow to receive sensitive market data updates. [SampleProtocol_3.rs](http://github.com/ilya-kavalenka/RECSEN/blob/master/docs/SampleProtocol/SampleProtocol_3.rs?raw=true) renames LoginRequest to LoginPublicRequest message type and adds LoginPrivateRequest, PasswordRequest and PasswordResponse message types.

```
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
```

The client now has a choice to initiate either a public or a private login operation. In response to the LoginPrivateRequest message the only message the client may receive is a PasswordRequest message containing an arbitrary binary token. The client has to encode the token with its private password and send the encoded binary token back to the server with a PasswordResponse message. It then receives either a LoginAccept or LoginReject message from the server as in the public login operation. Authenticated clients receive market data updates of additional symbols from the server.

```
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
```

In this version of the protocol the server sends a secondary request to the client.

### Sample Protocol 4

Now we would like to add a subscription mechanism to allow the client start and stop receiving market data updates while staying logged-in and connected. [SampleProtocol_4.rs](http://github.com/ilya-kavalenka/RECSEN/blob/master/docs/SampleProtocol/SampleProtocol_4.rs?raw=true) introduces five new subscription message types and additional statments in the Client and Server procedures.

```
message SubscribeRequest;

message SubscribeAccept;

message SubscribeReject
{
    string Text;
}

message UnsubscribeRequest;

message UnsubscribeAccept;
```

Note that once logged in (@L1) the client may only receive a Logout message from the server, it may not receive SnapshotRefresh messages yet. It is allowed to either send a SubscribeRequest or Logout message to the server at this stage. In response to a SubscribeRequest message the client may receive a SubscribeAccept or SubscribeReject message from the server. The continue statement defines a repetition of the subscribe procedure in response to the SubscribeReject message. The control flow continues outside the subscribe operation upon receive of a SubscribeAccept message.

Once subscribed (@L2) the client may receive multiple SnapshotRefresh messages or a Logout message from the server; or send a UnsubscribeRequest or Logout messages to the server. It may still receive SnapshotRefresh messages until the confirming UnsubscribeAccept or Logout message is received from the server. The return statement defines a control flow termination upon receive of a Logout from the server. The control flow continues outside the unsubscribe operation upon receive of a UnsubscribeAccept message from the server due to the loop construct.  The client may not receive any SnapshotRefresh messages anymore and is essentially in the same state as it was after the login procedure (@L1).

```
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
        recv (Logout)
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
```

In this version of the protocol the client and server implement an additional repeatable subscription workflow.

### Sample Protocol 5

Let us add another type of subscription to market news to the protocol. News subscription is separate from the symbol snapshot subscription, both workflows may overlap in time and are to be handled independently. [SampleProtocol_5.rs](http://github.com/ilya-kavalenka/RECSEN/blob/master/docs/SampleProtocol/SampleProtocol_5.rs?raw=true) introduces four base synthetic message types SymbolRequest, SymbolResponse, NewsRequest, NewsResponse and derives all the other symbol and news message types from them. A derived message includes all the fields of its base message and is compatible with the base message. Message type subclassing is used to group message types for common referencing and processing.

```
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
```

The client symbol snapshot control flow is defined by the SymbolClient procedure and the client news control flow is defined by the NewsClient procedure. Both procedures subclass the Client procedure. A subclass procedure defines a control flow for a subset of messages of the super procedure. 

```
proc SymbolClient() : Client
(
    SymbolRequest,
    SymbolResponse
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
```

The Client procedure now simply defines a send SymbolRequest and NewsRequest messages operation and a receive SymbolResponse and NewsResponse messages operation in-between the login and logout operations.

```
send (SymbolRequest, NewsRequest)
{
    repeat;
}
or recv (SymbolResponse, NewsResponse)
{
    repeat;
}
```

In this version of the protocol the client and server implement two independent workflows.

### Sample Protocol 6

Finally let us improve the symbol snapshot subscription mechanism to allow the client subscribe to / unsubscribe from market data snapshots by symbol, making the subscription mechanism selective. Per-symbol subscription means subscription workflows of different symbols may overlap in time and are to be handled independently. [SampleProtocol_6.rs](http://github.com/ilya-kavalenka/RECSEN/blob/master/docs/SampleProtocol/SampleProtocol_6.rs?raw=true) adds a string Symbol field to the SymbolRequest and SymbolResponse message types to be inherited by all the symbol messages. 

```
message SymbolRequest
{
    string Symbol;
}

message SymbolResponse
{
    string Symbol;
}
```

The SymbolClient procedure is updated to have an id of string type to define a control flow for a subset of messages having the same value of SymbolRequest.Symbol and SymbolResponse.Symbol fields.

```
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
```

It also makes use of message expressions to define control flow based on message field values in addition to message type.

```
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
```

As well as inlinable blocs to share common sequences of statements and improve code readibility.

```
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
```

In this version of the protocol the client and server implement multiple independent workflows.
