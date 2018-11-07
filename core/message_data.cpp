#include "message_data.h"

#include <string.h>

using namespace std;

namespace recsen::core
{
    message_data_t::message_data_t()
    {
      capacity_ = get_cappacity(0);
      data_ = (uint8_t*) malloc(capacity_);
      set_uint32(0, 8);
      set_uint32(4, 0);
    }

    message_data_t::message_data_t(size_t size)
    {
      capacity_ = get_cappacity(size);
      data_ = (uint8_t*) malloc(capacity_);
      set_uint32(0, (uint32_t) size);
      memset(data_ + 4, 0, size - 4);
    }

    message_data_t::message_data_t(const message_data_t& message_data)
    {
      capacity_ = message_data.capacity_;
      data_ = (uint8_t*) malloc(capacity_);
      memcpy(data_, message_data.data_, message_data.capacity_);
    }

    message_data_t::~message_data_t()
    {
      free(data_);
    }

    void message_data_t::set_bool(size_t offset, bool value)
    {
      if (offset + 1 > capacity_)
        throw runtime_error("Invalid field offset");

      *(uint8_t*) (data_ + offset) = value ? 1 : 0;
    }

    bool message_data_t::get_bool(size_t offset) const
    {
      if (offset + 1 > capacity_)
        throw runtime_error("Invalid field offset");

      return *(uint8_t*)(data_ + offset) != 0 ? true : false;
    }

    void message_data_t::set_bool_optional(size_t offset, optional<bool> value)
    {
      if (offset + 1 > capacity_)
        throw runtime_error("Invalid field offset");

      if (value.has_value())
      {
        *(uint8_t*) (data_ + offset) = value.value() ? 2 : 1;
      }
      else
        *(uint8_t*) (data_ + offset) = 0;
    }

    optional<bool> message_data_t::get_bool_optional(size_t offset) const
    {
      if (offset + 1 > capacity_)
        throw runtime_error("Invalid field offset");

      uint8_t data = *(uint8_t*) (data_ + offset);

      if (! data)
        return optional<bool>();

      return optional<bool>(data != 1 ? true : false);
    }

    void message_data_t::set_char(size_t offset, char value)
    {
      if (offset + 1 > capacity_)
        throw runtime_error("Invalid field offset");

      *(char*) (data_ + offset) = value;
    }

    char message_data_t::get_char(size_t offset) const
    {
      if (offset + 1 > capacity_)
        throw runtime_error("Invalid field offset");

      return *(char*) (data_ + offset);
    }

    void message_data_t::set_char_optional(size_t offset, optional<char> value)
    {
      if (offset + 1 > capacity_)
        throw runtime_error("Invalid field offset");

      if (value.has_value())
      {
        *(char*)(data_ + offset) = value.value() + 1;
      }
      else
        *(char*)(data_ + offset) = 0;
    }

    optional<char> message_data_t::get_char_optional(size_t offset) const
    {
      if (offset + 1 > capacity_)
        throw runtime_error("Invalid field offset");

      char data = *(char*) (data_ + offset);

      if (! data)
        return optional<char>();

      return optional<char>(data - 1);
    }

    void message_data_t::set_uchar(size_t offset, wchar_t value)
    {
      if (offset + 2 > capacity_)
        throw runtime_error("Invalid field offset");

      *(wchar_t*) (data_ + offset) = value;
    }

    wchar_t message_data_t::get_uchar(size_t offset) const
    {
      if (offset + 2 > capacity_)
        throw runtime_error("Invalid field offset");

      return *(wchar_t*) (data_ + offset);
    }

    void message_data_t::set_uchar_optional(size_t offset, optional<wchar_t> value)
    {
      if (offset + 2 > capacity_)
        throw runtime_error("Invalid field offset");

      if (value.has_value())
      {
        *(wchar_t*)(data_ + offset) = value.value() + 1;
      }
      else
        *(wchar_t*)(data_ + offset) = 0;
    }

