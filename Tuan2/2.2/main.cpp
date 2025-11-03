#include "Monomial.h"
#include <iostream>
#include <stdexcept>
using namespace std;

signed main() {
    try
    {
        Monomial a, b;
        a.input();
        b.input();

        a.output(); cout << endl;
        b.output(); cout << endl;

        cout << a.getCoef() << ' ' << a.getExpo() << endl;
        cout << b.getCoef() << ' ' << b.getExpo() << endl;
        
        a.setCoef(10);
        a.setExpo(3);
        a.output();
        cout << endl;
        
        double x = 0.423;
        cout << a.evaluate(x) << ' ' << b.evaluate(x) << endl;
        
        a.derive();
        b.derive();
        a.output(); cout << endl;
        b.output(); cout << endl;

        Monomial Product = a.mul(b);
        Product.output();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}