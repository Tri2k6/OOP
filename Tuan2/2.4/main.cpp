#include <iostream>
#include "Array.h"
#include <stdexcept>
using namespace std;

bool cmp(int a, int b) {
    if ((a & 1) != (b & 1)) return a & 1;
    if (a & 1) return a > b;
    return a < b;
}

int main() {
    try
    {
        Array a;
        a.input();
        a.output();

        cout << "Current size: " << a.getSize() << endl;
        a.setSize(5);
        cout << "The new size: " << a.getSize() << endl;

        cout << "Element at index 0: " << a.getElement(0) << endl;
        a.setElement(0, -1);
        cout << "After set element at index 0 = -1" << a.getElement(0) << endl;
        a.output();

        cout << "Find 7 in array: " << a.find(7) << endl;

        a.output();
        cout << "Sorted:" << endl;
        a.output();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}