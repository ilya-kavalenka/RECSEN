#include "utf8_encoding.h"

using namespace std;

namespace recsen::core
{
    size_t get_utf8_encode_size(const wstring& string)
    {
      return 0;
    }

    size_t get_utf8_decode_length(uint8_t* utf8_data, size_t utf8_size)
    {
      return 0;
    }

    void encode_utf8(uint8_t* utf8_data, size_t utf8_size, const wstring& string)
    {
    }

    void decode_utf8(wstring& string, const uint8_t* utf8_data, size_t utf8_size)
    {
    }
}