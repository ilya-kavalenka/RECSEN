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
        
        void setName(const std::string& value);
        
        std::string getName() const;
        
        size_t getSize() const;
        
        const recsen::MessageInfo* info() const;
        
        recsen::fbe::MessageData& data();
        const recsen::fbe::MessageData& data() const;
        
        LoginPublicRequest& operator=(const LoginPublicRequestRef& message);
        LoginPublicRequest& operator=(const LoginPublicRequestConstRef& message);
        LoginPublicRequest& operator=(const LoginPublicRequest& message);
        
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const recsen::MessageInfo* info_;
        recsen::fbe::MessageData data_;
    };
    
    class LoginPublicRequestRef
    {
    public:
        
        LoginPublicRequestRef(const recsen::MessageInfo* info, recsen::fbe::MessageData& data);
        LoginPublicRequestRef(LoginPublicRequest& message);
        LoginPublicRequestRef(const LoginPublicRequestRef& message);
        
        void setName(const std::string& value);
        
        std::string getName() const;
        
        size_t getSize() const;
        
        const recsen::MessageInfo* info() const;
        
        recsen::fbe::MessageData& data();
        const recsen::fbe::MessageData& data() const;
        
        LoginPublicRequestRef& operator=(const LoginPublicRequest& message);
        LoginPublicRequestRef& operator=(const LoginPublicRequestConstRef& message);
        LoginPublicRequestRef& operator=(const LoginPublicRequestRef& message);
        
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const recsen::MessageInfo* info_;
        recsen::fbe::MessageData& data_;
    };
    
    class LoginPublicRequestConstRef
    {
    public:
        
        LoginPublicRequestConstRef(const recsen::MessageInfo* info, const recsen::fbe::MessageData& data);
        LoginPublicRequestConstRef(const LoginPublicRequest& message);
        LoginPublicRequestConstRef(const LoginPublicRequestRef& message);
        LoginPublicRequestConstRef(const LoginPublicRequestConstRef& message);
        
        std::string getName() const;
        
        size_t getSize() const;
        
        const recsen::MessageInfo* info() const;
        
        const recsen::fbe::MessageData& data() const;
        
        operator recsen::MessageConstRef() const;
        
        std::string toString() const;
        
    private:
        
        const recsen::MessageInfo* info_;
        const recsen::fbe::MessageData& data_;
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
        
        void setName(const std::string& value);
        
        std::string getName() const;
        
        size_t getSize() const;
        
        const recsen::MessageInfo* info() const;
        
        recsen::fbe::MessageData& data();
        const recsen::fbe::MessageData& data() const;
        
        LoginPrivateRequest& operator=(const LoginPrivateRequestRef& message);
        LoginPrivateRequest& operator=(const LoginPrivateRequestConstRef& message);
        LoginPrivateRequest& operator=(const LoginPrivateRequest& message);
        
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const recsen::MessageInfo* info_;
        recsen::fbe::MessageData data_;
    };
    
    class LoginPrivateRequestRef
    {
    public:
        
        LoginPrivateRequestRef(const recsen::MessageInfo* info, recsen::fbe::MessageData& data);
        LoginPrivateRequestRef(LoginPrivateRequest& message);
        LoginPrivateRequestRef(const LoginPrivateRequestRef& message);
        
        void setName(const std::string& value);
        
        std::string getName() const;
        
        size_t getSize() const;
        
        const recsen::MessageInfo* info() const;
        
        recsen::fbe::MessageData& data();
        const recsen::fbe::MessageData& data() const;
        
        LoginPrivateRequestRef& operator=(const LoginPrivateRequest& message);
        LoginPrivateRequestRef& operator=(const LoginPrivateRequestConstRef& message);
        LoginPrivateRequestRef& operator=(const LoginPrivateRequestRef& message);
        
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const recsen::MessageInfo* info_;
        recsen::fbe::MessageData& data_;
    };
    
    class LoginPrivateRequestConstRef
    {
    public:
        
        LoginPrivateRequestConstRef(const recsen::MessageInfo* info, const recsen::fbe::MessageData& data);
        LoginPrivateRequestConstRef(const LoginPrivateRequest& message);
        LoginPrivateRequestConstRef(const LoginPrivateRequestRef& message);
        LoginPrivateRequestConstRef(const LoginPrivateRequestConstRef& message);
        
        std::string getName() const;
        
        size_t getSize() const;
        
        const recsen::MessageInfo* info() const;
        
        const recsen::fbe::MessageData& data() const;
        
        operator recsen::MessageConstRef() const;
        
        std::string toString() const;
        
    private:
        
        const recsen::MessageInfo* info_;
        const recsen::fbe::MessageData& data_;
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
        
        void setToken(const recsen::bytes_t& value);
        
        recsen::bytes_t getToken() const;
        
        size_t getSize() const;
        
        const recsen::MessageInfo* info() const;
        
        recsen::fbe::MessageData& data();
        const recsen::fbe::MessageData& data() const;
        
        PasswordRequest& operator=(const PasswordRequestRef& message);
        PasswordRequest& operator=(const PasswordRequestConstRef& message);
        PasswordRequest& operator=(const PasswordRequest& message);
        
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const recsen::MessageInfo* info_;
        recsen::fbe::MessageData data_;
    };
    
    class PasswordRequestRef
    {
    public:
        
        PasswordRequestRef(const recsen::MessageInfo* info, recsen::fbe::MessageData& data);
        PasswordRequestRef(PasswordRequest& message);
        PasswordRequestRef(const PasswordRequestRef& message);
        
        void setToken(const recsen::bytes_t& value);
        
        recsen::bytes_t getToken() const;
        
        size_t getSize() const;
        
        const recsen::MessageInfo* info() const;
        
        recsen::fbe::MessageData& data();
        const recsen::fbe::MessageData& data() const;
        
        PasswordRequestRef& operator=(const PasswordRequest& message);
        PasswordRequestRef& operator=(const PasswordRequestConstRef& message);
        PasswordRequestRef& operator=(const PasswordRequestRef& message);
        
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const recsen::MessageInfo* info_;
        recsen::fbe::MessageData& data_;
    };
    
    class PasswordRequestConstRef
    {
    public:
        
        PasswordRequestConstRef(const recsen::MessageInfo* info, const recsen::fbe::MessageData& data);
        PasswordRequestConstRef(const PasswordRequest& message);
        PasswordRequestConstRef(const PasswordRequestRef& message);
        PasswordRequestConstRef(const PasswordRequestConstRef& message);
        
        recsen::bytes_t getToken() const;
        
        size_t getSize() const;
        
        const recsen::MessageInfo* info() const;
        
        const recsen::fbe::MessageData& data() const;
        
        operator recsen::MessageConstRef() const;
        
        std::string toString() const;
        
    private:
        
        const recsen::MessageInfo* info_;
        const recsen::fbe::MessageData& data_;
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
        
        void setEncodedToken(const recsen::bytes_t& value);
        
        recsen::bytes_t getEncodedToken() const;
        
        size_t getSize() const;
        
        const recsen::MessageInfo* info() const;
        
        recsen::fbe::MessageData& data();
        const recsen::fbe::MessageData& data() const;
        
        PasswordResponse& operator=(const PasswordResponseRef& message);
        PasswordResponse& operator=(const PasswordResponseConstRef& message);
        PasswordResponse& operator=(const PasswordResponse& message);
        
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const recsen::MessageInfo* info_;
        recsen::fbe::MessageData data_;
    };
    
    class PasswordResponseRef
    {
    public:
        
        PasswordResponseRef(const recsen::MessageInfo* info, recsen::fbe::MessageData& data);
        PasswordResponseRef(PasswordResponse& message);
        PasswordResponseRef(const PasswordResponseRef& message);
        
        void setEncodedToken(const recsen::bytes_t& value);
        
        recsen::bytes_t getEncodedToken() const;
        
        size_t getSize() const;
        
        const recsen::MessageInfo* info() const;
        
        recsen::fbe::MessageData& data();
        const recsen::fbe::MessageData& data() const;
        
        PasswordResponseRef& operator=(const PasswordResponse& message);
        PasswordResponseRef& operator=(const PasswordResponseConstRef& message);
        PasswordResponseRef& operator=(const PasswordResponseRef& message);
        
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const recsen::MessageInfo* info_;
        recsen::fbe::MessageData& data_;
    };
    
    class PasswordResponseConstRef
    {
    public:
        
        PasswordResponseConstRef(const recsen::MessageInfo* info, const recsen::fbe::MessageData& data);
        PasswordResponseConstRef(const PasswordResponse& message);
        PasswordResponseConstRef(const PasswordResponseRef& message);
        PasswordResponseConstRef(const PasswordResponseConstRef& message);
        
        recsen::bytes_t getEncodedToken() const;
        
        size_t getSize() const;
        
        const recsen::MessageInfo* info() const;
        
        const recsen::fbe::MessageData& data() const;
        
        operator recsen::MessageConstRef() const;
        
        std::string toString() const;
        
    private:
        
        const recsen::MessageInfo* info_;
        const recsen::fbe::MessageData& data_;
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
        
        size_t getSize() const;
        
        const recsen::MessageInfo* info() const;
        
        recsen::fbe::MessageData& data();
        const recsen::fbe::MessageData& data() const;
        
        LoginAccept& operator=(const LoginAcceptRef& message);
        LoginAccept& operator=(const LoginAcceptConstRef& message);
        LoginAccept& operator=(const LoginAccept& message);
        
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const recsen::MessageInfo* info_;
        recsen::fbe::MessageData data_;
    };
    
    class LoginAcceptRef
    {
    public:
        
        LoginAcceptRef(const recsen::MessageInfo* info, recsen::fbe::MessageData& data);
        LoginAcceptRef(LoginAccept& message);
        LoginAcceptRef(const LoginAcceptRef& message);
        
        size_t getSize() const;
        
        const recsen::MessageInfo* info() const;
        
        recsen::fbe::MessageData& data();
        const recsen::fbe::MessageData& data() const;
        
        LoginAcceptRef& operator=(const LoginAccept& message);
        LoginAcceptRef& operator=(const LoginAcceptConstRef& message);
        LoginAcceptRef& operator=(const LoginAcceptRef& message);
        
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const recsen::MessageInfo* info_;
        recsen::fbe::MessageData& data_;
    };
    
    class LoginAcceptConstRef
    {
    public:
        
        LoginAcceptConstRef(const recsen::MessageInfo* info, const recsen::fbe::MessageData& data);
        LoginAcceptConstRef(const LoginAccept& message);
        LoginAcceptConstRef(const LoginAcceptRef& message);
        LoginAcceptConstRef(const LoginAcceptConstRef& message);
        
        size_t getSize() const;
        
        const recsen::MessageInfo* info() const;
        
        const recsen::fbe::MessageData& data() const;
        
        operator recsen::MessageConstRef() const;
        
        std::string toString() const;
        
    private:
        
        const recsen::MessageInfo* info_;
        const recsen::fbe::MessageData& data_;
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
        
        void setText(const std::string& value);
        
        std::string getText() const;
        
        size_t getSize() const;
        
        const recsen::MessageInfo* info() const;
        
        recsen::fbe::MessageData& data();
        const recsen::fbe::MessageData& data() const;
        
        LoginReject& operator=(const LoginRejectRef& message);
        LoginReject& operator=(const LoginRejectConstRef& message);
        LoginReject& operator=(const LoginReject& message);
        
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const recsen::MessageInfo* info_;
        recsen::fbe::MessageData data_;
    };
    
    class LoginRejectRef
    {
    public:
        
        LoginRejectRef(const recsen::MessageInfo* info, recsen::fbe::MessageData& data);
        LoginRejectRef(LoginReject& message);
        LoginRejectRef(const LoginRejectRef& message);
        
        void setText(const std::string& value);
        
        std::string getText() const;
        
        size_t getSize() const;
        
        const recsen::MessageInfo* info() const;
        
        recsen::fbe::MessageData& data();
        const recsen::fbe::MessageData& data() const;
        
        LoginRejectRef& operator=(const LoginReject& message);
        LoginRejectRef& operator=(const LoginRejectConstRef& message);
        LoginRejectRef& operator=(const LoginRejectRef& message);
        
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const recsen::MessageInfo* info_;
        recsen::fbe::MessageData& data_;
    };
    
    class LoginRejectConstRef
    {
    public:
        
        LoginRejectConstRef(const recsen::MessageInfo* info, const recsen::fbe::MessageData& data);
        LoginRejectConstRef(const LoginReject& message);
        LoginRejectConstRef(const LoginRejectRef& message);
        LoginRejectConstRef(const LoginRejectConstRef& message);
        
        std::string getText() const;
        
        size_t getSize() const;
        
        const recsen::MessageInfo* info() const;
        
        const recsen::fbe::MessageData& data() const;
        
        operator recsen::MessageConstRef() const;
        
        std::string toString() const;
        
    private:
        
        const recsen::MessageInfo* info_;
        const recsen::fbe::MessageData& data_;
    };
    
    template<> bool is<LoginRejectRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> bool is<LoginRejectConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    template<> LoginRejectRef cast<LoginRejectRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> LoginRejectConstRef cast<LoginRejectConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
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
        
        size_t getSize() const;
        
        const recsen::MessageInfo* info() const;
        
        recsen::fbe::MessageData& data();
        const recsen::fbe::MessageData& data() const;
        
        Logout& operator=(const LogoutRef& message);
        Logout& operator=(const LogoutConstRef& message);
        Logout& operator=(const Logout& message);
        
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const recsen::MessageInfo* info_;
        recsen::fbe::MessageData data_;
    };
    
    class LogoutRef
    {
    public:
        
        LogoutRef(const recsen::MessageInfo* info, recsen::fbe::MessageData& data);
        LogoutRef(Logout& message);
        LogoutRef(const LogoutRef& message);
        
        size_t getSize() const;
        
        const recsen::MessageInfo* info() const;
        
        recsen::fbe::MessageData& data();
        const recsen::fbe::MessageData& data() const;
        
        LogoutRef& operator=(const Logout& message);
        LogoutRef& operator=(const LogoutConstRef& message);
        LogoutRef& operator=(const LogoutRef& message);
        
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const recsen::MessageInfo* info_;
        recsen::fbe::MessageData& data_;
    };
    
    class LogoutConstRef
    {
    public:
        
        LogoutConstRef(const recsen::MessageInfo* info, const recsen::fbe::MessageData& data);
        LogoutConstRef(const Logout& message);
        LogoutConstRef(const LogoutRef& message);
        LogoutConstRef(const LogoutConstRef& message);
        
        size_t getSize() const;
        
        const recsen::MessageInfo* info() const;
        
        const recsen::fbe::MessageData& data() const;
        
        operator recsen::MessageConstRef() const;
        
        std::string toString() const;
        
    private:
        
        const recsen::MessageInfo* info_;
        const recsen::fbe::MessageData& data_;
    };
    
    template<> bool is<LogoutRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> bool is<LogoutConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    template<> LogoutRef cast<LogoutRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> LogoutConstRef cast<LogoutConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    class SubscribeRequest;
    class SubscribeRequestRef;
    class SubscribeRequestConstRef;
    
    class SubscribeRequest
    {
    public:
        
        SubscribeRequest();
        SubscribeRequest(const SubscribeRequestRef& message);
        SubscribeRequest(const SubscribeRequestConstRef& message);
        SubscribeRequest(const SubscribeRequest& message);
        
        size_t getSize() const;
        
        const recsen::MessageInfo* info() const;
        
        recsen::fbe::MessageData& data();
        const recsen::fbe::MessageData& data() const;
        
        SubscribeRequest& operator=(const SubscribeRequestRef& message);
        SubscribeRequest& operator=(const SubscribeRequestConstRef& message);
        SubscribeRequest& operator=(const SubscribeRequest& message);
        
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const recsen::MessageInfo* info_;
        recsen::fbe::MessageData data_;
    };
    
    class SubscribeRequestRef
    {
    public:
        
        SubscribeRequestRef(const recsen::MessageInfo* info, recsen::fbe::MessageData& data);
        SubscribeRequestRef(SubscribeRequest& message);
        SubscribeRequestRef(const SubscribeRequestRef& message);
        
        size_t getSize() const;
        
        const recsen::MessageInfo* info() const;
        
        recsen::fbe::MessageData& data();
        const recsen::fbe::MessageData& data() const;
        
        SubscribeRequestRef& operator=(const SubscribeRequest& message);
        SubscribeRequestRef& operator=(const SubscribeRequestConstRef& message);
        SubscribeRequestRef& operator=(const SubscribeRequestRef& message);
        
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const recsen::MessageInfo* info_;
        recsen::fbe::MessageData& data_;
    };
    
    class SubscribeRequestConstRef
    {
    public:
        
        SubscribeRequestConstRef(const recsen::MessageInfo* info, const recsen::fbe::MessageData& data);
        SubscribeRequestConstRef(const SubscribeRequest& message);
        SubscribeRequestConstRef(const SubscribeRequestRef& message);
        SubscribeRequestConstRef(const SubscribeRequestConstRef& message);
        
        size_t getSize() const;
        
        const recsen::MessageInfo* info() const;
        
        const recsen::fbe::MessageData& data() const;
        
        operator recsen::MessageConstRef() const;
        
        std::string toString() const;
        
    private:
        
        const recsen::MessageInfo* info_;
        const recsen::fbe::MessageData& data_;
    };
    
    template<> bool is<SubscribeRequestRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> bool is<SubscribeRequestConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    template<> SubscribeRequestRef cast<SubscribeRequestRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> SubscribeRequestConstRef cast<SubscribeRequestConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    class SubscribeAccept;
    class SubscribeAcceptRef;
    class SubscribeAcceptConstRef;
    
    class SubscribeAccept
    {
    public:
        
        SubscribeAccept();
        SubscribeAccept(const SubscribeAcceptRef& message);
        SubscribeAccept(const SubscribeAcceptConstRef& message);
        SubscribeAccept(const SubscribeAccept& message);
        
        size_t getSize() const;
        
        const recsen::MessageInfo* info() const;
        
        recsen::fbe::MessageData& data();
        const recsen::fbe::MessageData& data() const;
        
        SubscribeAccept& operator=(const SubscribeAcceptRef& message);
        SubscribeAccept& operator=(const SubscribeAcceptConstRef& message);
        SubscribeAccept& operator=(const SubscribeAccept& message);
        
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const recsen::MessageInfo* info_;
        recsen::fbe::MessageData data_;
    };
    
    class SubscribeAcceptRef
    {
    public:
        
        SubscribeAcceptRef(const recsen::MessageInfo* info, recsen::fbe::MessageData& data);
        SubscribeAcceptRef(SubscribeAccept& message);
        SubscribeAcceptRef(const SubscribeAcceptRef& message);
        
        size_t getSize() const;
        
        const recsen::MessageInfo* info() const;
        
        recsen::fbe::MessageData& data();
        const recsen::fbe::MessageData& data() const;
        
        SubscribeAcceptRef& operator=(const SubscribeAccept& message);
        SubscribeAcceptRef& operator=(const SubscribeAcceptConstRef& message);
        SubscribeAcceptRef& operator=(const SubscribeAcceptRef& message);
        
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const recsen::MessageInfo* info_;
        recsen::fbe::MessageData& data_;
    };
    
    class SubscribeAcceptConstRef
    {
    public:
        
        SubscribeAcceptConstRef(const recsen::MessageInfo* info, const recsen::fbe::MessageData& data);
        SubscribeAcceptConstRef(const SubscribeAccept& message);
        SubscribeAcceptConstRef(const SubscribeAcceptRef& message);
        SubscribeAcceptConstRef(const SubscribeAcceptConstRef& message);
        
        size_t getSize() const;
        
        const recsen::MessageInfo* info() const;
        
        const recsen::fbe::MessageData& data() const;
        
        operator recsen::MessageConstRef() const;
        
        std::string toString() const;
        
    private:
        
        const recsen::MessageInfo* info_;
        const recsen::fbe::MessageData& data_;
    };
    
    template<> bool is<SubscribeAcceptRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> bool is<SubscribeAcceptConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    template<> SubscribeAcceptRef cast<SubscribeAcceptRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> SubscribeAcceptConstRef cast<SubscribeAcceptConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    class SubscribeReject;
    class SubscribeRejectRef;
    class SubscribeRejectConstRef;
    
    class SubscribeReject
    {
    public:
        
        SubscribeReject();
        SubscribeReject(const SubscribeRejectRef& message);
        SubscribeReject(const SubscribeRejectConstRef& message);
        SubscribeReject(const SubscribeReject& message);
        
        void setText(const std::string& value);
        
        std::string getText() const;
        
        size_t getSize() const;
        
        const recsen::MessageInfo* info() const;
        
        recsen::fbe::MessageData& data();
        const recsen::fbe::MessageData& data() const;
        
        SubscribeReject& operator=(const SubscribeRejectRef& message);
        SubscribeReject& operator=(const SubscribeRejectConstRef& message);
        SubscribeReject& operator=(const SubscribeReject& message);
        
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const recsen::MessageInfo* info_;
        recsen::fbe::MessageData data_;
    };
    
    class SubscribeRejectRef
    {
    public:
        
        SubscribeRejectRef(const recsen::MessageInfo* info, recsen::fbe::MessageData& data);
        SubscribeRejectRef(SubscribeReject& message);
        SubscribeRejectRef(const SubscribeRejectRef& message);
        
        void setText(const std::string& value);
        
        std::string getText() const;
        
        size_t getSize() const;
        
        const recsen::MessageInfo* info() const;
        
        recsen::fbe::MessageData& data();
        const recsen::fbe::MessageData& data() const;
        
        SubscribeRejectRef& operator=(const SubscribeReject& message);
        SubscribeRejectRef& operator=(const SubscribeRejectConstRef& message);
        SubscribeRejectRef& operator=(const SubscribeRejectRef& message);
        
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const recsen::MessageInfo* info_;
        recsen::fbe::MessageData& data_;
    };
    
    class SubscribeRejectConstRef
    {
    public:
        
        SubscribeRejectConstRef(const recsen::MessageInfo* info, const recsen::fbe::MessageData& data);
        SubscribeRejectConstRef(const SubscribeReject& message);
        SubscribeRejectConstRef(const SubscribeRejectRef& message);
        SubscribeRejectConstRef(const SubscribeRejectConstRef& message);
        
        std::string getText() const;
        
        size_t getSize() const;
        
        const recsen::MessageInfo* info() const;
        
        const recsen::fbe::MessageData& data() const;
        
        operator recsen::MessageConstRef() const;
        
        std::string toString() const;
        
    private:
        
        const recsen::MessageInfo* info_;
        const recsen::fbe::MessageData& data_;
    };
    
    template<> bool is<SubscribeRejectRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> bool is<SubscribeRejectConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    template<> SubscribeRejectRef cast<SubscribeRejectRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> SubscribeRejectConstRef cast<SubscribeRejectConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    class UnsubscribeRequest;
    class UnsubscribeRequestRef;
    class UnsubscribeRequestConstRef;
    
    class UnsubscribeRequest
    {
    public:
        
        UnsubscribeRequest();
        UnsubscribeRequest(const UnsubscribeRequestRef& message);
        UnsubscribeRequest(const UnsubscribeRequestConstRef& message);
        UnsubscribeRequest(const UnsubscribeRequest& message);
        
        size_t getSize() const;
        
        const recsen::MessageInfo* info() const;
        
        recsen::fbe::MessageData& data();
        const recsen::fbe::MessageData& data() const;
        
        UnsubscribeRequest& operator=(const UnsubscribeRequestRef& message);
        UnsubscribeRequest& operator=(const UnsubscribeRequestConstRef& message);
        UnsubscribeRequest& operator=(const UnsubscribeRequest& message);
        
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const recsen::MessageInfo* info_;
        recsen::fbe::MessageData data_;
    };
    
    class UnsubscribeRequestRef
    {
    public:
        
        UnsubscribeRequestRef(const recsen::MessageInfo* info, recsen::fbe::MessageData& data);
        UnsubscribeRequestRef(UnsubscribeRequest& message);
        UnsubscribeRequestRef(const UnsubscribeRequestRef& message);
        
        size_t getSize() const;
        
        const recsen::MessageInfo* info() const;
        
        recsen::fbe::MessageData& data();
        const recsen::fbe::MessageData& data() const;
        
        UnsubscribeRequestRef& operator=(const UnsubscribeRequest& message);
        UnsubscribeRequestRef& operator=(const UnsubscribeRequestConstRef& message);
        UnsubscribeRequestRef& operator=(const UnsubscribeRequestRef& message);
        
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const recsen::MessageInfo* info_;
        recsen::fbe::MessageData& data_;
    };
    
    class UnsubscribeRequestConstRef
    {
    public:
        
        UnsubscribeRequestConstRef(const recsen::MessageInfo* info, const recsen::fbe::MessageData& data);
        UnsubscribeRequestConstRef(const UnsubscribeRequest& message);
        UnsubscribeRequestConstRef(const UnsubscribeRequestRef& message);
        UnsubscribeRequestConstRef(const UnsubscribeRequestConstRef& message);
        
        size_t getSize() const;
        
        const recsen::MessageInfo* info() const;
        
        const recsen::fbe::MessageData& data() const;
        
        operator recsen::MessageConstRef() const;
        
        std::string toString() const;
        
    private:
        
        const recsen::MessageInfo* info_;
        const recsen::fbe::MessageData& data_;
    };
    
    template<> bool is<UnsubscribeRequestRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> bool is<UnsubscribeRequestConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    template<> UnsubscribeRequestRef cast<UnsubscribeRequestRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> UnsubscribeRequestConstRef cast<UnsubscribeRequestConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    class UnsubscribeAccept;
    class UnsubscribeAcceptRef;
    class UnsubscribeAcceptConstRef;
    
    class UnsubscribeAccept
    {
    public:
        
        UnsubscribeAccept();
        UnsubscribeAccept(const UnsubscribeAcceptRef& message);
        UnsubscribeAccept(const UnsubscribeAcceptConstRef& message);
        UnsubscribeAccept(const UnsubscribeAccept& message);
        
        size_t getSize() const;
        
        const recsen::MessageInfo* info() const;
        
        recsen::fbe::MessageData& data();
        const recsen::fbe::MessageData& data() const;
        
        UnsubscribeAccept& operator=(const UnsubscribeAcceptRef& message);
        UnsubscribeAccept& operator=(const UnsubscribeAcceptConstRef& message);
        UnsubscribeAccept& operator=(const UnsubscribeAccept& message);
        
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const recsen::MessageInfo* info_;
        recsen::fbe::MessageData data_;
    };
    
    class UnsubscribeAcceptRef
    {
    public:
        
        UnsubscribeAcceptRef(const recsen::MessageInfo* info, recsen::fbe::MessageData& data);
        UnsubscribeAcceptRef(UnsubscribeAccept& message);
        UnsubscribeAcceptRef(const UnsubscribeAcceptRef& message);
        
        size_t getSize() const;
        
        const recsen::MessageInfo* info() const;
        
        recsen::fbe::MessageData& data();
        const recsen::fbe::MessageData& data() const;
        
        UnsubscribeAcceptRef& operator=(const UnsubscribeAccept& message);
        UnsubscribeAcceptRef& operator=(const UnsubscribeAcceptConstRef& message);
        UnsubscribeAcceptRef& operator=(const UnsubscribeAcceptRef& message);
        
        operator recsen::MessageRef();
        operator recsen::MessageConstRef() const;
        
        void reset();
        
        std::string toString() const;
        
    private:
        
        const recsen::MessageInfo* info_;
        recsen::fbe::MessageData& data_;
    };
    
    class UnsubscribeAcceptConstRef
    {
    public:
        
        UnsubscribeAcceptConstRef(const recsen::MessageInfo* info, const recsen::fbe::MessageData& data);
        UnsubscribeAcceptConstRef(const UnsubscribeAccept& message);
        UnsubscribeAcceptConstRef(const UnsubscribeAcceptRef& message);
        UnsubscribeAcceptConstRef(const UnsubscribeAcceptConstRef& message);
        
        size_t getSize() const;
        
        const recsen::MessageInfo* info() const;
        
        const recsen::fbe::MessageData& data() const;
        
        operator recsen::MessageConstRef() const;
        
        std::string toString() const;
        
    private:
        
        const recsen::MessageInfo* info_;
        const recsen::fbe::MessageData& data_;
    };
    
    template<> bool is<UnsubscribeAcceptRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> bool is<UnsubscribeAcceptConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
    template<> UnsubscribeAcceptRef cast<UnsubscribeAcceptRef, recsen::MessageRef>(recsen::MessageRef message);
    template<> UnsubscribeAcceptConstRef cast<UnsubscribeAcceptConstRef, recsen::MessageConstRef>(recsen::MessageConstRef message);
    
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
    
    struct LoginPublicClientContext : ClientContext
    {
    };
    
    struct LoginPrivateClientContext : ClientContext
    {
    };
    
    struct SubscribeClientContext : ClientContext
    {
    };
    
    struct LogoutClientContext : ClientContext
    {
    };
    
    struct UnsubscribeClientContext : ClientContext
    {
    };
    
    struct LogoutClientContext : ClientContext
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
        
        void sendLoginPublic(LoginPublicClientContext* context, LoginPublicRequestRef message);
        
        void sendLoginPrivate(LoginPrivateClientContext* context, LoginPrivateRequestRef message);
        
        void sendSubscribe(SubscribeClientContext* context, SubscribeRequestRef message);
        
        void sendLogout(LogoutClientContext* context, LogoutRef message);
        
        void sendUnsubscribe(UnsubscribeClientContext* context, UnsubscribeRequestRef message);
        
        void sendLogout(LogoutClientContext* context, LogoutRef message);
        
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
        
        void virtual onPublicLoginAccept(ClientSession* session, LoginPublicClientContext* context, LoginAcceptConstRef message);
        
        void virtual onPublicLoginReject(ClientSession* session, LoginPublicClientContext* context, LoginRejectConstRef message);
        
        void virtual onPassword(ClientSession* session, LoginPrivateClientContext* context, PasswordRequestConstRef message);
        
        void virtual onPrivateLoginAccept(ClientSession* session, LoginPrivateClientContext* context, LoginAcceptConstRef message);
        
        void virtual onPrivateLoginReject(ClientSession* session, LoginPrivateClientContext* context, LoginRejectConstRef message);
        
        void virtual onLogout(ClientSession* session, LogoutConstRef message);
        
        void virtual onSubscribeAccept(ClientSession* session, SubscribeClientContext* context, SubscribeAcceptConstRef message);
        
        void virtual onSubscribeReject(ClientSession* session, SubscribeClientContext* context, SubscribeRejectConstRef message);
        
        void virtual onLogout(ClientSession* session, SubscribeClientContext* context, LogoutConstRef message);
        
        void virtual onSnapshot(ClientSession* session, SnapshotRefreshConstRef message);
        
        void virtual onLogout(ClientSession* session, LogoutConstRef message);
        
        void virtual onLogout(ClientSession* session, UnsubscribeClientContext* context, LogoutConstRef message);
        
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
        
        void virtual onLoginPublic(ServerSession* session, LoginPublicRequestConstRef message);
        
        void virtual onLoginPrivate(ServerSession* session, LoginPrivateRequestConstRef message);
        
        void virtual onPassword(ServerSession* session, PasswordResponseConstRef message);
        
        void virtual onSubscribe(ServerSession* session, SubscribeRequestConstRef message);
        
        void virtual onLogout(ServerSession* session, LogoutConstRef message);
        
        void virtual onUnsubscribe(ServerSession* session, UnsubscribeRequestConstRef message);
        
        void virtual onLogout(ServerSession* session, LogoutConstRef message);
        
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
