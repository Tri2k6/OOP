#include "Function.h"
#include <iostream>

int main() {
    int n = 8;
    std::list<int> L(n);
    InitOddEven(n, L);

    for (auto it = L.begin(); it != L.end();it++) {
        std::cout << *it << ' ';
    }
    std::cout << '\n';

    InitPrime(n, L);
    for (auto it = L.begin();it != L.end();it++) {
        std::cout << *it << ' ';
    }
    return 0;
}