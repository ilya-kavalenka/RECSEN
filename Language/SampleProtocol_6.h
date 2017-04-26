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
    
    template<typename MESSAGE1, typename MESSAGE2> bool is(MESSAGE2 message);
    template<typename MESSAGE1, typename MESSAGE2> MESSAGE1 cast(MESSAGE2 message);
    
    class LoginPublicRequest;
    class LoginPublicRequestRef;
    class LoginPublicRequestConstRef;
    
    class LoginPublicRequest
    {
    public:
        
        LoginPublicRequest();
        LoginPublicRequest(const LoginPublicRequestRef& message);
        LoginPublicRequest(const LoginPublicRequestConstRef& message);
        LoginPublicRequest(const LoginPublicRequest& message);
        
        ~LoginPublicRequest();
        
        void setName(const std::string& value);
        
        std::string getName() const;
        
        LoginPublicRequest& operator=(const LoginPublicRequestRef& message);
        LoginPublicRequest& operator=(const LoginPublicRequestConstRef& message);
        LoginPublicRequest& operator=(const LoginPublicRequest& message);
        
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    class LoginPublicRequestRef
    {
    public:
        
        LoginPublicRequestRef(const MessageInfo* info, MessageData* data);
        LoginPublicRequestRef(const LoginPublicRequest& message);
        LoginPublicRequestRef(const LoginPublicRequestConstRef& message);
        LoginPublicRequestRef(const LoginPublicRequestRef& message);
        
        void setName(const std::string& value);
        
        std::string getName() const;
        
        LoginPublicRequestRef& operator=(const LoginPublicRequest& message);
        LoginPublicRequestRef& operator=(const LoginPublicRequestConstRef& message);
        LoginPublicRequestRef& operator=(const LoginPublicRequestRef& message);
        
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    class LoginPublicRequestConstRef
    {
    public:
        
        LoginPublicRequestConstRef(const MessageInfo* info, const MessageData* data);
        LoginPublicRequestConstRef(const LoginPublicRequest& message);
        LoginPublicRequestConstRef(const LoginPublicRequestRef& message);
        LoginPublicRequestConstRef(const LoginPublicRequestConstRef& message);
        
        std::string getName() const;
        
        operator recsen::MessageConstRef() const;
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        const MessageData* data_;
    };
    
    template<> bool is<LoginPublicRequestRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> bool is<LoginPublicRequestConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    template<> LoginPublicRequestRef cast<LoginPublicRequestRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> LoginPublicRequestConstRef cast<LoginPublicRequestConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    class LoginPrivateRequest;
    class LoginPrivateRequestRef;
    class LoginPrivateRequestConstRef;
    
    class LoginPrivateRequest
    {
    public:
        
        LoginPrivateRequest();
        LoginPrivateRequest(const LoginPrivateRequestRef& message);
        LoginPrivateRequest(const LoginPrivateRequestConstRef& message);
        LoginPrivateRequest(const LoginPrivateRequest& message);
        
        ~LoginPrivateRequest();
        
        void setName(const std::string& value);
        
        std::string getName() const;
        
        LoginPrivateRequest& operator=(const LoginPrivateRequestRef& message);
        LoginPrivateRequest& operator=(const LoginPrivateRequestConstRef& message);
        LoginPrivateRequest& operator=(const LoginPrivateRequest& message);
        
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    class LoginPrivateRequestRef
    {
    public:
        
        LoginPrivateRequestRef(const MessageInfo* info, MessageData* data);
        LoginPrivateRequestRef(const LoginPrivateRequest& message);
        LoginPrivateRequestRef(const LoginPrivateRequestConstRef& message);
        LoginPrivateRequestRef(const LoginPrivateRequestRef& message);
        
        void setName(const std::string& value);
        
        std::string getName() const;
        
        LoginPrivateRequestRef& operator=(const LoginPrivateRequest& message);
        LoginPrivateRequestRef& operator=(const LoginPrivateRequestConstRef& message);
        LoginPrivateRequestRef& operator=(const LoginPrivateRequestRef& message);
        
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    class LoginPrivateRequestConstRef
    {
    public:
        
        LoginPrivateRequestConstRef(const MessageInfo* info, const MessageData* data);
        LoginPrivateRequestConstRef(const LoginPrivateRequest& message);
        LoginPrivateRequestConstRef(const LoginPrivateRequestRef& message);
        LoginPrivateRequestConstRef(const LoginPrivateRequestConstRef& message);
        
        std::string getName() const;
        
        operator recsen::MessageConstRef() const;
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        const MessageData* data_;
    };
    
    template<> bool is<LoginPrivateRequestRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> bool is<LoginPrivateRequestConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    template<> LoginPrivateRequestRef cast<LoginPrivateRequestRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> LoginPrivateRequestConstRef cast<LoginPrivateRequestConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    class PasswordRequest;
    class PasswordRequestRef;
    class PasswordRequestConstRef;
    
    class PasswordRequest
    {
    public:
        
        PasswordRequest();
        PasswordRequest(const PasswordRequestRef& message);
        PasswordRequest(const PasswordRequestConstRef& message);
        PasswordRequest(const PasswordRequest& message);
        
        ~PasswordRequest();
        
        void setToken(const recsen::bytes_t& value);
        
        recsen::bytes_t getToken() const;
        
        PasswordRequest& operator=(const PasswordRequestRef& message);
        PasswordRequest& operator=(const PasswordRequestConstRef& message);
        PasswordRequest& operator=(const PasswordRequest& message);
        
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    class PasswordRequestRef
    {
    public:
        
        PasswordRequestRef(const MessageInfo* info, MessageData* data);
        PasswordRequestRef(const PasswordRequest& message);
        PasswordRequestRef(const PasswordRequestConstRef& message);
        PasswordRequestRef(const PasswordRequestRef& message);
        
        void setToken(const recsen::bytes_t& value);
        
        recsen::bytes_t getToken() const;
        
        PasswordRequestRef& operator=(const PasswordRequest& message);
        PasswordRequestRef& operator=(const PasswordRequestConstRef& message);
        PasswordRequestRef& operator=(const PasswordRequestRef& message);
        
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    class PasswordRequestConstRef
    {
    public:
        
        PasswordRequestConstRef(const MessageInfo* info, const MessageData* data);
        PasswordRequestConstRef(const PasswordRequest& message);
        PasswordRequestConstRef(const PasswordRequestRef& message);
        PasswordRequestConstRef(const PasswordRequestConstRef& message);
        
        recsen::bytes_t getToken() const;
        
        operator recsen::MessageConstRef() const;
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        const MessageData* data_;
    };
    
    template<> bool is<PasswordRequestRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> bool is<PasswordRequestConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    template<> PasswordRequestRef cast<PasswordRequestRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> PasswordRequestConstRef cast<PasswordRequestConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    class PasswordResponse;
    class PasswordResponseRef;
    class PasswordResponseConstRef;
    
    class PasswordResponse
    {
    public:
        
        PasswordResponse();
        PasswordResponse(const PasswordResponseRef& message);
        PasswordResponse(const PasswordResponseConstRef& message);
        PasswordResponse(const PasswordResponse& message);
        
        ~PasswordResponse();
        
        void setEncodedToken(const recsen::bytes_t& value);
        
        recsen::bytes_t getEncodedToken() const;
        
        PasswordResponse& operator=(const PasswordResponseRef& message);
        PasswordResponse& operator=(const PasswordResponseConstRef& message);
        PasswordResponse& operator=(const PasswordResponse& message);
        
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    class PasswordResponseRef
    {
    public:
        
        PasswordResponseRef(const MessageInfo* info, MessageData* data);
        PasswordResponseRef(const PasswordResponse& message);
        PasswordResponseRef(const PasswordResponseConstRef& message);
        PasswordResponseRef(const PasswordResponseRef& message);
        
        void setEncodedToken(const recsen::bytes_t& value);
        
        recsen::bytes_t getEncodedToken() const;
        
        PasswordResponseRef& operator=(const PasswordResponse& message);
        PasswordResponseRef& operator=(const PasswordResponseConstRef& message);
        PasswordResponseRef& operator=(const PasswordResponseRef& message);
        
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    class PasswordResponseConstRef
    {
    public:
        
        PasswordResponseConstRef(const MessageInfo* info, const MessageData* data);
        PasswordResponseConstRef(const PasswordResponse& message);
        PasswordResponseConstRef(const PasswordResponseRef& message);
        PasswordResponseConstRef(const PasswordResponseConstRef& message);
        
        recsen::bytes_t getEncodedToken() const;
        
        operator recsen::MessageConstRef() const;
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        const MessageData* data_;
    };
    
    template<> bool is<PasswordResponseRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> bool is<PasswordResponseConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    template<> PasswordResponseRef cast<PasswordResponseRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> PasswordResponseConstRef cast<PasswordResponseConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    class LoginAccept;
    class LoginAcceptRef;
    class LoginAcceptConstRef;
    
    class LoginAccept
    {
    public:
        
        LoginAccept();
        LoginAccept(const LoginAcceptRef& message);
        LoginAccept(const LoginAcceptConstRef& message);
        LoginAccept(const LoginAccept& message);
        
        ~LoginAccept();
        
        LoginAccept& operator=(const LoginAcceptRef& message);
        LoginAccept& operator=(const LoginAcceptConstRef& message);
        LoginAccept& operator=(const LoginAccept& message);
        
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    class LoginAcceptRef
    {
    public:
        
        LoginAcceptRef(const MessageInfo* info, MessageData* data);
        LoginAcceptRef(const LoginAccept& message);
        LoginAcceptRef(const LoginAcceptConstRef& message);
        LoginAcceptRef(const LoginAcceptRef& message);
        
        LoginAcceptRef& operator=(const LoginAccept& message);
        LoginAcceptRef& operator=(const LoginAcceptConstRef& message);
        LoginAcceptRef& operator=(const LoginAcceptRef& message);
        
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    class LoginAcceptConstRef
    {
    public:
        
        LoginAcceptConstRef(const MessageInfo* info, const MessageData* data);
        LoginAcceptConstRef(const LoginAccept& message);
        LoginAcceptConstRef(const LoginAcceptRef& message);
        LoginAcceptConstRef(const LoginAcceptConstRef& message);
        
        operator recsen::MessageConstRef() const;
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        const MessageData* data_;
    };
    
    template<> bool is<LoginAcceptRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> bool is<LoginAcceptConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    template<> LoginAcceptRef cast<LoginAcceptRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> LoginAcceptConstRef cast<LoginAcceptConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    class LoginReject;
    class LoginRejectRef;
    class LoginRejectConstRef;
    
    class LoginReject
    {
    public:
        
        LoginReject();
        LoginReject(const LoginRejectRef& message);
        LoginReject(const LoginRejectConstRef& message);
        LoginReject(const LoginReject& message);
        
        ~LoginReject();
        
        void setText(const std::string& value);
        
        std::string getText() const;
        
        LoginReject& operator=(const LoginRejectRef& message);
        LoginReject& operator=(const LoginRejectConstRef& message);
        LoginReject& operator=(const LoginReject& message);
        
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    class LoginRejectRef
    {
    public:
        
        LoginRejectRef(const MessageInfo* info, MessageData* data);
        LoginRejectRef(const LoginReject& message);
        LoginRejectRef(const LoginRejectConstRef& message);
        LoginRejectRef(const LoginRejectRef& message);
        
        void setText(const std::string& value);
        
        std::string getText() const;
        
        LoginRejectRef& operator=(const LoginReject& message);
        LoginRejectRef& operator=(const LoginRejectConstRef& message);
        LoginRejectRef& operator=(const LoginRejectRef& message);
        
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    class LoginRejectConstRef
    {
    public:
        
        LoginRejectConstRef(const MessageInfo* info, const MessageData* data);
        LoginRejectConstRef(const LoginReject& message);
        LoginRejectConstRef(const LoginRejectRef& message);
        LoginRejectConstRef(const LoginRejectConstRef& message);
        
        std::string getText() const;
        
        operator recsen::MessageConstRef() const;
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        const MessageData* data_;
    };
    
    template<> bool is<LoginRejectRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> bool is<LoginRejectConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    template<> LoginRejectRef cast<LoginRejectRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> LoginRejectConstRef cast<LoginRejectConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    class SymbolRequest;
    class SymbolRequestRef;
    class SymbolRequestConstRef;
    
    class SymbolRequest
    {
    public:
        
        SymbolRequest();
        SymbolRequest(const SymbolRequestRef& message);
        SymbolRequest(const SymbolRequestConstRef& message);
        SymbolRequest(const SymbolRequest& message);
        
        ~SymbolRequest();
        
        void setSymbol(const std::string& value);
        
        std::string getSymbol() const;
        
        SymbolRequest& operator=(const SymbolRequestRef& message);
        SymbolRequest& operator=(const SymbolRequestConstRef& message);
        SymbolRequest& operator=(const SymbolRequest& message);
        
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    class SymbolRequestRef
    {
    public:
        
        SymbolRequestRef(const MessageInfo* info, MessageData* data);
        SymbolRequestRef(const SymbolRequest& message);
        SymbolRequestRef(const SymbolRequestConstRef& message);
        SymbolRequestRef(const SymbolRequestRef& message);
        
        void setSymbol(const std::string& value);
        
        std::string getSymbol() const;
        
        SymbolRequestRef& operator=(const SymbolRequest& message);
        SymbolRequestRef& operator=(const SymbolRequestConstRef& message);
        SymbolRequestRef& operator=(const SymbolRequestRef& message);
        
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    class SymbolRequestConstRef
    {
    public:
        
        SymbolRequestConstRef(const MessageInfo* info, const MessageData* data);
        SymbolRequestConstRef(const SymbolRequest& message);
        SymbolRequestConstRef(const SymbolRequestRef& message);
        SymbolRequestConstRef(const SymbolRequestConstRef& message);
        
        std::string getSymbol() const;
        
        operator recsen::MessageConstRef() const;
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        const MessageData* data_;
    };
    
    template<> bool is<SymbolRequestRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> bool is<SymbolRequestConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    template<> SymbolRequestRef cast<SymbolRequestRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> SymbolRequestConstRef cast<SymbolRequestConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    class SymbolResponse;
    class SymbolResponseRef;
    class SymbolResponseConstRef;
    
    class SymbolResponse
    {
    public:
        
        SymbolResponse();
        SymbolResponse(const SymbolResponseRef& message);
        SymbolResponse(const SymbolResponseConstRef& message);
        SymbolResponse(const SymbolResponse& message);
        
        ~SymbolResponse();
        
        void setSymbol(const std::string& value);
        
        std::string getSymbol() const;
        
        SymbolResponse& operator=(const SymbolResponseRef& message);
        SymbolResponse& operator=(const SymbolResponseConstRef& message);
        SymbolResponse& operator=(const SymbolResponse& message);
        
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    class SymbolResponseRef
    {
    public:
        
        SymbolResponseRef(const MessageInfo* info, MessageData* data);
        SymbolResponseRef(const SymbolResponse& message);
        SymbolResponseRef(const SymbolResponseConstRef& message);
        SymbolResponseRef(const SymbolResponseRef& message);
        
        void setSymbol(const std::string& value);
        
        std::string getSymbol() const;
        
        SymbolResponseRef& operator=(const SymbolResponse& message);
        SymbolResponseRef& operator=(const SymbolResponseConstRef& message);
        SymbolResponseRef& operator=(const SymbolResponseRef& message);
        
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    class SymbolResponseConstRef
    {
    public:
        
        SymbolResponseConstRef(const MessageInfo* info, const MessageData* data);
        SymbolResponseConstRef(const SymbolResponse& message);
        SymbolResponseConstRef(const SymbolResponseRef& message);
        SymbolResponseConstRef(const SymbolResponseConstRef& message);
        
        std::string getSymbol() const;
        
        operator recsen::MessageConstRef() const;
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        const MessageData* data_;
    };
    
    template<> bool is<SymbolResponseRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> bool is<SymbolResponseConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    template<> SymbolResponseRef cast<SymbolResponseRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> SymbolResponseConstRef cast<SymbolResponseConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    class SubscribeSymbolRequest;
    class SubscribeSymbolRequestRef;
    class SubscribeSymbolRequestConstRef;
    
    class SubscribeSymbolRequest
    {
    public:
        
        SubscribeSymbolRequest();
        SubscribeSymbolRequest(const SubscribeSymbolRequestRef& message);
        SubscribeSymbolRequest(const SubscribeSymbolRequestConstRef& message);
        SubscribeSymbolRequest(const SubscribeSymbolRequest& message);
        
        ~SubscribeSymbolRequest();
        
        void setSymbol(const std::string& value);
        
        std::string getSymbol() const;
        
        SubscribeSymbolRequest& operator=(const SubscribeSymbolRequestRef& message);
        SubscribeSymbolRequest& operator=(const SubscribeSymbolRequestConstRef& message);
        SubscribeSymbolRequest& operator=(const SubscribeSymbolRequest& message);
        
        operator SymbolRequestRef();
        operator SymbolRequestConstRef() const;
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    class SubscribeSymbolRequestRef
    {
    public:
        
        SubscribeSymbolRequestRef(const MessageInfo* info, MessageData* data);
        SubscribeSymbolRequestRef(const SubscribeSymbolRequest& message);
        SubscribeSymbolRequestRef(const SubscribeSymbolRequestConstRef& message);
        SubscribeSymbolRequestRef(const SubscribeSymbolRequestRef& message);
        
        void setSymbol(const std::string& value);
        
        std::string getSymbol() const;
        
        SubscribeSymbolRequestRef& operator=(const SubscribeSymbolRequest& message);
        SubscribeSymbolRequestRef& operator=(const SubscribeSymbolRequestConstRef& message);
        SubscribeSymbolRequestRef& operator=(const SubscribeSymbolRequestRef& message);
        
        operator SymbolRequestRef();
        operator SymbolRequestConstRef() const;
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    class SubscribeSymbolRequestConstRef
    {
    public:
        
        SubscribeSymbolRequestConstRef(const MessageInfo* info, const MessageData* data);
        SubscribeSymbolRequestConstRef(const SubscribeSymbolRequest& message);
        SubscribeSymbolRequestConstRef(const SubscribeSymbolRequestRef& message);
        SubscribeSymbolRequestConstRef(const SubscribeSymbolRequestConstRef& message);
        
        std::string getSymbol() const;
        
        operator SymbolRequestConstRef() const;
        operator recsen::MessageConstRef() const;
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        const MessageData* data_;
    };
    
    template<> bool is<SubscribeSymbolRequestRef, SymbolRequestRef>(SymbolRequestRef message);
    template<> bool is<SubscribeSymbolRequestConstRef, SymbolRequestConstRef>(SymbolRequestConstRef message);
    template<> bool is<SubscribeSymbolRequestRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> bool is<SubscribeSymbolRequestConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    template<> SubscribeSymbolRequestRef cast<SubscribeSymbolRequestRef, SymbolRequestRef>(SymbolRequestRef message);
    template<> SubscribeSymbolRequestConstRef cast<SubscribeSymbolRequestConstRef, SymbolRequestConstRef>(SymbolRequestConstRef message);
    template<> SubscribeSymbolRequestRef cast<SubscribeSymbolRequestRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> SubscribeSymbolRequestConstRef cast<SubscribeSymbolRequestConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    class SubscribeSymbolAccept;
    class SubscribeSymbolAcceptRef;
    class SubscribeSymbolAcceptConstRef;
    
    class SubscribeSymbolAccept
    {
    public:
        
        SubscribeSymbolAccept();
        SubscribeSymbolAccept(const SubscribeSymbolAcceptRef& message);
        SubscribeSymbolAccept(const SubscribeSymbolAcceptConstRef& message);
        SubscribeSymbolAccept(const SubscribeSymbolAccept& message);
        
        ~SubscribeSymbolAccept();
        
        void setSymbol(const std::string& value);
        
        std::string getSymbol() const;
        
        SubscribeSymbolAccept& operator=(const SubscribeSymbolAcceptRef& message);
        SubscribeSymbolAccept& operator=(const SubscribeSymbolAcceptConstRef& message);
        SubscribeSymbolAccept& operator=(const SubscribeSymbolAccept& message);
        
        operator SymbolResponseRef();
        operator SymbolResponseConstRef() const;
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    class SubscribeSymbolAcceptRef
    {
    public:
        
        SubscribeSymbolAcceptRef(const MessageInfo* info, MessageData* data);
        SubscribeSymbolAcceptRef(const SubscribeSymbolAccept& message);
        SubscribeSymbolAcceptRef(const SubscribeSymbolAcceptConstRef& message);
        SubscribeSymbolAcceptRef(const SubscribeSymbolAcceptRef& message);
        
        void setSymbol(const std::string& value);
        
        std::string getSymbol() const;
        
        SubscribeSymbolAcceptRef& operator=(const SubscribeSymbolAccept& message);
        SubscribeSymbolAcceptRef& operator=(const SubscribeSymbolAcceptConstRef& message);
        SubscribeSymbolAcceptRef& operator=(const SubscribeSymbolAcceptRef& message);
        
        operator SymbolResponseRef();
        operator SymbolResponseConstRef() const;
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    class SubscribeSymbolAcceptConstRef
    {
    public:
        
        SubscribeSymbolAcceptConstRef(const MessageInfo* info, const MessageData* data);
        SubscribeSymbolAcceptConstRef(const SubscribeSymbolAccept& message);
        SubscribeSymbolAcceptConstRef(const SubscribeSymbolAcceptRef& message);
        SubscribeSymbolAcceptConstRef(const SubscribeSymbolAcceptConstRef& message);
        
        std::string getSymbol() const;
        
        operator SymbolResponseConstRef() const;
        operator recsen::MessageConstRef() const;
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        const MessageData* data_;
    };
    
    template<> bool is<SubscribeSymbolAcceptRef, SymbolResponseRef>(SymbolResponseRef message);
    template<> bool is<SubscribeSymbolAcceptConstRef, SymbolResponseConstRef>(SymbolResponseConstRef message);
    template<> bool is<SubscribeSymbolAcceptRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> bool is<SubscribeSymbolAcceptConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    template<> SubscribeSymbolAcceptRef cast<SubscribeSymbolAcceptRef, SymbolResponseRef>(SymbolResponseRef message);
    template<> SubscribeSymbolAcceptConstRef cast<SubscribeSymbolAcceptConstRef, SymbolResponseConstRef>(SymbolResponseConstRef message);
    template<> SubscribeSymbolAcceptRef cast<SubscribeSymbolAcceptRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> SubscribeSymbolAcceptConstRef cast<SubscribeSymbolAcceptConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    class SubscribeSymbolReject;
    class SubscribeSymbolRejectRef;
    class SubscribeSymbolRejectConstRef;
    
    class SubscribeSymbolReject
    {
    public:
        
        SubscribeSymbolReject();
        SubscribeSymbolReject(const SubscribeSymbolRejectRef& message);
        SubscribeSymbolReject(const SubscribeSymbolRejectConstRef& message);
        SubscribeSymbolReject(const SubscribeSymbolReject& message);
        
        ~SubscribeSymbolReject();
        
        void setSymbol(const std::string& value);
        
        std::string getSymbol() const;
        
        void setText(const std::string& value);
        
        std::string getText() const;
        
        SubscribeSymbolReject& operator=(const SubscribeSymbolRejectRef& message);
        SubscribeSymbolReject& operator=(const SubscribeSymbolRejectConstRef& message);
        SubscribeSymbolReject& operator=(const SubscribeSymbolReject& message);
        
        operator SymbolResponseRef();
        operator SymbolResponseConstRef() const;
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    class SubscribeSymbolRejectRef
    {
    public:
        
        SubscribeSymbolRejectRef(const MessageInfo* info, MessageData* data);
        SubscribeSymbolRejectRef(const SubscribeSymbolReject& message);
        SubscribeSymbolRejectRef(const SubscribeSymbolRejectConstRef& message);
        SubscribeSymbolRejectRef(const SubscribeSymbolRejectRef& message);
        
        void setSymbol(const std::string& value);
        
        std::string getSymbol() const;
        
        void setText(const std::string& value);
        
        std::string getText() const;
        
        SubscribeSymbolRejectRef& operator=(const SubscribeSymbolReject& message);
        SubscribeSymbolRejectRef& operator=(const SubscribeSymbolRejectConstRef& message);
        SubscribeSymbolRejectRef& operator=(const SubscribeSymbolRejectRef& message);
        
        operator SymbolResponseRef();
        operator SymbolResponseConstRef() const;
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    class SubscribeSymbolRejectConstRef
    {
    public:
        
        SubscribeSymbolRejectConstRef(const MessageInfo* info, const MessageData* data);
        SubscribeSymbolRejectConstRef(const SubscribeSymbolReject& message);
        SubscribeSymbolRejectConstRef(const SubscribeSymbolRejectRef& message);
        SubscribeSymbolRejectConstRef(const SubscribeSymbolRejectConstRef& message);
        
        std::string getSymbol() const;
        
        std::string getText() const;
        
        operator SymbolResponseConstRef() const;
        operator recsen::MessageConstRef() const;
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        const MessageData* data_;
    };
    
    template<> bool is<SubscribeSymbolRejectRef, SymbolResponseRef>(SymbolResponseRef message);
    template<> bool is<SubscribeSymbolRejectConstRef, SymbolResponseConstRef>(SymbolResponseConstRef message);
    template<> bool is<SubscribeSymbolRejectRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> bool is<SubscribeSymbolRejectConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    template<> SubscribeSymbolRejectRef cast<SubscribeSymbolRejectRef, SymbolResponseRef>(SymbolResponseRef message);
    template<> SubscribeSymbolRejectConstRef cast<SubscribeSymbolRejectConstRef, SymbolResponseConstRef>(SymbolResponseConstRef message);
    template<> SubscribeSymbolRejectRef cast<SubscribeSymbolRejectRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> SubscribeSymbolRejectConstRef cast<SubscribeSymbolRejectConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    class UnsubscribeSymbolRequest;
    class UnsubscribeSymbolRequestRef;
    class UnsubscribeSymbolRequestConstRef;
    
    class UnsubscribeSymbolRequest
    {
    public:
        
        UnsubscribeSymbolRequest();
        UnsubscribeSymbolRequest(const UnsubscribeSymbolRequestRef& message);
        UnsubscribeSymbolRequest(const UnsubscribeSymbolRequestConstRef& message);
        UnsubscribeSymbolRequest(const UnsubscribeSymbolRequest& message);
        
        ~UnsubscribeSymbolRequest();
        
        void setSymbol(const std::string& value);
        
        std::string getSymbol() const;
        
        UnsubscribeSymbolRequest& operator=(const UnsubscribeSymbolRequestRef& message);
        UnsubscribeSymbolRequest& operator=(const UnsubscribeSymbolRequestConstRef& message);
        UnsubscribeSymbolRequest& operator=(const UnsubscribeSymbolRequest& message);
        
        operator SymbolRequestRef();
        operator SymbolRequestConstRef() const;
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    class UnsubscribeSymbolRequestRef
    {
    public:
        
        UnsubscribeSymbolRequestRef(const MessageInfo* info, MessageData* data);
        UnsubscribeSymbolRequestRef(const UnsubscribeSymbolRequest& message);
        UnsubscribeSymbolRequestRef(const UnsubscribeSymbolRequestConstRef& message);
        UnsubscribeSymbolRequestRef(const UnsubscribeSymbolRequestRef& message);
        
        void setSymbol(const std::string& value);
        
        std::string getSymbol() const;
        
        UnsubscribeSymbolRequestRef& operator=(const UnsubscribeSymbolRequest& message);
        UnsubscribeSymbolRequestRef& operator=(const UnsubscribeSymbolRequestConstRef& message);
        UnsubscribeSymbolRequestRef& operator=(const UnsubscribeSymbolRequestRef& message);
        
        operator SymbolRequestRef();
        operator SymbolRequestConstRef() const;
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    class UnsubscribeSymbolRequestConstRef
    {
    public:
        
        UnsubscribeSymbolRequestConstRef(const MessageInfo* info, const MessageData* data);
        UnsubscribeSymbolRequestConstRef(const UnsubscribeSymbolRequest& message);
        UnsubscribeSymbolRequestConstRef(const UnsubscribeSymbolRequestRef& message);
        UnsubscribeSymbolRequestConstRef(const UnsubscribeSymbolRequestConstRef& message);
        
        std::string getSymbol() const;
        
        operator SymbolRequestConstRef() const;
        operator recsen::MessageConstRef() const;
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        const MessageData* data_;
    };
    
    template<> bool is<UnsubscribeSymbolRequestRef, SymbolRequestRef>(SymbolRequestRef message);
    template<> bool is<UnsubscribeSymbolRequestConstRef, SymbolRequestConstRef>(SymbolRequestConstRef message);
    template<> bool is<UnsubscribeSymbolRequestRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> bool is<UnsubscribeSymbolRequestConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    template<> UnsubscribeSymbolRequestRef cast<UnsubscribeSymbolRequestRef, SymbolRequestRef>(SymbolRequestRef message);
    template<> UnsubscribeSymbolRequestConstRef cast<UnsubscribeSymbolRequestConstRef, SymbolRequestConstRef>(SymbolRequestConstRef message);
    template<> UnsubscribeSymbolRequestRef cast<UnsubscribeSymbolRequestRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> UnsubscribeSymbolRequestConstRef cast<UnsubscribeSymbolRequestConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    class UnsubscribeSymbolAccept;
    class UnsubscribeSymbolAcceptRef;
    class UnsubscribeSymbolAcceptConstRef;
    
    class UnsubscribeSymbolAccept
    {
    public:
        
        UnsubscribeSymbolAccept();
        UnsubscribeSymbolAccept(const UnsubscribeSymbolAcceptRef& message);
        UnsubscribeSymbolAccept(const UnsubscribeSymbolAcceptConstRef& message);
        UnsubscribeSymbolAccept(const UnsubscribeSymbolAccept& message);
        
        ~UnsubscribeSymbolAccept();
        
        void setSymbol(const std::string& value);
        
        std::string getSymbol() const;
        
        UnsubscribeSymbolAccept& operator=(const UnsubscribeSymbolAcceptRef& message);
        UnsubscribeSymbolAccept& operator=(const UnsubscribeSymbolAcceptConstRef& message);
        UnsubscribeSymbolAccept& operator=(const UnsubscribeSymbolAccept& message);
        
        operator SymbolResponseRef();
        operator SymbolResponseConstRef() const;
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    class UnsubscribeSymbolAcceptRef
    {
    public:
        
        UnsubscribeSymbolAcceptRef(const MessageInfo* info, MessageData* data);
        UnsubscribeSymbolAcceptRef(const UnsubscribeSymbolAccept& message);
        UnsubscribeSymbolAcceptRef(const UnsubscribeSymbolAcceptConstRef& message);
        UnsubscribeSymbolAcceptRef(const UnsubscribeSymbolAcceptRef& message);
        
        void setSymbol(const std::string& value);
        
        std::string getSymbol() const;
        
        UnsubscribeSymbolAcceptRef& operator=(const UnsubscribeSymbolAccept& message);
        UnsubscribeSymbolAcceptRef& operator=(const UnsubscribeSymbolAcceptConstRef& message);
        UnsubscribeSymbolAcceptRef& operator=(const UnsubscribeSymbolAcceptRef& message);
        
        operator SymbolResponseRef();
        operator SymbolResponseConstRef() const;
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    class UnsubscribeSymbolAcceptConstRef
    {
    public:
        
        UnsubscribeSymbolAcceptConstRef(const MessageInfo* info, const MessageData* data);
        UnsubscribeSymbolAcceptConstRef(const UnsubscribeSymbolAccept& message);
        UnsubscribeSymbolAcceptConstRef(const UnsubscribeSymbolAcceptRef& message);
        UnsubscribeSymbolAcceptConstRef(const UnsubscribeSymbolAcceptConstRef& message);
        
        std::string getSymbol() const;
        
        operator SymbolResponseConstRef() const;
        operator recsen::MessageConstRef() const;
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        const MessageData* data_;
    };
    
    template<> bool is<UnsubscribeSymbolAcceptRef, SymbolResponseRef>(SymbolResponseRef message);
    template<> bool is<UnsubscribeSymbolAcceptConstRef, SymbolResponseConstRef>(SymbolResponseConstRef message);
    template<> bool is<UnsubscribeSymbolAcceptRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> bool is<UnsubscribeSymbolAcceptConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    template<> UnsubscribeSymbolAcceptRef cast<UnsubscribeSymbolAcceptRef, SymbolResponseRef>(SymbolResponseRef message);
    template<> UnsubscribeSymbolAcceptConstRef cast<UnsubscribeSymbolAcceptConstRef, SymbolResponseConstRef>(SymbolResponseConstRef message);
    template<> UnsubscribeSymbolAcceptRef cast<UnsubscribeSymbolAcceptRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> UnsubscribeSymbolAcceptConstRef cast<UnsubscribeSymbolAcceptConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    enum Side
    {
        Side_Bid = 0,
        Side_Ask = 1,
    };
    
    typedef recsen::array_ref_t<Side> SideArrayRef;
    typedef recsen::const_array_ref_t<Side> SideConstArrayRef;
    typedef recsen::array_ref_t<recsen::null_t<Side>> SideNullArrayRef;
    typedef recsen::const_array_ref_t<recsen::null_t<Side>> SideNullConstArrayRef;
    
    class SnapshotRefreshEntryRef;
    class SnapshotRefreshEntryConstRef;
    
    class SnapshotRefreshEntryRef
    {
    public:
        
        SnapshotRefreshEntryRef(MessageData* data, uint32_t offset);
        SnapshotRefreshEntryRef(const SnapshotRefreshEntryRef& group);
        
        void setSide(Side value);
        
        Side getSide() const;
        
        void setQty(int32_t value);
        
        int32_t getQty() const;
        
        void setPrice(double value);
        
        double getPrice() const;
        
        void setOrders(recsen::int32_null_t value);
        
        recsen::int32_null_t getOrders() const;
        
        SnapshotRefreshEntryRef& operator=(const SnapshotRefreshEntryConstRef& group);
        SnapshotRefreshEntryRef& operator=(const SnapshotRefreshEntryRef& group);
        
    private:
        
        MessageData* data_;
        uint32_t offset_;
    };
    
    typedef recsen::group_array_ref_t<SnapshotRefreshEntryRef> SnapshotRefreshEntryArrayRef;
    
    class SnapshotRefreshEntryConstRef
    {
    public:
        
        SnapshotRefreshEntryConstRef(const MessageData* data, uint32_t offset);
        SnapshotRefreshEntryConstRef(const SnapshotRefreshEntryRef& group);
        SnapshotRefreshEntryConstRef(const SnapshotRefreshEntryConstRef& group);
        
        Side getSide() const;
        
        int32_t getQty() const;
        
        double getPrice() const;
        
        recsen::int32_null_t getOrders() const;
        
    private:
        
        const MessageData* data_;
        uint32_t offset_;
    };
    
    typedef recsen::group_array_ref_t<SnapshotRefreshEntryConstRef> SnapshotRefreshEntryConstArrayRef;
    
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
        
        ~SnapshotRefresh();
        
        void setSymbol(const std::string& value);
        
        std::string getSymbol() const;
        
        SnapshotRefreshEntryArrayRef Entries();
        SnapshotRefreshEntryConstArrayRef Entries() const;
        
        SnapshotRefresh& operator=(const SnapshotRefreshRef& message);
        SnapshotRefresh& operator=(const SnapshotRefreshConstRef& message);
        SnapshotRefresh& operator=(const SnapshotRefresh& message);
        
        operator SymbolResponseRef();
        operator SymbolResponseConstRef() const;
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    class SnapshotRefreshRef
    {
    public:
        
        SnapshotRefreshRef(const MessageInfo* info, MessageData* data);
        SnapshotRefreshRef(const SnapshotRefresh& message);
        SnapshotRefreshRef(const SnapshotRefreshConstRef& message);
        SnapshotRefreshRef(const SnapshotRefreshRef& message);
        
        void setSymbol(const std::string& value);
        
        std::string getSymbol() const;
        
        SnapshotRefreshEntryArrayRef Entries();
        SnapshotRefreshEntryConstArrayRef Entries() const;
        
        SnapshotRefreshRef& operator=(const SnapshotRefresh& message);
        SnapshotRefreshRef& operator=(const SnapshotRefreshConstRef& message);
        SnapshotRefreshRef& operator=(const SnapshotRefreshRef& message);
        
        operator SymbolResponseRef();
        operator SymbolResponseConstRef() const;
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    class SnapshotRefreshConstRef
    {
    public:
        
        SnapshotRefreshConstRef(const MessageInfo* info, const MessageData* data);
        SnapshotRefreshConstRef(const SnapshotRefresh& message);
        SnapshotRefreshConstRef(const SnapshotRefreshRef& message);
        SnapshotRefreshConstRef(const SnapshotRefreshConstRef& message);
        
        std::string getSymbol() const;
        
        SnapshotRefreshEntryConstArrayRef Entries() const;
        
        operator SymbolResponseConstRef() const;
        operator recsen::MessageConstRef() const;
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        const MessageData* data_;
    };
    
    template<> bool is<SnapshotRefreshRef, SymbolResponseRef>(SymbolResponseRef message);
    template<> bool is<SnapshotRefreshConstRef, SymbolResponseConstRef>(SymbolResponseConstRef message);
    template<> bool is<SnapshotRefreshRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> bool is<SnapshotRefreshConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    template<> SnapshotRefreshRef cast<SnapshotRefreshRef, SymbolResponseRef>(SymbolResponseRef message);
    template<> SnapshotRefreshConstRef cast<SnapshotRefreshConstRef, SymbolResponseConstRef>(SymbolResponseConstRef message);
    template<> SnapshotRefreshRef cast<SnapshotRefreshRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> SnapshotRefreshConstRef cast<SnapshotRefreshConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    class NewsRequest;
    class NewsRequestRef;
    class NewsRequestConstRef;
    
    class NewsRequest
    {
    public:
        
        NewsRequest();
        NewsRequest(const NewsRequestRef& message);
        NewsRequest(const NewsRequestConstRef& message);
        NewsRequest(const NewsRequest& message);
        
        ~NewsRequest();
        
        NewsRequest& operator=(const NewsRequestRef& message);
        NewsRequest& operator=(const NewsRequestConstRef& message);
        NewsRequest& operator=(const NewsRequest& message);
        
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    class NewsRequestRef
    {
    public:
        
        NewsRequestRef(const MessageInfo* info, MessageData* data);
        NewsRequestRef(const NewsRequest& message);
        NewsRequestRef(const NewsRequestConstRef& message);
        NewsRequestRef(const NewsRequestRef& message);
        
        NewsRequestRef& operator=(const NewsRequest& message);
        NewsRequestRef& operator=(const NewsRequestConstRef& message);
        NewsRequestRef& operator=(const NewsRequestRef& message);
        
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    class NewsRequestConstRef
    {
    public:
        
        NewsRequestConstRef(const MessageInfo* info, const MessageData* data);
        NewsRequestConstRef(const NewsRequest& message);
        NewsRequestConstRef(const NewsRequestRef& message);
        NewsRequestConstRef(const NewsRequestConstRef& message);
        
        operator recsen::MessageConstRef() const;
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        const MessageData* data_;
    };
    
    template<> bool is<NewsRequestRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> bool is<NewsRequestConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    template<> NewsRequestRef cast<NewsRequestRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> NewsRequestConstRef cast<NewsRequestConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    class NewsResponse;
    class NewsResponseRef;
    class NewsResponseConstRef;
    
    class NewsResponse
    {
    public:
        
        NewsResponse();
        NewsResponse(const NewsResponseRef& message);
        NewsResponse(const NewsResponseConstRef& message);
        NewsResponse(const NewsResponse& message);
        
        ~NewsResponse();
        
        NewsResponse& operator=(const NewsResponseRef& message);
        NewsResponse& operator=(const NewsResponseConstRef& message);
        NewsResponse& operator=(const NewsResponse& message);
        
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    class NewsResponseRef
    {
    public:
        
        NewsResponseRef(const MessageInfo* info, MessageData* data);
        NewsResponseRef(const NewsResponse& message);
        NewsResponseRef(const NewsResponseConstRef& message);
        NewsResponseRef(const NewsResponseRef& message);
        
        NewsResponseRef& operator=(const NewsResponse& message);
        NewsResponseRef& operator=(const NewsResponseConstRef& message);
        NewsResponseRef& operator=(const NewsResponseRef& message);
        
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    class NewsResponseConstRef
    {
    public:
        
        NewsResponseConstRef(const MessageInfo* info, const MessageData* data);
        NewsResponseConstRef(const NewsResponse& message);
        NewsResponseConstRef(const NewsResponseRef& message);
        NewsResponseConstRef(const NewsResponseConstRef& message);
        
        operator recsen::MessageConstRef() const;
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        const MessageData* data_;
    };
    
    template<> bool is<NewsResponseRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> bool is<NewsResponseConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    template<> NewsResponseRef cast<NewsResponseRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> NewsResponseConstRef cast<NewsResponseConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    class SubscribeNewsRequest;
    class SubscribeNewsRequestRef;
    class SubscribeNewsRequestConstRef;
    
    class SubscribeNewsRequest
    {
    public:
        
        SubscribeNewsRequest();
        SubscribeNewsRequest(const SubscribeNewsRequestRef& message);
        SubscribeNewsRequest(const SubscribeNewsRequestConstRef& message);
        SubscribeNewsRequest(const SubscribeNewsRequest& message);
        
        ~SubscribeNewsRequest();
        
        SubscribeNewsRequest& operator=(const SubscribeNewsRequestRef& message);
        SubscribeNewsRequest& operator=(const SubscribeNewsRequestConstRef& message);
        SubscribeNewsRequest& operator=(const SubscribeNewsRequest& message);
        
        operator NewsRequestRef();
        operator NewsRequestConstRef() const;
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    class SubscribeNewsRequestRef
    {
    public:
        
        SubscribeNewsRequestRef(const MessageInfo* info, MessageData* data);
        SubscribeNewsRequestRef(const SubscribeNewsRequest& message);
        SubscribeNewsRequestRef(const SubscribeNewsRequestConstRef& message);
        SubscribeNewsRequestRef(const SubscribeNewsRequestRef& message);
        
        SubscribeNewsRequestRef& operator=(const SubscribeNewsRequest& message);
        SubscribeNewsRequestRef& operator=(const SubscribeNewsRequestConstRef& message);
        SubscribeNewsRequestRef& operator=(const SubscribeNewsRequestRef& message);
        
        operator NewsRequestRef();
        operator NewsRequestConstRef() const;
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    class SubscribeNewsRequestConstRef
    {
    public:
        
        SubscribeNewsRequestConstRef(const MessageInfo* info, const MessageData* data);
        SubscribeNewsRequestConstRef(const SubscribeNewsRequest& message);
        SubscribeNewsRequestConstRef(const SubscribeNewsRequestRef& message);
        SubscribeNewsRequestConstRef(const SubscribeNewsRequestConstRef& message);
        
        operator NewsRequestConstRef() const;
        operator recsen::MessageConstRef() const;
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        const MessageData* data_;
    };
    
    template<> bool is<SubscribeNewsRequestRef, NewsRequestRef>(NewsRequestRef message);
    template<> bool is<SubscribeNewsRequestConstRef, NewsRequestConstRef>(NewsRequestConstRef message);
    template<> bool is<SubscribeNewsRequestRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> bool is<SubscribeNewsRequestConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    template<> SubscribeNewsRequestRef cast<SubscribeNewsRequestRef, NewsRequestRef>(NewsRequestRef message);
    template<> SubscribeNewsRequestConstRef cast<SubscribeNewsRequestConstRef, NewsRequestConstRef>(NewsRequestConstRef message);
    template<> SubscribeNewsRequestRef cast<SubscribeNewsRequestRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> SubscribeNewsRequestConstRef cast<SubscribeNewsRequestConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    class SubscribeNewsAccept;
    class SubscribeNewsAcceptRef;
    class SubscribeNewsAcceptConstRef;
    
    class SubscribeNewsAccept
    {
    public:
        
        SubscribeNewsAccept();
        SubscribeNewsAccept(const SubscribeNewsAcceptRef& message);
        SubscribeNewsAccept(const SubscribeNewsAcceptConstRef& message);
        SubscribeNewsAccept(const SubscribeNewsAccept& message);
        
        ~SubscribeNewsAccept();
        
        SubscribeNewsAccept& operator=(const SubscribeNewsAcceptRef& message);
        SubscribeNewsAccept& operator=(const SubscribeNewsAcceptConstRef& message);
        SubscribeNewsAccept& operator=(const SubscribeNewsAccept& message);
        
        operator NewsResponseRef();
        operator NewsResponseConstRef() const;
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    class SubscribeNewsAcceptRef
    {
    public:
        
        SubscribeNewsAcceptRef(const MessageInfo* info, MessageData* data);
        SubscribeNewsAcceptRef(const SubscribeNewsAccept& message);
        SubscribeNewsAcceptRef(const SubscribeNewsAcceptConstRef& message);
        SubscribeNewsAcceptRef(const SubscribeNewsAcceptRef& message);
        
        SubscribeNewsAcceptRef& operator=(const SubscribeNewsAccept& message);
        SubscribeNewsAcceptRef& operator=(const SubscribeNewsAcceptConstRef& message);
        SubscribeNewsAcceptRef& operator=(const SubscribeNewsAcceptRef& message);
        
        operator NewsResponseRef();
        operator NewsResponseConstRef() const;
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    class SubscribeNewsAcceptConstRef
    {
    public:
        
        SubscribeNewsAcceptConstRef(const MessageInfo* info, const MessageData* data);
        SubscribeNewsAcceptConstRef(const SubscribeNewsAccept& message);
        SubscribeNewsAcceptConstRef(const SubscribeNewsAcceptRef& message);
        SubscribeNewsAcceptConstRef(const SubscribeNewsAcceptConstRef& message);
        
        operator NewsResponseConstRef() const;
        operator recsen::MessageConstRef() const;
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        const MessageData* data_;
    };
    
    template<> bool is<SubscribeNewsAcceptRef, NewsResponseRef>(NewsResponseRef message);
    template<> bool is<SubscribeNewsAcceptConstRef, NewsResponseConstRef>(NewsResponseConstRef message);
    template<> bool is<SubscribeNewsAcceptRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> bool is<SubscribeNewsAcceptConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    template<> SubscribeNewsAcceptRef cast<SubscribeNewsAcceptRef, NewsResponseRef>(NewsResponseRef message);
    template<> SubscribeNewsAcceptConstRef cast<SubscribeNewsAcceptConstRef, NewsResponseConstRef>(NewsResponseConstRef message);
    template<> SubscribeNewsAcceptRef cast<SubscribeNewsAcceptRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> SubscribeNewsAcceptConstRef cast<SubscribeNewsAcceptConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    class SubscribeNewsReject;
    class SubscribeNewsRejectRef;
    class SubscribeNewsRejectConstRef;
    
    class SubscribeNewsReject
    {
    public:
        
        SubscribeNewsReject();
        SubscribeNewsReject(const SubscribeNewsRejectRef& message);
        SubscribeNewsReject(const SubscribeNewsRejectConstRef& message);
        SubscribeNewsReject(const SubscribeNewsReject& message);
        
        ~SubscribeNewsReject();
        
        SubscribeNewsReject& operator=(const SubscribeNewsRejectRef& message);
        SubscribeNewsReject& operator=(const SubscribeNewsRejectConstRef& message);
        SubscribeNewsReject& operator=(const SubscribeNewsReject& message);
        
        operator NewsResponseRef();
        operator NewsResponseConstRef() const;
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    class SubscribeNewsRejectRef
    {
    public:
        
        SubscribeNewsRejectRef(const MessageInfo* info, MessageData* data);
        SubscribeNewsRejectRef(const SubscribeNewsReject& message);
        SubscribeNewsRejectRef(const SubscribeNewsRejectConstRef& message);
        SubscribeNewsRejectRef(const SubscribeNewsRejectRef& message);
        
        SubscribeNewsRejectRef& operator=(const SubscribeNewsReject& message);
        SubscribeNewsRejectRef& operator=(const SubscribeNewsRejectConstRef& message);
        SubscribeNewsRejectRef& operator=(const SubscribeNewsRejectRef& message);
        
        operator NewsResponseRef();
        operator NewsResponseConstRef() const;
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    class SubscribeNewsRejectConstRef
    {
    public:
        
        SubscribeNewsRejectConstRef(const MessageInfo* info, const MessageData* data);
        SubscribeNewsRejectConstRef(const SubscribeNewsReject& message);
        SubscribeNewsRejectConstRef(const SubscribeNewsRejectRef& message);
        SubscribeNewsRejectConstRef(const SubscribeNewsRejectConstRef& message);
        
        operator NewsResponseConstRef() const;
        operator recsen::MessageConstRef() const;
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        const MessageData* data_;
    };
    
    template<> bool is<SubscribeNewsRejectRef, NewsResponseRef>(NewsResponseRef message);
    template<> bool is<SubscribeNewsRejectConstRef, NewsResponseConstRef>(NewsResponseConstRef message);
    template<> bool is<SubscribeNewsRejectRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> bool is<SubscribeNewsRejectConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    template<> SubscribeNewsRejectRef cast<SubscribeNewsRejectRef, NewsResponseRef>(NewsResponseRef message);
    template<> SubscribeNewsRejectConstRef cast<SubscribeNewsRejectConstRef, NewsResponseConstRef>(NewsResponseConstRef message);
    template<> SubscribeNewsRejectRef cast<SubscribeNewsRejectRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> SubscribeNewsRejectConstRef cast<SubscribeNewsRejectConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    class UnsubscribeNewsRequest;
    class UnsubscribeNewsRequestRef;
    class UnsubscribeNewsRequestConstRef;
    
    class UnsubscribeNewsRequest
    {
    public:
        
        UnsubscribeNewsRequest();
        UnsubscribeNewsRequest(const UnsubscribeNewsRequestRef& message);
        UnsubscribeNewsRequest(const UnsubscribeNewsRequestConstRef& message);
        UnsubscribeNewsRequest(const UnsubscribeNewsRequest& message);
        
        ~UnsubscribeNewsRequest();
        
        UnsubscribeNewsRequest& operator=(const UnsubscribeNewsRequestRef& message);
        UnsubscribeNewsRequest& operator=(const UnsubscribeNewsRequestConstRef& message);
        UnsubscribeNewsRequest& operator=(const UnsubscribeNewsRequest& message);
        
        operator NewsRequestRef();
        operator NewsRequestConstRef() const;
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    class UnsubscribeNewsRequestRef
    {
    public:
        
        UnsubscribeNewsRequestRef(const MessageInfo* info, MessageData* data);
        UnsubscribeNewsRequestRef(const UnsubscribeNewsRequest& message);
        UnsubscribeNewsRequestRef(const UnsubscribeNewsRequestConstRef& message);
        UnsubscribeNewsRequestRef(const UnsubscribeNewsRequestRef& message);
        
        UnsubscribeNewsRequestRef& operator=(const UnsubscribeNewsRequest& message);
        UnsubscribeNewsRequestRef& operator=(const UnsubscribeNewsRequestConstRef& message);
        UnsubscribeNewsRequestRef& operator=(const UnsubscribeNewsRequestRef& message);
        
        operator NewsRequestRef();
        operator NewsRequestConstRef() const;
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    class UnsubscribeNewsRequestConstRef
    {
    public:
        
        UnsubscribeNewsRequestConstRef(const MessageInfo* info, const MessageData* data);
        UnsubscribeNewsRequestConstRef(const UnsubscribeNewsRequest& message);
        UnsubscribeNewsRequestConstRef(const UnsubscribeNewsRequestRef& message);
        UnsubscribeNewsRequestConstRef(const UnsubscribeNewsRequestConstRef& message);
        
        operator NewsRequestConstRef() const;
        operator recsen::MessageConstRef() const;
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        const MessageData* data_;
    };
    
    template<> bool is<UnsubscribeNewsRequestRef, NewsRequestRef>(NewsRequestRef message);
    template<> bool is<UnsubscribeNewsRequestConstRef, NewsRequestConstRef>(NewsRequestConstRef message);
    template<> bool is<UnsubscribeNewsRequestRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> bool is<UnsubscribeNewsRequestConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    template<> UnsubscribeNewsRequestRef cast<UnsubscribeNewsRequestRef, NewsRequestRef>(NewsRequestRef message);
    template<> UnsubscribeNewsRequestConstRef cast<UnsubscribeNewsRequestConstRef, NewsRequestConstRef>(NewsRequestConstRef message);
    template<> UnsubscribeNewsRequestRef cast<UnsubscribeNewsRequestRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> UnsubscribeNewsRequestConstRef cast<UnsubscribeNewsRequestConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    class UnsubscribeNewsAccept;
    class UnsubscribeNewsAcceptRef;
    class UnsubscribeNewsAcceptConstRef;
    
    class UnsubscribeNewsAccept
    {
    public:
        
        UnsubscribeNewsAccept();
        UnsubscribeNewsAccept(const UnsubscribeNewsAcceptRef& message);
        UnsubscribeNewsAccept(const UnsubscribeNewsAcceptConstRef& message);
        UnsubscribeNewsAccept(const UnsubscribeNewsAccept& message);
        
        ~UnsubscribeNewsAccept();
        
        UnsubscribeNewsAccept& operator=(const UnsubscribeNewsAcceptRef& message);
        UnsubscribeNewsAccept& operator=(const UnsubscribeNewsAcceptConstRef& message);
        UnsubscribeNewsAccept& operator=(const UnsubscribeNewsAccept& message);
        
        operator NewsResponseRef();
        operator NewsResponseConstRef() const;
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    class UnsubscribeNewsAcceptRef
    {
    public:
        
        UnsubscribeNewsAcceptRef(const MessageInfo* info, MessageData* data);
        UnsubscribeNewsAcceptRef(const UnsubscribeNewsAccept& message);
        UnsubscribeNewsAcceptRef(const UnsubscribeNewsAcceptConstRef& message);
        UnsubscribeNewsAcceptRef(const UnsubscribeNewsAcceptRef& message);
        
        UnsubscribeNewsAcceptRef& operator=(const UnsubscribeNewsAccept& message);
        UnsubscribeNewsAcceptRef& operator=(const UnsubscribeNewsAcceptConstRef& message);
        UnsubscribeNewsAcceptRef& operator=(const UnsubscribeNewsAcceptRef& message);
        
        operator NewsResponseRef();
        operator NewsResponseConstRef() const;
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    class UnsubscribeNewsAcceptConstRef
    {
    public:
        
        UnsubscribeNewsAcceptConstRef(const MessageInfo* info, const MessageData* data);
        UnsubscribeNewsAcceptConstRef(const UnsubscribeNewsAccept& message);
        UnsubscribeNewsAcceptConstRef(const UnsubscribeNewsAcceptRef& message);
        UnsubscribeNewsAcceptConstRef(const UnsubscribeNewsAcceptConstRef& message);
        
        operator NewsResponseConstRef() const;
        operator recsen::MessageConstRef() const;
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        const MessageData* data_;
    };
    
    template<> bool is<UnsubscribeNewsAcceptRef, NewsResponseRef>(NewsResponseRef message);
    template<> bool is<UnsubscribeNewsAcceptConstRef, NewsResponseConstRef>(NewsResponseConstRef message);
    template<> bool is<UnsubscribeNewsAcceptRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> bool is<UnsubscribeNewsAcceptConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    template<> UnsubscribeNewsAcceptRef cast<UnsubscribeNewsAcceptRef, NewsResponseRef>(NewsResponseRef message);
    template<> UnsubscribeNewsAcceptConstRef cast<UnsubscribeNewsAcceptConstRef, NewsResponseConstRef>(NewsResponseConstRef message);
    template<> UnsubscribeNewsAcceptRef cast<UnsubscribeNewsAcceptRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> UnsubscribeNewsAcceptConstRef cast<UnsubscribeNewsAcceptConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    enum NewsSeverity
    {
        NewsSeverity_Critical = 0,
        NewsSeverity_Warning = 1,
        NewsSeverity_Information = 2,
    };
    
    typedef recsen::array_ref_t<NewsSeverity> NewsSeverityArrayRef;
    typedef recsen::const_array_ref_t<NewsSeverity> NewsSeverityConstArrayRef;
    typedef recsen::array_ref_t<recsen::null_t<NewsSeverity>> NewsSeverityNullArrayRef;
    typedef recsen::const_array_ref_t<recsen::null_t<NewsSeverity>> NewsSeverityNullConstArrayRef;
    
    class NewsNotification;
    class NewsNotificationRef;
    class NewsNotificationConstRef;
    
    class NewsNotification
    {
    public:
        
        NewsNotification();
        NewsNotification(const NewsNotificationRef& message);
        NewsNotification(const NewsNotificationConstRef& message);
        NewsNotification(const NewsNotification& message);
        
        ~NewsNotification();
        
        void setSeverity(NewsSeverity value);
        
        NewsSeverity getSeverity() const;
        
        void setHeader(const std::string& value);
        
        std::string getHeader() const;
        
        void setText(const std::string& value);
        
        std::string getText() const;
        
        NewsNotification& operator=(const NewsNotificationRef& message);
        NewsNotification& operator=(const NewsNotificationConstRef& message);
        NewsNotification& operator=(const NewsNotification& message);
        
        operator NewsResponseRef();
        operator NewsResponseConstRef() const;
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    class NewsNotificationRef
    {
    public:
        
        NewsNotificationRef(const MessageInfo* info, MessageData* data);
        NewsNotificationRef(const NewsNotification& message);
        NewsNotificationRef(const NewsNotificationConstRef& message);
        NewsNotificationRef(const NewsNotificationRef& message);
        
        void setSeverity(NewsSeverity value);
        
        NewsSeverity getSeverity() const;
        
        void setHeader(const std::string& value);
        
        std::string getHeader() const;
        
        void setText(const std::string& value);
        
        std::string getText() const;
        
        NewsNotificationRef& operator=(const NewsNotification& message);
        NewsNotificationRef& operator=(const NewsNotificationConstRef& message);
        NewsNotificationRef& operator=(const NewsNotificationRef& message);
        
        operator NewsResponseRef();
        operator NewsResponseConstRef() const;
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    class NewsNotificationConstRef
    {
    public:
        
        NewsNotificationConstRef(const MessageInfo* info, const MessageData* data);
        NewsNotificationConstRef(const NewsNotification& message);
        NewsNotificationConstRef(const NewsNotificationRef& message);
        NewsNotificationConstRef(const NewsNotificationConstRef& message);
        
        NewsSeverity getSeverity() const;
        
        std::string getHeader() const;
        
        std::string getText() const;
        
        operator NewsResponseConstRef() const;
        operator recsen::MessageConstRef() const;
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        const MessageData* data_;
    };
    
    template<> bool is<NewsNotificationRef, NewsResponseRef>(NewsResponseRef message);
    template<> bool is<NewsNotificationConstRef, NewsResponseConstRef>(NewsResponseConstRef message);
    template<> bool is<NewsNotificationRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> bool is<NewsNotificationConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    template<> NewsNotificationRef cast<NewsNotificationRef, NewsResponseRef>(NewsResponseRef message);
    template<> NewsNotificationConstRef cast<NewsNotificationConstRef, NewsResponseConstRef>(NewsResponseConstRef message);
    template<> NewsNotificationRef cast<NewsNotificationRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> NewsNotificationConstRef cast<NewsNotificationConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    class Logout;
    class LogoutRef;
    class LogoutConstRef;
    
    class Logout
    {
    public:
        
        Logout();
        Logout(const LogoutRef& message);
        Logout(const LogoutConstRef& message);
        Logout(const Logout& message);
        
        ~Logout();
        
        Logout& operator=(const LogoutRef& message);
        Logout& operator=(const LogoutConstRef& message);
        Logout& operator=(const Logout& message);
        
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    class LogoutRef
    {
    public:
        
        LogoutRef(const MessageInfo* info, MessageData* data);
        LogoutRef(const Logout& message);
        LogoutRef(const LogoutConstRef& message);
        LogoutRef(const LogoutRef& message);
        
        LogoutRef& operator=(const Logout& message);
        LogoutRef& operator=(const LogoutConstRef& message);
        LogoutRef& operator=(const LogoutRef& message);
        
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        MessageData* data_;
    };
    
    class LogoutConstRef
    {
    public:
        
        LogoutConstRef(const MessageInfo* info, const MessageData* data);
        LogoutConstRef(const Logout& message);
        LogoutConstRef(const LogoutRef& message);
        LogoutConstRef(const LogoutConstRef& message);
        
        operator recsen::MessageConstRef() const;
        
        std::string toString() const;
        
    private:
        
        const MessageInfo* info_;
        const MessageData* data_;
    };
    
    template<> bool is<LogoutRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> bool is<LogoutConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    template<> LogoutRef cast<LogoutRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> LogoutConstRef cast<LogoutConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
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
        
        void loginPublic(loginPublicClientContext* context, LoginPublicRequestRef message);
        
        void loginPrivate(loginPrivateClientContext* context, LoginPrivateRequestRef message);
        
        void Logout(LogoutClientContext* context, LogoutRef message);
        
        void subscribeSymbol(subscribeSymbolClientContext* context, SubscribeSymbolRequestRef message);
        
        void unsubscribeSymbol(unsubscribeSymbolClientContext* context, UnsubscribeSymbolRequestRef message);
        
        void subscribeNews(subscribeNewsClientContext* context, SubscribeNewsRequestRef message);
        
        void unsubscribeNews(unsubscribeNewsClientContext* context, UnsubscribeNewsRequestRef message);
        
        void send(recsen::MessageRef message);
        
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
        
        void virtual onPublicLoginAccept(ClientSession* session, loginPublicClientContext* context, LoginAcceptConstRef message);
        
        void virtual onPublicLoginReject(ClientSession* session, loginPublicClientContext* context, LoginRejectConstRef message);
        
        void virtual onPassword(ClientSession* session, loginPrivateClientContext* context, PasswordRequestConstRef message);
        
        void virtual onPrivateLoginAccept(ClientSession* session, loginPrivateClientContext* context, LoginAcceptConstRef message);
        
        void virtual onPrivateLoginReject(ClientSession* session, loginPrivateClientContext* context, LoginRejectConstRef message);
        
        void virtual onLogout(ClientSession* session, LogoutConstRef message);
        
        void virtual onSubscribeSymbolAccept(ClientSession* session, subscribeSymbolClientContext* context, SubscribeSymbolAcceptConstRef message);
        
        void virtual onSubscribeSymbolReject(ClientSession* session, subscribeSymbolClientContext* context, SubscribeSymbolRejectConstRef message);
        
        void virtual onSnapshot(ClientSession* session, SnapshotRefreshConstRef message);
        
        void virtual onSubscribeNewsAccept(ClientSession* session, subscribeNewsClientContext* context, SubscribeNewsAcceptConstRef message);
        
        void virtual onSubscribeNewsReject(ClientSession* session, subscribeNewsClientContext* context, SubscribeNewsRejectConstRef message);
        
        void virtual onNews(ClientSession* session, NewsNotificationConstRef message);
        
        void virtual onReceive(ClientSession* session, recsen::MessageConstRef message);
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
        
        void send(recsen::MessageRef message);
        
    private:
        
        ServerSessionData* data_;
    };
    
    class ServerListener
    {
    public:
        
        void virtual onConnect(ServerSession* session);
        
        void virtual onDisconnect(ServerSession* session, const std::string& text);
        
        void virtual onLoginPublic(ServerSession* session, LoginPublicRequestConstRef message);
        
        void virtual onLoginPrivate(ServerSession* session, LoginPrivateRequestConstRef message);
        
        void virtual onPassword(ServerSession* session, PasswordResponseConstRef message);
        
        void virtual onLogout(ServerSession* session, LogoutConstRef message);
        
        void virtual onSubscribeSymbol(ServerSession* session, SubscribeSymbolRequestConstRef message);
        
        void virtual onUnsubscribeSymbol(ServerSession* session, UnsubscribeSymbolRequestConstRef message);
        
        void virtual onSubscribeNews(ServerSession* session, SubscribeNewsRequestConstRef message);
        
        void virtual onUnsubscribeNews(ServerSession* session, UnsubscribeNewsRequestConstRef message);
        
        void virtual onReceive(ServerSession* session, recsen::MessageConstRef message);
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
