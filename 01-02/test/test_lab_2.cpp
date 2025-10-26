#include <cassert>
#include <iostream>
#include <map>
#include "utils.hpp"

void tests() {
    std::map<std::string, float> test_data;
    test_data["2+2="] = 4;
    test_data["5-3="] = 5-3;
    test_data["(2+3)*4="] = (2+3)*4;
    test_data["10/5+3*2="] = 10/5+3*2;
    test_data["(8-3)*(2+1)="] = (8-3)*(2+1);
    test_data["7+(6*(5+4))/3="] = 7+(6*(5+4))/3;
    test_data["((1+2)*(3+4))="] = ((1+2)*(3+4));
    test_data["12/3/2="] = 12/3/2;
    test_data["3.5*2+1.5="] = 3.5*2+1.5;
    test_data["3,5*2+1,5="] = 3.5*2+1.5;

    for (const auto& [input, output] : test_data) {
        std::cout << input << calculate(input) << std::endl;
        assert(calculate(input) == output);
    }
    
    std::cout << std::to_string(test_data.size()) << " tests were successful!" << std::endl;
}

int main() {
    tests();
}