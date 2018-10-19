#pragma once

#include <string>
#include <stdint.h>

namespace recsen::core
{
    void make_directory(const std::string& path);

    class file_t
    {
    public:

        static const size_t END_OF_FILE = -1;

        file_t();
        file_t(const std::string& path);
        file_t(const file_t&) = delete;

        ~file_t();

        void open(const std::string& path);

        void close();

        std::string get_path() const;

        size_t get_size() const;

        size_t write(const uint8_t* buffer, size_t size);

        size_t read(const uint8_t* buffer, size_t size);

        void seek(size_t offset);

        void flush();

        file_t& operator=(const file_t&) = delete;

    private:

        bool opened_;
        std::string path_;
        int file_;
    };
}
