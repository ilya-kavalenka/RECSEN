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
    
    class LoginPublicRequest
    {
    public:
        
        LoginPublicRequest();
        LoginPublicRequest(MessageInfo* info, MessageData* data);
        
        void setName(const std::string& value);
        
        std::string getName() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        MessageInfo* info_;
        MessageData* data_;
    };
    
    class LoginPublicRequestConst
    {
    public:
        
        LoginPublicRequestConst();
        LoginPublicRequestConst(MessageInfo* info, MessageData* data);
        
        std::string getName() const;
        
        std::string toString() const;
        
    private:
        
        MessageInfo* info_;
        MessageData* data_;
    };
    
    class LoginPrivateRequest
    {
    public:
        
        LoginPrivateRequest();
        LoginPrivateRequest(MessageInfo* info, MessageData* data);
        
        void setName(const std::string& value);
        
        std::string getName() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        MessageInfo* info_;
        MessageData* data_;
    };
    
    class LoginPrivateRequestConst
    {
    public:
        
        LoginPrivateRequestConst();
        LoginPrivateRequestConst(MessageInfo* info, MessageData* data);
        
        std::string getName() const;
        
        std::string toString() const;
        
    private:
        
        MessageInfo* info_;
        MessageData* data_;
    };
    
    class PasswordRequest
    {
    public:
        
        PasswordRequest();
        PasswordRequest(MessageInfo* info, MessageData* data);
        
        void setToken(const recsen::bytes_t& value);
        
        recsen::bytes_t getToken() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        MessageInfo* info_;
        MessageData* data_;
    };
    
    class PasswordRequestConst
    {
    public:
        
        PasswordRequestConst();
        PasswordRequestConst(MessageInfo* info, MessageData* data);
        
        recsen::bytes_t getToken() const;
        
        std::string toString() const;
        
    private:
        
        MessageInfo* info_;
        MessageData* data_;
    };
    
    class PasswordResponse
    {
    public:
        
        PasswordResponse();
        PasswordResponse(MessageInfo* info, MessageData* data);
        
        void setEncodedToken(const recsen::bytes_t& value);
        
        recsen::bytes_t getEncodedToken() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        MessageInfo* info_;
        MessageData* data_;
    };
    
    class PasswordResponseConst
    {
    public:
        
        PasswordResponseConst();
        PasswordResponseConst(MessageInfo* info, MessageData* data);
        
        recsen::bytes_t getEncodedToken() const;
        
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
    
    class SubscribeRequest
    {
    public:
        
        SubscribeRequest();
        SubscribeRequest(MessageInfo* info, MessageData* data);
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        MessageInfo* info_;
        MessageData* data_;
    };
    
    class SubscribeRequestConst
    {
    public:
        
        SubscribeRequestConst();
        SubscribeRequestConst(MessageInfo* info, MessageData* data);
        
        std::string toString() const;
        
    private:
        
        MessageInfo* info_;
        MessageData* data_;
    };
    
    class SubscribeAccept
    {
    public:
        
        SubscribeAccept();
        SubscribeAccept(MessageInfo* info, MessageData* data);
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        MessageInfo* info_;
        MessageData* data_;
    };
    
    class SubscribeAcceptConst
    {
    public:
        
        SubscribeAcceptConst();
        SubscribeAcceptConst(MessageInfo* info, MessageData* data);
        
        std::string toString() const;
        
    private:
        
        MessageInfo* info_;
        MessageData* data_;
    };
    
    class SubscribeReject
    {
    public:
        
        SubscribeReject();
        SubscribeReject(MessageInfo* info, MessageData* data);
        
        void setText(const std::string& value);
        
        std::string getText() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        MessageInfo* info_;
        MessageData* data_;
    };
    
    class SubscribeRejectConst
    {
    public:
        
        SubscribeRejectConst();
        SubscribeRejectConst(MessageInfo* info, MessageData* data);
        
        std::string getText() const;
        
        std::string toString() const;
        
    private:
        
        MessageInfo* info_;
        MessageData* data_;
    };
    
    class UnsubscribeRequest
    {
    public:
        
        UnsubscribeRequest();
        UnsubscribeRequest(MessageInfo* info, MessageData* data);
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        MessageInfo* info_;
        MessageData* data_;
    };
    
    class UnsubscribeRequestConst
    {
    public:
        
        UnsubscribeRequestConst();
        UnsubscribeRequestConst(MessageInfo* info, MessageData* data);
        
        std::string toString() const;
        
    private:
        
        MessageInfo* info_;
        MessageData* data_;
    };
    
    class UnsubscribeAccept
    {
    public:
        
        UnsubscribeAccept();
        UnsubscribeAccept(MessageInfo* info, MessageData* data);
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        MessageInfo* info_;
        MessageData* data_;
    };
    
    class UnsubscribeAcceptConst
    {
    public:
        
        UnsubscribeAcceptConst();
        UnsubscribeAcceptConst(MessageInfo* info, MessageData* data);
        
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
    template<> bool is<LoginPublicRequest, recsen::Message>(recsen::Message& message);
    template<> bool is<LoginPrivateRequest, recsen::Message>(recsen::Message& message);
    template<> bool is<PasswordRequest, recsen::Message>(recsen::Message& message);
    template<> bool is<PasswordResponse, recsen::Message>(recsen::Message& message);
    template<> bool is<LoginAccept, recsen::Message>(recsen::Message& message);
    template<> bool is<LoginReject, recsen::Message>(recsen::Message& message);
    template<> bool is<Logout, recsen::Message>(recsen::Message& message);
    template<> bool is<SubscribeRequest, recsen::Message>(recsen::Message& message);
    template<> bool is<SubscribeAccept, recsen::Message>(recsen::Message& message);
    template<> bool is<SubscribeReject, recsen::Message>(recsen::Message& message);
    template<> bool is<UnsubscribeRequest, recsen::Message>(recsen::Message& message);
    template<> bool is<UnsubscribeAccept, recsen::Message>(recsen::Message& message);
    template<> bool is<SnapshotRefresh, recsen::Message>(recsen::Message& message);
    template<> bool is<LoginPublicRequestConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> bool is<LoginPrivateRequestConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> bool is<PasswordRequestConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> bool is<PasswordResponseConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> bool is<LoginAcceptConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> bool is<LoginRejectConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> bool is<LogoutConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> bool is<SubscribeRequestConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> bool is<SubscribeAcceptConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> bool is<SubscribeRejectConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> bool is<UnsubscribeRequestConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> bool is<UnsubscribeAcceptConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> bool is<SnapshotRefreshConst, recsen::MessageConst>(recsen::MessageConst& message);
    
    template<typename MESSAGE1, typename MESSAGE2> MESSAGE1 cast(MESSAGE2& message);
    template<> recsen::Message cast<recsen::Message, LoginPublicRequest>(LoginPublicRequest& message);
    template<> LoginPublicRequest cast<LoginPublicRequest, recsen::Message>(recsen::Message& message);
    template<> recsen::Message cast<recsen::Message, LoginPrivateRequest>(LoginPrivateRequest& message);
    template<> LoginPrivateRequest cast<LoginPrivateRequest, recsen::Message>(recsen::Message& message);
    template<> recsen::Message cast<recsen::Message, PasswordRequest>(PasswordRequest& message);
    template<> PasswordRequest cast<PasswordRequest, recsen::Message>(recsen::Message& message);
    template<> recsen::Message cast<recsen::Message, PasswordResponse>(PasswordResponse& message);
    template<> PasswordResponse cast<PasswordResponse, recsen::Message>(recsen::Message& message);
    template<> recsen::Message cast<recsen::Message, LoginAccept>(LoginAccept& message);
    template<> LoginAccept cast<LoginAccept, recsen::Message>(recsen::Message& message);
    template<> recsen::Message cast<recsen::Message, LoginReject>(LoginReject& message);
    template<> LoginReject cast<LoginReject, recsen::Message>(recsen::Message& message);
    template<> recsen::Message cast<recsen::Message, Logout>(Logout& message);
    template<> Logout cast<Logout, recsen::Message>(recsen::Message& message);
    template<> recsen::Message cast<recsen::Message, SubscribeRequest>(SubscribeRequest& message);
    template<> SubscribeRequest cast<SubscribeRequest, recsen::Message>(recsen::Message& message);
    template<> recsen::Message cast<recsen::Message, SubscribeAccept>(SubscribeAccept& message);
    template<> SubscribeAccept cast<SubscribeAccept, recsen::Message>(recsen::Message& message);
    template<> recsen::Message cast<recsen::Message, SubscribeReject>(SubscribeReject& message);
    template<> SubscribeReject cast<SubscribeReject, recsen::Message>(recsen::Message& message);
    template<> recsen::Message cast<recsen::Message, UnsubscribeRequest>(UnsubscribeRequest& message);
    template<> UnsubscribeRequest cast<UnsubscribeRequest, recsen::Message>(recsen::Message& message);
    template<> recsen::Message cast<recsen::Message, UnsubscribeAccept>(UnsubscribeAccept& message);
    template<> UnsubscribeAccept cast<UnsubscribeAccept, recsen::Message>(recsen::Message& message);
    template<> recsen::Message cast<recsen::Message, SnapshotRefresh>(SnapshotRefresh& message);
    template<> SnapshotRefresh cast<SnapshotRefresh, recsen::Message>(recsen::Message& message);
    template<> recsen::MessageConst cast<recsen::MessageConst, LoginPublicRequestConst>(LoginPublicRequestConst& message);
    template<> LoginPublicRequestConst cast<LoginPublicRequestConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> recsen::MessageConst cast<recsen::MessageConst, LoginPrivateRequestConst>(LoginPrivateRequestConst& message);
    template<> LoginPrivateRequestConst cast<LoginPrivateRequestConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> recsen::MessageConst cast<recsen::MessageConst, PasswordRequestConst>(PasswordRequestConst& message);
    template<> PasswordRequestConst cast<PasswordRequestConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> recsen::MessageConst cast<recsen::MessageConst, PasswordResponseConst>(PasswordResponseConst& message);
    template<> PasswordResponseConst cast<PasswordResponseConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> recsen::MessageConst cast<recsen::MessageConst, LoginAcceptConst>(LoginAcceptConst& message);
    template<> LoginAcceptConst cast<LoginAcceptConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> recsen::MessageConst cast<recsen::MessageConst, LoginRejectConst>(LoginRejectConst& message);
    template<> LoginRejectConst cast<LoginRejectConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> recsen::MessageConst cast<recsen::MessageConst, LogoutConst>(LogoutConst& message);
    template<> LogoutConst cast<LogoutConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> recsen::MessageConst cast<recsen::MessageConst, SubscribeRequestConst>(SubscribeRequestConst& message);
    template<> SubscribeRequestConst cast<SubscribeRequestConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> recsen::MessageConst cast<recsen::MessageConst, SubscribeAcceptConst>(SubscribeAcceptConst& message);
    template<> SubscribeAcceptConst cast<SubscribeAcceptConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> recsen::MessageConst cast<recsen::MessageConst, SubscribeRejectConst>(SubscribeRejectConst& message);
    template<> SubscribeRejectConst cast<SubscribeRejectConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> recsen::MessageConst cast<recsen::MessageConst, UnsubscribeRequestConst>(UnsubscribeRequestConst& message);
    template<> UnsubscribeRequestConst cast<UnsubscribeRequestConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> recsen::MessageConst cast<recsen::MessageConst, UnsubscribeAcceptConst>(UnsubscribeAcceptConst& message);
    template<> UnsubscribeAcceptConst cast<UnsubscribeAcceptConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> recsen::MessageConst cast<recsen::MessageConst, SnapshotRefreshConst>(SnapshotRefreshConst& message);
    template<> SnapshotRefreshConst cast<SnapshotRefreshConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> LoginPublicRequestConst cast<LoginPublicRequestConst, LoginPublicRequest>(LoginPublicRequest& message);
    template<> LoginPrivateRequestConst cast<LoginPrivateRequestConst, LoginPrivateRequest>(LoginPrivateRequest& message);
    template<> PasswordRequestConst cast<PasswordRequestConst, PasswordRequest>(PasswordRequest& message);
    template<> PasswordResponseConst cast<PasswordResponseConst, PasswordResponse>(PasswordResponse& message);
    template<> LoginAcceptConst cast<LoginAcceptConst, LoginAccept>(LoginAccept& message);
    template<> LoginRejectConst cast<LoginRejectConst, LoginReject>(LoginReject& message);
    template<> LogoutConst cast<LogoutConst, Logout>(Logout& message);
    template<> SubscribeRequestConst cast<SubscribeRequestConst, SubscribeRequest>(SubscribeRequest& message);
    template<> SubscribeAcceptConst cast<SubscribeAcceptConst, SubscribeAccept>(SubscribeAccept& message);
    template<> SubscribeRejectConst cast<SubscribeRejectConst, SubscribeReject>(SubscribeReject& message);
    template<> UnsubscribeRequestConst cast<UnsubscribeRequestConst, UnsubscribeRequest>(UnsubscribeRequest& message);
    template<> UnsubscribeAcceptConst cast<UnsubscribeAcceptConst, UnsubscribeAccept>(UnsubscribeAccept& message);
    template<> SnapshotRefreshConst cast<SnapshotRefreshConst, SnapshotRefresh>(SnapshotRefresh& message);
    
    struct loginPublicClientContext : recsen::Context
    {
    };
    
    struct loginPrivateClientContext : recsen::Context
    {
    };
    
    struct subscribeClientContext : recsen::Context
    {
    };
    
    struct logoutClientContext : recsen::Context
    {
    };
    
    struct unsubscribeClientContext : recsen::Context
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
        
        void loginPublic(loginPublicClientContext* context, LoginPublicRequest& message);
        
        void loginPrivate(loginPrivateClientContext* context, LoginPrivateRequest& message);
        
        void subscribe(subscribeClientContext* context, SubscribeRequest& message);
        
        void logout(logoutClientContext* context, Logout& message);
        
        void unsubscribe(unsubscribeClientContext* context, UnsubscribeRequest& message);
        
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
        
        void virtual onPublicLoginAccept(ClientSession* session, loginPublicClientContext* context, LoginAcceptConst& message);
        
        void virtual onPublicLoginReject(ClientSession* session, loginPublicClientContext* context, LoginRejectConst& message);
        
        void virtual onPassword(ClientSession* session, loginPrivateClientContext* context, PasswordRequestConst& message);
        
        void virtual onPrivateLoginAccept(ClientSession* session, loginPrivateClientContext* context, LoginAcceptConst& message);
        
        void virtual onPrivateLoginReject(ClientSession* session, loginPrivateClientContext* context, LoginRejectConst& message);
        
        void virtual onLogout(ClientSession* session, LogoutConst& message);
        
        void virtual onSubscribeAccept(ClientSession* session, subscribeClientContext* context, SubscribeAcceptConst& message);
        
        void virtual onSubscribeReject(ClientSession* session, subscribeClientContext* context, SubscribeRejectConst& message);
        
        void virtual onLogout(ClientSession* session, subscribeClientContext* context, LogoutConst& message);
        
        void virtual onSnapshot(ClientSession* session, SnapshotRefreshConst& message);
        
        void virtual onLogout(ClientSession* session, LogoutConst& message);
        
        void virtual onLogout(ClientSession* session, unsubscribeClientContext* context, LogoutConst& message);
        
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
        
        void virtual onLoginPublic(ServerSession* session, LoginPublicRequestConst& message);
        
        void virtual onLoginPrivate(ServerSession* session, LoginPrivateRequestConst& message);
        
        void virtual onPassword(ServerSession* session, PasswordResponseConst& message);
        
        void virtual onSubscribe(ServerSession* session, SubscribeRequestConst& message);
        
        void virtual onLogout(ServerSession* session, LogoutConst& message);
        
        void virtual onUnsubscribe(ServerSession* session, UnsubscribeRequestConst& message);
        
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
