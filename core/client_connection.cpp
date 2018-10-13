#include "client_connection.h"

#include <stdexcept>

#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>

using namespace std;

namespace recsen::core
{
    client_connection_t::client_connection_t(const client_connection_options_t& options) :
        options_(options)
    {
    }

    bool client_connection_t::connect(const string& address, uint16_t port)
    {
        if (socket_ != -1)
            throw runtime_error("Connection is already connected");

        struct hostent* hostent = gethostbyname(address.c_str());

        if (hostent == NULL)
            throw runtime_error("Could not get IP address");

        if (hostent->h_addrtype != AF_INET)
            throw runtime_error("Could not get IP address");

        if (! hostent->h_addr_list[0])
            throw runtime_error("Could not get IP address");

        int socket = ::socket(AF_INET, SOCK_STREAM, 0);

        if (socket == -1)
            throw runtime_error("Could not create socket instance");

        try
        {
            CONNECT:

            sockaddr_in addr;
            addr.sin_family = AF_INET;
            addr.sin_addr.s_addr = *(in_addr_t*) hostent->h_addr_list[0];
            addr.sin_port = htons(port);

            int result = ::connect(socket, (const sockaddr*) &addr, sizeof(addr));

            if (result == -1)
            {
                if (errno == EINPROGRESS)
                    return false;

                if (errno == EINTR)
                    goto CONNECT;

                throw runtime_error("Could not connect socket");
            }

            socket_ = socket;

            return true;
        }
        catch (...)
        {
            close(socket);

            throw;
        }
    }
}