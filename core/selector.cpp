#include "selector.h"

#include <stdexcept>

#include <unistd.h>

using namespace std;

namespace recsen::core
{
    selector_t::selector_t() :
        opened_(false)
    {
    }

    selector_t::selector_t(int size) :
        opened_(false)
    {
        open(size);
    }

    selector_t::~selector_t()
    {
        close();
    }

    void selector_t::open(int size)
    {
        if (opened_)
            throw runtime_error("Selector is already opened");

        epoll_ = epoll_create(size);

        if (epoll_ == -1)
          throw runtime_error("Could not create epoll instance");

        opened_ = true;
    }

    void selector_t::close()
    {
        if (opened_)
        {
            opened_ = false;

            ::close(epoll_);
            epoll_ = -1;
        }
    }

    void selector_t::add(connection_t* connection, events_t events)
    {
        epoll_event epoll_event;

        // note that we use the edge-triggered, one-shot mode
        epoll_event.events = EPOLLET | EPOLLONESHOT;
        if (events & WRITE_EVENT)
          epoll_event.events |= EPOLLOUT;
        if (events & READ_EVENT)
          epoll_event.events |= EPOLLIN;

        epoll_event.data.ptr = connection;

        int result = epoll_ctl(epoll_, EPOLL_CTL_ADD, connection->socket_, &epoll_event);

        if (result == -1)
          throw runtime_error("Could not add connection to epoll instance");
    }

    void selector_t::modify(connection_t* connection, events_t events)
    {
        epoll_event epoll_event;

        // note that we use the edge-triggered, one-shot mode
        epoll_event.events = EPOLLET | EPOLLONESHOT;
        if (events & WRITE_EVENT)
          epoll_event.events |= EPOLLOUT;
        if (events & READ_EVENT)
          epoll_event.events |= EPOLLIN;

        epoll_event.data.ptr = connection;

        int result = epoll_ctl(epoll_, EPOLL_CTL_MOD, connection->socket_, &epoll_event);

        if (result == -1)
          throw runtime_error("Could not modify connection in epoll instance");
    }

    void selector_t::remove(connection_t* connection)
    {
        epoll_ctl(epoll_, EPOLL_CTL_DEL, connection->socket_, NULL);
    }

    size_t selector_t::wait(event_info_t event_infos[EVENT_INFO_SIZE], uint32_t timeout)
    {
        // note that wait() must be thread-safe / can be called  from multiple threads
        epoll_event epoll_events[EVENT_INFO_SIZE];

        WAIT:

        int result = epoll_wait(epoll_, epoll_events, EVENT_INFO_SIZE, timeout);

        if (result == -1)
        {
            if (errno == EINTR)
                goto WAIT;

            throw runtime_error("Could not wait for epoll instance");
        }

        if (! result)
            return WAIT_TIMEOUT;

        for (size_t index = 0; index < result; ++ index)
        {
            event_info_t& event_info = event_infos[index];
            const epoll_event& epoll_event = epoll_events[index];

            event_info.events = 0;
            if (epoll_event.events & EPOLLOUT)
                event_info.events |= WRITE_EVENT;
            if (epoll_event.events & EPOLLIN)
                event_info.events |= READ_EVENT;
            if (epoll_event.events & EPOLLERR)
                event_info.events |= ERROR_EVENT;
            if (epoll_event.events & EPOLLHUP)
                event_info.events |= ERROR_EVENT;

            event_info.connection = (connection_t*) epoll_event.data.ptr;
        }

        return result;
    }
}