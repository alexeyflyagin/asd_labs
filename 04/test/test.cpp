#include <iostream>
#include <functional>
#include <cassert>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "sort_algorithms.hpp"
#include "test_data.hpp"

void test(std::vector<double> (*func)(std::vector<double>)) {
    for (size_t i = 0; i < test_arrs.size(); ++i) {
        auto sorted_arr = func(test_arrs[i]);
        std::cout << i << " - ";
        assert(std::is_sorted(sorted_arr.begin(), sorted_arr.end()));
        std::cout << "OK" << std::endl;
    }
    
    std::cout << std::to_string(test_arrs.size()) << " tests were successful!" << std::endl;
}

int main() {
    test(lab5::sort);
    return 1;
}