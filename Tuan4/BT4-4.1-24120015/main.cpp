#include <iostream>
#include "Fraction.h"
#include <stdexcept>
using namespace std;

int main() {    

    try
    {
        Fraction A, B;
        cout << "Phan so A: \n";
        cin >> A;
        cout << "Phan so B: \n";
        cin >> B;

        cout << "A + B = " << A + B << endl;
        cout << "A * B = " << A * B << endl;
        cout << "A > B: " << ((A > B) ? "True": "False") << endl;
        cout << "A < B: " << ((A < B) ? "True": "False") << endl;
        cout << "A == B: " << ((A == B) ? "True": "False") << endl;
        cout << "A >= B: " << ((A >= B) ? "True": "False") << endl;
        cout << "A <= B: " << ((A <= B) ? "True": "False") << endl;
        cout << "A != B: " << ((A != B) ? "True": "False") << endl;

        Fraction C;
        // Sao chep C mang gia tri cua phan tu A
        C = A;
        cout << "Copy A to C: " << C << endl;

        C += A;
        cout  << "C += A: " << C << endl;

        C *= B;
        cout << "C *= B: " << C << endl;

        cout << "++B before: " << B << endl << "++B after: " << ++B << endl;
        B++;
        cout << "B++: " << B << endl;

        cout << "--A before: " << A << endl << "--A after: " << --A << endl;
        A--;
        cout << "A--(after): " << A << endl;
        
        int I_A = (int) A;
        cout << "Ep kieu int phan so A: " << I_A << endl;
        float F_B = (float) B;
        cout << "Ep kieu float phan so B: " << F_B << endl; 
        
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}