    optional<wchar_t> message_data_t::get_uchar_optional(size_t offset) const
    {
      if (offset + 2 > capacity_)
        throw runtime_error("Invalid field offset");

      wchar_t data = *(wchar_t*) (data_ + offset);

      if (! data)
        return optional<wchar_t>();

      return optional<wchar_t>(data - 1);
    }

    void message_data_t::set_int8(size_t offset, int8_t value)
    {
      if (offset + 1 > capacity_)
        throw runtime_error("Invalid field offset");

      *(int8_t*) (data_ + offset) = value;
    }

    int8_t message_data_t::get_int8(size_t offset) const
    {
      if (offset + 1 > capacity_)
        throw runtime_error("Invalid field offset");

      return *(int8_t*) (data_ + offset);
    }

    void message_data_t::set_int8_optional(size_t offset, optional<int8_t> value)
    {
      if (offset + 1 > capacity_)
        throw runtime_error("Invalid field offset");

      if (value.has_value())
      {
        *(int8_t*) (data_ + offset) = value.value() + INT8_MIN;
      }
      else
        *(int8_t*) (data_ + offset) = 0;
    }

    optional<int8_t> message_data_t::get_int8_optional(size_t offset) const
    {
      if (offset + 1 > capacity_)
        throw runtime_error("Invalid field offset");

      int8_t data = *(int8_t*) (data_ + offset);

      if (! data)
        return optional<int8_t>();

      return optional<int8_t>(data - INT8_MIN);
    }

    void message_data_t::set_uint8(size_t offset, uint8_t value)
    {
      if (offset + 1 > capacity_)
        throw runtime_error("Invalid field offset");

      *(uint8_t*) (data_ + offset) = value;
    }

    uint8_t message_data_t::get_uint8(size_t offset) const
    {
      if (offset + 1 > capacity_)
        throw runtime_error("Invalid field offset");

      return *(uint8_t*) (data_ + offset);
    }

    void message_data_t::set_uint8_optional(size_t offset, optional<uint8_t> value)
    {
      if (offset + 1 > capacity_)
        throw runtime_error("Invalid field offset");

      if (value.has_value())
      {
        *(uint8_t*) (data_ + offset) = value.value() + 1;
      }
      else
        *(uint8_t*) (data_ + offset) = 0;
    }

    optional<uint8_t> message_data_t::get_uint8_optional(size_t offset) const
    {
      if (offset + 1 > capacity_)
        throw runtime_error("Invalid field offset");

      uint8_t data = *(uint8_t*) (data_ + offset);

      if (! data)
        return optional<uint8_t>();

      return optional<uint8_t>(data - 1);
    }

    void message_data_t::set_int16(size_t offset, int16_t value)
    {
      if (offset + 2 > capacity_)
        throw runtime_error("Invalid field offset");

      *(int16_t*) (data_ + offset) = value;
    }

    int16_t message_data_t::get_int16(size_t offset) const
    {
      if (offset + 2 > capacity_)
        throw runtime_error("Invalid field offset");

      return *(int16_t*) (data_ + offset);
    }

    void message_data_t::set_int16_optional(size_t offset, optional<int16_t> value)
    {
      if (offset + 2 > capacity_)
        throw runtime_error("Invalid field offset");

      if (value.has_value())
      {
        *(int16_t*) (data_ + offset) = value.value() + INT16_MIN;
      }
      else
        *(int16_t*) (data_ + offset) = 0;
    }

    optional<int16_t> message_data_t::get_int16_optional(size_t offset) const
    {
      if (offset + 2 > capacity_)
        throw runtime_error("Invalid field offset");

      int16_t data = *(int16_t*) (data_ + offset);

      if (! data)
        return optional<int16_t>();

      return optional<int16_t>(data - INT16_MIN);
    }

    void message_data_t::set_uint16(size_t offset, uint16_t value)
    {
      if (offset + 2 > capacity_)
        throw runtime_error("Invalid field offset");

      *(uint16_t*) (data_ + offset) = value;
    }

