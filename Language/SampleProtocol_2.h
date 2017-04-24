#pragma once

#include "Common.h"

#include <stdint.h>
#include <string>

namespace SampleProtocol
{
    class MessageInfo;
    class MessageData;
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
    
    class LoginRequest
    {
    public:
        
        LoginRequest();
        LoginRequest(MessageInfo* info, MessageData* data);
        
        void setName(const std::string& value);
        
        std::string getName() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        MessageInfo* info_;
        MessageData* data_;
    };
    
    class LoginRequestConst
    {
    public:
        
        LoginRequestConst();
        LoginRequestConst(MessageInfo* info, MessageData* data);
        
        std::string getName() const;
        
        std::string toString() const;
        
    private:
        
        MessageInfo* info_;
        MessageData* data_;
    };
    
    class LoginAccept
    {
    public:
        
        LoginAccept();
        LoginAccept(MessageInfo* info, MessageData* data);
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        MessageInfo* info_;
        MessageData* data_;
    };
    
    class LoginAcceptConst
    {
    public:
        
        LoginAcceptConst();
        LoginAcceptConst(MessageInfo* info, MessageData* data);
        
        std::string toString() const;
        
    private:
        
        MessageInfo* info_;
        MessageData* data_;
    };
    
    class LoginReject
    {
    public:
        
        LoginReject();
        LoginReject(MessageInfo* info, MessageData* data);
        
        void setText(const std::string& value);
        
        std::string getText() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        MessageInfo* info_;
        MessageData* data_;
    };
    
    class LoginRejectConst
    {
    public:
        
        LoginRejectConst();
        LoginRejectConst(MessageInfo* info, MessageData* data);
        
        std::string getText() const;
        
        std::string toString() const;
        
    private:
        
        MessageInfo* info_;
        MessageData* data_;
    };
    
    class Logout
    {
    public:
        
        Logout();
        Logout(MessageInfo* info, MessageData* data);
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        MessageInfo* info_;
        MessageData* data_;
    };
    
    class LogoutConst
    {
    public:
        
        LogoutConst();
        LogoutConst(MessageInfo* info, MessageData* data);
        
        std::string toString() const;
        
    private:
        
        MessageInfo* info_;
        MessageData* data_;
    };
    
    enum Side
    {
        Bid = 0,
        Ask = 1,
    };
    
    typedef recsen::array_t<Side> SideArray;
    typedef recsen::const_array_t<Side> SideConstArray;
    typedef recsen::array_t<recsen::null_t<Side>> SideNullArray;
    typedef recsen::const_array_t<recsen::null_t<Side>> SideNullConstArray;
    
    class SnapshotRefreshEntry
    {
    public:
        
        SnapshotRefreshEntry(MessageData* data, uint32_t offset);
        
        void setSide(Side value);
        
        Side getSide() const;
        
        void setQty(int32_t value);
        
        int32_t getQty() const;
        
        void setPrice(double value);
        
        double getPrice() const;
        
        void setOrders(recsen::int32_null_t value);
        
        recsen::int32_null_t getOrders() const;
        
    private:
        
        MessageData* data_;
        uint32_t offset_;
    };
    
    typedef recsen::group_array_t<SnapshotRefreshEntry> SnapshotRefreshEntryArray;
    
    class SnapshotRefreshEntryConst
    {
        public:
        
        SnapshotRefreshEntryConst(MessageData* data, uint32_t offset);
        
        Side getSide() const;
        
        int32_t getQty() const;
        
        double getPrice() const;
        
        recsen::int32_null_t getOrders() const;
        
    private:
        
        MessageData* data_;
        uint32_t offset_;
    };
    
    typedef recsen::group_array_t<SnapshotRefreshEntryConst> SnapshotRefreshEntryConstArray;
    
    class SnapshotRefresh
    {
    public:
        
        SnapshotRefresh();
        SnapshotRefresh(MessageInfo* info, MessageData* data);
        
        void setSymbol(const std::string& value);
        
        std::string getSymbol() const;
        
        SnapshotRefreshEntryArray Entries();
        
        SnapshotRefreshEntryConstArray Entries() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        MessageInfo* info_;
        MessageData* data_;
    };
    
    class SnapshotRefreshConst
    {
    public:
        
        SnapshotRefreshConst();
        SnapshotRefreshConst(MessageInfo* info, MessageData* data);
        
        std::string getSymbol() const;
        
        SnapshotRefreshEntryConstArray Entries() const;
        
        std::string toString() const;
        
    private:
        
        MessageInfo* info_;
        MessageData* data_;
    };
    
    template<typename MESSAGE1, typename MESSAGE2> bool is(MESSAGE2& message);
    template<> bool is<LoginRequest, recsen::Message>(recsen::Message& message);
    template<> bool is<LoginAccept, recsen::Message>(recsen::Message& message);
    template<> bool is<LoginReject, recsen::Message>(recsen::Message& message);
    template<> bool is<Logout, recsen::Message>(recsen::Message& message);
    template<> bool is<SnapshotRefresh, recsen::Message>(recsen::Message& message);
    template<> bool is<LoginRequestConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> bool is<LoginAcceptConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> bool is<LoginRejectConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> bool is<LogoutConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> bool is<SnapshotRefreshConst, recsen::MessageConst>(recsen::MessageConst& message);
    
