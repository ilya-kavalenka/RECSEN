#include "message_info.h"

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
}
