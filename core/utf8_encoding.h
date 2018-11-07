#pragma once

#include "common.h"

#include <string>

namespace recsen::core
{
    size_t get_utf8_encode_size(const std::wstring& string);

    size_t get_utf8_decode_length(uint8_t* utf8_data, size_t utf8_size);

    void encode_utf8(uint8_t* utf8_data, size_t utf8_size, const std::wstring& string);

    void decode_utf8(std::wstring& string, const uint8_t* utf8_data, size_t utf8_size);
}