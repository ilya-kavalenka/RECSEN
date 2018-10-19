#pragma once

#include "mutex.h"

#include <pthread.h>

namespace recsen::core
{
    class condition_t
    {
    public:

        condition_t();
        condition_t(int);
        condition_t(const condition_t&) = delete;

        ~condition_t();

        void open(int);

        void close();

        void signal();

        void broadcast();

        bool wait(mutex_t& mutex, int timeout);

        condition_t& operator=(const condition_t&) = delete;

    private:

        bool opened_;
        pthread_cond_t cond_;       
    };
}
