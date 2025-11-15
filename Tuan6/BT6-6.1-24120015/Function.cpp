#include "Function.h"

bool isPrime(int x) {
    for (int i = 2;i * i <= x;i++) {
        if (x % i == 0) return false;
    }
    return x > 1;
}

void InitOddEven(int n, std::list<int>& L) {
    int idx = 0;

    auto OddEvenCondition = [&idx] () {
        if (idx & 1) {
            idx++;
            return rand();
        }
        int val = idx / 2 + 1;
        idx++;
        return val;
    };

    std::generate(L.begin(), L.end(), OddEvenCondition);
}

void InitPrime(int n, std::list<int>& L) {
    int idx = 2;

    auto PrimeCondition = [&idx] () {
        while (!isPrime(idx)) idx++;
        idx++;
        return idx - 1;
    };

    std::generate(L.begin(), L.end(), PrimeCondition);
}