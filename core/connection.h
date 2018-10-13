#pragma once

#include "common.h"

#include <stdlib.h>
#include <inttypes.h>
#include <string>

namespace recsen::core
{
    struct connection_options_t
    {
        inline connection_options_t();

        size_t send_buffer_size;
        size_t recv_buffer_size;
    };

    inline connection_options_t::connection_options_t():
        send_buffer_size(0),
        recv_buffer_size(0)
    {
    }

    struct connection_endpoint_t
    {
        std::string address;
        uint16_t port;
    };

    class connection_t
    {
        friend class selector_t;

    public:

        static const size_t WOULD_BLOCK = -1;
        static const size_t END_OF_FILE = -2;

        connection_t();

        ~connection_t();

        void disconnect();

        connection_endpoint_t get_local_endpoint();

        connection_endpoint_t get_remote_endpoint();

        size_t send(const uint8_t* buffer, size_t size);

        size_t recv(uint8_t* buffer, size_t size);

    protected:

        void set_options(int socket, const connection_options_t& options);

        connection_options_t options_;

        int socket_;
    };
}
