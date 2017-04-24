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
    
    class SymbolRequest
    {
    public:
        
        SymbolRequest();
        SymbolRequest(MessageInfo* info, MessageData* data);
        
        void setSymbol(const std::string& value);
        
        std::string getSymbol() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        MessageInfo* info_;
        MessageData* data_;
    };
    
    class SymbolRequestConst
    {
    public:
        
        SymbolRequestConst();
        SymbolRequestConst(MessageInfo* info, MessageData* data);
        
        std::string getSymbol() const;
        
        std::string toString() const;
        
    private:
        
        MessageInfo* info_;
        MessageData* data_;
    };
    
    class SymbolResponse
    {
    public:
        
        SymbolResponse();
        SymbolResponse(MessageInfo* info, MessageData* data);
        
        void setSymbol(const std::string& value);
        
        std::string getSymbol() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        MessageInfo* info_;
        MessageData* data_;
    };
    
    class SymbolResponseConst
    {
    public:
        
        SymbolResponseConst();
        SymbolResponseConst(MessageInfo* info, MessageData* data);
        
        std::string getSymbol() const;
        
        std::string toString() const;
        
    private:
        
        MessageInfo* info_;
        MessageData* data_;
    };
    
    class SubscribeSymbolRequest
    {
    public:
        
        SubscribeSymbolRequest();
        SubscribeSymbolRequest(MessageInfo* info, MessageData* data);
        
        void setSymbol(const std::string& value);
        
        std::string getSymbol() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        MessageInfo* info_;
        MessageData* data_;
    };
    
    class SubscribeSymbolRequestConst
    {
    public:
        
        SubscribeSymbolRequestConst();
        SubscribeSymbolRequestConst(MessageInfo* info, MessageData* data);
        
        std::string getSymbol() const;
        
        std::string toString() const;
        
    private:
        
        MessageInfo* info_;
        MessageData* data_;
    };
    
    class SubscribeSymbolAccept
    {
    public:
        
        SubscribeSymbolAccept();
        SubscribeSymbolAccept(MessageInfo* info, MessageData* data);
        
        void setSymbol(const std::string& value);
        
        std::string getSymbol() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        MessageInfo* info_;
        MessageData* data_;
    };
    
    class SubscribeSymbolAcceptConst
    {
    public:
        
        SubscribeSymbolAcceptConst();
        SubscribeSymbolAcceptConst(MessageInfo* info, MessageData* data);
        
        std::string getSymbol() const;
        
        std::string toString() const;
        
    private:
        
        MessageInfo* info_;
        MessageData* data_;
    };
    
    class SubscribeSymbolReject
    {
    public:
        
        SubscribeSymbolReject();
        SubscribeSymbolReject(MessageInfo* info, MessageData* data);
        
        void setSymbol(const std::string& value);
        
        std::string getSymbol() const;
        
        void setText(const std::string& value);
        
        std::string getText() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        MessageInfo* info_;
        MessageData* data_;
    };
    
    class SubscribeSymbolRejectConst
    {
    public:
        
        SubscribeSymbolRejectConst();
        SubscribeSymbolRejectConst(MessageInfo* info, MessageData* data);
        
        std::string getSymbol() const;
        
        std::string getText() const;
        
        std::string toString() const;
        
    private:
        
        MessageInfo* info_;
        MessageData* data_;
    };
    
    class UnsubscribeSymbolRequest
    {
    public:
        
        UnsubscribeSymbolRequest();
        UnsubscribeSymbolRequest(MessageInfo* info, MessageData* data);
        
        void setSymbol(const std::string& value);
        
        std::string getSymbol() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        MessageInfo* info_;
        MessageData* data_;
    };
    
    class UnsubscribeSymbolRequestConst
    {
    public:
        
        UnsubscribeSymbolRequestConst();
        UnsubscribeSymbolRequestConst(MessageInfo* info, MessageData* data);
        
        std::string getSymbol() const;
        
        std::string toString() const;
        
    private:
        
        MessageInfo* info_;
        MessageData* data_;
    };
    
    class UnsubscribeSymbolAccept
    {
    public:
        
        UnsubscribeSymbolAccept();
        UnsubscribeSymbolAccept(MessageInfo* info, MessageData* data);
        
        void setSymbol(const std::string& value);
        
        std::string getSymbol() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        MessageInfo* info_;
        MessageData* data_;
    };
    
    class UnsubscribeSymbolAcceptConst
    {
    public:
        
        UnsubscribeSymbolAcceptConst();
        UnsubscribeSymbolAcceptConst(MessageInfo* info, MessageData* data);
        
        std::string getSymbol() const;
        
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
    
    class NewsRequest
    {
    public:
        
        NewsRequest();
        NewsRequest(MessageInfo* info, MessageData* data);
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        MessageInfo* info_;
        MessageData* data_;
    };
    
    class NewsRequestConst
    {
    public:
        
        NewsRequestConst();
        NewsRequestConst(MessageInfo* info, MessageData* data);
        
        std::string toString() const;
        
    private:
        
        MessageInfo* info_;
        MessageData* data_;
    };
    
    class NewsResponse
    {
    public:
        
        NewsResponse();
        NewsResponse(MessageInfo* info, MessageData* data);
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        MessageInfo* info_;
        MessageData* data_;
    };
    
    class NewsResponseConst
    {
    public:
        
        NewsResponseConst();
        NewsResponseConst(MessageInfo* info, MessageData* data);
        
        std::string toString() const;
        
    private:
        
        MessageInfo* info_;
        MessageData* data_;
    };
    
    class SubscribeNewsRequest
    {
    public:
        
        SubscribeNewsRequest();
        SubscribeNewsRequest(MessageInfo* info, MessageData* data);
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        MessageInfo* info_;
        MessageData* data_;
    };
    
    class SubscribeNewsRequestConst
    {
    public:
        
        SubscribeNewsRequestConst();
        SubscribeNewsRequestConst(MessageInfo* info, MessageData* data);
        
        std::string toString() const;
        
    private:
        
        MessageInfo* info_;
        MessageData* data_;
    };
    
    class SubscribeNewsAccept
    {
    public:
        
        SubscribeNewsAccept();
        SubscribeNewsAccept(MessageInfo* info, MessageData* data);
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        MessageInfo* info_;
        MessageData* data_;
    };
    
    class SubscribeNewsAcceptConst
    {
    public:
        
        SubscribeNewsAcceptConst();
        SubscribeNewsAcceptConst(MessageInfo* info, MessageData* data);
        
        std::string toString() const;
        
    private:
        
        MessageInfo* info_;
        MessageData* data_;
    };
    
    class SubscribeNewsReject
    {
    public:
        
        SubscribeNewsReject();
        SubscribeNewsReject(MessageInfo* info, MessageData* data);
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        MessageInfo* info_;
        MessageData* data_;
    };
    
    class SubscribeNewsRejectConst
    {
    public:
        
        SubscribeNewsRejectConst();
        SubscribeNewsRejectConst(MessageInfo* info, MessageData* data);
        
        std::string toString() const;
        
    private:
        
        MessageInfo* info_;
        MessageData* data_;
    };
    
    class UnsubscribeNewsRequest
    {
    public:
        
        UnsubscribeNewsRequest();
        UnsubscribeNewsRequest(MessageInfo* info, MessageData* data);
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        MessageInfo* info_;
        MessageData* data_;
    };
    
    class UnsubscribeNewsRequestConst
    {
    public:
        
        UnsubscribeNewsRequestConst();
        UnsubscribeNewsRequestConst(MessageInfo* info, MessageData* data);
        
        std::string toString() const;
        
    private:
        
        MessageInfo* info_;
        MessageData* data_;
    };
    
    class UnsubscribeNewsAccept
    {
    public:
        
        UnsubscribeNewsAccept();
        UnsubscribeNewsAccept(MessageInfo* info, MessageData* data);
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        MessageInfo* info_;
        MessageData* data_;
    };
    
    class UnsubscribeNewsAcceptConst
    {
    public:
        
        UnsubscribeNewsAcceptConst();
        UnsubscribeNewsAcceptConst(MessageInfo* info, MessageData* data);
        
        std::string toString() const;
        
    private:
        
        MessageInfo* info_;
        MessageData* data_;
    };
    
    enum NewsSeverity
    {
        Critical = 0,
        Warning = 1,
        Information = 2,
    };
    
    typedef recsen::array_t<NewsSeverity> NewsSeverityArray;
    typedef recsen::const_array_t<NewsSeverity> NewsSeverityConstArray;
    typedef recsen::array_t<recsen::null_t<NewsSeverity>> NewsSeverityNullArray;
    typedef recsen::const_array_t<recsen::null_t<NewsSeverity>> NewsSeverityNullConstArray;
    
    class NewsNotification
    {
    public:
        
        NewsNotification();
        NewsNotification(MessageInfo* info, MessageData* data);
        
        void setSeverity(NewsSeverity value);
        
        NewsSeverity getSeverity() const;
        
        void setHeader(const std::string& value);
        
        std::string getHeader() const;
        
        void setText(const std::string& value);
        
        std::string getText() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        MessageInfo* info_;
        MessageData* data_;
    };
    
    class NewsNotificationConst
    {
    public:
        
        NewsNotificationConst();
        NewsNotificationConst(MessageInfo* info, MessageData* data);
        
        NewsSeverity getSeverity() const;
        
        std::string getHeader() const;
        
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
    
    template<typename MESSAGE1, typename MESSAGE2> bool is(MESSAGE2& message);
    template<> bool is<LoginPublicRequest, recsen::Message>(recsen::Message& message);
    template<> bool is<LoginPrivateRequest, recsen::Message>(recsen::Message& message);
    template<> bool is<PasswordRequest, recsen::Message>(recsen::Message& message);
    template<> bool is<PasswordResponse, recsen::Message>(recsen::Message& message);
    template<> bool is<LoginAccept, recsen::Message>(recsen::Message& message);
    template<> bool is<LoginReject, recsen::Message>(recsen::Message& message);
    template<> bool is<SymbolRequest, recsen::Message>(recsen::Message& message);
    template<> bool is<SymbolResponse, recsen::Message>(recsen::Message& message);
    template<> bool is<SubscribeSymbolRequest, SymbolRequest>(SymbolRequest& message);
    template<> bool is<SubscribeSymbolRequest, recsen::Message>(recsen::Message& message);
    template<> bool is<SubscribeSymbolAccept, SymbolResponse>(SymbolResponse& message);
    template<> bool is<SubscribeSymbolAccept, recsen::Message>(recsen::Message& message);
    template<> bool is<SubscribeSymbolReject, SymbolResponse>(SymbolResponse& message);
    template<> bool is<SubscribeSymbolReject, recsen::Message>(recsen::Message& message);
    template<> bool is<UnsubscribeSymbolRequest, SymbolRequest>(SymbolRequest& message);
    template<> bool is<UnsubscribeSymbolRequest, recsen::Message>(recsen::Message& message);
    template<> bool is<UnsubscribeSymbolAccept, SymbolResponse>(SymbolResponse& message);
    template<> bool is<UnsubscribeSymbolAccept, recsen::Message>(recsen::Message& message);
    template<> bool is<SnapshotRefresh, SymbolResponse>(SymbolResponse& message);
    template<> bool is<SnapshotRefresh, recsen::Message>(recsen::Message& message);
    template<> bool is<NewsRequest, recsen::Message>(recsen::Message& message);
    template<> bool is<NewsResponse, recsen::Message>(recsen::Message& message);
    template<> bool is<SubscribeNewsRequest, NewsRequest>(NewsRequest& message);
    template<> bool is<SubscribeNewsRequest, recsen::Message>(recsen::Message& message);
    template<> bool is<SubscribeNewsAccept, NewsResponse>(NewsResponse& message);
    template<> bool is<SubscribeNewsAccept, recsen::Message>(recsen::Message& message);
    template<> bool is<SubscribeNewsReject, NewsResponse>(NewsResponse& message);
    template<> bool is<SubscribeNewsReject, recsen::Message>(recsen::Message& message);
    template<> bool is<UnsubscribeNewsRequest, NewsRequest>(NewsRequest& message);
    template<> bool is<UnsubscribeNewsRequest, recsen::Message>(recsen::Message& message);
    template<> bool is<UnsubscribeNewsAccept, NewsResponse>(NewsResponse& message);
    template<> bool is<UnsubscribeNewsAccept, recsen::Message>(recsen::Message& message);
    template<> bool is<NewsNotification, NewsResponse>(NewsResponse& message);
    template<> bool is<NewsNotification, recsen::Message>(recsen::Message& message);
    template<> bool is<Logout, recsen::Message>(recsen::Message& message);
    template<> bool is<LoginPublicRequestConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> bool is<LoginPrivateRequestConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> bool is<PasswordRequestConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> bool is<PasswordResponseConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> bool is<LoginAcceptConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> bool is<LoginRejectConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> bool is<SymbolRequestConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> bool is<SymbolResponseConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> bool is<SubscribeSymbolRequestConst, SymbolRequestConst>(SymbolRequestConst& message);
    template<> bool is<SubscribeSymbolRequestConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> bool is<SubscribeSymbolAcceptConst, SymbolResponseConst>(SymbolResponseConst& message);
    template<> bool is<SubscribeSymbolAcceptConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> bool is<SubscribeSymbolRejectConst, SymbolResponseConst>(SymbolResponseConst& message);
    template<> bool is<SubscribeSymbolRejectConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> bool is<UnsubscribeSymbolRequestConst, SymbolRequestConst>(SymbolRequestConst& message);
    template<> bool is<UnsubscribeSymbolRequestConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> bool is<UnsubscribeSymbolAcceptConst, SymbolResponseConst>(SymbolResponseConst& message);
    template<> bool is<UnsubscribeSymbolAcceptConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> bool is<SnapshotRefreshConst, SymbolResponseConst>(SymbolResponseConst& message);
    template<> bool is<SnapshotRefreshConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> bool is<NewsRequestConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> bool is<NewsResponseConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> bool is<SubscribeNewsRequestConst, NewsRequestConst>(NewsRequestConst& message);
    template<> bool is<SubscribeNewsRequestConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> bool is<SubscribeNewsAcceptConst, NewsResponseConst>(NewsResponseConst& message);
    template<> bool is<SubscribeNewsAcceptConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> bool is<SubscribeNewsRejectConst, NewsResponseConst>(NewsResponseConst& message);
    template<> bool is<SubscribeNewsRejectConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> bool is<UnsubscribeNewsRequestConst, NewsRequestConst>(NewsRequestConst& message);
    template<> bool is<UnsubscribeNewsRequestConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> bool is<UnsubscribeNewsAcceptConst, NewsResponseConst>(NewsResponseConst& message);
    template<> bool is<UnsubscribeNewsAcceptConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> bool is<NewsNotificationConst, NewsResponseConst>(NewsResponseConst& message);
    template<> bool is<NewsNotificationConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> bool is<LogoutConst, recsen::MessageConst>(recsen::MessageConst& message);
    
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
    template<> recsen::Message cast<recsen::Message, SymbolRequest>(SymbolRequest& message);
    template<> SymbolRequest cast<SymbolRequest, recsen::Message>(recsen::Message& message);
    template<> recsen::Message cast<recsen::Message, SymbolResponse>(SymbolResponse& message);
    template<> SymbolResponse cast<SymbolResponse, recsen::Message>(recsen::Message& message);
    template<> SymbolRequest cast<SymbolRequest, SubscribeSymbolRequest>(SubscribeSymbolRequest& message);
    template<> SubscribeSymbolRequest cast<SubscribeSymbolRequest, SymbolRequest>(SymbolRequest& message);
    template<> recsen::Message cast<recsen::Message, SubscribeSymbolRequest>(SubscribeSymbolRequest& message);
    template<> SubscribeSymbolRequest cast<SubscribeSymbolRequest, recsen::Message>(recsen::Message& message);
    template<> SymbolResponse cast<SymbolResponse, SubscribeSymbolAccept>(SubscribeSymbolAccept& message);
    template<> SubscribeSymbolAccept cast<SubscribeSymbolAccept, SymbolResponse>(SymbolResponse& message);
    template<> recsen::Message cast<recsen::Message, SubscribeSymbolAccept>(SubscribeSymbolAccept& message);
    template<> SubscribeSymbolAccept cast<SubscribeSymbolAccept, recsen::Message>(recsen::Message& message);
    template<> SymbolResponse cast<SymbolResponse, SubscribeSymbolReject>(SubscribeSymbolReject& message);
    template<> SubscribeSymbolReject cast<SubscribeSymbolReject, SymbolResponse>(SymbolResponse& message);
    template<> recsen::Message cast<recsen::Message, SubscribeSymbolReject>(SubscribeSymbolReject& message);
    template<> SubscribeSymbolReject cast<SubscribeSymbolReject, recsen::Message>(recsen::Message& message);
    template<> SymbolRequest cast<SymbolRequest, UnsubscribeSymbolRequest>(UnsubscribeSymbolRequest& message);
    template<> UnsubscribeSymbolRequest cast<UnsubscribeSymbolRequest, SymbolRequest>(SymbolRequest& message);
    template<> recsen::Message cast<recsen::Message, UnsubscribeSymbolRequest>(UnsubscribeSymbolRequest& message);
    template<> UnsubscribeSymbolRequest cast<UnsubscribeSymbolRequest, recsen::Message>(recsen::Message& message);
    template<> SymbolResponse cast<SymbolResponse, UnsubscribeSymbolAccept>(UnsubscribeSymbolAccept& message);
    template<> UnsubscribeSymbolAccept cast<UnsubscribeSymbolAccept, SymbolResponse>(SymbolResponse& message);
    template<> recsen::Message cast<recsen::Message, UnsubscribeSymbolAccept>(UnsubscribeSymbolAccept& message);
    template<> UnsubscribeSymbolAccept cast<UnsubscribeSymbolAccept, recsen::Message>(recsen::Message& message);
    template<> SymbolResponse cast<SymbolResponse, SnapshotRefresh>(SnapshotRefresh& message);
    template<> SnapshotRefresh cast<SnapshotRefresh, SymbolResponse>(SymbolResponse& message);
    template<> recsen::Message cast<recsen::Message, SnapshotRefresh>(SnapshotRefresh& message);
    template<> SnapshotRefresh cast<SnapshotRefresh, recsen::Message>(recsen::Message& message);
    template<> recsen::Message cast<recsen::Message, NewsRequest>(NewsRequest& message);
    template<> NewsRequest cast<NewsRequest, recsen::Message>(recsen::Message& message);
    template<> recsen::Message cast<recsen::Message, NewsResponse>(NewsResponse& message);
    template<> NewsResponse cast<NewsResponse, recsen::Message>(recsen::Message& message);
    template<> NewsRequest cast<NewsRequest, SubscribeNewsRequest>(SubscribeNewsRequest& message);
    template<> SubscribeNewsRequest cast<SubscribeNewsRequest, NewsRequest>(NewsRequest& message);
    template<> recsen::Message cast<recsen::Message, SubscribeNewsRequest>(SubscribeNewsRequest& message);
    template<> SubscribeNewsRequest cast<SubscribeNewsRequest, recsen::Message>(recsen::Message& message);
    template<> NewsResponse cast<NewsResponse, SubscribeNewsAccept>(SubscribeNewsAccept& message);
    template<> SubscribeNewsAccept cast<SubscribeNewsAccept, NewsResponse>(NewsResponse& message);
    template<> recsen::Message cast<recsen::Message, SubscribeNewsAccept>(SubscribeNewsAccept& message);
    template<> SubscribeNewsAccept cast<SubscribeNewsAccept, recsen::Message>(recsen::Message& message);
    template<> NewsResponse cast<NewsResponse, SubscribeNewsReject>(SubscribeNewsReject& message);
    template<> SubscribeNewsReject cast<SubscribeNewsReject, NewsResponse>(NewsResponse& message);
    template<> recsen::Message cast<recsen::Message, SubscribeNewsReject>(SubscribeNewsReject& message);
    template<> SubscribeNewsReject cast<SubscribeNewsReject, recsen::Message>(recsen::Message& message);
    template<> NewsRequest cast<NewsRequest, UnsubscribeNewsRequest>(UnsubscribeNewsRequest& message);
    template<> UnsubscribeNewsRequest cast<UnsubscribeNewsRequest, NewsRequest>(NewsRequest& message);
    template<> recsen::Message cast<recsen::Message, UnsubscribeNewsRequest>(UnsubscribeNewsRequest& message);
    template<> UnsubscribeNewsRequest cast<UnsubscribeNewsRequest, recsen::Message>(recsen::Message& message);
    template<> NewsResponse cast<NewsResponse, UnsubscribeNewsAccept>(UnsubscribeNewsAccept& message);
    template<> UnsubscribeNewsAccept cast<UnsubscribeNewsAccept, NewsResponse>(NewsResponse& message);
    template<> recsen::Message cast<recsen::Message, UnsubscribeNewsAccept>(UnsubscribeNewsAccept& message);
    template<> UnsubscribeNewsAccept cast<UnsubscribeNewsAccept, recsen::Message>(recsen::Message& message);
    template<> NewsResponse cast<NewsResponse, NewsNotification>(NewsNotification& message);
    template<> NewsNotification cast<NewsNotification, NewsResponse>(NewsResponse& message);
    template<> recsen::Message cast<recsen::Message, NewsNotification>(NewsNotification& message);
    template<> NewsNotification cast<NewsNotification, recsen::Message>(recsen::Message& message);
    template<> recsen::Message cast<recsen::Message, Logout>(Logout& message);
    template<> Logout cast<Logout, recsen::Message>(recsen::Message& message);
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
    template<> recsen::MessageConst cast<recsen::MessageConst, SymbolRequestConst>(SymbolRequestConst& message);
    template<> SymbolRequestConst cast<SymbolRequestConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> recsen::MessageConst cast<recsen::MessageConst, SymbolResponseConst>(SymbolResponseConst& message);
    template<> SymbolResponseConst cast<SymbolResponseConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> SymbolRequestConst cast<SymbolRequestConst, SubscribeSymbolRequestConst>(SubscribeSymbolRequestConst& message);
    template<> SubscribeSymbolRequestConst cast<SubscribeSymbolRequestConst, SymbolRequestConst>(SymbolRequestConst& message);
    template<> recsen::MessageConst cast<recsen::MessageConst, SubscribeSymbolRequestConst>(SubscribeSymbolRequestConst& message);
    template<> SubscribeSymbolRequestConst cast<SubscribeSymbolRequestConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> SymbolResponseConst cast<SymbolResponseConst, SubscribeSymbolAcceptConst>(SubscribeSymbolAcceptConst& message);
    template<> SubscribeSymbolAcceptConst cast<SubscribeSymbolAcceptConst, SymbolResponseConst>(SymbolResponseConst& message);
    template<> recsen::MessageConst cast<recsen::MessageConst, SubscribeSymbolAcceptConst>(SubscribeSymbolAcceptConst& message);
    template<> SubscribeSymbolAcceptConst cast<SubscribeSymbolAcceptConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> SymbolResponseConst cast<SymbolResponseConst, SubscribeSymbolRejectConst>(SubscribeSymbolRejectConst& message);
    template<> SubscribeSymbolRejectConst cast<SubscribeSymbolRejectConst, SymbolResponseConst>(SymbolResponseConst& message);
    template<> recsen::MessageConst cast<recsen::MessageConst, SubscribeSymbolRejectConst>(SubscribeSymbolRejectConst& message);
    template<> SubscribeSymbolRejectConst cast<SubscribeSymbolRejectConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> SymbolRequestConst cast<SymbolRequestConst, UnsubscribeSymbolRequestConst>(UnsubscribeSymbolRequestConst& message);
    template<> UnsubscribeSymbolRequestConst cast<UnsubscribeSymbolRequestConst, SymbolRequestConst>(SymbolRequestConst& message);
    template<> recsen::MessageConst cast<recsen::MessageConst, UnsubscribeSymbolRequestConst>(UnsubscribeSymbolRequestConst& message);
    template<> UnsubscribeSymbolRequestConst cast<UnsubscribeSymbolRequestConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> SymbolResponseConst cast<SymbolResponseConst, UnsubscribeSymbolAcceptConst>(UnsubscribeSymbolAcceptConst& message);
    template<> UnsubscribeSymbolAcceptConst cast<UnsubscribeSymbolAcceptConst, SymbolResponseConst>(SymbolResponseConst& message);
    template<> recsen::MessageConst cast<recsen::MessageConst, UnsubscribeSymbolAcceptConst>(UnsubscribeSymbolAcceptConst& message);
    template<> UnsubscribeSymbolAcceptConst cast<UnsubscribeSymbolAcceptConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> SymbolResponseConst cast<SymbolResponseConst, SnapshotRefreshConst>(SnapshotRefreshConst& message);
    template<> SnapshotRefreshConst cast<SnapshotRefreshConst, SymbolResponseConst>(SymbolResponseConst& message);
    template<> recsen::MessageConst cast<recsen::MessageConst, SnapshotRefreshConst>(SnapshotRefreshConst& message);
    template<> SnapshotRefreshConst cast<SnapshotRefreshConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> recsen::MessageConst cast<recsen::MessageConst, NewsRequestConst>(NewsRequestConst& message);
    template<> NewsRequestConst cast<NewsRequestConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> recsen::MessageConst cast<recsen::MessageConst, NewsResponseConst>(NewsResponseConst& message);
    template<> NewsResponseConst cast<NewsResponseConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> NewsRequestConst cast<NewsRequestConst, SubscribeNewsRequestConst>(SubscribeNewsRequestConst& message);
    template<> SubscribeNewsRequestConst cast<SubscribeNewsRequestConst, NewsRequestConst>(NewsRequestConst& message);
    template<> recsen::MessageConst cast<recsen::MessageConst, SubscribeNewsRequestConst>(SubscribeNewsRequestConst& message);
    template<> SubscribeNewsRequestConst cast<SubscribeNewsRequestConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> NewsResponseConst cast<NewsResponseConst, SubscribeNewsAcceptConst>(SubscribeNewsAcceptConst& message);
    template<> SubscribeNewsAcceptConst cast<SubscribeNewsAcceptConst, NewsResponseConst>(NewsResponseConst& message);
    template<> recsen::MessageConst cast<recsen::MessageConst, SubscribeNewsAcceptConst>(SubscribeNewsAcceptConst& message);
    template<> SubscribeNewsAcceptConst cast<SubscribeNewsAcceptConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> NewsResponseConst cast<NewsResponseConst, SubscribeNewsRejectConst>(SubscribeNewsRejectConst& message);
    template<> SubscribeNewsRejectConst cast<SubscribeNewsRejectConst, NewsResponseConst>(NewsResponseConst& message);
    template<> recsen::MessageConst cast<recsen::MessageConst, SubscribeNewsRejectConst>(SubscribeNewsRejectConst& message);
    template<> SubscribeNewsRejectConst cast<SubscribeNewsRejectConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> NewsRequestConst cast<NewsRequestConst, UnsubscribeNewsRequestConst>(UnsubscribeNewsRequestConst& message);
    template<> UnsubscribeNewsRequestConst cast<UnsubscribeNewsRequestConst, NewsRequestConst>(NewsRequestConst& message);
    template<> recsen::MessageConst cast<recsen::MessageConst, UnsubscribeNewsRequestConst>(UnsubscribeNewsRequestConst& message);
    template<> UnsubscribeNewsRequestConst cast<UnsubscribeNewsRequestConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> NewsResponseConst cast<NewsResponseConst, UnsubscribeNewsAcceptConst>(UnsubscribeNewsAcceptConst& message);
    template<> UnsubscribeNewsAcceptConst cast<UnsubscribeNewsAcceptConst, NewsResponseConst>(NewsResponseConst& message);
    template<> recsen::MessageConst cast<recsen::MessageConst, UnsubscribeNewsAcceptConst>(UnsubscribeNewsAcceptConst& message);
    template<> UnsubscribeNewsAcceptConst cast<UnsubscribeNewsAcceptConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> NewsResponseConst cast<NewsResponseConst, NewsNotificationConst>(NewsNotificationConst& message);
    template<> NewsNotificationConst cast<NewsNotificationConst, NewsResponseConst>(NewsResponseConst& message);
    template<> recsen::MessageConst cast<recsen::MessageConst, NewsNotificationConst>(NewsNotificationConst& message);
    template<> NewsNotificationConst cast<NewsNotificationConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> recsen::MessageConst cast<recsen::MessageConst, LogoutConst>(LogoutConst& message);
    template<> LogoutConst cast<LogoutConst, recsen::MessageConst>(recsen::MessageConst& message);
    template<> LoginPublicRequestConst cast<LoginPublicRequestConst, LoginPublicRequest>(LoginPublicRequest& message);
    template<> LoginPrivateRequestConst cast<LoginPrivateRequestConst, LoginPrivateRequest>(LoginPrivateRequest& message);
    template<> PasswordRequestConst cast<PasswordRequestConst, PasswordRequest>(PasswordRequest& message);
    template<> PasswordResponseConst cast<PasswordResponseConst, PasswordResponse>(PasswordResponse& message);
    template<> LoginAcceptConst cast<LoginAcceptConst, LoginAccept>(LoginAccept& message);
    template<> LoginRejectConst cast<LoginRejectConst, LoginReject>(LoginReject& message);
    template<> SymbolRequestConst cast<SymbolRequestConst, SymbolRequest>(SymbolRequest& message);
    template<> SymbolResponseConst cast<SymbolResponseConst, SymbolResponse>(SymbolResponse& message);
    template<> SubscribeSymbolRequestConst cast<SubscribeSymbolRequestConst, SubscribeSymbolRequest>(SubscribeSymbolRequest& message);
    template<> SubscribeSymbolAcceptConst cast<SubscribeSymbolAcceptConst, SubscribeSymbolAccept>(SubscribeSymbolAccept& message);
    template<> SubscribeSymbolRejectConst cast<SubscribeSymbolRejectConst, SubscribeSymbolReject>(SubscribeSymbolReject& message);
    template<> UnsubscribeSymbolRequestConst cast<UnsubscribeSymbolRequestConst, UnsubscribeSymbolRequest>(UnsubscribeSymbolRequest& message);
    template<> UnsubscribeSymbolAcceptConst cast<UnsubscribeSymbolAcceptConst, UnsubscribeSymbolAccept>(UnsubscribeSymbolAccept& message);
    template<> SnapshotRefreshConst cast<SnapshotRefreshConst, SnapshotRefresh>(SnapshotRefresh& message);
    template<> NewsRequestConst cast<NewsRequestConst, NewsRequest>(NewsRequest& message);
    template<> NewsResponseConst cast<NewsResponseConst, NewsResponse>(NewsResponse& message);
    template<> SubscribeNewsRequestConst cast<SubscribeNewsRequestConst, SubscribeNewsRequest>(SubscribeNewsRequest& message);
    template<> SubscribeNewsAcceptConst cast<SubscribeNewsAcceptConst, SubscribeNewsAccept>(SubscribeNewsAccept& message);
    template<> SubscribeNewsRejectConst cast<SubscribeNewsRejectConst, SubscribeNewsReject>(SubscribeNewsReject& message);
    template<> UnsubscribeNewsRequestConst cast<UnsubscribeNewsRequestConst, UnsubscribeNewsRequest>(UnsubscribeNewsRequest& message);
    template<> UnsubscribeNewsAcceptConst cast<UnsubscribeNewsAcceptConst, UnsubscribeNewsAccept>(UnsubscribeNewsAccept& message);
    template<> NewsNotificationConst cast<NewsNotificationConst, NewsNotification>(NewsNotification& message);
    template<> LogoutConst cast<LogoutConst, Logout>(Logout& message);
    
    struct loginPublicClientContext : recsen::Context
    {
    };
    
    struct loginPrivateClientContext : recsen::Context
    {
    };
    
    struct LogoutClientContext : recsen::Context
    {
    };
    
    struct subscribeSymbolClientContext : recsen::Context
    {
    };
    
    struct unsubscribeSymbolClientContext : recsen::Context
    {
    };
    
    struct subscribeNewsClientContext : recsen::Context
    {
    };
    
    struct unsubscribeNewsClientContext : recsen::Context
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
        
        void Logout(LogoutClientContext* context, Logout& message);
        
        void subscribeSymbol(subscribeSymbolClientContext* context, SubscribeSymbolRequest& message);
        
        void unsubscribeSymbol(unsubscribeSymbolClientContext* context, UnsubscribeSymbolRequest& message);
        
        void subscribeNews(subscribeNewsClientContext* context, SubscribeNewsRequest& message);
        
        void unsubscribeNews(unsubscribeNewsClientContext* context, UnsubscribeNewsRequest& message);
        
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
        
        void virtual onSubscribeSymbolAccept(ClientSession* session, subscribeSymbolClientContext* context, SubscribeSymbolAcceptConst& message);
        
        void virtual onSubscribeSymbolReject(ClientSession* session, subscribeSymbolClientContext* context, SubscribeSymbolRejectConst& message);
        
        void virtual onSnapshot(ClientSession* session, SnapshotRefreshConst& message);
        
        void virtual onSubscribeNewsAccept(ClientSession* session, subscribeNewsClientContext* context, SubscribeNewsAcceptConst& message);
        
        void virtual onSubscribeNewsReject(ClientSession* session, subscribeNewsClientContext* context, SubscribeNewsRejectConst& message);
        
        void virtual onNews(ClientSession* session, NewsNotificationConst& message);
        
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
        
        void virtual onLogout(ServerSession* session, LogoutConst& message);
        
        void virtual onSubscribeSymbol(ServerSession* session, SubscribeSymbolRequestConst& message);
        
        void virtual onUnsubscribeSymbol(ServerSession* session, UnsubscribeSymbolRequestConst& message);
        
        void virtual onSubscribeNews(ServerSession* session, SubscribeNewsRequestConst& message);
        
        void virtual onUnsubscribeNews(ServerSession* session, UnsubscribeNewsRequestConst& message);
        
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
