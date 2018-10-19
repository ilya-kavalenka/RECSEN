#include "file.h"

#include <stdexcept>

#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

using namespace std;

namespace recsen::core
{
    void make_directory(const string& path)
    {
        size_t pos = path.find('/', 0);

        while (pos != string::npos)
        {
            string_t name = path.substr(0, pos);

            int result = mkdir(name.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

            if (result == -1)
            {
                if (errno != EEXIST)
                    throw runtime_error(("Could not create directory : " + name).c_str());
            }

            pos = path.find('/', pos + 1);
        }

        int result = mkdir(path.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

        if (result == -1)
        {
            if (errno != EEXIST)
                throw runtime_error(("Could not create directory : " + path).c_str());
        }
    }

    file_t::file_t() :
        opened_(false)
    {
    }

    file_t::file_t(const string& path) :
        opened_(false)
    {
        open(path);
    }

    file_t::~file_t()
    {
        close();
    }

    void file_t::open(const string& path)
    {
        if (opened_)
            throw runtime_error("File is already opened");

        path_ = path;

        file_ = ::open(path.c_str(), O_CREAT | O_RDWR);

        if (file_ == -1)
            throw runtime_error("Could not open file: " + path);

        opened_ = true;
    }

    void file_t::close()
    {
        if (opened_)
        {
            opened_ = false;

            ::close(file_);
        }
    }

    string file_t::get_path() const
    {
        return path_;
    }

    size_t file_t::get_size() const
    {
        return 0;
    }

    size_t file_t::write(const uint8_t* buffer, size_t size)
    {
        WRITE:

        ssize_t result = ::write(file_, buffer, size);

        if (result == -1)
        {
            if (errno == EINTR)
                goto WRITE;

            throw runtime_error("Could not write to file");
        }

        return (size_t) result;
    }            

    size_t file_t::read(const uint8_t* buffer, size_t size)
    {
        READ:

        ssize_t result = ::read(file_, buffer, size);

        if (result == -1)
        {
            if (errno == EINTR)
                goto READ;

            throw runtime_error("Could not read from file");
        }

        if (! result)
            return END_OF_FILE;

        return (size_t) result;
    }

    void file_t::seek(size_t offset)
    {
        off_t result = lseek(file_, offset, SEEK_SET);

        if (result == -1)
            throw runtime_error("Could not seek file");
    }    

    void file_t::flush()
    {
        fsync(file_);
    }
}