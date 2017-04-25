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
    
    class SubscribeRequest
    {
    public:
        
        SubscribeRequest(const MessageInfo* info, MessageData* data);
        SubscribeRequest(const SubscribeRequest& message);
        
        ~SubscribeRequest();
        
        SubscribeRequest& operator=(const SubscribeRequest& message);
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    template<> SubscribeRequest create<SubscribeRequest>();
    
    template<> bool is<SubscribeRequest, recsen::Message>(recsen::Message message);
    
    template<> recsen::Message cast<recsen::Message, SubscribeRequest>(SubscribeRequest message);
    template<> SubscribeRequest cast<SubscribeRequest, recsen::Message>(recsen::Message message);
    
    class SubscribeRequestConst
    {
    public:
        
        SubscribeRequestConst(const MessageInfo* info, const MessageData* data);
        SubscribeRequestConst(const SubscribeRequestConst& message);
        
        ~SubscribeRequestConst();
        
        SubscribeRequestConst& operator=(const SubscribeRequestConst& message);
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        const MessageData* data_;
    };
    
    template<> bool is<SubscribeRequestConst, recsen::MessageConst>(recsen::MessageConst message);
    
    template<> recsen::MessageConst cast<recsen::MessageConst, SubscribeRequestConst>(SubscribeRequestConst message);
    template<> SubscribeRequestConst cast<SubscribeRequestConst, recsen::MessageConst>(recsen::MessageConst message);
    template<> SubscribeRequestConst cast<SubscribeRequestConst, SubscribeRequest>(SubscribeRequest message);
    
    class SubscribeAccept
    {
    public:
        
        SubscribeAccept(const MessageInfo* info, MessageData* data);
        SubscribeAccept(const SubscribeAccept& message);
        
        ~SubscribeAccept();
        
        SubscribeAccept& operator=(const SubscribeAccept& message);
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    template<> SubscribeAccept create<SubscribeAccept>();
    
    template<> bool is<SubscribeAccept, recsen::Message>(recsen::Message message);
    
    template<> recsen::Message cast<recsen::Message, SubscribeAccept>(SubscribeAccept message);
    template<> SubscribeAccept cast<SubscribeAccept, recsen::Message>(recsen::Message message);
    
    class SubscribeAcceptConst
    {
    public:
        
        SubscribeAcceptConst(const MessageInfo* info, const MessageData* data);
        SubscribeAcceptConst(const SubscribeAcceptConst& message);
        
        ~SubscribeAcceptConst();
        
        SubscribeAcceptConst& operator=(const SubscribeAcceptConst& message);
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        const MessageData* data_;
    };
    
    template<> bool is<SubscribeAcceptConst, recsen::MessageConst>(recsen::MessageConst message);
    
    template<> recsen::MessageConst cast<recsen::MessageConst, SubscribeAcceptConst>(SubscribeAcceptConst message);
    template<> SubscribeAcceptConst cast<SubscribeAcceptConst, recsen::MessageConst>(recsen::MessageConst message);
    template<> SubscribeAcceptConst cast<SubscribeAcceptConst, SubscribeAccept>(SubscribeAccept message);
    
    class SubscribeReject
    {
    public:
        
        SubscribeReject(const MessageInfo* info, MessageData* data);
        SubscribeReject(const SubscribeReject& message);
        
        ~SubscribeReject();
        
        SubscribeReject& operator=(const SubscribeReject& message);
        
        void setText(const std::string& value);
        
        std::string getText() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    template<> SubscribeReject create<SubscribeReject>();
    
    template<> bool is<SubscribeReject, recsen::Message>(recsen::Message message);
    
    template<> recsen::Message cast<recsen::Message, SubscribeReject>(SubscribeReject message);
    template<> SubscribeReject cast<SubscribeReject, recsen::Message>(recsen::Message message);
    
    class SubscribeRejectConst
    {
    public:
        
        SubscribeRejectConst(const MessageInfo* info, const MessageData* data);
        SubscribeRejectConst(const SubscribeRejectConst& message);
        
        ~SubscribeRejectConst();
        
        SubscribeRejectConst& operator=(const SubscribeRejectConst& message);
        
        std::string getText() const;
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        const MessageData* data_;
    };
    
    template<> bool is<SubscribeRejectConst, recsen::MessageConst>(recsen::MessageConst message);
    
    template<> recsen::MessageConst cast<recsen::MessageConst, SubscribeRejectConst>(SubscribeRejectConst message);
    template<> SubscribeRejectConst cast<SubscribeRejectConst, recsen::MessageConst>(recsen::MessageConst message);
    template<> SubscribeRejectConst cast<SubscribeRejectConst, SubscribeReject>(SubscribeReject message);
    
    class UnsubscribeRequest
    {
    public:
        
        UnsubscribeRequest(const MessageInfo* info, MessageData* data);
        UnsubscribeRequest(const UnsubscribeRequest& message);
        
        ~UnsubscribeRequest();
        
        UnsubscribeRequest& operator=(const UnsubscribeRequest& message);
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    template<> UnsubscribeRequest create<UnsubscribeRequest>();
    
    template<> bool is<UnsubscribeRequest, recsen::Message>(recsen::Message message);
    
    template<> recsen::Message cast<recsen::Message, UnsubscribeRequest>(UnsubscribeRequest message);
    template<> UnsubscribeRequest cast<UnsubscribeRequest, recsen::Message>(recsen::Message message);
    
    class UnsubscribeRequestConst
    {
    public:
        
        UnsubscribeRequestConst(const MessageInfo* info, const MessageData* data);
        UnsubscribeRequestConst(const UnsubscribeRequestConst& message);
        
        ~UnsubscribeRequestConst();
        
        UnsubscribeRequestConst& operator=(const UnsubscribeRequestConst& message);
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        const MessageData* data_;
    };
    
    template<> bool is<UnsubscribeRequestConst, recsen::MessageConst>(recsen::MessageConst message);
    
    template<> recsen::MessageConst cast<recsen::MessageConst, UnsubscribeRequestConst>(UnsubscribeRequestConst message);
    template<> UnsubscribeRequestConst cast<UnsubscribeRequestConst, recsen::MessageConst>(recsen::MessageConst message);
    template<> UnsubscribeRequestConst cast<UnsubscribeRequestConst, UnsubscribeRequest>(UnsubscribeRequest message);
    
    class UnsubscribeAccept
    {
    public:
        
        UnsubscribeAccept(const MessageInfo* info, MessageData* data);
        UnsubscribeAccept(const UnsubscribeAccept& message);
        
        ~UnsubscribeAccept();
        
        UnsubscribeAccept& operator=(const UnsubscribeAccept& message);
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    template<> UnsubscribeAccept create<UnsubscribeAccept>();
    
    template<> bool is<UnsubscribeAccept, recsen::Message>(recsen::Message message);
    
    template<> recsen::Message cast<recsen::Message, UnsubscribeAccept>(UnsubscribeAccept message);
    template<> UnsubscribeAccept cast<UnsubscribeAccept, recsen::Message>(recsen::Message message);
    
    class UnsubscribeAcceptConst
    {
    public:
        
        UnsubscribeAcceptConst(const MessageInfo* info, const MessageData* data);
        UnsubscribeAcceptConst(const UnsubscribeAcceptConst& message);
        
        ~UnsubscribeAcceptConst();
        
        UnsubscribeAcceptConst& operator=(const UnsubscribeAcceptConst& message);
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        const MessageData* data_;
    };
    
    template<> bool is<UnsubscribeAcceptConst, recsen::MessageConst>(recsen::MessageConst message);
    
    template<> recsen::MessageConst cast<recsen::MessageConst, UnsubscribeAcceptConst>(UnsubscribeAcceptConst message);
    template<> UnsubscribeAcceptConst cast<UnsubscribeAcceptConst, recsen::MessageConst>(recsen::MessageConst message);
    template<> UnsubscribeAcceptConst cast<UnsubscribeAcceptConst, UnsubscribeAccept>(UnsubscribeAccept message);
    
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
        
        void loginPublic(loginPublicClientContext* context, LoginPublicRequest message);
        
        void loginPrivate(loginPrivateClientContext* context, LoginPrivateRequest message);
        
        void subscribe(subscribeClientContext* context, SubscribeRequest message);
        
        void logout(logoutClientContext* context, Logout message);
        
        void unsubscribe(unsubscribeClientContext* context, UnsubscribeRequest message);
        
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
        
        void virtual onLogout(ClientSession* session, LogoutConst message);
        
        void virtual onSubscribeAccept(ClientSession* session, subscribeClientContext* context, SubscribeAcceptConst message);
        
        void virtual onSubscribeReject(ClientSession* session, subscribeClientContext* context, SubscribeRejectConst message);
        
        void virtual onLogout(ClientSession* session, subscribeClientContext* context, LogoutConst message);
        
        void virtual onSnapshot(ClientSession* session, SnapshotRefreshConst message);
        
        void virtual onLogout(ClientSession* session, LogoutConst message);
        
        void virtual onLogout(ClientSession* session, unsubscribeClientContext* context, LogoutConst message);
        
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
        
        void virtual onSubscribe(ServerSession* session, SubscribeRequestConst message);
        
        void virtual onLogout(ServerSession* session, LogoutConst message);
        
        void virtual onUnsubscribe(ServerSession* session, UnsubscribeRequestConst message);
        
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
