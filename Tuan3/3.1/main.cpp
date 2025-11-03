#include <iostream>
#include "Fraction.h"
#include <stdexcept>
using namespace std;

int main() {
 
    try
    {
        Fraction a;
        a.output();
        cout << endl << endl;

        int num = 13;
        int den = 132;

        Fraction b;
        b.output();
        cout << endl;
        b = Fraction(num, den);
        b.output();
        cout << endl << endl;

        Fraction c;
        int value = 52561;
        c = Fraction(value);
        c.output();
        cout << endl << endl;

        Fraction* d = new Fraction;

        (*d) = Fraction(c);

        (*d).output();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}