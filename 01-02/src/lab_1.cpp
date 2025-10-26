#include "models.hpp"
#include <iostream>
#include <string>
#include "constants.hpp"
#include "utils.hpp"

int main() {
    setlocale(LC_ALL, "Russian");
    system("cls");

    std::string x;
    std::cout << ENTER_LINE;
    std::getline(std::cin, x);
    std::cout << (checkBrackets(x) ? LINE_EXISTS : LINE_DOESNT_EXIST) << std::endl;
    
    return 0;
}
