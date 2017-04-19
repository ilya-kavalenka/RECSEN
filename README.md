The ambitious goal of RECSEN project is to provide a way to formalize definition of custom message-oriented communication protocols and automate creation of client-server protocol handlers for cross-platform, network software communication.

The RECSEN language (.rs file extension) is designed to express protocol data and control flows with a high level of detail. The language is used to define protocol messages and fields in a type-safe manner as well as define protocol states and state transitions from the client and server side perspectives in a procedure-like manner.

The RECSEN compiler (rsc command) parses RECSEN files, processes protocol definition and produces either the XML protocol definition for further arbitrary processing or the client-server protocol handlers ready for use in an application. 

The RECSEN protocol handlers provide the application with all expected functionality including message encoding and decoding, sending and receiving messages, protocol state management, request-response correlation, event and message logging. Received and sent messages are validated against the protocol control flow to simplify application processing and prevent control flow violation.

The RECSEN runtime library supports a number of message formats, communication transports and platforms including FastBinaryEncoding, TCP sockets, UDP sockets, C++/Linux and is extensible for other alternatives.

## RECSEN Language

The RECSEN language is designed to serve as protocol workflow definition. The protocol workflow is essential consists of data flow (what) and control flow (when). It is useful to introduce the language through an evolution of a sample communication protocol from its basic form to a real-life version. The sample protocol is used by market data subscribers to receive market data updates from a market data publisher.

### Sample Protocol 1

SampleProtocol_1_0.rs presents the most basic version of the protocol. The only message defined is the SnapshotFullRefresh message which has two fields. The string Symbol field contains id of the symbol the snapshot message relates to and the Entries field contains the symbol bids and asks (the order book). The Entries field is actual a variable size array of elements of group type SnapshotFullRefreshEntry.

```
message SnapshotFullRefresh
{
    string Symbol;
    SnapshotFullRefreshEntry[] Entries;
}
```

A group is a set of fields used to define arrays or to reuse a common set of fields across messages.

```
group SnapshotFullRefreshEntry
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

The Client processor defines a repeatable receive operation for SnapshotFullRefresh messages named onSnapshot. The client is not allowed to send messages.

```
processor Client()
{
    recv onSnapshot(SnapshotFullRefresh)
        repeat;
}
```

Similarly the Server processor defines a repeatable send operation for SnapshotFullRefresh messages. The server is may not receive messages.

```
processor Server()
{
    send (SnapshotFullRefresh)
        repeat;
}
```


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