    template<typename MESSAGE1, typename MESSAGE2> MESSAGE1 cast(MESSAGE2& message);
    template<> recsen::Message cast<recsen::Message, LoginRequest>(LoginRequest& message);
    template<> LoginRequest cast<LoginRequest, recsen::Message>(recsen::Message& message);
    template<> recsen::Message cast<recsen::Message, LoginAccept>(LoginAccept& message);
    template<> LoginAccept cast<LoginAccept, recsen::Message>(recsen::Message& message);
    template<> recsen::Message cast<recsen::Message, LoginReject>(LoginReject& message);
    template<> LoginReject cast<LoginReject, recsen::Message>(recsen::Message& message);
    template<> recsen::Message cast<recsen::Message, Logout>(Logout& message);
    template<> Logout cast<Logout, recsen::Message>(recsen::Message& message);
    template<> recsen::Message cast<recsen::Message, SnapshotRefresh>(SnapshotRefresh& message);
    template<> SnapshotRefresh cast<SnapshotRefresh, recsen::Message>(recsen::Message& message);
    template<> recsen::MessageConst cast<recsen::MessageConst, LoginRequestConst>(LoginRequestConst& message);
    template<> LoginRequestConst cast<LoginRequestConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> recsen::MessageConst cast<recsen::MessageConst, LoginAcceptConst>(LoginAcceptConst& message);
    template<> LoginAcceptConst cast<LoginAcceptConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> recsen::MessageConst cast<recsen::MessageConst, LoginRejectConst>(LoginRejectConst& message);
    template<> LoginRejectConst cast<LoginRejectConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> recsen::MessageConst cast<recsen::MessageConst, LogoutConst>(LogoutConst& message);
    template<> LogoutConst cast<LogoutConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> recsen::MessageConst cast<recsen::MessageConst, SnapshotRefreshConst>(SnapshotRefreshConst& message);
    template<> SnapshotRefreshConst cast<SnapshotRefreshConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> LoginRequestConst cast<LoginRequestConst, LoginRequest>(LoginRequest& message);
    template<> LoginAcceptConst cast<LoginAcceptConst, LoginAccept>(LoginAccept& message);
    template<> LoginRejectConst cast<LoginRejectConst, LoginReject>(LoginReject& message);
    template<> LogoutConst cast<LogoutConst, Logout>(Logout& message);
    template<> SnapshotRefreshConst cast<SnapshotRefreshConst, SnapshotRefresh>(SnapshotRefresh& message);
    
    struct loginClientContext : recsen::Context
    {
    };
    
    struct logoutClientContext : recsen::Context
    {
    };
    
    class ClientSession
    {
    public:
        
        Client* getClient() const;
        
        uint32_t getId() const;
        
        void setData(void* data);
        
        void* getData() const;
        
        void connect(const std::string& address);
        
        void disconnect(const std::string& text);
        
        void login(loginClientContext* context, LoginRequest& message);
        
        void logout(logoutClientContext* context, Logout& message);
        
        void send(recsen::Message& message);
        
        bool waitConnect(int timeout);
        
        bool waitDisconnect(int timeout);
        
        bool wait(recsen::Context& context, int timeout);
        
    private:
        
        ClientSessionData* data_;
    };
    
    class ClientListener
    {
    public:
        
        void virtual onConnect(ClientSession* session);
        
        void virtual onConnectError(ClientSession* session, const std::exception& exception);
        
        void virtual onDisconnect(ClientSession* session, const std::string& text);
        
        void virtual onLoginAccept(ClientSession* session, loginClientContext* context, LoginAcceptConst& message);
        
        void virtual onLoginReject(ClientSession* session, loginClientContext* context, LoginRejectConst& message);
        
        void virtual onSnapshot(ClientSession* session, SnapshotRefreshConst& message);
        
        void virtual onLogout(ClientSession* session, LogoutConst& message);
        
        void virtual onReceive(ClientSession* session, recsen::MessageConst& message);
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
        
        std::string logDirectory;
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
    
    class ServerSession
    {
    public:
        
        Server* getServer() const;
        
        uint32_t getId() const;
        
        void setData(void* data);
        
        void* getData() const;
        
        void send(recsen::Message& message);
        
    private:
        
        ServerSessionData* data_;
    };
    
    class ServerListener
    {
    public:
        
        void virtual onConnect(ServerSession* session);
        
        void virtual onDisconnect(ServerSession* session, const std::string& text);
        
        void virtual onLogin(ServerSession* session, LoginRequestConst& message);
        
        void virtual onLogout(ServerSession* session, LogoutConst& message);
        
        void virtual onReceive(ServerSession* session, recsen::MessageConst& message);
    };
    
    struct ServerOptions
    {
        ServerOptions(uint16_t listenPort);
        
        uint16_t listenPort;
        
        uint32_t maxSessionCount;
        
        uint32_t threadCount;
        
        uint32_t heartbeatInterval;
        
        std::string logDirectory;
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
