#include "server_connection.h"

#include <stdexcept>

#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

using namespace std;

namespace recsen::core
{
    server_connection_t::server_connection_t(const server_connection_options_t& options) :
        options_(options)
    {
    }

    void server_connection_t::listen(const string& address, uint16_t port)
    {
        int socket = ::socket(AF_INET, SOCK_STREAM, 0);

        if (socket == -1)
            throw runtime_error("Could not create socket instance");

        try
        {
            set_options(socket, options_);

            sockaddr_in addr;
            addr.sin_family = AF_INET;
            addr.sin_addr.s_addr = address.size() ? inet_addr(address.c_str()) : INADDR_ANY;
            addr.sin_port = htons(port);

            int result = bind(socket, (const sockaddr *) &addr, sizeof(addr));

            if (result == -1)
                throw runtime_error("Could not bind socket");

            result = ::listen(socket, options_.listen_queue_size);

            if (result == -1)
                throw runtime_error("Could not listen socket");

            socket_ = socket;
        }
        catch (...)
        {
            close(socket);

            throw;
        }
    }

    bool server_connection_t::accept(server_connection_t& server_connection)
    {
        ACCEPT:

        int socket = ::accept(socket_, NULL, NULL);

        if (socket == -1)
        {
            if (errno == EWOULDBLOCK)
                return false;

            if (errno == EINTR)
                goto ACCEPT;

            throw runtime_error("Could not accept socket");
        }

        try
        {
            set_options(socket, server_connection.options_);

            server_connection.socket_ = socket;

            return true;
        }
        catch (...)
        {
            close(socket);

            throw;
        }
    }

    void server_connection_t::set_options(int socket, const server_connection_options_t& options)
    {
        connection_t::set_options(socket, options);

        if (options.reuse_address)
        {
            int value = 1;
            int result = setsockopt(socket, SOL_SOCKET, SO_REUSEADDR, &value, sizeof(value));

            if (result == -1)
                throw runtime_error("Could not set socket SO_REUSEADDR option");
        }
    }
}