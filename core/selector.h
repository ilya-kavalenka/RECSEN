#pragma once

#include "connection.h"
#include "common.h"

#include <stdlib.h>
#include <inttypes.h>

#include <sys/epoll.h>

namespace recsen::core
{
    class selector_t
    {
    public:

        typedef uint32_t events_t;

        struct event_info_t
        {
            connection_t* connection;
            events_t events;
        };

        static const size_t EVENT_INFO_SIZE = 1024;

        static const events_t WRITE_EVENT = 0x01;
        static const events_t READ_EVENT = 0x02;
        static const events_t ERROR_EVENT = 0x04;

        static const size_t WAIT_TIMEOUT = 0;

        selector_t();
        selector_t(int size);
        selector_t(const selector_t&) = delete;

        ~selector_t();

        void open(int size);

        void close();

        void add(connection_t* connection, events_t events);

        void modify(connection_t* connection, events_t events);

        void remove(connection_t* connection);

        size_t wait(event_info_t event_infos[EVENT_INFO_SIZE], uint32_t timeout);

        selector_t& operator=(const selector_t&) = delete;

    private:

        int epoll_;
        epoll_event epoll_events_[EVENT_INFO_SIZE];
    };
}