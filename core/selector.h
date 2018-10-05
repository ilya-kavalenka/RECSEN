#pragma once

#include "connection.h"

namespace recsen::core
{
    class selector_t
    {
    public:

        typedef uint32_t events_t;

        static const events_t WRITE_EVENT = 0x01;        
        static const events_t READ_EVENT = 0x02;

        static const size_t TIMEOUT = 0;

        struct event_info_t
        {
            connection_t* connection;
            events_t events;
        };

        selector_t();

        ~selector_t();

        void open();

        void close();

        void add_connection(connection_t* connection, events_t events);

        void remove_connection(connection_t* connection);

        size_t wait(event_info_t* event_infos, size_t event_info_count, uint32_t timeout);

    private:

        
    };
}