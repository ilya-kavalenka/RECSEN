#include "ascii_encoding.h"

#include <string.h>

using namespace std;

namespace recsen::core
{
    size_t get_ascii_encode_size(const string& string)
    {
      return string.size();
    }

    size_t get_ascii_decode_length(uint8_t* ascii_data, size_t ascii_size)
    {
      return ascii_size;
    }

    void encode_ascii(uint8_t* ascii_data, size_t ascii_size, const string& string)
    {
      memcpy(ascii_data, string.data(), ascii_size);
    }

    void decode_ascii(string& string, const uint8_t* ascii_data, size_t ascii_size)
    {
      memcpy(string.data(), ascii_data, string.size());
    }
}