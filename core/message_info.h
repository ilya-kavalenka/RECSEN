#pragma once

#include "common.h"
#include "message_data.h"

#include <string>

namespace recsen::core
{
    struct enum_member_info_t;
    struct enum_info_t;
    struct set_member_info_t;
    struct set_info_t;
    struct field_info_t;

    enum class field_type_t
    {
        Bool,
        Char,
        UChar,
        Int8,
        UInt8,
        Int16,
        UInt16,
        Int32,
        UInt32,
        Int64,
        UInt64,
        Double,
        Timestamp,
        String,
        UString,
        Bytes,
        Enum,
        Set,
        Group
    };

    struct enum_member_info_t
    {
        const char* name;
        uint8_t value;
    };

    struct enum_info_t
    {
        const char* name;
        size_t member_length;
        const enum_member_info_t* members;
    };

    struct set_member_info_t
    {
        const char* name;
        uint8_t value;
    };

    struct set_info_t
    {
        const char* name;
        size_t member_length;
        const set_member_info_t* members;
    };

    struct group_info_t
    {
        const char* name;
        size_t size;
        size_t field_length;
        const field_info_t* fields;
    };

    struct field_info_t
    {
        const char* name;
        size_t offset;
        field_type_t type;
        bool optional;
        bool array;
        const enum_info_t* _enum;
        const set_info_t* set;
        const group_info_t* group;
    };

    struct message_info_t
    {
        const message_info_t* super_message;
        const char* name;
        uint8_t id;
        size_t size;
        size_t field_length;
        const field_info_t* fields;
    };

    // returns true if message_info2 is derived from message_info1 or the same
    bool is_message_info(const message_info_t* message_info1, const message_info_t* message_info2);

    std::string get_message_string(const message_info_t& message_info, const message_data_t& message_data);
}
