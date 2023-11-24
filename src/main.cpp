#include <iostream>

enum class json_type { Null, False, True, Number, String, Array, Object };

enum class parse_error {
    expect_value,       // 一个 JSON 只含有空白
    invalid_value,      // 值不是那三种字面值
    root_not_singular   // 一个值之后，在空白之后还有其他字符
};

struct json_value {
    json_type type;


    // function
    int parse(const std::string& value) {

    }
};

struct json_context {
    
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
