#pragma once

namespace recsen::core
{
    class thread_listener_t;

    class thread_t
    {
    public:

        typedef int (*handler_t)(void* args);

        thread_t(const string_t& name);

        ~thread_t();

        string_t get_name() const;

        void set_listener(thread_listener_t* listener);

        thread_listener_t* get_listener() const;

        void start(handler_t handler, void* args);

        int status() const;

        void join();

    protected:      

    };

    class thread_listener_t
    {
    public:

        virtual void on_begin(thread_t* thread) {}

        virtual void on_end(thread_t* thread) {}
    };
}
