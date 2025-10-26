#include <iostream>
#include <cstdlib>
#include <vector>
#include <exception>
#include "models.hpp"
#include "constants.hpp"
#include "utils.hpp"

int main() {
    setlocale(LC_ALL, "Russian");
    system("cls");

    std::string expression;
    std::getline(std::cin, expression);

    try {
        auto res = calculate(expression); 
        std::cout << res << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
