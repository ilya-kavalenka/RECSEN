#pragma once

#include "common.h"

#include <string>

namespace recsen::core
{
  size_t get_ascii_encode_size(const std::string& string);

  size_t get_ascii_decode_length(uint8_t* ascii_data, size_t ascii_size);

  void encode_ascii(uint8_t* ascii_data, size_t ascii_size, const std::string& string);

  void decode_ascii(std::string& string, const uint8_t* ascii_data, size_t ascii_size);
}