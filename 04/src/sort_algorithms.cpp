#include "sort_algorithms.hpp"
#include "utils.hpp"
#include "constants.hpp"

namespace lab4 {
    std::vector<double> sort(std::vector<double> arr) {
        double step = arr.size();
        bool swapped = true;
        
        while (step > 1 || swapped) {
            step /= lab4::LAB4_CONST;
            if (step < 1) step = 1;

            swapped = false;
            for (int i = 0; i + step < arr.size(); ++i) {
                if (arr[i] <= arr[i + static_cast<int>(step)]) continue;
                
                swap(arr[i], arr[i + static_cast<int>(step)]);
                swapped = true;
            }
        }

        return arr;
    }
}