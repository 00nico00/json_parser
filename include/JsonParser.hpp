#pragma once

#include <string>
#include <cassert>

namespace Nico233 {

    enum class json_type {
        Null, False, True, Number, String, Array, Object
    };

    enum class parse_code {
        parse_ok,
        expect_value,       // 一个 JSON 只含有空白
        invalid_value,      // 值不是那三种字面值
        root_not_singular   // 一个值之后，在空白之后还有其他字符
    };

    struct json_value {
        struct json_context {
            std::string json;
            size_t idx{};

            char operator*() const {
                return json[idx];
            }

            char operator[](size_t index) const {
                return json[idx + index];
            }

            json_context operator++(int) {
                auto tmp = *this;
                idx++;
                return tmp;
            }

            json_context& operator+=(int value) {
                idx += value;
                return *this;
            }

            bool is_arrive_end() const {
                return idx == json.size();
            }
        };

        json_type type;

        parse_code parse(const std::string &value) {
            json_context c;
            c.json = value;
            type = json_type::Null;
            parse_whitespace(c);
            parse_code ret = parse_value(c);
            if (ret == parse_code::parse_ok) {
                parse_whitespace(c);
                if (!c.is_arrive_end()) {
                    return parse_code::root_not_singular;
                }
            }

            return ret;
        }

        /* ws = *(%x20 / %x09 / %x0A / %x0D) */
        void parse_whitespace(json_context &context) {
            while (*context == ' ' || *context == '\t' || *context == '\n' ||
                    *context == '\r') {
                context++;
            }
        }

        /* null  = "null" */
        parse_code parse_null(json_context& context) {
            assert(*context == 'n');
            context++;

            if (context[0] != 'u' || context[1] != 'l' || context[2] != 'l') {
                return parse_code::invalid_value;
            }
            context += 3;
            type = json_type::Null;
            return parse_code::parse_ok;
        }

        /* true  = "true" */
        parse_code parse_true(json_context& context) {
            assert(*context == 't');
            context++;

            if (context[0] != 'r' || context[1] != 'u' || context[2] != 'e') {
                return parse_code::invalid_value;
            }
            context += 3;
            type = json_type::True;
            return parse_code::parse_ok;
        }

        /* false  = "false" */
        parse_code parse_false(json_context& context) {
            assert(*context == 'f');
            context++;

            if (context[0] != 'a' || context[1] != 'l' || context[2] != 's' || context[3] != 'e') {
                return parse_code::invalid_value;
            }
            context += 4;
            type = json_type::False;
            return parse_code::parse_ok;
        }

        parse_code parse_value(json_context& context) {
            switch (*context) {
                case 'n': return parse_null(context);
                case 't': return parse_true(context);
                case 'f': return parse_false(context);
                case '\0': return parse_code::expect_value;
                default: return parse_code::invalid_value;
            }
        }

    };


}