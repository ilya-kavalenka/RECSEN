#pragma once

#include <stdlib.h>
#include <inttypes.h>
#include <chrono>

namespace recsen::core
{
    typedef std::chrono::time_point<std::chrono::system_clock, std::chrono::microseconds> timestamp_t;

    void sleep(uint32_t timeout);
}