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
    
    template<typename MESSAGE> MESSAGE create();
    template<typename MESSAGE1, typename MESSAGE2> bool is(MESSAGE2 message);
    template<typename MESSAGE1, typename MESSAGE2> MESSAGE1 cast(MESSAGE2 message);
    
    class LoginPublicRequest
    {
    public:
        
        LoginPublicRequest(const MessageInfo* info, MessageData* data);
        LoginPublicRequest(const LoginPublicRequest& message);
        
        ~LoginPublicRequest();
        
        LoginPublicRequest& operator=(const LoginPublicRequest& message);
        
        void setName(const std::string& value);
        
        std::string getName() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    template<> LoginPublicRequest create<LoginPublicRequest>();
    
    template<> bool is<LoginPublicRequest, recsen::Message>(recsen::Message message);
    
    template<> recsen::Message cast<recsen::Message, LoginPublicRequest>(LoginPublicRequest message);
    template<> LoginPublicRequest cast<LoginPublicRequest, recsen::Message>(recsen::Message message);
    
    class LoginPublicRequestConst
    {
    public:
        
        LoginPublicRequestConst(const MessageInfo* info, const MessageData* data);
        LoginPublicRequestConst(const LoginPublicRequestConst& message);
        
        ~LoginPublicRequestConst();
        
        LoginPublicRequestConst& operator=(const LoginPublicRequestConst& message);
        
        std::string getName() const;
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        const MessageData* data_;
    };
    
    template<> bool is<LoginPublicRequestConst, recsen::MessageConst>(recsen::MessageConst message);
    
    template<> recsen::MessageConst cast<recsen::MessageConst, LoginPublicRequestConst>(LoginPublicRequestConst message);
    template<> LoginPublicRequestConst cast<LoginPublicRequestConst, recsen::MessageConst>(recsen::MessageConst message);
    template<> LoginPublicRequestConst cast<LoginPublicRequestConst, LoginPublicRequest>(LoginPublicRequest message);
    
    class LoginPrivateRequest
    {
    public:
        
        LoginPrivateRequest(const MessageInfo* info, MessageData* data);
        LoginPrivateRequest(const LoginPrivateRequest& message);
        
        ~LoginPrivateRequest();
        
        LoginPrivateRequest& operator=(const LoginPrivateRequest& message);
        
        void setName(const std::string& value);
        
        std::string getName() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    template<> LoginPrivateRequest create<LoginPrivateRequest>();
    
    template<> bool is<LoginPrivateRequest, recsen::Message>(recsen::Message message);
    
    template<> recsen::Message cast<recsen::Message, LoginPrivateRequest>(LoginPrivateRequest message);
    template<> LoginPrivateRequest cast<LoginPrivateRequest, recsen::Message>(recsen::Message message);
    
    class LoginPrivateRequestConst
    {
    public:
        
        LoginPrivateRequestConst(const MessageInfo* info, const MessageData* data);
        LoginPrivateRequestConst(const LoginPrivateRequestConst& message);
        
        ~LoginPrivateRequestConst();
        
        LoginPrivateRequestConst& operator=(const LoginPrivateRequestConst& message);
        
        std::string getName() const;
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        const MessageData* data_;
    };
    
    template<> bool is<LoginPrivateRequestConst, recsen::MessageConst>(recsen::MessageConst message);
    
    template<> recsen::MessageConst cast<recsen::MessageConst, LoginPrivateRequestConst>(LoginPrivateRequestConst message);
    template<> LoginPrivateRequestConst cast<LoginPrivateRequestConst, recsen::MessageConst>(recsen::MessageConst message);
    template<> LoginPrivateRequestConst cast<LoginPrivateRequestConst, LoginPrivateRequest>(LoginPrivateRequest message);
    
    class PasswordRequest
    {
    public:
        
        PasswordRequest(const MessageInfo* info, MessageData* data);
        PasswordRequest(const PasswordRequest& message);
        
        ~PasswordRequest();
        
        PasswordRequest& operator=(const PasswordRequest& message);
        
        void setToken(const recsen::bytes_t& value);
        
        recsen::bytes_t getToken() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    template<> PasswordRequest create<PasswordRequest>();
    
    template<> bool is<PasswordRequest, recsen::Message>(recsen::Message message);
    
    template<> recsen::Message cast<recsen::Message, PasswordRequest>(PasswordRequest message);
    template<> PasswordRequest cast<PasswordRequest, recsen::Message>(recsen::Message message);
    
    class PasswordRequestConst
    {
    public:
        
        PasswordRequestConst(const MessageInfo* info, const MessageData* data);
        PasswordRequestConst(const PasswordRequestConst& message);
        
        ~PasswordRequestConst();
        
        PasswordRequestConst& operator=(const PasswordRequestConst& message);
        
        recsen::bytes_t getToken() const;
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        const MessageData* data_;
    };
    
    template<> bool is<PasswordRequestConst, recsen::MessageConst>(recsen::MessageConst message);
    
    template<> recsen::MessageConst cast<recsen::MessageConst, PasswordRequestConst>(PasswordRequestConst message);
    template<> PasswordRequestConst cast<PasswordRequestConst, recsen::MessageConst>(recsen::MessageConst message);
    template<> PasswordRequestConst cast<PasswordRequestConst, PasswordRequest>(PasswordRequest message);
    
    class PasswordResponse
    {
    public:
        
        PasswordResponse(const MessageInfo* info, MessageData* data);
        PasswordResponse(const PasswordResponse& message);
        
        ~PasswordResponse();
        
        PasswordResponse& operator=(const PasswordResponse& message);
        
        void setEncodedToken(const recsen::bytes_t& value);
        
        recsen::bytes_t getEncodedToken() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    template<> PasswordResponse create<PasswordResponse>();
    
    template<> bool is<PasswordResponse, recsen::Message>(recsen::Message message);
    
    template<> recsen::Message cast<recsen::Message, PasswordResponse>(PasswordResponse message);
    template<> PasswordResponse cast<PasswordResponse, recsen::Message>(recsen::Message message);
    
    class PasswordResponseConst
    {
    public:
        
        PasswordResponseConst(const MessageInfo* info, const MessageData* data);
        PasswordResponseConst(const PasswordResponseConst& message);
        
        ~PasswordResponseConst();
        
        PasswordResponseConst& operator=(const PasswordResponseConst& message);
        
        recsen::bytes_t getEncodedToken() const;
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        const MessageData* data_;
    };
    
    template<> bool is<PasswordResponseConst, recsen::MessageConst>(recsen::MessageConst message);
    
    template<> recsen::MessageConst cast<recsen::MessageConst, PasswordResponseConst>(PasswordResponseConst message);
    template<> PasswordResponseConst cast<PasswordResponseConst, recsen::MessageConst>(recsen::MessageConst message);
    template<> PasswordResponseConst cast<PasswordResponseConst, PasswordResponse>(PasswordResponse message);
    
    class LoginAccept
    {
    public:
        
        LoginAccept(const MessageInfo* info, MessageData* data);
        LoginAccept(const LoginAccept& message);
        
        ~LoginAccept();
        
        LoginAccept& operator=(const LoginAccept& message);
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    template<> LoginAccept create<LoginAccept>();
    
    template<> bool is<LoginAccept, recsen::Message>(recsen::Message message);
    
    template<> recsen::Message cast<recsen::Message, LoginAccept>(LoginAccept message);
    template<> LoginAccept cast<LoginAccept, recsen::Message>(recsen::Message message);
    
    class LoginAcceptConst
    {
    public:
        
        LoginAcceptConst(const MessageInfo* info, const MessageData* data);
        LoginAcceptConst(const LoginAcceptConst& message);
        
        ~LoginAcceptConst();
        
        LoginAcceptConst& operator=(const LoginAcceptConst& message);
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        const MessageData* data_;
    };
    
    template<> bool is<LoginAcceptConst, recsen::MessageConst>(recsen::MessageConst message);
    
    template<> recsen::MessageConst cast<recsen::MessageConst, LoginAcceptConst>(LoginAcceptConst message);
    template<> LoginAcceptConst cast<LoginAcceptConst, recsen::MessageConst>(recsen::MessageConst message);
    template<> LoginAcceptConst cast<LoginAcceptConst, LoginAccept>(LoginAccept message);
    
    class LoginReject
    {
    public:
        
        LoginReject(const MessageInfo* info, MessageData* data);
        LoginReject(const LoginReject& message);
        
        ~LoginReject();
        
        LoginReject& operator=(const LoginReject& message);
        
        void setText(const std::string& value);
        
        std::string getText() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    template<> LoginReject create<LoginReject>();
    
    template<> bool is<LoginReject, recsen::Message>(recsen::Message message);
    
    template<> recsen::Message cast<recsen::Message, LoginReject>(LoginReject message);
    template<> LoginReject cast<LoginReject, recsen::Message>(recsen::Message message);
    
    class LoginRejectConst
    {
    public:
        
        LoginRejectConst(const MessageInfo* info, const MessageData* data);
        LoginRejectConst(const LoginRejectConst& message);
        
        ~LoginRejectConst();
        
        LoginRejectConst& operator=(const LoginRejectConst& message);
        
        std::string getText() const;
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        const MessageData* data_;
    };
    
    template<> bool is<LoginRejectConst, recsen::MessageConst>(recsen::MessageConst message);
    
    template<> recsen::MessageConst cast<recsen::MessageConst, LoginRejectConst>(LoginRejectConst message);
    template<> LoginRejectConst cast<LoginRejectConst, recsen::MessageConst>(recsen::MessageConst message);
    template<> LoginRejectConst cast<LoginRejectConst, LoginReject>(LoginReject message);
    
    class Logout
    {
    public:
        
        Logout(const MessageInfo* info, MessageData* data);
        Logout(const Logout& message);
        
        ~Logout();
        
        Logout& operator=(const Logout& message);
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    template<> Logout create<Logout>();
    
    template<> bool is<Logout, recsen::Message>(recsen::Message message);
    
    template<> recsen::Message cast<recsen::Message, Logout>(Logout message);
    template<> Logout cast<Logout, recsen::Message>(recsen::Message message);
    
    class LogoutConst
    {
    public:
        
        LogoutConst(const MessageInfo* info, const MessageData* data);
        LogoutConst(const LogoutConst& message);
        
        ~LogoutConst();
        
        LogoutConst& operator=(const LogoutConst& message);
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        const MessageData* data_;
    };
    
    template<> bool is<LogoutConst, recsen::MessageConst>(recsen::MessageConst message);
    
    template<> recsen::MessageConst cast<recsen::MessageConst, LogoutConst>(LogoutConst message);
    template<> LogoutConst cast<LogoutConst, recsen::MessageConst>(recsen::MessageConst message);
    template<> LogoutConst cast<LogoutConst, Logout>(Logout message);
    
    enum Side
    {
        Side_Bid = 0,
        Side_Ask = 1,
    };
    
    typedef recsen::array_t<Side> SideArray;
    typedef recsen::const_array_t<Side> SideConstArray;
    typedef recsen::array_t<recsen::null_t<Side>> SideNullArray;
    typedef recsen::const_array_t<recsen::null_t<Side>> SideNullConstArray;
    
    class SnapshotRefreshEntry
    {
    public:
        
        SnapshotRefreshEntry(MessageData* data, uint32_t offset);
        SnapshotRefreshEntry(const SnapshotRefreshEntry& group);
        
        ~SnapshotRefreshEntry();
        
        SnapshotRefreshEntry& operator=(const SnapshotRefreshEntry& group);
        
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
        
        SnapshotRefreshEntryConst(const MessageData* data, uint32_t offset);
        SnapshotRefreshEntryConst(const SnapshotRefreshEntryConst& group);
        
        ~SnapshotRefreshEntryConst();
        
        SnapshotRefreshEntryConst& operator=(const SnapshotRefreshEntryConst& group);
        
        Side getSide() const;
        
        int32_t getQty() const;
        
        double getPrice() const;
        
        recsen::int32_null_t getOrders() const;
        
    private:
        
        const MessageData* data_;
        uint32_t offset_;
    };
    
    typedef recsen::group_array_t<SnapshotRefreshEntryConst> SnapshotRefreshEntryConstArray;
    
    class SnapshotRefresh
    {
    public:
        
        SnapshotRefresh(const MessageInfo* info, MessageData* data);
        SnapshotRefresh(const SnapshotRefresh& message);
        
        ~SnapshotRefresh();
        
        SnapshotRefresh& operator=(const SnapshotRefresh& message);
        
        void setSymbol(const std::string& value);
        
        std::string getSymbol() const;
        
        SnapshotRefreshEntryArray Entries();
        
        SnapshotRefreshEntryConstArray Entries() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    template<> SnapshotRefresh create<SnapshotRefresh>();
    
    template<> bool is<SnapshotRefresh, recsen::Message>(recsen::Message message);
    
    template<> recsen::Message cast<recsen::Message, SnapshotRefresh>(SnapshotRefresh message);
    template<> SnapshotRefresh cast<SnapshotRefresh, recsen::Message>(recsen::Message message);
    
    class SnapshotRefreshConst
    {
    public:
        
        SnapshotRefreshConst(const MessageInfo* info, const MessageData* data);
        SnapshotRefreshConst(const SnapshotRefreshConst& message);
        
        ~SnapshotRefreshConst();
        
        SnapshotRefreshConst& operator=(const SnapshotRefreshConst& message);
        
        std::string getSymbol() const;
        
        SnapshotRefreshEntryConstArray Entries() const;
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        const MessageData* data_;
    };
    
    template<> bool is<SnapshotRefreshConst, recsen::MessageConst>(recsen::MessageConst message);
    
    template<> recsen::MessageConst cast<recsen::MessageConst, SnapshotRefreshConst>(SnapshotRefreshConst message);
    template<> SnapshotRefreshConst cast<SnapshotRefreshConst, recsen::MessageConst>(recsen::MessageConst message);
    template<> SnapshotRefreshConst cast<SnapshotRefreshConst, SnapshotRefresh>(SnapshotRefresh message);
    
    struct loginPublicClientContext : recsen::Context
    {
    };
    
    struct loginPrivateClientContext : recsen::Context
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
        
        void loginPublic(loginPublicClientContext* context, LoginPublicRequest message);
        
        void loginPrivate(loginPrivateClientContext* context, LoginPrivateRequest message);
        
        void logout(logoutClientContext* context, Logout message);
        
        void send(recsen::Message message);
        
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
        
        void virtual onPublicLoginAccept(ClientSession* session, loginPublicClientContext* context, LoginAcceptConst message);
        
        void virtual onPublicLoginReject(ClientSession* session, loginPublicClientContext* context, LoginRejectConst message);
        
        void virtual onPassword(ClientSession* session, loginPrivateClientContext* context, PasswordRequestConst message);
        
        void virtual onPrivateLoginAccept(ClientSession* session, loginPrivateClientContext* context, LoginAcceptConst message);
        
        void virtual onPrivateLoginReject(ClientSession* session, loginPrivateClientContext* context, LoginRejectConst message);
        
        void virtual onSnapshot(ClientSession* session, SnapshotRefreshConst message);
        
        void virtual onLogout(ClientSession* session, LogoutConst message);
        
        void virtual onReceive(ClientSession* session, recsen::MessageConst message);
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
        
        void send(recsen::Message message);
        
    private:
        
        ServerSessionData* data_;
    };
    
    class ServerListener
    {
    public:
        
        void virtual onConnect(ServerSession* session);
        
        void virtual onDisconnect(ServerSession* session, const std::string& text);
        
        void virtual onLoginPublic(ServerSession* session, LoginPublicRequestConst message);
        
        void virtual onLoginPrivate(ServerSession* session, LoginPrivateRequestConst message);
        
        void virtual onPassword(ServerSession* session, PasswordResponseConst message);
        
        void virtual onLogout(ServerSession* session, LogoutConst message);
        
        void virtual onReceive(ServerSession* session, recsen::MessageConst message);
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
