#include "sort_algorithms.hpp"
#include "utils.hpp"
#include "constants.hpp"

namespace lab4 {
    std::vector<double> sort(std::vector<double> arr) {
    int n = 0;
    double fact = lab4::LAB4_CONST;
    double step = arr.size() - 1;
    
    while (step >= 1) {
        for (int i = 0; i + step < arr.size(); ++i) {
            if (arr[i] <= arr[i + step]) continue;
            swap(arr[i], arr[i + step]);
            ++n;
        }
        step /= fact;
    }
    
    for (int i = 0; i < arr.size(); ++i) {
        bool swapped = false;
        for (int j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j] <= arr[j + 1]) continue;
            swap(arr[j], arr[j + 1]);
            swapped = true;
            ++n;
        }
        if (!swapped) break;
    }

    return arr;
}
}