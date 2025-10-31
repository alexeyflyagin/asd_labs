#include <iostream>
#include <cmath>
#include <vector>
#include <string>

inline const std::string SEP = ", ";

int function(int k, int l, int m) {
    return pow(3, k) * pow(5, l) * pow(7, m);
}

std::vector<int> ex3(int x) {
    std::vector<int> res;
    for (int k = 0; ; ++k) {
        if (function(k, 0, 0) > x) break;
        for (int l = 0; ; ++l) {
            if (function(k, l, 0) > x) break;
            for (int m = 0; ; ++m) {
                int c = function(k, l, m);
                if (c > x) break;
                res.push_back(c);
            }
        }
    }
    return res;
}

void printVector(std::vector<int>& e) {
    for (int i = 0; i < e.size(); ++i) {
        std::cout << e[i];
        if (i != e.size() - 1) std::cout << SEP;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    system("cls");

    int x;
    std::cin >> x;
    
    auto res = ex3(x);
    printVector(res);

    return 1;
}