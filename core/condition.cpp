#include "condition.h"

#include <stdexcept>

#include <time.h>
#include <errno.h>

using namespace std;

namespace recsen::core
{
    condition_t::condition_t() :
        opened_(false)
    {
    }

    condition_t::condition_t(int) :
        opened_(false)
    {
        open(0);
    }

    condition_t::~condition_t()
    {
        close();
    }

    void condition_t::open(int)
    {
        if (opened_)
            throw runtime_error("Condition is already opened");

        int result = pthread_cond_init(&cond_, 0);

        if (result)
            throw runtime_error("Could not create condition instance");

        opened_ = true;        
    }

    void condition_t::close()
    {
        if (opened_)
        {
            opened_ = false;

            pthread_cond_destroy(&cond_);
        }
    }    

    void condition_t::signal()
    {
        int result = pthread_cond_signal(&cond_);

        if (result)
            throw runtime_error("Could not signal condition");
    }

    void condition_t::broadcast()
    {
        int result = pthread_cond_broadcast(&cond_);

        if (result)
            throw runtime_error("Could not broadcast condition");
    }

    bool condition_t::wait(mutex_t& mutex, int timeout)
    {
        if (timeout != -1)
        {
            timespec ts;
            clock_gettime(CLOCK_REALTIME, &ts);

            ts.tv_sec += timeout / 1000;
            ts.tv_nsec += (timeout % 1000) * 1000000;

            if (ts.tv_nsec >= 1000000000)
            {
                ts.tv_sec += 1;
                ts.tv_nsec -= 1000000000;
            }

            int result = pthread_cond_timedwait(&cond_, &mutex.mutex_, &ts);

            if (result)
            {
                if (result == ETIMEDOUT)
                    return false;
    
                throw runtime_error("Could not wait for condition");
            }           
        }
        else
        {
            int result = pthread_cond_wait(&cond_, &mutex.mutex_);

            if (result)
                throw runtime_error("Could not wait for condition");
        }

        return true;
    }    
}