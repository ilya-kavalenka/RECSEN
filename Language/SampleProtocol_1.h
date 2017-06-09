#pragma once

#include "Fbe/MessageData.h"
#include "Context.h"
#include "Common.h"

#include <stdint.h>
#include <vector>
#include <string>

namespace SampleProtocol
{
    class Client;
    class ClientData;
    class ClientSession;
    class ClientSessionData;
    class ClientListener;
    class Server;
    class ServerData;
    class ServerSession;
    class ServerSessionData;
    class ServerListener;
    
    template<typename MESSAGE1, typename MESSAGE2> bool is(MESSAGE2 message);
    template<typename MESSAGE1, typename MESSAGE2> MESSAGE1 cast(MESSAGE2 message);
    
    enum Side
    {
        Side_Bid = 0,
        Side_Ask = 1,
    };
    
    typedef recsen::array_ref_t<Side> SideArrayRef;
    typedef recsen::const_array_ref_t<Side> SideConstArrayRef;
    typedef recsen::array_ref_t<recsen::Null<Side>> SideNullArrayRef;
    typedef recsen::const_array_ref_t<recsen::Null<Side>> SideNullConstArrayRef;
    
    class SnapshotRefreshEntryRef;
    class SnapshotRefreshEntryConstRef;
    
    class SnapshotRefreshEntryRef
    {
    public:
        
        SnapshotRefreshEntryRef(recsen::fbe::MessageData& data, uint32_t offset);
        SnapshotRefreshEntryRef(const SnapshotRefreshEntryRef& group);
        
        void setSide(Side value);
        
        Side getSide() const;
        
        void setQty(int32_t value);
        
        int32_t getQty() const;
        
        void setPrice(double value);
        
        double getPrice() const;
        
        void setOrders(recsen::int32_null_t value);
        
        recsen::int32_null_t getOrders() const;
        
        recsen::fbe::MessageData& data();
        const recsen::fbe::MessageData& data() const;
        
        uint32_t offset() const;
        
    private:
        
        SnapshotRefreshEntryRef& operator=(const SnapshotRefreshEntryRef& group);
        
        recsen::fbe::MessageData& data_;
        uint32_t offset_;
    };
    
    typedef recsen::group_array_ref_t<SnapshotRefreshEntryRef> SnapshotRefreshEntryArrayRef;
    
    class SnapshotRefreshEntryConstRef
    {
    public:
        
        SnapshotRefreshEntryConstRef(const recsen::fbe::MessageData& data, uint32_t offset);
        SnapshotRefreshEntryConstRef(const SnapshotRefreshEntryRef& group);
        SnapshotRefreshEntryConstRef(const SnapshotRefreshEntryConstRef& group);
        
        Side getSide() const;
        
        int32_t getQty() const;
        
        double getPrice() const;
        
        recsen::int32_null_t getOrders() const;
        
        const recsen::fbe::MessageData& data() const;
        
        uint32_t offset() const;
        
    private:
        
        SnapshotRefreshEntryConstRef& operator=(const SnapshotRefreshEntryConstRef& group);
        
        const recsen::fbe::MessageData& data_;
        uint32_t offset_;
    };
    
    typedef recsen::group_const_array_ref_t<SnapshotRefreshEntryConstRef> SnapshotRefreshEntryConstArrayRef;
    
    class SnapshotRefresh;
    class SnapshotRefreshRef;
    class SnapshotRefreshConstRef;
    
    class SnapshotRefresh
    {
    public:
        
        SnapshotRefresh();
        SnapshotRefresh(const SnapshotRefreshRef& message);
        SnapshotRefresh(const SnapshotRefreshConstRef& message);
        SnapshotRefresh(const SnapshotRefresh& message);
        
        void setSymbol(const std::string& value);
        
        std::string getSymbol() const;
        
        SnapshotRefreshEntryArrayRef Entries();
        SnapshotRefreshEntryConstArrayRef Entries() const;
        
        size_t getSize() const;
        
        const recsen::MessageInfo* info() const;
        
        recsen::fbe::MessageData& data();
        const recsen::fbe::MessageData& data() const;
        
        SnapshotRefresh& operator=(const SnapshotRefreshRef& message);
        SnapshotRefresh& operator=(const SnapshotRefreshConstRef& message);
        SnapshotRefresh& operator=(const SnapshotRefresh& message);
        
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const recsen::MessageInfo* info_;
        recsen::fbe::MessageData data_;
    };
    
    class SnapshotRefreshRef
    {
    public:
        
        SnapshotRefreshRef(const recsen::MessageInfo* info, recsen::fbe::MessageData& data);
        SnapshotRefreshRef(SnapshotRefresh& message);
        SnapshotRefreshRef(const SnapshotRefreshRef& message);
        
        void setSymbol(const std::string& value);
        
        std::string getSymbol() const;
        
        SnapshotRefreshEntryArrayRef Entries();
        SnapshotRefreshEntryConstArrayRef Entries() const;
        
        size_t getSize() const;
        
        const recsen::MessageInfo* info() const;
        
        recsen::fbe::MessageData& data();
        const recsen::fbe::MessageData& data() const;
        
