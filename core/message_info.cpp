#include "message_info.h"

#include <sstream>

using namespace std;

namespace recsen::core
{
    bool is_message_info(const message_info_t* message_info1, const message_info_t* message_info2)
    {
      if (message_info2 == message_info1)
        return true;

      const message_info_t* super_message_info = message_info2->super_message;

      while (super_message_info)
      {
        if (super_message_info == message_info1)
          return true;
      }

      return false;
    }

    string get_enum_value_name(const enum_info_t& enum_info, uint8_t value)
    {
      for (size_t index = 0; index < enum_info.member_length; ++ index)
      {
        const enum_member_info_t& enum_member_info = enum_info.members[index];

        if (value == enum_member_info.value)
          return enum_member_info.name;
      }

      return to_string(value);
    }

    string get_set_value_name(const set_info_t& set_info, uint32_t value)
    {
      string name = "'";

      for (size_t index = 0; index < set_info.member_length; ++ index)
      {
        const set_member_info_t& set_member_info = set_info.members[index];

        if (value & (1 << set_member_info.value))
        {
          if (name.size())
            name += "|";

          name += set_member_info.name;
        }
      }

      name += "'";

      return name;
    }

    void write_field(const message_data_t& message_data, const field_info_t& field_info, const string& base_name, size_t base_offset, stringstream& ss)
    {
      switch (field_info.type)
      {
        case field_type_t::Bool:
        {
          if (field_info.array)
          {
            if (field_info.optional)
            {
              size_t length = message_data.get_array_length(base_offset + field_info.offset);

              for (size_t index = 0; index < length; ++ index)
              {
                size_t item_offset = message_data.get_array_item_offset(base_offset + field_info.offset, index, 1);
                optional<bool> value = message_data.get_bool_optional(item_offset);

                if (value.has_value())
                  ss << " " << base_name << field_info.name << "[" << index << "]=" << (value.value() ? "True" : "False");
              }
            }
            else
            {
              size_t length = message_data.get_array_length(base_offset + field_info.offset);

              for (size_t index = 0; index < length; ++ index)
              {
                size_t item_offset = message_data.get_array_item_offset(base_offset + field_info.offset, index, 1);
                bool value = message_data.get_bool(item_offset);

                ss << " " << base_name << field_info.name << "[" << index << "]=" << (value ? "True" : "False");
              }
            }
          }
          else
          {
            if (field_info.optional)
            {
              optional<bool> value = message_data.get_bool_optional(base_offset + field_info.offset);

              if (value.has_value())
                ss << " " << base_name << field_info.name << "=" << (value.value() ? "True" : "False");
            }
            else
            {
              bool value = message_data.get_bool(base_offset + field_info.offset);

              ss << " " << base_name << field_info.name << "=" << (value ? "True" : "False");
            }
          }

          break;
        }
        case field_type_t::Char:
        {
          if (field_info.array)
          {
            if (field_info.optional)
            {
              size_t length = message_data.get_array_length(base_offset + field_info.offset);

              for (size_t index = 0; index < length; ++ index)
              {
                size_t item_offset = message_data.get_array_item_offset(base_offset + field_info.offset, index, 1);
                optional<char> value = message_data.get_char_optional(item_offset);

                if (value.has_value())
                  ss << " " << base_name << field_info.name << "[" << index << "]=" << value.value();
              }
            }
            else
            {
              size_t length = message_data.get_array_length(base_offset + field_info.offset);

              for (size_t index = 0; index < length; ++ index)
              {
                size_t item_offset = message_data.get_array_item_offset(base_offset + field_info.offset, index, 1);
                char value = message_data.get_char(item_offset);

                ss << " " << base_name << field_info.name << "[" << index << "]=" << value;
              }
            }
          }
          else
          {
            if (field_info.optional)
            {
              optional<char> value = message_data.get_char_optional(base_offset + field_info.offset);

              if (value.has_value())
                ss << " " << base_name << field_info.name << "=" << value.value();
            }
            else
            {
              char value = message_data.get_char(base_offset + field_info.offset);

              ss << " " << base_name << field_info.name << "=" << value;
            }
          }

          break;
        }
        case field_type_t::UChar:
        {
          if (field_info.array)
          {
            if (field_info.optional)
            {
              size_t length = message_data.get_array_length(base_offset + field_info.offset);

              for (size_t index = 0; index < length; ++ index)
              {
                size_t item_offset = message_data.get_array_item_offset(base_offset + field_info.offset, index, 2);
                optional<wchar_t> value = message_data.get_uchar_optional(item_offset);

                if (value.has_value())
                  ss << " " << base_name << field_info.name << "[" << index << "]=" << value.value();
              }
            }
            else
            {
              size_t length = message_data.get_array_length(base_offset + field_info.offset);

              for (size_t index = 0; index < length; ++ index)
              {
                size_t item_offset = message_data.get_array_item_offset(base_offset + field_info.offset, index, 2);
                wchar_t value = message_data.get_uchar(item_offset);

                ss << " " << base_name << field_info.name << "[" << index << "]=" << value;
              }
            }
          }
          else
          {
            if (field_info.optional)
            {
              optional<wchar_t> value = message_data.get_uchar_optional(base_offset + field_info.offset);

              if (value.has_value())
                ss << " " << base_name << field_info.name << "=" << value.value();
            }
            else
            {
              wchar_t value = message_data.get_uchar(base_offset + field_info.offset);

              ss << " " << base_name << field_info.name << "=" << value;
            }
          }

          break;
        }
        case field_type_t::Int8:
        {
          if (field_info.array)
          {
            if (field_info.optional)
            {
              size_t length = message_data.get_array_length(base_offset + field_info.offset);

              for (size_t index = 0; index < length; ++ index)
              {
                size_t item_offset = message_data.get_array_item_offset(base_offset + field_info.offset, index, 1);
                optional<int8_t> value = message_data.get_int8_optional(item_offset);

                if (value.has_value())
                  ss << " " << base_name << field_info.name << "[" << index << "]=" << (int) value.value();
              }
            }
            else
            {
              size_t length = message_data.get_array_length(base_offset + field_info.offset);

              for (size_t index = 0; index < length; ++ index)
              {
                size_t item_offset = message_data.get_array_item_offset(base_offset + field_info.offset, index, 1);
                int8_t value = message_data.get_int8(item_offset);

                ss << " " << base_name << field_info.name << "[" << index << "]=" << (int) value;
              }
            }
          }
          else
          {
            if (field_info.optional)
            {
              optional<int8_t> value = message_data.get_int8_optional(base_offset + field_info.offset);

              if (value.has_value())
                ss << " " << base_name << field_info.name << "=" << (int) value.value();
            }
            else
            {
              int8_t value = message_data.get_int8(base_offset + field_info.offset);

              ss << " " << base_name << field_info.name << "=" << (int) value;
            }
          }

          break;
        }
        case field_type_t::UInt8:
        {
          if (field_info.array)
          {
            if (field_info.optional)
            {
              size_t length = message_data.get_array_length(base_offset + field_info.offset);

              for (size_t index = 0; index < length; ++ index)
              {
                size_t item_offset = message_data.get_array_item_offset(base_offset + field_info.offset, index, 1);
                optional<uint8_t> value = message_data.get_uint8_optional(item_offset);

                if (value.has_value())
                  ss << " " << base_name << field_info.name << "[" << index << "]=" << (unsigned int) value.value();
              }
            }
            else
            {
              size_t length = message_data.get_array_length(base_offset + field_info.offset);

              for (size_t index = 0; index < length; ++ index)
              {
                size_t item_offset = message_data.get_array_item_offset(base_offset + field_info.offset, index, 1);
                uint8_t value = message_data.get_uint8(item_offset);

                ss << " " << base_name << field_info.name << "[" << index << "]=" << (unsigned int) value;
              }
            }
          }
          else
          {
            if (field_info.optional)
            {
              optional<uint8_t> value = message_data.get_uint8_optional(base_offset + field_info.offset);

              if (value.has_value())
                ss << " " << base_name << field_info.name << "=" << (unsigned int) value.value();
            }
            else
            {
              uint8_t value = message_data.get_uint8(base_offset + field_info.offset);

              ss << " " << base_name << field_info.name << "=" << (unsigned int) value;
            }
          }

          break;
        }
        case field_type_t::Int16:
        {
          if (field_info.array)
          {
            if (field_info.optional)
            {
              size_t length = message_data.get_array_length(base_offset + field_info.offset);

              for (size_t index = 0; index < length; ++ index)
              {
                size_t item_offset = message_data.get_array_item_offset(base_offset + field_info.offset, index, 2);
                optional<int16_t> value = message_data.get_int16_optional(item_offset);

                if (value.has_value())
                  ss << " " << base_name << field_info.name << "[" << index << "]=" << (int) value.value();
              }
            }
            else
            {
              size_t length = message_data.get_array_length(base_offset + field_info.offset);

              for (size_t index = 0; index < length; ++ index)
              {
                size_t item_offset = message_data.get_array_item_offset(base_offset + field_info.offset, index, 2);
                int16_t value = message_data.get_int16(item_offset);

                ss << " " << base_name << field_info.name << "[" << index << "]=" << (int) value;
              }
            }
          }
          else
          {
            if (field_info.optional)
            {
              optional<int16_t> value = message_data.get_int16_optional(base_offset + field_info.offset);

              if (value.has_value())
                ss << " " << base_name << field_info.name << "=" << (int) value.value();
            }
            else
            {
              int16_t value = message_data.get_int16(base_offset + field_info.offset);

              ss << " " << base_name << field_info.name << "=" << (int) value;
            }
          }

          break;
        }
        case field_type_t::UInt16:
        {
          if (field_info.array)
          {
            if (field_info.optional)
            {
              size_t length = message_data.get_array_length(base_offset + field_info.offset);

              for (size_t index = 0; index < length; ++ index)
              {
                size_t item_offset = message_data.get_array_item_offset(base_offset + field_info.offset, index, 2);
                optional<uint16_t> value = message_data.get_uint16_optional(item_offset);

                if (value.has_value())
                  ss << " " << base_name << field_info.name << "[" << index << "]=" << (unsigned int) value.value();
              }
            }
            else
            {
              size_t length = message_data.get_array_length(base_offset + field_info.offset);

              for (size_t index = 0; index < length; ++ index)
              {
                size_t item_offset = message_data.get_array_item_offset(base_offset + field_info.offset, index, 2);
                uint16_t value = message_data.get_uint16(item_offset);

                ss << " " << base_name << field_info.name << "[" << index << "]=" << (unsigned int) value;
              }
            }
          }
          else
          {
            if (field_info.optional)
            {
              optional<uint16_t> value = message_data.get_uint16_optional(base_offset + field_info.offset);

              if (value.has_value())
                ss << " " << base_name << field_info.name << "=" << (unsigned int) value.value();
            }
            else
            {
              uint16_t value = message_data.get_uint16(base_offset + field_info.offset);

              ss << " " << base_name << field_info.name << "=" << (unsigned int) value;
            }
          }

          break;
        }
        case field_type_t::Int32:
        {
          if (field_info.array)
          {
            if (field_info.optional)
            {
              size_t length = message_data.get_array_length(base_offset + field_info.offset);

              for (size_t index = 0; index < length; ++ index)
              {
                size_t item_offset = message_data.get_array_item_offset(base_offset + field_info.offset, index, 4);
                optional<int32_t> value = message_data.get_int32_optional(item_offset);

                if (value.has_value())
                  ss << " " << base_name << field_info.name << "[" << index << "]=" << value.value();
              }
            }
            else
            {
              size_t length = message_data.get_array_length(base_offset + field_info.offset);

              for (size_t index = 0; index < length; ++ index)
              {
                size_t item_offset = message_data.get_array_item_offset(base_offset + field_info.offset, index, 4);
                int32_t value = message_data.get_int32(item_offset);

                ss << " " << base_name << field_info.name << "[" << index << "]=" << value;
              }
            }
          }
          else
          {
            if (field_info.optional)
            {
              optional<int32_t> value = message_data.get_int32_optional(base_offset + field_info.offset);

              if (value.has_value())
                ss << " " << base_name << field_info.name << "=" << value.value();
            }
            else
            {
              int32_t value = message_data.get_int32(base_offset + field_info.offset);

              ss << " " << base_name << field_info.name << "=" << value;
            }
          }

          break;
        }
        case field_type_t::UInt32:
        {
          if (field_info.array)
          {
            if (field_info.optional)
            {
              size_t length = message_data.get_array_length(base_offset + field_info.offset);

              for (size_t index = 0; index < length; ++ index)
              {
                size_t item_offset = message_data.get_array_item_offset(base_offset + field_info.offset, index, 4);
                optional<uint32_t> value = message_data.get_uint32_optional(item_offset);

                if (value.has_value())
                  ss << " " << base_name << field_info.name << "[" << index << "]=" << value.value();
              }
            }
            else
            {
              size_t length = message_data.get_array_length(base_offset + field_info.offset);

              for (size_t index = 0; index < length; ++ index)
              {
                size_t item_offset = message_data.get_array_item_offset(base_offset + field_info.offset, index, 4);
                uint32_t value = message_data.get_uint32(item_offset);

                ss << " " << base_name << field_info.name << "[" << index << "]=" << value;
              }
            }
          }
          else
          {
            if (field_info.optional)
            {
              optional<uint32_t> value = message_data.get_uint32_optional(base_offset + field_info.offset);

              if (value.has_value())
                ss << " " << base_name << field_info.name << "=" << value.value();
            }
            else
            {
              uint32_t value = message_data.get_uint32(base_offset + field_info.offset);

              ss << " " << base_name << field_info.name << "=" << value;
            }
          }

          break;
        }
        case field_type_t::Int64:
        {
          if (field_info.array)
          {
            if (field_info.optional)
            {
              size_t length = message_data.get_array_length(base_offset + field_info.offset);

              for (size_t index = 0; index < length; ++ index)
              {
                size_t item_offset = message_data.get_array_item_offset(base_offset + field_info.offset, index, 8);
                optional<int64_t> value = message_data.get_int64_optional(item_offset);

                if (value.has_value())
                  ss << " " << base_name << field_info.name << "[" << index << "]=" << value.value();
              }
            }
            else
            {
              size_t length = message_data.get_array_length(base_offset + field_info.offset);

              for (size_t index = 0; index < length; ++ index)
              {
                size_t item_offset = message_data.get_array_item_offset(base_offset + field_info.offset, index, 8);
                int64_t value = message_data.get_int64(item_offset);

                ss << " " << base_name << field_info.name << "[" << index << "]=" << value;
              }
            }
          }
          else
          {
            if (field_info.optional)
            {
              optional<int64_t> value = message_data.get_int64_optional(base_offset + field_info.offset);

              if (value.has_value())
                ss << " " << base_name << field_info.name << "=" << value.value();
            }
            else
            {
              int64_t value = message_data.get_int64(base_offset + field_info.offset);

              ss << " " << base_name << field_info.name << "=" << value;
            }
          }

          break;
        }
        case field_type_t::UInt64:
        {
          if (field_info.array)
          {
            if (field_info.optional)
            {
              size_t length = message_data.get_array_length(base_offset + field_info.offset);

              for (size_t index = 0; index < length; ++ index)
              {
                size_t item_offset = message_data.get_array_item_offset(base_offset + field_info.offset, index, 8);
                optional<uint64_t> value = message_data.get_uint64_optional(item_offset);

                if (value.has_value())
                  ss << " " << base_name << field_info.name << "[" << index << "]=" << value.value();
              }
            }
            else
            {
              size_t length = message_data.get_array_length(base_offset + field_info.offset);

              for (size_t index = 0; index < length; ++ index)
              {
                size_t item_offset = message_data.get_array_item_offset(base_offset + field_info.offset, index, 8);
                uint64_t value = message_data.get_uint64(item_offset);

                ss << " " << base_name << field_info.name << "[" << index << "]=" << value;
              }
            }
          }
          else
          {
            if (field_info.optional)
            {
              optional<uint64_t> value = message_data.get_uint64_optional(base_offset + field_info.offset);

              if (value.has_value())
                ss << " " << base_name << field_info.name << "=" << value.value();
            }
            else
            {
              uint64_t value = message_data.get_uint64(base_offset + field_info.offset);

              ss << " " << base_name << field_info.name << "=" << value;
            }
          }

          break;
        }
        case field_type_t::Double:
        {
          if (field_info.array)
          {
            if (field_info.optional)
            {
              size_t length = message_data.get_array_length(base_offset + field_info.offset);

              for (size_t index = 0; index < length; ++ index)
              {
                size_t item_offset = message_data.get_array_item_offset(base_offset + field_info.offset, index, 8);
                optional<double> value = message_data.get_double_optional(item_offset);

                if (value.has_value())
                  ss << " " << base_name << field_info.name << "[" << index << "]=" << value.value();
              }
            }
            else
            {
              size_t length = message_data.get_array_length(base_offset + field_info.offset);

              for (size_t index = 0; index < length; ++ index)
              {
                size_t item_offset = message_data.get_array_item_offset(base_offset + field_info.offset, index, 8);
                double value = message_data.get_double(item_offset);

                ss << " " << base_name << field_info.name << "[" << index << "]=" << value;
              }
            }
          }
          else
          {
            if (field_info.optional)
            {
              optional<double> value = message_data.get_double_optional(base_offset + field_info.offset);

              if (value.has_value())
                ss << " " << base_name << field_info.name << "=" << value.value();
            }
            else
            {
              double value = message_data.get_double(base_offset + field_info.offset);

              ss << " " << base_name << field_info.name << "=" << value;
            }
          }

          break;
        }
        case field_type_t::Timestamp:
        {
          if (field_info.array)
          {
            if (field_info.optional)
            {
              size_t length = message_data.get_array_length(base_offset + field_info.offset);

              for (size_t index = 0; index < length; ++ index)
              {
                size_t item_offset = message_data.get_array_item_offset(base_offset + field_info.offset, index, 8);
                optional<timestamp_t> value = message_data.get_timestamp_optional(item_offset);

                if (value.has_value())
                  ss << " " << base_name << field_info.name << "[" << index << "]=" << value.value().time_since_epoch().count();
              }
            }
            else
            {
              size_t length = message_data.get_array_length(base_offset + field_info.offset);

              for (size_t index = 0; index < length; ++ index)
              {
                size_t item_offset = message_data.get_array_item_offset(base_offset + field_info.offset, index, 8);
                timestamp_t value = message_data.get_timestamp(item_offset);

                ss << " " << base_name << field_info.name << "[" << index << "]=" << value.time_since_epoch().count();
              }
            }
          }
          else
          {
            if (field_info.optional)
            {
              optional<timestamp_t> value = message_data.get_timestamp_optional(base_offset + field_info.offset);

              if (value.has_value())
                ss << " " << base_name << field_info.name << "=" << value.value().time_since_epoch().count();
            }
            else
            {
              timestamp_t value = message_data.get_timestamp(base_offset + field_info.offset);

              ss << " " << base_name << field_info.name << "=" << value.time_since_epoch().count();
            }
          }

          break;
        }
        case field_type_t::String:
        {
          if (field_info.array)
          {
            if (field_info.optional)
            {
              size_t length = message_data.get_array_length(base_offset + field_info.offset);

              for (size_t index = 0; index < length; ++ index)
              {
                size_t item_offset = message_data.get_array_item_offset(base_offset + field_info.offset, index, 8);
                optional<string> value = message_data.get_string_optional(item_offset);

                if (value.has_value())
                  ss << " " << base_name << field_info.name << "[" << index << "]=\"" << value.value() << "\"";
              }
            }
            else
            {
              size_t length = message_data.get_array_length(base_offset + field_info.offset);

              for (size_t index = 0; index < length; ++ index)
              {
                size_t item_offset = message_data.get_array_item_offset(base_offset + field_info.offset, index, 8);
                string value = message_data.get_string(item_offset);

                ss << " " << base_name << field_info.name << "[" << index << "]=\"" << value << "\"";
              }
            }
          }
          else
          {
            if (field_info.optional)
            {
              optional<string> value = message_data.get_string_optional(base_offset + field_info.offset);

              if (value.has_value())
                ss << " " << base_name << field_info.name << "=\"" << value.value() << "\"";
            }
            else
            {
              string value = message_data.get_string(base_offset + field_info.offset);

              ss << " " << base_name << field_info.name << "=\"" << value << "\"";
            }
          }

          break;
        }
        case field_type_t::UString:
        {
          if (field_info.array)
          {
            if (field_info.optional)
            {
              size_t length = message_data.get_array_length(base_offset + field_info.offset);

              for (size_t index = 0; index < length; ++ index)
              {
                size_t item_offset = message_data.get_array_item_offset(base_offset + field_info.offset, index, 8);
                optional<string> value = message_data.get_string_optional(item_offset);

                if (value.has_value())
                  ss << " " << base_name << field_info.name << "[" << index << "]=\"" << value.value() << "\"";
              }
            }
            else
            {
              size_t length = message_data.get_array_length(base_offset + field_info.offset);

              for (size_t index = 0; index < length; ++ index)
              {
                size_t item_offset = message_data.get_array_item_offset(base_offset + field_info.offset, index, 8);
                string value = message_data.get_string(item_offset);

                ss << " " << base_name << field_info.name << "[" << index << "]=\"" << value << "\"";
              }
            }
          }
          else
          {
            if (field_info.optional)
            {
              optional<string> value = message_data.get_string_optional(base_offset + field_info.offset);

              if (value.has_value())
                ss << " " << base_name << field_info.name << "=\"" << value.value() << "\"";
            }
            else
            {
              string value = message_data.get_string(base_offset + field_info.offset);

              ss << " " << base_name << field_info.name << "=\"" << value << "\"";
            }
          }

          break;
        }
        case field_type_t::Bytes:
        {
          if (field_info.array)
          {
            if (field_info.optional)
            {
              size_t length = message_data.get_array_length(base_offset + field_info.offset);

              for (size_t index = 0; index < length; ++ index)
              {
                size_t item_offset = message_data.get_array_item_offset(base_offset + field_info.offset, index, 8);
                optional<size_t> value = message_data.get_bytes_size_optional(item_offset);

                if (value.has_value())
                  ss << " " << base_name << field_info.name << "[" << index << "]=[" << value.value() << "]";
              }
            }
            else
            {
              size_t length = message_data.get_array_length(base_offset + field_info.offset);

              for (size_t index = 0; index < length; ++ index)
              {
                size_t item_offset = message_data.get_array_item_offset(base_offset + field_info.offset, index, 8);
                size_t value = message_data.get_bytes_size(item_offset);

                ss << " " << base_name << field_info.name << "[" << index << "]=[" << value << "]";
              }
            }
          }
          else
          {
            if (field_info.optional)
            {
              optional<size_t> value = message_data.get_bytes_size_optional(base_offset + field_info.offset);

              if (value.has_value())
                ss << " " << base_name << field_info.name << "=[" << value.value() << "]";
            }
            else
            {
              size_t value = message_data.get_bytes_size(base_offset + field_info.offset);

              ss << " " << base_name << field_info.name << "=[" << value << "]";
            }
          }

          break;
        }
        case field_type_t::Enum:
        {
          if (field_info.array)
          {
            if (field_info.optional)
            {
              size_t length = message_data.get_array_length(base_offset + field_info.offset);

              for (size_t index = 0; index < length; ++ index)
              {
                size_t item_offset = message_data.get_array_item_offset(base_offset + field_info.offset, index, 4);
                optional<uint32_t> value = message_data.get_uint32_optional(item_offset);

                if (value.has_value())
                {
                  string name = get_enum_value_name(*field_info._enum, value.value());
                  ss << " " << base_name << field_info.name << "[" << index << "]=" << name;
                }
              }
            }
            else
            {
              size_t length = message_data.get_array_length(base_offset + field_info.offset);

              for (size_t index = 0; index < length; ++ index)
              {
                size_t item_offset = message_data.get_array_item_offset(base_offset + field_info.offset, index, 4);
                uint32_t value = message_data.get_uint32(item_offset);
                string name = get_enum_value_name(*field_info._enum, value);

                ss << " " << base_name << field_info.name << "[" << index << "]=" << name;
              }
            }
          }
          else
          {
            if (field_info.optional)
            {
              optional<uint32_t> value = message_data.get_uint32_optional(base_offset + field_info.offset);

              if (value.has_value())
              {
                string name = get_enum_value_name(*field_info._enum, value.value());
                ss << " " << base_name << field_info.name << "=" << name;
              }
            }
            else
            {
              uint32_t value = message_data.get_uint32(base_offset + field_info.offset);
              string name = get_enum_value_name(*field_info._enum, value);

              ss << " " << base_name << field_info.name << "=" << name;
            }
          }

          break;
        }
        case field_type_t::Set:
        {
          if (field_info.array)
          {
            if (field_info.optional)
            {
              size_t length = message_data.get_array_length(base_offset + field_info.offset);

              for (size_t index = 0; index < length; ++ index)
              {
                size_t item_offset = message_data.get_array_item_offset(base_offset + field_info.offset, index, 4);
                optional<uint32_t> value = message_data.get_uint32_optional(item_offset);

                if (value.has_value())
                {
                  string name = get_set_value_name(*field_info.set, value.value());
                  ss << " " << base_name << field_info.name << "[" << index << "]=" << name;
                }
              }
            }
            else
            {
              size_t length = message_data.get_array_length(base_offset + field_info.offset);

              for (size_t index = 0; index < length; ++ index)
              {
                size_t item_offset = message_data.get_array_item_offset(base_offset + field_info.offset, index, 4);
                uint32_t value = message_data.get_uint32(item_offset);
                string name = get_set_value_name(*field_info.set, value);

                ss << " " << base_name << field_info.name << "[" << index << "]=" << name;
              }
            }
          }
          else
          {
            if (field_info.optional)
            {
              optional<uint32_t> value = message_data.get_uint32_optional(base_offset + field_info.offset);

              if (value.has_value())
              {
                string name = get_set_value_name(*field_info.set, value.value());
                ss << " " << base_name << field_info.name << "=" << name;
              }
            }
            else
            {
              uint32_t value = message_data.get_uint32(base_offset + field_info.offset);
              string name = get_set_value_name(*field_info.set, value);

              ss << " " << base_name << field_info.name << "=" << name;
            }
          }

          break;
        }
        case field_type_t::Group:
        {
          if (field_info.array)
          {
            if (field_info.optional)
            {
              size_t length = message_data.get_array_length(base_offset + field_info.offset);

              for (size_t index = 0; index < length; ++ index)
              {
                size_t item_offset = message_data.get_array_item_offset(base_offset + field_info.offset, index, 4);
                uint32_t data_offset = message_data.get_uint32(item_offset);

                if (data_offset)
                {
                  string item_name = base_name + field_info.name + "[" + to_string(index) + "].";

                  for (size_t index = 0; index < field_info.group->field_length; ++ index)
                  {
                    const field_info_t& child_field_info = field_info.group->fields[index];

                    write_field(message_data, child_field_info, item_name, data_offset, ss);
                  }
                }
              }
            }
            else
            {
              size_t length = message_data.get_array_length(base_offset + field_info.offset);

              for (size_t index = 0; index < length; ++ index)
              {
                size_t item_offset = message_data.get_array_item_offset(base_offset + field_info.offset, index, field_info.group->size);
                string item_name = base_name + field_info.name + "[" + to_string(index) + "].";

                for (size_t index = 0; index < field_info.group->field_length; ++ index)
                {
                  const field_info_t& child_field_info = field_info.group->fields[index];

                  write_field(message_data, child_field_info, item_name, item_offset, ss);
                }
              }
            }
          }
          else
          {
            if (field_info.optional)
            {
              size_t item_offset = base_offset + field_info.offset;
              uint32_t data_offset = message_data.get_uint32(item_offset);

              if (data_offset)
              {
                string item_name = base_name + field_info.name + ".";

                for (size_t index = 0; index < field_info.group->field_length; ++ index)
                {
                  const field_info_t& child_field_info = field_info.group->fields[index];

                  write_field(message_data, child_field_info, item_name, data_offset, ss);
                }
              }
            }
            else
            {
              size_t item_offset = base_offset + field_info.offset;
              string item_name = base_name + field_info.name + ".";

              for (size_t index = 0; index < field_info.group->field_length; ++ index)
              {
                const field_info_t& child_field_info = field_info.group->fields[index];

                write_field(message_data, child_field_info, item_name, item_offset, ss);
              }
            }
          }

          break;
        }
      }
    }

    string get_message_string(const message_info_t& messag_info, const message_data_t& message_data)
    {
      stringstream ss;
      ss << messag_info.name << " : ";

      for (size_t index = 0; index < messag_info.field_length; ++ index)
      {
        const field_info_t& field_info = messag_info.fields[index];

        write_field(message_data, field_info, "", 0, ss);
      }

      return ss.str();
    }
}
