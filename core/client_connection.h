#pragma once

#include "connection.h"

#include <string>

namespace recsen::core
{
    struct client_connection_options_t : connection_options_t
    {
        inline client_connection_options_t();
    };

    inline client_connection_options_t::client_connection_options_t()
    {
    }

    class client_connection_t : public connection_t
    {
    public:

        client_connection_t(const client_connection_options_t& options);

        bool connect(const std::string& address, uint16_t port);

    private:

        client_connection_options_t options_;
    };
}