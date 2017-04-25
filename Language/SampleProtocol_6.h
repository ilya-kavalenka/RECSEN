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
    
    class SymbolRequest
    {
    public:
        
        SymbolRequest(const MessageInfo* info, MessageData* data);
        SymbolRequest(const SymbolRequest& message);
        
        ~SymbolRequest();
        
        SymbolRequest& operator=(const SymbolRequest& message);
        
        void setSymbol(const std::string& value);
        
        std::string getSymbol() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    template<> SymbolRequest create<SymbolRequest>();
    
    template<> bool is<SymbolRequest, recsen::Message>(recsen::Message message);
    
    template<> recsen::Message cast<recsen::Message, SymbolRequest>(SymbolRequest message);
    template<> SymbolRequest cast<SymbolRequest, recsen::Message>(recsen::Message message);
    
    class SymbolRequestConst
    {
    public:
        
        SymbolRequestConst(const MessageInfo* info, const MessageData* data);
        SymbolRequestConst(const SymbolRequestConst& message);
        
        ~SymbolRequestConst();
        
        SymbolRequestConst& operator=(const SymbolRequestConst& message);
        
        std::string getSymbol() const;
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        const MessageData* data_;
    };
    
    template<> bool is<SymbolRequestConst, recsen::MessageConst>(recsen::MessageConst message);
    
    template<> recsen::MessageConst cast<recsen::MessageConst, SymbolRequestConst>(SymbolRequestConst message);
    template<> SymbolRequestConst cast<SymbolRequestConst, recsen::MessageConst>(recsen::MessageConst message);
    template<> SymbolRequestConst cast<SymbolRequestConst, SymbolRequest>(SymbolRequest message);
    
    class SymbolResponse
    {
    public:
        
        SymbolResponse(const MessageInfo* info, MessageData* data);
        SymbolResponse(const SymbolResponse& message);
        
        ~SymbolResponse();
        
        SymbolResponse& operator=(const SymbolResponse& message);
        
        void setSymbol(const std::string& value);
        
        std::string getSymbol() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    template<> SymbolResponse create<SymbolResponse>();
    
    template<> bool is<SymbolResponse, recsen::Message>(recsen::Message message);
    
    template<> recsen::Message cast<recsen::Message, SymbolResponse>(SymbolResponse message);
    template<> SymbolResponse cast<SymbolResponse, recsen::Message>(recsen::Message message);
    
    class SymbolResponseConst
    {
    public:
        
        SymbolResponseConst(const MessageInfo* info, const MessageData* data);
        SymbolResponseConst(const SymbolResponseConst& message);
        
        ~SymbolResponseConst();
        
        SymbolResponseConst& operator=(const SymbolResponseConst& message);
        
        std::string getSymbol() const;
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        const MessageData* data_;
    };
    
    template<> bool is<SymbolResponseConst, recsen::MessageConst>(recsen::MessageConst message);
    
    template<> recsen::MessageConst cast<recsen::MessageConst, SymbolResponseConst>(SymbolResponseConst message);
    template<> SymbolResponseConst cast<SymbolResponseConst, recsen::MessageConst>(recsen::MessageConst message);
    template<> SymbolResponseConst cast<SymbolResponseConst, SymbolResponse>(SymbolResponse message);
    
    class SubscribeSymbolRequest
    {
    public:
        
        SubscribeSymbolRequest(const MessageInfo* info, MessageData* data);
        SubscribeSymbolRequest(const SubscribeSymbolRequest& message);
        
        ~SubscribeSymbolRequest();
        
        SubscribeSymbolRequest& operator=(const SubscribeSymbolRequest& message);
        
        void setSymbol(const std::string& value);
        
        std::string getSymbol() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    template<> SubscribeSymbolRequest create<SubscribeSymbolRequest>();
    
    template<> bool is<SubscribeSymbolRequest, SymbolRequest>(SymbolRequest message);
    template<> bool is<SubscribeSymbolRequest, recsen::Message>(recsen::Message message);
    
    template<> SymbolRequest cast<SymbolRequest, SubscribeSymbolRequest>(SubscribeSymbolRequest message);
    template<> SubscribeSymbolRequest cast<SubscribeSymbolRequest, SymbolRequest>(SymbolRequest message);
    template<> recsen::Message cast<recsen::Message, SubscribeSymbolRequest>(SubscribeSymbolRequest message);
    template<> SubscribeSymbolRequest cast<SubscribeSymbolRequest, recsen::Message>(recsen::Message message);
    
    class SubscribeSymbolRequestConst
    {
    public:
        
        SubscribeSymbolRequestConst(const MessageInfo* info, const MessageData* data);
        SubscribeSymbolRequestConst(const SubscribeSymbolRequestConst& message);
        
        ~SubscribeSymbolRequestConst();
        
        SubscribeSymbolRequestConst& operator=(const SubscribeSymbolRequestConst& message);
        
        std::string getSymbol() const;
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        const MessageData* data_;
    };
    
    template<> bool is<SubscribeSymbolRequestConst, SymbolRequestConst>(SymbolRequestConst message);
    template<> bool is<SubscribeSymbolRequestConst, recsen::MessageConst>(recsen::MessageConst message);
    
    template<> SymbolRequestConst cast<SymbolRequestConst, SubscribeSymbolRequestConst>(SubscribeSymbolRequestConst message);
    template<> SubscribeSymbolRequestConst cast<SubscribeSymbolRequestConst, SymbolRequestConst>(SymbolRequestConst message);
    template<> recsen::MessageConst cast<recsen::MessageConst, SubscribeSymbolRequestConst>(SubscribeSymbolRequestConst message);
    template<> SubscribeSymbolRequestConst cast<SubscribeSymbolRequestConst, recsen::MessageConst>(recsen::MessageConst message);
    template<> SubscribeSymbolRequestConst cast<SubscribeSymbolRequestConst, SubscribeSymbolRequest>(SubscribeSymbolRequest message);
    
    class SubscribeSymbolAccept
    {
    public:
        
        SubscribeSymbolAccept(const MessageInfo* info, MessageData* data);
        SubscribeSymbolAccept(const SubscribeSymbolAccept& message);
        
        ~SubscribeSymbolAccept();
        
        SubscribeSymbolAccept& operator=(const SubscribeSymbolAccept& message);
        
        void setSymbol(const std::string& value);
        
        std::string getSymbol() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    template<> SubscribeSymbolAccept create<SubscribeSymbolAccept>();
    
    template<> bool is<SubscribeSymbolAccept, SymbolResponse>(SymbolResponse message);
    template<> bool is<SubscribeSymbolAccept, recsen::Message>(recsen::Message message);
    
    template<> SymbolResponse cast<SymbolResponse, SubscribeSymbolAccept>(SubscribeSymbolAccept message);
    template<> SubscribeSymbolAccept cast<SubscribeSymbolAccept, SymbolResponse>(SymbolResponse message);
    template<> recsen::Message cast<recsen::Message, SubscribeSymbolAccept>(SubscribeSymbolAccept message);
    template<> SubscribeSymbolAccept cast<SubscribeSymbolAccept, recsen::Message>(recsen::Message message);
    
    class SubscribeSymbolAcceptConst
    {
    public:
        
        SubscribeSymbolAcceptConst(const MessageInfo* info, const MessageData* data);
        SubscribeSymbolAcceptConst(const SubscribeSymbolAcceptConst& message);
        
        ~SubscribeSymbolAcceptConst();
        
        SubscribeSymbolAcceptConst& operator=(const SubscribeSymbolAcceptConst& message);
        
        std::string getSymbol() const;
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        const MessageData* data_;
    };
    
    template<> bool is<SubscribeSymbolAcceptConst, SymbolResponseConst>(SymbolResponseConst message);
    template<> bool is<SubscribeSymbolAcceptConst, recsen::MessageConst>(recsen::MessageConst message);
    
    template<> SymbolResponseConst cast<SymbolResponseConst, SubscribeSymbolAcceptConst>(SubscribeSymbolAcceptConst message);
    template<> SubscribeSymbolAcceptConst cast<SubscribeSymbolAcceptConst, SymbolResponseConst>(SymbolResponseConst message);
    template<> recsen::MessageConst cast<recsen::MessageConst, SubscribeSymbolAcceptConst>(SubscribeSymbolAcceptConst message);
    template<> SubscribeSymbolAcceptConst cast<SubscribeSymbolAcceptConst, recsen::MessageConst>(recsen::MessageConst message);
    template<> SubscribeSymbolAcceptConst cast<SubscribeSymbolAcceptConst, SubscribeSymbolAccept>(SubscribeSymbolAccept message);
    
    class SubscribeSymbolReject
    {
    public:
        
        SubscribeSymbolReject(const MessageInfo* info, MessageData* data);
        SubscribeSymbolReject(const SubscribeSymbolReject& message);
        
        ~SubscribeSymbolReject();
        
        SubscribeSymbolReject& operator=(const SubscribeSymbolReject& message);
        
        void setSymbol(const std::string& value);
        
        std::string getSymbol() const;
        
        void setText(const std::string& value);
        
        std::string getText() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    template<> SubscribeSymbolReject create<SubscribeSymbolReject>();
    
    template<> bool is<SubscribeSymbolReject, SymbolResponse>(SymbolResponse message);
    template<> bool is<SubscribeSymbolReject, recsen::Message>(recsen::Message message);
    
    template<> SymbolResponse cast<SymbolResponse, SubscribeSymbolReject>(SubscribeSymbolReject message);
    template<> SubscribeSymbolReject cast<SubscribeSymbolReject, SymbolResponse>(SymbolResponse message);
    template<> recsen::Message cast<recsen::Message, SubscribeSymbolReject>(SubscribeSymbolReject message);
    template<> SubscribeSymbolReject cast<SubscribeSymbolReject, recsen::Message>(recsen::Message message);
    
    class SubscribeSymbolRejectConst
    {
    public:
        
        SubscribeSymbolRejectConst(const MessageInfo* info, const MessageData* data);
        SubscribeSymbolRejectConst(const SubscribeSymbolRejectConst& message);
        
        ~SubscribeSymbolRejectConst();
        
        SubscribeSymbolRejectConst& operator=(const SubscribeSymbolRejectConst& message);
        
        std::string getSymbol() const;
        
        std::string getText() const;
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        const MessageData* data_;
    };
    
    template<> bool is<SubscribeSymbolRejectConst, SymbolResponseConst>(SymbolResponseConst message);
    template<> bool is<SubscribeSymbolRejectConst, recsen::MessageConst>(recsen::MessageConst message);
    
    template<> SymbolResponseConst cast<SymbolResponseConst, SubscribeSymbolRejectConst>(SubscribeSymbolRejectConst message);
    template<> SubscribeSymbolRejectConst cast<SubscribeSymbolRejectConst, SymbolResponseConst>(SymbolResponseConst message);
    template<> recsen::MessageConst cast<recsen::MessageConst, SubscribeSymbolRejectConst>(SubscribeSymbolRejectConst message);
    template<> SubscribeSymbolRejectConst cast<SubscribeSymbolRejectConst, recsen::MessageConst>(recsen::MessageConst message);
    template<> SubscribeSymbolRejectConst cast<SubscribeSymbolRejectConst, SubscribeSymbolReject>(SubscribeSymbolReject message);
    
    class UnsubscribeSymbolRequest
    {
    public:
        
        UnsubscribeSymbolRequest(const MessageInfo* info, MessageData* data);
        UnsubscribeSymbolRequest(const UnsubscribeSymbolRequest& message);
        
        ~UnsubscribeSymbolRequest();
        
        UnsubscribeSymbolRequest& operator=(const UnsubscribeSymbolRequest& message);
        
        void setSymbol(const std::string& value);
        
        std::string getSymbol() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    template<> UnsubscribeSymbolRequest create<UnsubscribeSymbolRequest>();
    
    template<> bool is<UnsubscribeSymbolRequest, SymbolRequest>(SymbolRequest message);
    template<> bool is<UnsubscribeSymbolRequest, recsen::Message>(recsen::Message message);
    
    template<> SymbolRequest cast<SymbolRequest, UnsubscribeSymbolRequest>(UnsubscribeSymbolRequest message);
    template<> UnsubscribeSymbolRequest cast<UnsubscribeSymbolRequest, SymbolRequest>(SymbolRequest message);
    template<> recsen::Message cast<recsen::Message, UnsubscribeSymbolRequest>(UnsubscribeSymbolRequest message);
    template<> UnsubscribeSymbolRequest cast<UnsubscribeSymbolRequest, recsen::Message>(recsen::Message message);
    
    class UnsubscribeSymbolRequestConst
    {
    public:
        
        UnsubscribeSymbolRequestConst(const MessageInfo* info, const MessageData* data);
        UnsubscribeSymbolRequestConst(const UnsubscribeSymbolRequestConst& message);
        
        ~UnsubscribeSymbolRequestConst();
        
        UnsubscribeSymbolRequestConst& operator=(const UnsubscribeSymbolRequestConst& message);
        
        std::string getSymbol() const;
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        const MessageData* data_;
    };
    
    template<> bool is<UnsubscribeSymbolRequestConst, SymbolRequestConst>(SymbolRequestConst message);
    template<> bool is<UnsubscribeSymbolRequestConst, recsen::MessageConst>(recsen::MessageConst message);
    
    template<> SymbolRequestConst cast<SymbolRequestConst, UnsubscribeSymbolRequestConst>(UnsubscribeSymbolRequestConst message);
    template<> UnsubscribeSymbolRequestConst cast<UnsubscribeSymbolRequestConst, SymbolRequestConst>(SymbolRequestConst message);
    template<> recsen::MessageConst cast<recsen::MessageConst, UnsubscribeSymbolRequestConst>(UnsubscribeSymbolRequestConst message);
    template<> UnsubscribeSymbolRequestConst cast<UnsubscribeSymbolRequestConst, recsen::MessageConst>(recsen::MessageConst message);
    template<> UnsubscribeSymbolRequestConst cast<UnsubscribeSymbolRequestConst, UnsubscribeSymbolRequest>(UnsubscribeSymbolRequest message);
    
    class UnsubscribeSymbolAccept
    {
    public:
        
        UnsubscribeSymbolAccept(const MessageInfo* info, MessageData* data);
        UnsubscribeSymbolAccept(const UnsubscribeSymbolAccept& message);
        
        ~UnsubscribeSymbolAccept();
        
        UnsubscribeSymbolAccept& operator=(const UnsubscribeSymbolAccept& message);
        
        void setSymbol(const std::string& value);
        
        std::string getSymbol() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    template<> UnsubscribeSymbolAccept create<UnsubscribeSymbolAccept>();
    
    template<> bool is<UnsubscribeSymbolAccept, SymbolResponse>(SymbolResponse message);
    template<> bool is<UnsubscribeSymbolAccept, recsen::Message>(recsen::Message message);
    
    template<> SymbolResponse cast<SymbolResponse, UnsubscribeSymbolAccept>(UnsubscribeSymbolAccept message);
    template<> UnsubscribeSymbolAccept cast<UnsubscribeSymbolAccept, SymbolResponse>(SymbolResponse message);
    template<> recsen::Message cast<recsen::Message, UnsubscribeSymbolAccept>(UnsubscribeSymbolAccept message);
    template<> UnsubscribeSymbolAccept cast<UnsubscribeSymbolAccept, recsen::Message>(recsen::Message message);
    
    class UnsubscribeSymbolAcceptConst
    {
    public:
        
        UnsubscribeSymbolAcceptConst(const MessageInfo* info, const MessageData* data);
        UnsubscribeSymbolAcceptConst(const UnsubscribeSymbolAcceptConst& message);
        
        ~UnsubscribeSymbolAcceptConst();
        
        UnsubscribeSymbolAcceptConst& operator=(const UnsubscribeSymbolAcceptConst& message);
        
        std::string getSymbol() const;
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        const MessageData* data_;
    };
    
    template<> bool is<UnsubscribeSymbolAcceptConst, SymbolResponseConst>(SymbolResponseConst message);
    template<> bool is<UnsubscribeSymbolAcceptConst, recsen::MessageConst>(recsen::MessageConst message);
    
    template<> SymbolResponseConst cast<SymbolResponseConst, UnsubscribeSymbolAcceptConst>(UnsubscribeSymbolAcceptConst message);
    template<> UnsubscribeSymbolAcceptConst cast<UnsubscribeSymbolAcceptConst, SymbolResponseConst>(SymbolResponseConst message);
    template<> recsen::MessageConst cast<recsen::MessageConst, UnsubscribeSymbolAcceptConst>(UnsubscribeSymbolAcceptConst message);
    template<> UnsubscribeSymbolAcceptConst cast<UnsubscribeSymbolAcceptConst, recsen::MessageConst>(recsen::MessageConst message);
    template<> UnsubscribeSymbolAcceptConst cast<UnsubscribeSymbolAcceptConst, UnsubscribeSymbolAccept>(UnsubscribeSymbolAccept message);
    
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
    
    template<> bool is<SnapshotRefresh, SymbolResponse>(SymbolResponse message);
    template<> bool is<SnapshotRefresh, recsen::Message>(recsen::Message message);
    
    template<> SymbolResponse cast<SymbolResponse, SnapshotRefresh>(SnapshotRefresh message);
    template<> SnapshotRefresh cast<SnapshotRefresh, SymbolResponse>(SymbolResponse message);
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
    
    template<> bool is<SnapshotRefreshConst, SymbolResponseConst>(SymbolResponseConst message);
    template<> bool is<SnapshotRefreshConst, recsen::MessageConst>(recsen::MessageConst message);
    
    template<> SymbolResponseConst cast<SymbolResponseConst, SnapshotRefreshConst>(SnapshotRefreshConst message);
    template<> SnapshotRefreshConst cast<SnapshotRefreshConst, SymbolResponseConst>(SymbolResponseConst message);
    template<> recsen::MessageConst cast<recsen::MessageConst, SnapshotRefreshConst>(SnapshotRefreshConst message);
    template<> SnapshotRefreshConst cast<SnapshotRefreshConst, recsen::MessageConst>(recsen::MessageConst message);
    template<> SnapshotRefreshConst cast<SnapshotRefreshConst, SnapshotRefresh>(SnapshotRefresh message);
    
    class NewsRequest
    {
    public:
        
        NewsRequest(const MessageInfo* info, MessageData* data);
        NewsRequest(const NewsRequest& message);
        
        ~NewsRequest();
        
        NewsRequest& operator=(const NewsRequest& message);
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    template<> NewsRequest create<NewsRequest>();
    
    template<> bool is<NewsRequest, recsen::Message>(recsen::Message message);
    
    template<> recsen::Message cast<recsen::Message, NewsRequest>(NewsRequest message);
    template<> NewsRequest cast<NewsRequest, recsen::Message>(recsen::Message message);
    
    class NewsRequestConst
    {
    public:
        
        NewsRequestConst(const MessageInfo* info, const MessageData* data);
        NewsRequestConst(const NewsRequestConst& message);
        
        ~NewsRequestConst();
        
        NewsRequestConst& operator=(const NewsRequestConst& message);
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        const MessageData* data_;
    };
    
    template<> bool is<NewsRequestConst, recsen::MessageConst>(recsen::MessageConst message);
    
    template<> recsen::MessageConst cast<recsen::MessageConst, NewsRequestConst>(NewsRequestConst message);
    template<> NewsRequestConst cast<NewsRequestConst, recsen::MessageConst>(recsen::MessageConst message);
    template<> NewsRequestConst cast<NewsRequestConst, NewsRequest>(NewsRequest message);
    
    class NewsResponse
    {
    public:
        
        NewsResponse(const MessageInfo* info, MessageData* data);
        NewsResponse(const NewsResponse& message);
        
        ~NewsResponse();
        
        NewsResponse& operator=(const NewsResponse& message);
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    template<> NewsResponse create<NewsResponse>();
    
    template<> bool is<NewsResponse, recsen::Message>(recsen::Message message);
    
    template<> recsen::Message cast<recsen::Message, NewsResponse>(NewsResponse message);
    template<> NewsResponse cast<NewsResponse, recsen::Message>(recsen::Message message);
    
    class NewsResponseConst
    {
    public:
        
        NewsResponseConst(const MessageInfo* info, const MessageData* data);
        NewsResponseConst(const NewsResponseConst& message);
        
        ~NewsResponseConst();
        
        NewsResponseConst& operator=(const NewsResponseConst& message);
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        const MessageData* data_;
    };
    
    template<> bool is<NewsResponseConst, recsen::MessageConst>(recsen::MessageConst message);
    
    template<> recsen::MessageConst cast<recsen::MessageConst, NewsResponseConst>(NewsResponseConst message);
    template<> NewsResponseConst cast<NewsResponseConst, recsen::MessageConst>(recsen::MessageConst message);
    template<> NewsResponseConst cast<NewsResponseConst, NewsResponse>(NewsResponse message);
    
    class SubscribeNewsRequest
    {
    public:
        
        SubscribeNewsRequest(const MessageInfo* info, MessageData* data);
        SubscribeNewsRequest(const SubscribeNewsRequest& message);
        
        ~SubscribeNewsRequest();
        
        SubscribeNewsRequest& operator=(const SubscribeNewsRequest& message);
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    template<> SubscribeNewsRequest create<SubscribeNewsRequest>();
    
    template<> bool is<SubscribeNewsRequest, NewsRequest>(NewsRequest message);
    template<> bool is<SubscribeNewsRequest, recsen::Message>(recsen::Message message);
    
    template<> NewsRequest cast<NewsRequest, SubscribeNewsRequest>(SubscribeNewsRequest message);
    template<> SubscribeNewsRequest cast<SubscribeNewsRequest, NewsRequest>(NewsRequest message);
    template<> recsen::Message cast<recsen::Message, SubscribeNewsRequest>(SubscribeNewsRequest message);
    template<> SubscribeNewsRequest cast<SubscribeNewsRequest, recsen::Message>(recsen::Message message);
    
    class SubscribeNewsRequestConst
    {
    public:
        
        SubscribeNewsRequestConst(const MessageInfo* info, const MessageData* data);
        SubscribeNewsRequestConst(const SubscribeNewsRequestConst& message);
        
        ~SubscribeNewsRequestConst();
        
        SubscribeNewsRequestConst& operator=(const SubscribeNewsRequestConst& message);
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        const MessageData* data_;
    };
    
    template<> bool is<SubscribeNewsRequestConst, NewsRequestConst>(NewsRequestConst message);
    template<> bool is<SubscribeNewsRequestConst, recsen::MessageConst>(recsen::MessageConst message);
    
    template<> NewsRequestConst cast<NewsRequestConst, SubscribeNewsRequestConst>(SubscribeNewsRequestConst message);
    template<> SubscribeNewsRequestConst cast<SubscribeNewsRequestConst, NewsRequestConst>(NewsRequestConst message);
    template<> recsen::MessageConst cast<recsen::MessageConst, SubscribeNewsRequestConst>(SubscribeNewsRequestConst message);
    template<> SubscribeNewsRequestConst cast<SubscribeNewsRequestConst, recsen::MessageConst>(recsen::MessageConst message);
    template<> SubscribeNewsRequestConst cast<SubscribeNewsRequestConst, SubscribeNewsRequest>(SubscribeNewsRequest message);
    
    class SubscribeNewsAccept
    {
    public:
        
        SubscribeNewsAccept(const MessageInfo* info, MessageData* data);
        SubscribeNewsAccept(const SubscribeNewsAccept& message);
        
        ~SubscribeNewsAccept();
        
        SubscribeNewsAccept& operator=(const SubscribeNewsAccept& message);
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    template<> SubscribeNewsAccept create<SubscribeNewsAccept>();
    
    template<> bool is<SubscribeNewsAccept, NewsResponse>(NewsResponse message);
    template<> bool is<SubscribeNewsAccept, recsen::Message>(recsen::Message message);
    
    template<> NewsResponse cast<NewsResponse, SubscribeNewsAccept>(SubscribeNewsAccept message);
    template<> SubscribeNewsAccept cast<SubscribeNewsAccept, NewsResponse>(NewsResponse message);
    template<> recsen::Message cast<recsen::Message, SubscribeNewsAccept>(SubscribeNewsAccept message);
    template<> SubscribeNewsAccept cast<SubscribeNewsAccept, recsen::Message>(recsen::Message message);
    
    class SubscribeNewsAcceptConst
    {
    public:
        
        SubscribeNewsAcceptConst(const MessageInfo* info, const MessageData* data);
        SubscribeNewsAcceptConst(const SubscribeNewsAcceptConst& message);
        
        ~SubscribeNewsAcceptConst();
        
        SubscribeNewsAcceptConst& operator=(const SubscribeNewsAcceptConst& message);
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        const MessageData* data_;
    };
    
    template<> bool is<SubscribeNewsAcceptConst, NewsResponseConst>(NewsResponseConst message);
    template<> bool is<SubscribeNewsAcceptConst, recsen::MessageConst>(recsen::MessageConst message);
    
    template<> NewsResponseConst cast<NewsResponseConst, SubscribeNewsAcceptConst>(SubscribeNewsAcceptConst message);
    template<> SubscribeNewsAcceptConst cast<SubscribeNewsAcceptConst, NewsResponseConst>(NewsResponseConst message);
    template<> recsen::MessageConst cast<recsen::MessageConst, SubscribeNewsAcceptConst>(SubscribeNewsAcceptConst message);
    template<> SubscribeNewsAcceptConst cast<SubscribeNewsAcceptConst, recsen::MessageConst>(recsen::MessageConst message);
    template<> SubscribeNewsAcceptConst cast<SubscribeNewsAcceptConst, SubscribeNewsAccept>(SubscribeNewsAccept message);
    
    class SubscribeNewsReject
    {
    public:
        
        SubscribeNewsReject(const MessageInfo* info, MessageData* data);
        SubscribeNewsReject(const SubscribeNewsReject& message);
        
        ~SubscribeNewsReject();
        
        SubscribeNewsReject& operator=(const SubscribeNewsReject& message);
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    template<> SubscribeNewsReject create<SubscribeNewsReject>();
    
    template<> bool is<SubscribeNewsReject, NewsResponse>(NewsResponse message);
    template<> bool is<SubscribeNewsReject, recsen::Message>(recsen::Message message);
    
    template<> NewsResponse cast<NewsResponse, SubscribeNewsReject>(SubscribeNewsReject message);
    template<> SubscribeNewsReject cast<SubscribeNewsReject, NewsResponse>(NewsResponse message);
    template<> recsen::Message cast<recsen::Message, SubscribeNewsReject>(SubscribeNewsReject message);
    template<> SubscribeNewsReject cast<SubscribeNewsReject, recsen::Message>(recsen::Message message);
    
    class SubscribeNewsRejectConst
    {
    public:
        
        SubscribeNewsRejectConst(const MessageInfo* info, const MessageData* data);
        SubscribeNewsRejectConst(const SubscribeNewsRejectConst& message);
        
        ~SubscribeNewsRejectConst();
        
        SubscribeNewsRejectConst& operator=(const SubscribeNewsRejectConst& message);
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        const MessageData* data_;
    };
    
    template<> bool is<SubscribeNewsRejectConst, NewsResponseConst>(NewsResponseConst message);
    template<> bool is<SubscribeNewsRejectConst, recsen::MessageConst>(recsen::MessageConst message);
    
    template<> NewsResponseConst cast<NewsResponseConst, SubscribeNewsRejectConst>(SubscribeNewsRejectConst message);
    template<> SubscribeNewsRejectConst cast<SubscribeNewsRejectConst, NewsResponseConst>(NewsResponseConst message);
    template<> recsen::MessageConst cast<recsen::MessageConst, SubscribeNewsRejectConst>(SubscribeNewsRejectConst message);
    template<> SubscribeNewsRejectConst cast<SubscribeNewsRejectConst, recsen::MessageConst>(recsen::MessageConst message);
    template<> SubscribeNewsRejectConst cast<SubscribeNewsRejectConst, SubscribeNewsReject>(SubscribeNewsReject message);
    
    class UnsubscribeNewsRequest
    {
    public:
        
        UnsubscribeNewsRequest(const MessageInfo* info, MessageData* data);
        UnsubscribeNewsRequest(const UnsubscribeNewsRequest& message);
        
        ~UnsubscribeNewsRequest();
        
        UnsubscribeNewsRequest& operator=(const UnsubscribeNewsRequest& message);
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    template<> UnsubscribeNewsRequest create<UnsubscribeNewsRequest>();
    
    template<> bool is<UnsubscribeNewsRequest, NewsRequest>(NewsRequest message);
    template<> bool is<UnsubscribeNewsRequest, recsen::Message>(recsen::Message message);
    
    template<> NewsRequest cast<NewsRequest, UnsubscribeNewsRequest>(UnsubscribeNewsRequest message);
    template<> UnsubscribeNewsRequest cast<UnsubscribeNewsRequest, NewsRequest>(NewsRequest message);
    template<> recsen::Message cast<recsen::Message, UnsubscribeNewsRequest>(UnsubscribeNewsRequest message);
    template<> UnsubscribeNewsRequest cast<UnsubscribeNewsRequest, recsen::Message>(recsen::Message message);
    
    class UnsubscribeNewsRequestConst
    {
    public:
        
        UnsubscribeNewsRequestConst(const MessageInfo* info, const MessageData* data);
        UnsubscribeNewsRequestConst(const UnsubscribeNewsRequestConst& message);
        
        ~UnsubscribeNewsRequestConst();
        
        UnsubscribeNewsRequestConst& operator=(const UnsubscribeNewsRequestConst& message);
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        const MessageData* data_;
    };
    
    template<> bool is<UnsubscribeNewsRequestConst, NewsRequestConst>(NewsRequestConst message);
    template<> bool is<UnsubscribeNewsRequestConst, recsen::MessageConst>(recsen::MessageConst message);
    
    template<> NewsRequestConst cast<NewsRequestConst, UnsubscribeNewsRequestConst>(UnsubscribeNewsRequestConst message);
    template<> UnsubscribeNewsRequestConst cast<UnsubscribeNewsRequestConst, NewsRequestConst>(NewsRequestConst message);
    template<> recsen::MessageConst cast<recsen::MessageConst, UnsubscribeNewsRequestConst>(UnsubscribeNewsRequestConst message);
    template<> UnsubscribeNewsRequestConst cast<UnsubscribeNewsRequestConst, recsen::MessageConst>(recsen::MessageConst message);
    template<> UnsubscribeNewsRequestConst cast<UnsubscribeNewsRequestConst, UnsubscribeNewsRequest>(UnsubscribeNewsRequest message);
    
    class UnsubscribeNewsAccept
    {
    public:
        
        UnsubscribeNewsAccept(const MessageInfo* info, MessageData* data);
        UnsubscribeNewsAccept(const UnsubscribeNewsAccept& message);
        
        ~UnsubscribeNewsAccept();
        
        UnsubscribeNewsAccept& operator=(const UnsubscribeNewsAccept& message);
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    template<> UnsubscribeNewsAccept create<UnsubscribeNewsAccept>();
    
    template<> bool is<UnsubscribeNewsAccept, NewsResponse>(NewsResponse message);
    template<> bool is<UnsubscribeNewsAccept, recsen::Message>(recsen::Message message);
    
    template<> NewsResponse cast<NewsResponse, UnsubscribeNewsAccept>(UnsubscribeNewsAccept message);
    template<> UnsubscribeNewsAccept cast<UnsubscribeNewsAccept, NewsResponse>(NewsResponse message);
    template<> recsen::Message cast<recsen::Message, UnsubscribeNewsAccept>(UnsubscribeNewsAccept message);
    template<> UnsubscribeNewsAccept cast<UnsubscribeNewsAccept, recsen::Message>(recsen::Message message);
    
    class UnsubscribeNewsAcceptConst
    {
    public:
        
        UnsubscribeNewsAcceptConst(const MessageInfo* info, const MessageData* data);
        UnsubscribeNewsAcceptConst(const UnsubscribeNewsAcceptConst& message);
        
        ~UnsubscribeNewsAcceptConst();
        
        UnsubscribeNewsAcceptConst& operator=(const UnsubscribeNewsAcceptConst& message);
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        const MessageData* data_;
    };
    
    template<> bool is<UnsubscribeNewsAcceptConst, NewsResponseConst>(NewsResponseConst message);
    template<> bool is<UnsubscribeNewsAcceptConst, recsen::MessageConst>(recsen::MessageConst message);
    
    template<> NewsResponseConst cast<NewsResponseConst, UnsubscribeNewsAcceptConst>(UnsubscribeNewsAcceptConst message);
    template<> UnsubscribeNewsAcceptConst cast<UnsubscribeNewsAcceptConst, NewsResponseConst>(NewsResponseConst message);
    template<> recsen::MessageConst cast<recsen::MessageConst, UnsubscribeNewsAcceptConst>(UnsubscribeNewsAcceptConst message);
    template<> UnsubscribeNewsAcceptConst cast<UnsubscribeNewsAcceptConst, recsen::MessageConst>(recsen::MessageConst message);
    template<> UnsubscribeNewsAcceptConst cast<UnsubscribeNewsAcceptConst, UnsubscribeNewsAccept>(UnsubscribeNewsAccept message);
    
    enum NewsSeverity
    {
        NewsSeverity_Critical = 0,
        NewsSeverity_Warning = 1,
        NewsSeverity_Information = 2,
    };
    
    typedef recsen::array_t<NewsSeverity> NewsSeverityArray;
    typedef recsen::const_array_t<NewsSeverity> NewsSeverityConstArray;
    typedef recsen::array_t<recsen::null_t<NewsSeverity>> NewsSeverityNullArray;
    typedef recsen::const_array_t<recsen::null_t<NewsSeverity>> NewsSeverityNullConstArray;
    
    class NewsNotification
    {
    public:
        
        NewsNotification(const MessageInfo* info, MessageData* data);
        NewsNotification(const NewsNotification& message);
        
        ~NewsNotification();
        
        NewsNotification& operator=(const NewsNotification& message);
        
        void setSeverity(NewsSeverity value);
        
        NewsSeverity getSeverity() const;
        
        void setHeader(const std::string& value);
        
        std::string getHeader() const;
        
        void setText(const std::string& value);
        
        std::string getText() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    template<> NewsNotification create<NewsNotification>();
    
    template<> bool is<NewsNotification, NewsResponse>(NewsResponse message);
    template<> bool is<NewsNotification, recsen::Message>(recsen::Message message);
    
    template<> NewsResponse cast<NewsResponse, NewsNotification>(NewsNotification message);
    template<> NewsNotification cast<NewsNotification, NewsResponse>(NewsResponse message);
    template<> recsen::Message cast<recsen::Message, NewsNotification>(NewsNotification message);
    template<> NewsNotification cast<NewsNotification, recsen::Message>(recsen::Message message);
    
    class NewsNotificationConst
    {
    public:
        
        NewsNotificationConst(const MessageInfo* info, const MessageData* data);
        NewsNotificationConst(const NewsNotificationConst& message);
        
        ~NewsNotificationConst();
        
        NewsNotificationConst& operator=(const NewsNotificationConst& message);
        
        NewsSeverity getSeverity() const;
        
        std::string getHeader() const;
        
        std::string getText() const;
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        const MessageData* data_;
    };
    
    template<> bool is<NewsNotificationConst, NewsResponseConst>(NewsResponseConst message);
    template<> bool is<NewsNotificationConst, recsen::MessageConst>(recsen::MessageConst message);
    
    template<> NewsResponseConst cast<NewsResponseConst, NewsNotificationConst>(NewsNotificationConst message);
    template<> NewsNotificationConst cast<NewsNotificationConst, NewsResponseConst>(NewsResponseConst message);
    template<> recsen::MessageConst cast<recsen::MessageConst, NewsNotificationConst>(NewsNotificationConst message);
    template<> NewsNotificationConst cast<NewsNotificationConst, recsen::MessageConst>(recsen::MessageConst message);
    template<> NewsNotificationConst cast<NewsNotificationConst, NewsNotification>(NewsNotification message);
    
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
        
        void loginPublic(loginPublicClientContext* context, LoginPublicRequest message);
        
        void loginPrivate(loginPrivateClientContext* context, LoginPrivateRequest message);
        
        void Logout(LogoutClientContext* context, Logout message);
        
        void subscribeSymbol(subscribeSymbolClientContext* context, SubscribeSymbolRequest message);
        
        void unsubscribeSymbol(unsubscribeSymbolClientContext* context, UnsubscribeSymbolRequest message);
        
        void subscribeNews(subscribeNewsClientContext* context, SubscribeNewsRequest message);
        
        void unsubscribeNews(unsubscribeNewsClientContext* context, UnsubscribeNewsRequest message);
        
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
        
        void virtual onSubscribeSymbolAccept(ClientSession* session, subscribeSymbolClientContext* context, SubscribeSymbolAcceptConst message);
        
        void virtual onSubscribeSymbolReject(ClientSession* session, subscribeSymbolClientContext* context, SubscribeSymbolRejectConst message);
        
        void virtual onSnapshot(ClientSession* session, SnapshotRefreshConst message);
        
        void virtual onSubscribeNewsAccept(ClientSession* session, subscribeNewsClientContext* context, SubscribeNewsAcceptConst message);
        
        void virtual onSubscribeNewsReject(ClientSession* session, subscribeNewsClientContext* context, SubscribeNewsRejectConst message);
        
        void virtual onNews(ClientSession* session, NewsNotificationConst message);
        
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
        
        void virtual onSubscribeSymbol(ServerSession* session, SubscribeSymbolRequestConst message);
        
        void virtual onUnsubscribeSymbol(ServerSession* session, UnsubscribeSymbolRequestConst message);
        
        void virtual onSubscribeNews(ServerSession* session, SubscribeNewsRequestConst message);
        
        void virtual onUnsubscribeNews(ServerSession* session, UnsubscribeNewsRequestConst message);
        
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
