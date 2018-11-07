#include "ascii_encoding.h"

using namespace std;

namespace recsen::core
{
    size_t get_ascii_encode_size(const string& string)
    {
      return 0;
    }

    size_t get_ascii_decode_length(uint8_t* ascii_data, size_t ascii_size)
    {
      return 0;
    }

    void encode_ascii(uint8_t* ascii_data, size_t ascii_size, const string& string)
    {
    }

    void decode_ascii(string& string, const uint8_t* ascii_data, size_t ascii_size)
    {
    }
}