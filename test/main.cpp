#include <gtest/gtest.h>

#include "JsonParser.hpp"

using namespace Nico233;

TEST(test_parse_null, parse_null) {
    json_value v{};
    v.type = json_type::True;
    EXPECT_EQ(parse_code::parse_ok, v.parse("null"));
    EXPECT_EQ(json_type::Null, v.type);
    EXPECT_EQ(parse_code::root_not_singular, v.parse("null x"));
}

TEST(test_parse_true, parse_true) {
    json_value v{};
    v.type = json_type::Null;
    EXPECT_EQ(parse_code::parse_ok, v.parse("true"));
    EXPECT_EQ(json_type::True, v.type);
}

TEST(test_parse_false, parse_false) {
    json_value v{};
    v.type = json_type::Null;
    EXPECT_EQ(parse_code::parse_ok, v.parse("false"));
    EXPECT_EQ(json_type::False, v.type);
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}