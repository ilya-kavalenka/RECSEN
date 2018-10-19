#pragma once

#include <string>

#include <pthread.h>

namespace recsen::core
{
    class thread_listener_t;

    typedef int (*thread_procedure_t)(void* args);

    class thread_t
    {
    public:

        static const int STATUS_ERROR = 1;
        static const int STATUS_SUCCESS = 0;
        static const int STATUS_UNKNOWN = -1;
        
        thread_t(const std::string& name);
        thread_t(const std::string& name, thread_procedure_t procedure, void* args);
        thread_t(const thread_t&) = delete;

        ~thread_t();

        std::string get_name() const;

        void set_listener(thread_listener_t* listener);

        thread_listener_t* get_listener() const;

        void run(thread_procedure_t procedure, void* args);

        int join();

        thread_t& operator=(const thread_t&) = delete;

    private:

        static void* procedure(void* args);

        void set_status(int status);

        std::string name_;
        thread_listener_t* listener_;

        thread_procedure_t procedure_;
        void* args_;
        int status_;

        bool running_;
        pthread_mutex_t mutex_;
        pthread_cond_t cond_;
        pthread_t thread_;
    };

    class thread_listener_t
    {
    public:

        virtual void on_begin(thread_t* thread) {}

        virtual void on_end(thread_t* thread) {}
    };
}
