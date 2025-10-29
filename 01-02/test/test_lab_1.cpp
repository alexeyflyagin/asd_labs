#include <cassert>
#include <iostream>
#include <string>
#include "utils.hpp"
#include <map>

void tests() {
    std::map<std::string, bool> test_data;
    test_data["()"] = true;
    test_data["((()))"] = true;
    test_data["(()"] = false;
    test_data["())("] = false;
    test_data["{}"] = true;
    test_data["{{}}"] = true;
    test_data["{{}"] = false;
    test_data["[]"] = true;
    test_data["[][][]"] = true;
    test_data["[[[[]]]"] = false;
    test_data["()[{}]"] = true;
    test_data["()[({}())]"] = true;
    test_data["{[()]}"] = true;
    test_data["(({{[[]]}}))"] = true;
    test_data["[({})]()"] = true;
    test_data["[({)]}"] = false;
    test_data["[({})"] = false;
    test_data["([]{})"] = true;
    test_data["([}{])"] = false;
    test_data["((}))"] = false;
    test_data[""] = true;
    test_data["(((((((((())))))))))"] = true;
    test_data["{[()()[]{}()]}"] = true;
    test_data["{[(()]))}"] = false;
    test_data["((([[[{{{}}}]]])))"] = true;

    for (const auto& [input, output] : test_data) {
        std::cout << input << "  ->  " << output << std::endl;
        assert(checkBrackets(input) == output);
    }
    
    std::cout << std::to_string(test_data.size()) << " tests were successful!" << std::endl;
}

int main() {
    tests();
}