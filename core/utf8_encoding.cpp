#include "utf8_encoding.h"

#include <iconv.h>

#include <stdexcept>

using namespace std;

namespace recsen::core
{
    size_t get_utf8_encode_size(const wstring& string)
    {
      iconv_t ic = iconv_open("UTF-8", "WCHAR_T");

      if (ic == (iconv_t)-1)
        throw runtime_error("Could not convert to UTF8");

      char out_buf[4096];

      char* in_ptr = (char*)string.data();
      size_t in_size = string.size() * sizeof(wchar_t);
      char* out_ptr = (char*)out_buf;
      size_t out_size = sizeof(out_buf);
      size_t size = iconv(ic, &in_ptr, &in_size, &out_ptr, &out_size);

      if (size == (size_t)-1)
      {
        iconv_close(ic);

        throw runtime_error("Could not convert to UTF8");
      }

      iconv_close(ic);

      return out_ptr - out_buf;
    }

    size_t get_utf8_decode_length(uint8_t* utf8_data, size_t utf8_size)
    {
      iconv_t ic = iconv_open("WCHAR_T", "UTF-8");

      if (ic == (iconv_t)-1)
        throw runtime_error("Could not convert from UTF8");

      wchar_t out_buf[4096];

      char* in_ptr = (char*)utf8_data;
      size_t in_size = utf8_size;
      char* out_ptr = (char*)out_buf;
      size_t out_size = sizeof(out_buf);
      size_t size = iconv(ic, &in_ptr, &in_size, &out_ptr, &out_size);

      if (size == (size_t)-1)
      {
        iconv_close(ic);

        throw runtime_error("Could not convert from UTF8");
      }

      iconv_close(ic);

      return (wchar_t*)out_ptr - out_buf;
    }

    void encode_utf8(uint8_t* utf8_data, size_t utf8_size, const wstring& string)
    {
      iconv_t ic = iconv_open("UTF-8", "WCHAR_T");

      if (ic == (iconv_t)-1)
        throw runtime_error("Could not convert to UTF8");

      char* in_ptr = (char*)string.data();
      size_t in_size = string.size() * sizeof(wchar_t);
      char* out_ptr = (char*)utf8_data;
      size_t out_size = utf8_size;
      size_t size = iconv(ic, &in_ptr, &in_size, &out_ptr, &out_size);

      if (size == (size_t)-1)
      {
        iconv_close(ic);

        throw runtime_error("Could not convert to UTF8");
      }

      iconv_close(ic);
    }

    void decode_utf8(wstring& string, const uint8_t* utf8_data, size_t utf8_size)
    {
      iconv_t ic = iconv_open("WCHAR_T", "UTF-8");

      if (ic == (iconv_t)-1)
        throw runtime_error("Could not convert from UTF8");

      char* in_ptr = (char*)utf8_data;
      size_t in_size = utf8_size;
      char* out_ptr = (char*)string.data();
      size_t out_size = sizeof(wchar_t) * string.size();
      size_t size = iconv(ic, &in_ptr, &in_size, &out_ptr, &out_size);

      if (size == (size_t)-1)
      {
        iconv_close(ic);

        throw runtime_error("Could not convert from UTF8");
      }

      iconv_close(ic);
    }
}