        SnapshotRefreshRef& operator=(const SnapshotRefresh& message);
        SnapshotRefreshRef& operator=(const SnapshotRefreshConstRef& message);
        SnapshotRefreshRef& operator=(const SnapshotRefreshRef& message);
        
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const recsen::MessageInfo* info_;
        recsen::fbe::MessageData& data_;
    };
    
    class SnapshotRefreshConstRef
    {
    public:
        
        SnapshotRefreshConstRef(const recsen::MessageInfo* info, const recsen::fbe::MessageData& data);
        SnapshotRefreshConstRef(const SnapshotRefresh& message);
        SnapshotRefreshConstRef(const SnapshotRefreshRef& message);
        SnapshotRefreshConstRef(const SnapshotRefreshConstRef& message);
        
        std::string getSymbol() const;
        
        SnapshotRefreshEntryConstArrayRef Entries() const;
        
        size_t getSize() const;
        
        const recsen::MessageInfo* info() const;
        
        const recsen::fbe::MessageData& data() const;
        
        operator recsen::MessageConstRef() const;
        
        std::string toString() const;
        
    private:
        
        const recsen::MessageInfo* info_;
        const recsen::fbe::MessageData& data_;
    };
    
    template<> bool is<SnapshotRefreshRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> bool is<SnapshotRefreshConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    template<> SnapshotRefreshRef cast<SnapshotRefreshRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> SnapshotRefreshConstRef cast<SnapshotRefreshConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    struct ClientContext : recsen::Context
    {
    };
    
    typedef std::vector<ClientContext*> ClientContextVector;
    
    class ClientSession
    {
    public:
        
        Client* getClient() const;
        
        uint32_t getId() const;
        
        void setData(void* data);
        
        void* getData() const;
        
        void connect(const std::string& address);
        
        void disconnect(const std::string& text);
        
        void send(recsen::MessageRef message);
        
        bool waitConnect(int timeout);
        
        bool waitDisconnect(int timeout);
        
        bool waitSend(int timeout);
        
        bool wait(ClientContext& context, int timeout);
        
    private:
        
        ClientSessionData* data_;
    };
    
    class ClientListener
    {
    public:
        
        void virtual onConnect(ClientSession* session);
        
        void virtual onConnectError(ClientSession* session, const std::exception& exception);
        
        void virtual onDisconnect(ClientSession* session, const ClientContextVector& contexts, const std::string& text);
        
        void virtual onSnapshot(ClientSession* session, SnapshotRefreshConstRef message);
        
        void virtual onReceive(ClientSession* session, recsen::MessageConstRef message);
        
        void virtual onSend(ClientSession* session);
    };
    
    struct ClientLogOptions
    {
        ClientLogOptions();
        
        std::string directory;
        bool events;
        bool states;
        bool messages;
    };
    
    struct ClientOptions
    {
        ClientOptions(uint16_t connectPort);
        
        uint16_t connectPort;
        uint32_t maxConnectCount;
        uint32_t maxReconnectCount;
        uint32_t connectInterval;
        uint32_t maxSessionCount;
        uint32_t threadCount;
        uint32_t heartbeatInterval;
        uint32_t sendBufferSize;
        ClientLogOptions log;
    };
    
    class Client
    {
    public:
        
        Client(const std::string& name, const ClientOptions& options);
        
        const std::string& getName() const;
        
        const ClientOptions& getOptions() const;
        
        void setListener(ClientListener* listener);
        
        ClientSession* addSession();
        
        void removeSession(uint32_t id);
        
        void start();
        
        void stop();
        
        void join();
        
    private:
        
        ClientData* data_;
    };
    
    struct ServerContext : recsen::Context
    {
    };
    
    typedef std::vector<ServerContext*> ServerContextVector;
    
    class ServerSession
    {
    public:
        
        Server* getServer() const;
        
        uint32_t getId() const;
        
        void setData(void* data);
        
        void* getData() const;
        
        void disconnect(const std::string& text);
        
        void send(recsen::MessageRef message);
        
    private:
        
        ServerSessionData* data_;
    };
    
    class ServerListener
    {
    public:
        
        void virtual onConnect(ServerSession* session);
        
        void virtual onDisconnect(ServerSession* session, const ServerContextVector& contexts, const std::string& text);
        
        void virtual onReceive(ServerSession* session, recsen::MessageConstRef message);
        
        void virtual onSend(ServerSession* session);
    };
    
    struct ServerLogOptions
    {
        ServerLogOptions();
        
        std::string directory;
        bool events;
        bool states;
        bool messages;
    };
    
    struct ServerOptions
    {
        ServerOptions(uint16_t listenPort);
        
        uint16_t listenPort;
        uint32_t maxSessionCount;
        uint32_t threadCount;
        uint32_t heartbeatInterval;
        uint32_t sendBufferSize;
        ServerLogOptions log;
    };
    
    class Server
    {
    public:
        
        Server(const std::string& name, const ServerOptions& options);
        
        const std::string& getName() const;
        
        const ServerOptions& getOptions() const;
        
        void setListener(ServerListener* listener);
        
        void start();
        
        void stop();
        
        void join();
        
    private:
        
        ServerData* data_;
    };
}
