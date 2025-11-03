#include "Student.h"
#include <iostream>
#include <stdexcept>
using namespace std;

signed main() {
    try
    {
        Student a, b;
        a.input();
        cout << a.getName() << endl;
        cout << a.getLit() << endl;
        cout << a.getMath() << endl;

        a.output();

        a.setName("Nguyen Van B");
        a.setLit(7);
        a.setMath(8);
        
        cout << a.getName() << endl;
        cout << a.getLit() << endl;
        cout << a.getMath() << endl;


        cout << a.calculateGPA() << ' ' << a.grade() << endl;
        
        a.output();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}