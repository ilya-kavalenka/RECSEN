#pragma once

#include "common.h"

#include <sstream>
#include <string>
#include <optional>

namespace recsen::core
{
    class message_data_t
    {
    public:

        message_data_t();
        message_data_t(size_t size);
        message_data_t(const message_data_t& message_data);

        ~message_data_t();

        void set_bool(size_t offset, bool value);

        bool get_bool(size_t offset) const;

        void set_bool_optional(size_t offset, std::optional<bool> value);

        std::optional<bool> get_bool_optional(size_t offset) const;

        void set_char(size_t offset, char value);

        char get_char(size_t offset) const;

        void set_char_optional(size_t offset, std::optional<char> value);

        std::optional<char> get_char_optional(size_t offset) const;

        void set_uchar(size_t offset, wchar_t value);

        wchar_t get_uchar(size_t offset) const;

        void set_uchar_optional(size_t offset, std::optional<wchar_t> value);

        std::optional<wchar_t> get_uchar_optional(size_t offset) const;

        void set_int8(size_t offset, int8_t value);

        int8_t get_int8(size_t offset) const;

        void set_int8_optional(size_t offset, std::optional<int8_t> value);

        std::optional<int8_t> get_int8_optional(size_t offset) const;

        void set_uint8(size_t offset, uint8_t value);

        uint8_t get_uint8(size_t offset) const;

        void set_uint8_optional(size_t offset, std::optional<uint8_t> value);

        std::optional<uint8_t> get_uint8_optional(size_t offset) const;

        void set_int16(size_t offset, int16_t value);

        int16_t get_int16(size_t offset) const;

        void set_int16_optional(size_t offset, std::optional<int16_t> value);

        std::optional<int16_t> get_int16_optional(size_t offset) const;

        void set_uint16(size_t offset, uint16_t value);

        uint16_t get_uint16(size_t offset) const;

        void set_uint16_optional(size_t offset, std::optional<uint16_t> value);

        std::optional<uint16_t> get_uint16_optional(size_t offset) const;

        void set_int32(size_t offset, int32_t value);

        int32_t get_int32(size_t offset) const;

        void set_int32_optional(size_t offset, std::optional<int32_t> value);

        std::optional<int32_t> get_int32_optional(size_t offset) const;

        void set_uint32(size_t offset, uint32_t value);

        uint32_t get_uint32(size_t offset) const;

        void set_uint32_optional(size_t offset, std::optional<uint32_t> value);

        std::optional<uint32_t> get_uint32_optional(size_t offset) const;

        void set_int64(size_t offset, int64_t value);

        int64_t get_int64(size_t offset) const;

        void set_int64_optional(size_t offset, std::optional<int64_t> value);

        std::optional<int64_t> get_int64_optional(size_t offset) const;

        void set_uint64(size_t offset, uint64_t value);

        uint64_t get_uint64(size_t offset) const;

        void set_uint64_optional(size_t offset, std::optional<uint64_t> value);

        std::optional<uint64_t> get_uint64_optional(size_t offset) const;

        void set_double(size_t offset, double value);

        double get_double(size_t offset) const;

        void set_double_optional(size_t offset, std::optional<double> value);

        std::optional<double> get_double_optional(size_t offset) const;

        void set_timestamp(size_t offset, timestamp_t value);

        timestamp_t get_timestamp(size_t offset) const;

        void set_timestamp_optional(size_t offset, std::optional<timestamp_t> value);

        std::optional<timestamp_t> get_timestamp_optional(size_t offset) const;

        void set_string(size_t offset, const std::string& value);

        std::string get_string(size_t offset) const;
        void get_string(size_t offset, std::string& value) const;

        void set_string_optional(size_t offset, const std::optional<std::string>& value);

        std::optional<std::string> get_string_optional(size_t offset) const;
        void get_string_optional(size_t offset, std::optional<std::string>& value) const;

        void set_ustring(size_t offset, const std::wstring& value);

        std::wstring get_ustring(size_t offset) const;
        void get_ustring(size_t offset, std::wstring& value) const;

        void set_ustring_optional(size_t offset, const std::optional<std::wstring>& value);

        std::optional<std::wstring> get_ustring_optional(size_t offset) const;
        void get_ustring_optional(size_t offset, std::optional<std::wstring>& value) const;

        void set_bytes(size_t offset, const uint8_t* value_data, size_t value_size);

        size_t get_bytes(size_t offset, uint8_t* value_data, size_t value_size) const;

        size_t get_bytes_size(size_t offset) const;

        void set_bytes_optional(size_t offset, const std::optional<uint8_t*> value_data, std::optional<size_t> value_size);

        std::optional<size_t> get_bytes_optional(size_t offset, uint8_t* value_data, size_t value_size) const;

        std::optional<size_t> get_bytes_size_optional(size_t offset) const;

        size_t new_group(size_t offset, size_t size);

        void set_array_length(size_t offset, size_t length, size_t item_size);

        size_t get_array_length(size_t offset) const;

        size_t get_array_item_offset(size_t offset, size_t index, size_t item_size) const;

        size_t get_size() const;

        uint8_t* get_data();
        const uint8_t* get_data() const;

        void resize(size_t size);

        void copy(const message_data_t& message_data);

        void reset(size_t size);

        inline message_data_t& operator=(const message_data_t& message_data);

    private:

        static size_t get_capacity(size_t size);

        size_t allocate(size_t size);

        size_t capacity_;
        uint8_t* data_;
    };

    inline message_data_t& message_data_t::operator=(const message_data_t& message_data)
    {
        copy(message_data);

        return *this;
    }
}