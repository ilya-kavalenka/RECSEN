#pragma once

#include "connection.h"

#include <string>

namespace recsen::core
{
    struct server_connection_options_t : connection_options_t
    {
        inline server_connection_options_t();

        bool reuse_address;
        size_t listen_queue_size;
    };

    inline server_connection_options_t::server_connection_options_t() :
        reuse_address(true),
        listen_queue_size(100)
    {
    }

    class server_connection_t : public connection_t
    {
    public:

        server_connection_t(const server_connection_options_t& options);
        server_connection_t(const server_connection_t&) = delete;

        void listen(const std::string& address, uint16_t port);

        bool accept(server_connection_t& server_connection);

        server_connection_t& operator=(const server_connection_t&) = delete;

    private:

        void set_options(int socket, const server_connection_options_t& options);

        server_connection_options_t options_;
    };
}