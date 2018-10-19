#include "thread.h"

#include <stdexcept>

using namespace std;

namespace recsen::core
{
    thread_t::thread_t(const string& name):
        name_(name),
        running_(false)
    {
    }

    thread_t::thread_t(const string& name, thread_procedure_t procedure, void* args) :
        name_(name),
        running_(false)
    {
        run(procedure, args);
    }

    thread_t::~thread_t()
    {
        if (running_)
        {
            running_ = false;

            void* retval;
            pthread_join(thread_, &retval);
            pthread_cond_destroy(&cond_);
            pthread_mutex_destroy(&mutex_);
        }
    }

    string thread_t::get_name() const
    {
        return name_;
    }

    void thread_t::set_listener(thread_listener_t* listener)
    {
        if (running_)
            throw runtime_error("Thread is running");

        listener_ = listener;
    }

    thread_listener_t* thread_t::get_listener() const
    {
        return listener_;
    }

    void thread_t::run(thread_procedure_t procedure, void* args)
    {
        if (running_)
        {
            running_ = false;

            void* retval;
            pthread_join(thread_, &retval);
            pthread_cond_destroy(&cond_);
            pthread_mutex_destroy(&mutex_);
        }

        procedure_ = procedure;
        args_ = args;
        status_ = STATUS_UNKNOWN;

        int result = pthread_mutex_init(&mutex_, 0);

        if (result)
            throw runtime_error("Could not create mutex instance");

        try
        {
            result = pthread_cond_init(&cond_, 0);

            if (result)
                throw runtime_error("Could not create condition instance");

            try
            {       
                result = pthread_create(&thread_, 0, thread_t::procedure, this);

                if (result)
                    throw runtime_error("Could not create thread instance");

                running_ = true;
            }
            catch (...)
            {
                pthread_cond_destroy(&cond_);

                throw;
            }
        }
        catch (...)
        {
            pthread_mutex_destroy(&mutex_);

            throw;
        }
    }

    int thread_t::join()
    {
        int status;
    
        if (running_)
        {
            int result = pthread_mutex_lock(&mutex_);

            if (result)
                throw runtime_error("Could not lock mutex");

            while (status_ == STATUS_UNKNOWN)
            {
                result = pthread_cond_wait(&cond_, &mutex_);

                if (result)
                {
                    pthread_mutex_unlock(&mutex_);

                    throw runtime_error("Could not wait for condition");
                }
            }

            status = status_;
            
            pthread_mutex_unlock(&mutex_);
        }
        else
            status = STATUS_UNKNOWN;

        return status;
    }

    void* thread_t::procedure(void* args)
    {
        try
        {
            thread_t* thread = (thread_t*) args;

            try
            {
                if (thread->listener_)
                {
                    try
                    {
                        thread->listener_->on_begin(thread);
                    }
                    catch (...)
                    {
                    }
                }

                int status = thread->procedure_(thread->args_);

                if (thread->listener_)
                {
                    try
                    {
                        thread->listener_->on_end(thread);
                    }
                    catch (...)
                    {
                    }
                }

                thread->set_status(status);

                return NULL;
            }
            catch (...)
            {
                thread->set_status(STATUS_ERROR);

                throw;
            }
        }
        catch (...)
        {
            return NULL;
        }
    }

    void thread_t::set_status(int status)
    {
        int result = pthread_mutex_lock(&mutex_);

        if (result)
            throw runtime_error("Could not lock mutex");

        status_ = status;

        result = pthread_cond_broadcast(&cond_);

        if (result)
        {
            pthread_mutex_unlock(&mutex_);

            return;
        }

        pthread_mutex_unlock(&mutex_);
    }
}

