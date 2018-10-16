#include "mutex.h"

#include <stdexcept>

using namespace std;

namespace recsen::core
{
    mutex_t::mutex_t() :
        opened_(false)
    {
    }

    mutex_t::mutex_t(int) :
        opened_(false)
    {
        open(0);
    }

    mutex_t::~mutex_t()
    {
        close();
    }

    void mutex_t::open(int)
    {
        if (opened_)
            throw rutime_error("Mutex is already opened");

        int result = pthread_mutex_init(&mutex_, 0);

        if (result)
            throw runtime_error("Could not not create mutex instance");

        opened_ = true;        
    }

    void mutex_t::close()
    {
        if (opened_)
        {
            opened_ = false;

            pthread_mutex_destroy(&mutex_);
        }
    }

    void mutex_t::lock()
    {
        int result = pthread_mutex_lock(&mutex_);

        if (result)
            throw runtime_error("Could not lock mutex");
    }

    void mutex_t::unlock()
    {
        pthread_mutex_unlock(&mutex_);
    }        
}