    uint16_t message_data_t::get_uint16(size_t offset) const
    {
      if (offset + 2 > capacity_)
        throw runtime_error("Invalid field offset");

      return *(uint16_t*) (data_ + offset);
    }

    void message_data_t::set_uint16_optional(size_t offset, optional<uint16_t> value)
    {
      if (offset + 2 > capacity_)
        throw runtime_error("Invalid field offset");

      if (value.has_value())
      {
        *(uint16_t*) (data_ + offset) = value.value() + 1;
      }
      else
        *(uint16_t*) (data_ + offset) = 0;
    }

    optional<uint16_t> message_data_t::get_uint16_optional(size_t offset) const
    {
      if (offset + 2 > capacity_)
        throw runtime_error("Invalid field offset");

      uint16_t data = *(uint16_t*) (data_ + offset);

      if (! data)
        return optional<uint16_t>();

      return optional<uint16_t>(data - 1);
    }
    
    void message_data_t::set_int32(size_t offset, int32_t value)
    {
      if (offset + 4 > capacity_)
        throw runtime_error("Invalid field offset");

      *(int32_t*) (data_ + offset) = value;
    }

    int32_t message_data_t::get_int32(size_t offset) const
    {
      if (offset + 4 > capacity_)
        throw runtime_error("Invalid field offset");

      return *(int32_t*) (data_ + offset);
    }

    void message_data_t::set_int32_optional(size_t offset, optional<int32_t> value)
    {
      if (offset + 4 > capacity_)
        throw runtime_error("Invalid field offset");

      if (value.has_value())
      {
        *(int32_t*) (data_ + offset) = value.value() + INT32_MIN;
      }
      else
        *(int32_t*) (data_ + offset) = 0;
    }

    optional<int32_t> message_data_t::get_int32_optional(size_t offset) const
    {
      if (offset + 4 > capacity_)
        throw runtime_error("Invalid field offset");

      int32_t data = *(int32_t*) (data_ + offset);

      if (! data)
        return optional<int32_t>();

      return optional<int32_t>(data - INT32_MIN);
    }

    void message_data_t::set_uint32(size_t offset, uint32_t value)
    {
      if (offset + 4 > capacity_)
        throw runtime_error("Invalid field offset");

      *(uint32_t*) (data_ + offset) = value;
    }

    uint32_t message_data_t::get_uint32(size_t offset) const
    {
      if (offset + 4 > capacity_)
        throw runtime_error("Invalid field offset");

      return *(uint32_t*) (data_ + offset);
    }

    void message_data_t::set_uint32_optional(size_t offset, optional<uint32_t> value)
    {
      if (offset + 4 > capacity_)
        throw runtime_error("Invalid field offset");

      if (value.has_value())
      {
        *(uint32_t*) (data_ + offset) = value.value() + 1;
      }
      else
        *(uint32_t*) (data_ + offset) = 0;
    }

    optional<uint32_t> message_data_t::get_uint32_optional(size_t offset) const
    {
      if (offset + 4 > capacity_)
        throw runtime_error("Invalid field offset");

      uint32_t data = *(uint32_t*) (data_ + offset);

      if (! data)
        return optional<uint32_t>();

      return optional<uint32_t>(data - 1);
    }
    
    void message_data_t::set_int64(size_t offset, int64_t value)
    {
      if (offset + 8 > capacity_)
        throw runtime_error("Invalid field offset");

      *(int64_t*) (data_ + offset) = value;
    }

    int64_t message_data_t::get_int64(size_t offset) const
    {
      if (offset + 8 > capacity_)
        throw runtime_error("Invalid field offset");

      return *(int64_t*) (data_ + offset);
    }

    void message_data_t::set_int64_optional(size_t offset, optional<int64_t> value)
    {
      if (offset + 8 > capacity_)
        throw runtime_error("Invalid field offset");

      if (value.has_value())
      {
        *(int64_t*) (data_ + offset) = value.value() + INT64_MIN;
      }
      else
        *(int64_t*) (data_ + offset) = 0;
    }

