#include <iostream>
#include "utils.hpp"
#include "constants.hpp"

void printVector(const std::vector<double>& arr, std::string sep) {
    for (int i = 0; i < arr.size(); ++i) {
        std::cout << arr[i];
        if (i != arr.size() - 1) std::cout << sep;
    }
}

void fillVector(std::vector<double>& arr) {
    size_t n;
    std::cout << ENTER_COUNT;
    std::cin >> n;

    for (size_t i = 0; i < n; ++i) {
        double value;
        std::cin >> value;
        arr.push_back(value); 
    }
}

void swap(double& a1, double& a2) {
    double temp = a1;
    a1 = a2;
    a2 = temp;
}