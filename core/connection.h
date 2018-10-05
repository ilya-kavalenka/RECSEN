#pragma once

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

    class connection_t
    {
    public:

        static const size_t WOULD_BLOCK = -1;
        static const size_t END_OF_FILE = -2;

        connection_t(const connection_options_t& options);

        ~connection_t();

        void disconnect();

        size_t send(const uint8_t* buffer, size_t size);

        size_t recv(uint8_t* buffer, size_t size);

    protected:      

    };
}
