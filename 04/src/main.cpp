#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include "utils.hpp"
#include "sort_algorithms.hpp"

int main() {
    setlocale(LC_ALL, "Russian");
    system("cls");

    std::vector<double> arr;
    fillVector(arr);

    arr = lab4::sort(arr);
    printVector(arr);

    return 1;
}