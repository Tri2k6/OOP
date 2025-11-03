#include <iostream>
#include <stdexcept>
#include "Monomial.h"
using namespace std;

int main() {
    try
    {
        Monomial A, B;
        cout << "Monomial A: \n";
        cin >> A;
        cout << "Monomial B: \n";
        cin >> B;

        if (A.GetExpo() == B.GetExpo()) cout << "A + B = " << A + B << endl;
        else cout << "Error different exponent" << endl;
        cout << "A * B = " << A * B << endl;
        cout << "A > B: " << ((A > B) ? "True": "False") << endl;
        cout << "A < B: " << ((A < B) ? "True": "False") << endl;
        cout << "A == B: " << ((A == B) ? "True": "False") << endl;
        cout << "A >= B: " << ((A >= B) ? "True": "False") << endl;
        cout << "A <= B: " << ((A <= B) ? "True": "False") << endl;
        cout << "A != B: " << ((A != B) ? "True": "False") << endl;
        cout << "Derive of A: " << (!A) << endl;
        
        Monomial C;
        C = A;
        cout << "Copy A to C: " << C << endl;
        
        C += A;
        cout << "C += A: " << C << endl;
        
        C *= B;
        cout << "C *= B: " << C << endl;

        cout << "++B before: " << B << endl << "++B after: " << ++B << endl;
        B++;
        cout << "B++: " << B << endl;

        cout << "--A before: " << A << endl << "--A after: " << --A << endl;
        A--;
        cout << "A--(after): " << A << endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}