    optional<int64_t> message_data_t::get_int64_optional(size_t offset) const
    {
      if (offset + 8 > capacity_)
        throw runtime_error("Invalid field offset");

      int64_t data = *(int64_t*) (data_ + offset);

      if (! data)
        return optional<int64_t>();

      return optional<int64_t>(data - INT64_MIN);
    }

    void message_data_t::set_uint64(size_t offset, uint64_t value)
    {
      if (offset + 8 > capacity_)
        throw runtime_error("Invalid field offset");

      *(uint64_t*) (data_ + offset) = value;
    }

    uint64_t message_data_t::get_uint64(size_t offset) const
    {
      if (offset + 8 > capacity_)
        throw runtime_error("Invalid field offset");

      return *(uint64_t*) (data_ + offset);
    }

    void message_data_t::set_uint64_optional(size_t offset, optional<uint64_t> value)
    {
      if (offset + 8 > capacity_)
        throw runtime_error("Invalid field offset");

      if (value.has_value())
      {
        *(uint64_t*) (data_ + offset) = value.value() + 1;
      }
      else
        *(uint64_t*) (data_ + offset) = 0;
    }

    optional<uint64_t> message_data_t::get_uint64_optional(size_t offset) const
    {
      if (offset + 8 > capacity_)
        throw runtime_error("Invalid field offset");

      uint64_t data = *(uint64_t*) (data_ + offset);

      if (! data)
        return optional<uint64_t>();

      return optional<uint64_t>(data - 1);
    }

    void message_data_t::set_double(size_t offset, double value)
    {
      if (offset + 8 > capacity_)
        throw runtime_error("Invalid field offset");

      *(double*)(data_ + offset) = value;
    }

    double message_data_t::get_double(size_t offset) const
    {
      if (offset + 8 > capacity_)
        throw runtime_error("Invalid field offset");

      return *(double*)(data_ + offset);
    }

    void message_data_t::set_double_optional(size_t offset, optional<double> value)
    {
      if (offset + 8 > capacity_)
        throw runtime_error("Invalid field offset");

      if (value.has_value())
      {
        *(double*)(data_ + offset) = ~ *(uint64_t*) &value.value();
      }
      else
        *(double*)(data_ + offset) = 0;
    }

    optional<double> message_data_t::get_double_optional(size_t offset) const
    {
      if (offset + 8 > capacity_)
        throw runtime_error("Invalid field offset");

      uint64_t data = *(uint64_t*) (data_ + offset);

      if (! data)
        return optional<double>();

      data = ~ data;

      return optional<double>(*(double*) &data);
    }

    void message_data_t::set_timestamp(size_t offset, timestamp_t value)
    {
      if (offset + 8 > capacity_)
        throw runtime_error("Invalid field offset");

      uint64_t data = value.time_since_epoch().count();

      *(uint64_t*) (data_ + offset) = data;
    }

    timestamp_t message_data_t::get_timestamp(size_t offset) const
    {
      if (offset + 8 > capacity_)
        throw runtime_error("Invalid field offset");

      uint64_t data = *(uint64_t*) (data_ + offset);

      return timestamp_t(timestamp_t::duration(data));
    }

    void message_data_t::set_timestamp_optional(size_t offset, optional<timestamp_t> value)
    {
      if (offset + 8 > capacity_)
        throw runtime_error("Invalid field offset");

      if (value.has_value())
      {
        uint64_t data = value.value().time_since_epoch().count();

        *(uint64_t*) (data_ + offset) = data;
      }
      else
        *(uint64_t*) (data_ + offset) = 0;
    }

    optional<timestamp_t> message_data_t::get_timestamp_optional(size_t offset) const
    {
      if (offset + 8 > capacity_)
        throw runtime_error("Invalid field offset");

      uint64_t data = *(uint64_t *) (data_ + offset);

      if (! data)
        return optional<timestamp_t>();

      return optional<timestamp_t>(timestamp_t(timestamp_t::duration(data)));
    }

    size_t message_data_t::get_cappacity(size_t size)
    {
      return (size + 0xFF) & ~0xFF;
    }
}