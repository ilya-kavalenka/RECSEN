#include "connection.h"

#include <stdexcept>

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

using namespace std;

namespace recsen::core
{
    connection_t::connection_t() :
        socket_(-1)
    {
    }

    connection_t::~connection_t()
    {
        disconnect();
    }

    void connection_t::disconnect()
    {
        if (socket_ != -1)
        {
            close(socket_);
            socket_ = -1;
        }
    }

    connection_endpoint_t connection_t::get_local_endpoint()
    {
        sockaddr_in addr;
        addr.sin_family = AF_INET;
        socklen_t addrlen = sizeof(addr);

        int result = getsockname(socket_, (sockaddr*) &addr, &addrlen);

        if (result == -1)
          throw runtime_error("Could not get socket name");

        connection_endpoint_t endpoint;
        endpoint.address = inet_ntoa(addr.sin_addr);
        endpoint.port = ntohs(addr.sin_port);

        return endpoint;
    }

    connection_endpoint_t connection_t::get_remote_endpoint()
    {
        sockaddr_in addr;
        addr.sin_family = AF_INET;
        socklen_t addrlen = sizeof(addr);

        int result = getpeername(socket_, (sockaddr*) &addr, &addrlen);

        if (result == -1)
          throw runtime_error("Could not get peer name");

        connection_endpoint_t endpoint;
        endpoint.address = inet_ntoa(addr.sin_addr);
        endpoint.port = ntohs(addr.sin_port);

        return endpoint;
    }

    size_t connection_t::send(const uint8_t* buffer, size_t size)
    {
        SEND:

        ssize_t result = ::send(socket_, buffer, size, 0);

        if (result == -1)
        {
            if (errno == EWOULDBLOCK)
                return WOULD_BLOCK;

            if (errno == ECONNRESET)
                return END_OF_FILE;

            if (errno == EINTR)
                goto SEND;

            throw runtime_error("Could not send data to socket");
        }

        return result;
    }

    size_t connection_t::recv(uint8_t* buffer, size_t size)
    {
        RECV:

        ssize_t result = ::recv(socket_, buffer, size, 0);

        if (result == -1)
        {
            if (errno == EWOULDBLOCK)
                return WOULD_BLOCK;

            if (errno == ECONNRESET)
                return END_OF_FILE;

            if (errno == EINTR)
                goto RECV;

            throw runtime_error("Could not receive data from socket");
        }

        if (! result)
            return END_OF_FILE;

        return result;
    }

    void connection_t::set_options(int socket, const connection_options_t& options)
    {
        int value = 1;
        int result = setsockopt(socket, IPPROTO_TCP, TCP_NODELAY, &value, sizeof(value));

        if (result == -1)
            throw runtime_error("Could not set socket TCP_NODELAY option");

        int flags = fcntl(socket, F_GETFL);

        if (flags < 0)
            throw runtime_error("Could not set socket non-blocking mode");

        flags |= O_NONBLOCK;

        result = fcntl(socket, F_SETFL, flags);

        if (result == -1)
            throw runtime_error("Could not set socket non-blocking mode");

        if (options.send_buffer_size)
        {
            value = options.send_buffer_size;
            result = setsockopt(socket, SOL_SOCKET, SO_SNDBUF, &value, sizeof(value));

            if (result == -1)
                throw runtime_error("Could not set socket SO_SNDBUF option");
        }

        if (options.recv_buffer_size)
        {
            value = options.recv_buffer_size;
            result = setsockopt(socket, SOL_SOCKET, SO_RCVBUF, &value, sizeof(value));

            if (result == -1)
                throw runtime_error("Could not set socket SO_RCVBUF option");
        }
    }
}
