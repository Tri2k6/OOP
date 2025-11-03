#include <iostream>
#include "Fraction.h"
using namespace std;

signed main() {
    
    Fraction<int> a, b;
    cout << "Moi ban nhap vao phan so a: ";
    cin >> a;
    cout << "Moi ban nhap vao phan so b: ";
    cin >> b;

    try
    {
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
    cout << a << endl;
    cout << b << endl;

    a.Reduce();
    b.Reduce();

    return 0;
}