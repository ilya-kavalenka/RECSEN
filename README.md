The ambitious goal of RECSEN project is to provide a way to formalize definition of custom message-oriented communication protocols and automate creation of client-server protocol handlers for cross-platform, network software communication.

The [RECSEN language](#language) (.rs file extension) is designed to express protocol data and control flows with a high level of detail. The language is used to define protocol messages and fields in a type-safe manner as well as protocol states and state transitions from the client and server side perspectives in a procedural manner.

The [RECSEN compiler](#compiler) (rsc command) parses RECSEN files, processes protocol and produces either the XML protocol definition for further processing or the client-server protocol handlers ready for use in an application. 

The [RECSEN handlers](#handlers) provide the application with all expected functionality including message encoding and decoding, sending and receiving messages, protocol state management, request-response correlation, event and message logging.

The RECSEN runtime library supports a number of message formats, communication transports and platforms including FastBinaryEncoding, TCP sockets, UDP sockets, C++/Linux and is extensible for other alternatives.

## RECSEN Language<a name="language"/>

The RECSEN language is designed to serve as a protocol definition. The protocol workflow essentially consists of data flow (what) and control flow (when). It is useful to introduce the language through an evolution of a sample communication protocol from its basic form to a real-life version. The sample protocol is used by market data subscribers to receive updates from a market data publisher.

### Sample Protocol 1

[SampleProtocol_1.rs](http://github.com/ilya-kavalenka/RECSEN/blob/master/Language/SampleProtocol_1.rs?raw=true) represents the most basic version of the protocol. The only message type defined is SnapshotRefresh which has two fields. The string Symbol field contains id of the symbol the snapshot message relates to and the Entries field contains the symbol bids and asks (or the order book).

```
message SnapshotRefresh
{
    string Symbol;
    SnapshotRefreshEntry[] Entries;
}
```

The Entries field is actual a variable size array of elements of group type SnapshotRefreshEntry. A group is a set of fields used to define arrays or to reuse a set of fields across messages.

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

The Client processor defines a repeatable receive SnapshotRefresh message operation named onSnapshot. The client is not allowed to send messages.

```
processor Client()
{
    recv onSnapshot(SnapshotRefresh)
        repeat;
}
```

Similarly the Server processor defines an unnamed repeatable send SnapshotRefresh message operation. The server may not receive messages.

```
processor Server()
{
    send (SnapshotRefresh)
        repeat;
}
```

In this version of the protocol the client connects to the server and the server immediately starts sending the client snapshot messages until the client disconnects. 

### Sample Protocol 2

Let us add a basic client login/logout workflow to the protocol. [SampleProtocol_2.rs](http://github.com/ilya-kavalenka/RECSEN/blob/master/Language/SampleProtocol_2.rs?raw=true) adds four new message types as well as additional statements to the Client and Server processors. 

```
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
```

Initially the only thing the client is allowed to do is to send a LoginRequest message. Initially the client may not receive any messages. In response to the LoginRequest message the client may receive either a LoginAccept or LoginReject message from the server. The client is not allowed to send any messages until it receives a response. The return statement defines a termination of the control flow in response to the LoginReject message. The control flow continues outside the login operation if the LoginAccept message is received from the server. 

```
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
```

Once logged in the client may receive any number of SnapshotRefresh messages or a Logout message from the server. The client is also allowed to send own Logout message to the server. It is not allowed to receive or send other messages (e.g. LoginRequest) at this stage of the communication. After a Logout message is sent by the client it may still receive SnapshotRefresh messages until the confirming Logout message is received from the server. Upon receive of a Logout message from the server the client control flow finishes.

```
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
```

In this version of the protocol the client and server may send and receive messages. The client and server processors define what messages are allowed to send and may be received at every stage of the client and server communication.

### Sample Protocol 3

Now let us add a client authentication workflow to receive sensitive market data updates. [SampleProtocol_3.rs](http://github.com/ilya-kavalenka/RECSEN/blob/master/Language/SampleProtocol_3.rs?raw=true) renames LoginRequest to LoginPublicRequest message type and adds LoginPrivateRequest, PasswordRequest and PasswordResponse message types.

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
```

In this version of the protocol the server sends a secondary request to the client.

### Sample Protocol 4

Now we would like to add a subscription mechanism to allow the client start and stop receiving market data updates while staying logged-in and connected. [SampleProtocol_4.rs](http://github.com/ilya-kavalenka/RECSEN/blob/master/Language/SampleProtocol_4.rs?raw=true) introduces five new subscription message types and additional statments in the Client and Server processors.

```
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
```

Note that once logged in (@L1) the client may only receive a Logout message from the server, it may not receive SnapshotRefresh messages yet. It is allowed to either send a SubscribeRequest or Logout message to the server at this stage. In response to a SubscribeRequest message the client may receive a SubscribeAccept or SubscribeReject message from the server. The continue statement defines a repetition of the subscribe procedure in response to the SubscribeReject message. The control flow continues outside the subscribe operation upon receive of a SubscribeAccept message.

Once subscribed (@L2) the client may receive multiple SnapshotRefresh messages or a Logout message from the server; or send a UnsubscribeRequest or Logout messages to the server. It may still receive SnapshotRefresh messages until the confirming UnsubscribeAccept or Logout message is received from the server. The return statement defines a control flow termination upon receive of a Logout from the server. The control flow continues outside the unsubscribe operation upon receive of a UnsubscribeAccept message from the server due to the loop construct.  The client may not receive any SnapshotRefresh messages anymore and is essentially in the same state as it was after the login procedure (@L1).

```
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
```

In this version of the protocol the client and server implement an additional repeatable subscription workflow.

### Sample Protocol 5

Let us add another type of subscription to market news to the protocol. News subscription is independent from the symbol snapshot subscription, both workflows may overlap in time and are to be handled in parallel. [SampleProtocol_5.rs](http://github.com/ilya-kavalenka/RECSEN/blob/master/Language/SampleProtocol_5.rs?raw=true) introduces four base synthetic message types SymbolRequest, SymbolResponse, NewsRequest, NewsResponse and derives all the other symbol and news message types from them. A derived message includes all the fields of its base message and is compatible with the base message. Message type subclassing is used to group message types for common referencing and processing.

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

The client symbol snapshot control flow is defined by the SymbolClient processor and the client news control flow is defined by the NewsClient processor. Both processors subclass the Client processor. A subclass processor defines a parallel control flow for a set of messages of the super processor. 

```
processor SymbolClient() : Client
(
    SymbolRequest,
    SymbolResponse
) 
{
    send subscribeSymbol(SubscribeSymbolRequest)
    {
        recv onSubscribeSymbolAccept(SubscribeSymbolAccept)
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
```

The Client processor now simply defines a send SymbolRequest and NewsRequest messages operation and a receive SymbolResponse and NewsResponse messages operation in-between the login and logout operations.

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

In this version of the protocol the client and server implement two independent parallel workflows.

### Sample Protocol 6

Finally let us improve the symbol snapshot subscription mechanism to allow the client subscribe to / unsubscribe from market data snapshots by symbol, making the subscription mechanism selective. Per-symbol subscription means subscription workflows of different symbols may overlap in time and are to be handled in parallel. [SampleProtocol_6.rs](http://github.com/ilya-kavalenka/RECSEN/blob/master/Language/SampleProtocol_6.rs?raw=true) adds a string Symbol field to the SymbolRequest and SymbolResponse message type to be inherited by all symbol messages. 

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

It also modifies the SymbolClient processor to have an id of string type to define a control flow for a subset of messages having the same value of SymbolRequest.Symbol and SymbolResponse.Symbol fields.

```
processor SymbolClient(string) : Client
(
    SymbolRequest.Symbol,
    SymbolResponse.Symbol
) 
{
    send subscribeSymbol(SubscribeSymbolRequest)
    {
        recv onSubscribeSymbolAccept(SubscribeSymbolAccept)
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
```

In this version of the protocol the client and server implement multiple independent parallel workflows.

## RECSEN Compiler<a name="compiler"/>

Two targets currently supportyed by the compiler are XML and C++.

```
rsc -t <target> -o <output_filename> <input_filename>
```

### XML Output

The XML output can be used for further arbitrary protocol processing, compiler verification and troubleshooting.

[SampleProtocol_1.xml](http://github.com/ilya-kavalenka/RECSEN/blob/master/Language/SampleProtocol_1.xml?raw=true), 
[SampleProtocol_2.xml](http://github.com/ilya-kavalenka/RECSEN/blob/master/Language/SampleProtocol_2.xml?raw=true), 
[SampleProtocol_3.xml](http://github.com/ilya-kavalenka/RECSEN/blob/master/Language/SampleProtocol_3.xml?raw=true), 
[SampleProtocol_4.xml](http://github.com/ilya-kavalenka/RECSEN/blob/master/Language/SampleProtocol_4.xml?raw=true), 
[SampleProtocol_5.xml](http://github.com/ilya-kavalenka/RECSEN/blob/master/Language/SampleProtocol_5.xml?raw=true), 
[SampleProtocol_6.xml](http://github.com/ilya-kavalenka/RECSEN/blob/master/Language/SampleProtocol_6.xml?raw=true) 

### C++ Output

The C++ protocol handlers produced can be directly used in a C++ application.

[SampleProtocol_1.h](http://github.com/ilya-kavalenka/RECSEN/blob/master/Language/SampleProtocol_1.h?raw=true), 
[SampleProtocol_2.h](http://github.com/ilya-kavalenka/RECSEN/blob/master/Language/SampleProtocol_2.h?raw=true), 
[SampleProtocol_3.h](http://github.com/ilya-kavalenka/RECSEN/blob/master/Language/SampleProtocol_3.h?raw=true), 
[SampleProtocol_4.h](http://github.com/ilya-kavalenka/RECSEN/blob/master/Language/SampleProtocol_4.h?raw=true), 
[SampleProtocol_5.h](http://github.com/ilya-kavalenka/RECSEN/blob/master/Language/SampleProtocol_5.h?raw=true), 
[SampleProtocol_6.h](http://github.com/ilya-kavalenka/RECSEN/blob/master/Language/SampleProtocol_6.h?raw=true)

## RECSEN Handlers<a name="handlers"/>

The RECSEN handlers are thread-safe scalable client-server protocol handlers. The application uses handler API to establish a connection, send and receive messages. Received and sent messages are validated against the protocol control flow to simplify application processing and prevent control flow violation.

### Messages

For each message type there are three C++ classes produced. A message class with the standard C++ value semantics, a message class with the standard C++ reference semantics (Ref) and a message class with the standard C++ constant reference semantics (ConstRef).

```
SnapshotRefresh snapshotRefresh;
SnapshotRefreshRef snapshotRefreshRef = snapshotRefresh;
SnapshotRefreshConstRef snapshotRefreshConstRef = snapshotRefresh;
```

### Composing Messages

Upon message construction or a reset message fields have their default values. Message fields can be assigned in a random order.

```
void composeMessage(SnapshotRefreshRef snapshotRefresh)
{
    snapshotRefresh.reset();
    snapshotRefresh.setSymbol("FGBL");
    
    SnapshotRefreshEntryArrayRef entries = snapshotRefresh.Entries();
    entries.setSize(2);

    SnapshotRefreshEntryRef entry0 = entries[0];
    entry0.setSide(Side_Bid);
    entry0.setQty(1);
    entry0.setPrice(10.02);

    SnapshotRefreshEntryRef entry1 = entries[1];
    entry1.setSide(Side_Ask);
    entry1.setQty(2);
    entry1.setPrice(10.04);
}
```

### Parsing Messages

Message fields can be accessed in a random order.

```
void parseMessage(SnapshotRefreshConstRef snapshotRefresh)
{
    string symbol = snapshotRefresh.getSymbol();

    SnapshotRefreshEntryConstArrayRef entries = snapshotRefresh.Entries();
    size_t entriesSize = entries.getSize();

    for (size_t entryIndex = 0; entryIndex < entriesSize; ++ entryIndex)
    {
        SnapshotRefreshEntryConstRef entry = entries[entryIndex];

        Side side = entry.getSide();
        int32_t qty = entry.getQty();
        double price = entry.getPrice();
        int32_null_t orders = entry.getOrders();
    }
}
```

### Casting Messages

Message reference types can be examined at runtime and casted. Message reference upcast operations are implicit.

```
void castMessage(SnapshotRefreshRef snapshotRefresh)
{
    SymbolResponseRef symbolResponse = snapshotRefresh;

    MessageRef message = symbolResponse;

    if (is<SymbolResponseRef>(message))
    {
        SymbolResponseRef symbolResponse = cast<SymbolResponseRef>(message);

        if (is<SnapshotRefreshRef>(symbolResponse))
        {
            SnapshotRefreshRef snapshotRefresh = cast<SnapshotRefreshRef>(symbolResponse);
        }
    }
}
```

### Sending Messages

Messages are sent via a client or server session object. Named operation messages are sent with a dedicated session function.

```
void subscribeSymbol(ClinetSession* session, SubscribeSymbolRequestRef subscribeSymbolRequest)
{
    session->subscribeSymbol(0, subscribeSymbolRequest);
}
```

Unnamed operation messages are sent with the generic send session function.

```
void pushSnapshot(ServerSession* session, SnapshotRefreshRef snapshotRefresh)
{
    session->send(snapshotRefresh);
}
```

### Receiving Messages

Messages are received via a client or server listener callback interface. Named operation messages are received via a dedicated listener function.

```
void AppClientListener::onSubscribeSymbolAccept
(
    ClientSession* session, 
    subscribeSymbolClientContext* context, 
    SubscribeSymbolAcceptConstRef message
)
{
}
```

Unnamed operation messages are received via the generic onReceive listener function.

```
void AppClientListener::onReceive
(
    ClientSession* session,
    MessageConstRef message
)
{
}
```

### Contexts

Contexts is a mechanism to correlate send and receive operations. Each named send operation receives a pointer to a context data structure. The context pointer is then provided to all named receive operations defined within the scope of the send operation. The application is responsible for the context data structure allocation and deallocation.

```
struct AppSubscribeSymbolClientContext : subscribeSymbolClientContext
{
    Symbol* symbol;
};

void AppClientListener::onSubscribeSymbolAccept
(
    ClientSession* session, 
    subscribeSymbolClientContext* context, 
    SubscribeSymbolAcceptConstRef message
)
{
    AppSubscribeSymbolClientContext* appContext = (AppSubscribeSymbolClientContext*) context;
    appContext->symbol->onSubscribeSuccess(session);
    delete appContext;
}

void AppClientListener::onSubscribeSymbolReject
(
    ClientSession* session, 
    subscribeSymbolClientContext* context, 
    SubscribeSymbolRejectConstRef message
)
{
    AppSubscribeSymbolClientContext* appContext = (AppSubscribeSymbolClientContext*) context;
    string text = message.getText();
    appContext->symbol->onSubscribeError(session, text);
    delete appContext;
}

void subscribeSymbolAsync(Symbol* symbol, ClientSession* session)
{
    AppSubscribeSymbolClientContext* appContext = new AppSubscribeSymbolClientContext();

    try
    {        
        appContext->symbol = symbol;

        SubscribeSymbolRequest subscribeSymbolRequest;
        subscribeSymbolRequest.setSymbol(symbol->getName());
        session->subscribeSymbol(appContext, subscribeSymbolRequest);
    }
    catch (...)
    {
        delete appContext;
        throw;
    }
}
```

### Waiting For Completion

An application thread can be blocked to wait for a completion of a send operation as defined by the scope of the send operation.

```
struct AppSubscribeSymbolClientContext : subscribeSymbolClientContext
{
    bool success;
    string text;
};

void AppClientListener::onSubscribeSymbolAccept
(
    ClientSession* session, 
    subscribeSymbolClientContext* context, 
    SubscribeSymbolAcceptConstRef message
)
{
    AppSubscribeSymbolClientContext* appContext = (AppSubscribeSymbolClientContext*) context;
    appContext->success = true;
}

void AppClientListener::onSubscribeSymbolReject
(
    ClientSession* session, 
    subscribeSymbolClientContext* context, 
    SubscribeSymbolRejectConstRef message
)
{
    AppSubscribeSymbolClientContext* appContext = (AppSubscribeSymbolClientContext*) context;    
    appContext->success = false;
    appContext->text = message.getText();
}

void subscribeSymbolSync(Symbol* symbol, ClientSession* session)
{
    AppSubscribeSymbolClientContext appContext;

    SubscribeSymbolRequest subscribeSymbolRequest;
    subscribeSymbolRequest.setSymbol(symbol->getName());
    session->subscribeSymbol(&appContext, subscribeSymbolRequest);

    session->wait(appContext);

    if (! appContext.success)
        throw exception(appContext.text.c_str());
}
```

### Unexpected Messages

Unexpected messages are rejected with an exception on the send side to prevent protocol control flow violation. Unexpected messages on the receive side cause automatic client-server session termination.

### Threading

RECSEN handlers process an arbitrary number of client-server sessions with a limited number of internal threads.
