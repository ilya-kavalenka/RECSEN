The ambitious goal of RECSEN project is to provide a way to formalize definition of custom message-oriented communication protocols and automate creation of client-server protocol handlers for cross-platform, network software communication.

The RECSEN language (.rs file extension) is designed to express protocol data and control flows with a high level of detail. The language is used to define protocol messages and fields in a type-safe manner as well as define protocol states and state transitions from the client and server side perspectives in a procedure-like manner.

The RECSEN compiler (rsc command) parses RECSEN files, processes protocol definition and produces either the XML protocol definition file for further arbitrary processing or the client-server protocol handlers ready for use in an application. 

The RECSEN protocol handlers provide the application with all expected functionality including message encoding and decoding, sending and receiving messages, protocol state management, request-response correlation, event and message logging. Received and sent messages are validated against the protocol control flow to simplify application processing and prevent control flow violation.

The RECSEN runtime library supports a number of message formats, communication transports and platforms including FastBinaryEncoding, TCP sockets, UDP sockets, C++/Linux and is extensible for other alternatives.

## RECSEN Language

The RECSEN language is designed to serve as a protocol definition. The protocol workflow is essential consists of data flow (what) and control flow (when). It is useful to introduce the language through an evolution of a sample communication protocol from its basic form to a real-life version. The sample protocol is used by market data subscribers to receive market data updates from a market data publisher.

### Sample Protocol 1

SampleProtocol_1_0.rs represents the most basic version of the protocol. The only message defined is the SnapshotRefresh message with two fields. The string Symbol field contains id of the symbol the snapshot message relates to and the Entries field contains the symbol bids and asks (or the order book).

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
    int32 Orders;
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

In this version of the protocol the client simply connects to the server and the server immediately starts sending the client snapshot  messages until the client disconnects. 

### Sample Protocol 2

Let us add a basic client login/logout workflow to the protocol. SampleProtocol_2_0.rs adds four new message types as well as additional statements to the Client and Server processors. 

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

Initially the only thing the client is allowed to do is to send a LoginRequest message. Initially the client may not receive any messages. In response to the LoginRequest message the client may receive either a LoginAccept or LoginReject message. The client is not allowed to send any messages until it receives a response from the server. The return statement defines a termination of the control flow in response to the LoginReject message. The control flow continues outside the login operation if the LoginAccept message is received from the server. 

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

Now let us add a client authentication workflow to receive sensitive market updates. SampleProtocol_3_0.rs renames LoginRequest to LoginPublicRequest message type and adds LoginPrivateRequest, PasswordRequest and PasswordResponse message types.

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

The client now has a choice to initiate either a public or a private login operation. In response to the LoginPrivate message the only message the client may receive is a PasswordRequest message containing an arbitrary binary token. The client has to encode the token with its private password and send the encoded binary token back to the server with a PasswordResponse message. It then receives either the LoginAccept or LoginReject message from the server as in the public login operation. Authenticated clients receive market data updates of additional symbols from the server.

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



## Welcome to GitHub Pages

You can use the [editor on GitHub](https://github.com/ilya-kavalenka/recsen/edit/master/README.md) to maintain and preview the content for your website in Markdown files.

Whenever you commit to this repository, GitHub Pages will run [Jekyll](https://jekyllrb.com/) to rebuild the pages in your site, from the content in your Markdown files.


### Markdown

Markdown is a lightweight and easy-to-use syntax for styling your writing. It includes conventions for

```markdown
Syntax highlighted code block

# Header 1
## Header 2
### Header 3

- Bulleted
- List

1. Numbered
2. List

**Bold** and _Italic_ and `Code` text

[Link](url) and ![Image](src)
```

For more details see [GitHub Flavored Markdown](https://guides.github.com/features/mastering-markdown/).

### Jekyll Themes

Your Pages site will use the layout and styles from the Jekyll theme you have selected in your [repository settings](https://github.com/ilya-kavalenka/recsen/settings). The name of this theme is saved in the Jekyll `_config.yml` configuration file.

### Support or Contact

Having trouble with Pages? Check out our [documentation](https://help.github.com/categories/github-pages-basics/) or [contact support](https://github.com/contact) and we’ll help you sort it out.
