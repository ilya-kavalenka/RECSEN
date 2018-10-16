#pragma once

#include <pthread.h>

namespace recsen::core
{
    class mutex_t
    {
    public:
        
        mutex_t();
        mutex_t(int);
        mutex_t(const mutex_t&) = delete;

        ~mutex_t();

        void open(int);

        void close();

        void lock();

        void unlock();

        mutex_t& operator=(const mutex_t&) = delete;

    private:

        friend class condition_t;

        bool opened_;
        pthread_mutex_t mutex_;
    };

    class mutex_lock_t
    {
    public:

        inline mutex_lock_t(mutex_t& mutex);
        mutex_lock_t(const mutex_lock_t&) = delete;

        inline ~mutex_lock_t();

        mutex_lock_t& operator=(const mutex_lock_t&) = delete;

    private:

        mutex_t& mutex_;
    };

    inline mutex_lock_t::mutex_lock_t(mutex_t& mutex) :
        mutex_(mutex)
    {
        mutex_.lock();
    }

    inline mutex_lock_t::~mutex_lock_t()
    {
        mutex_.unlock();
    }
}