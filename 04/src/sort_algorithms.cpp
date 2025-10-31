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

namespace lab5 {
    std::vector<double> sort(std::vector<double> arr) {
        double temp;
        int pointer;

        for (int i = 1; i < arr.size(); ++i) {
            temp = arr[i];
            pointer = i - 1;

            while (pointer >= 0 && arr[pointer] > temp) {
                arr[pointer + 1] = arr[pointer];
                pointer--;
            }

            arr[pointer + 1] = temp;
        }

        return arr;
    }
}

namespace lab6 {
    std::vector<double> sort(std::vector<double> arr) {
        int min_pointer;

        for (int i = 0; i < arr.size(); ++i) {
            min_pointer = i;
            for (int k = i + 1; k < arr.size(); ++k) {
                if (arr[k] >= arr[min_pointer]) continue;
                min_pointer = k;
            }
            swap(arr[i], arr[min_pointer]);
        }

        return arr;
    }
}