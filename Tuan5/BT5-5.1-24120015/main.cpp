#include "Polynomial.h"
#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
    try
    {
        // 1.1 Default constructor
        Polynomial P1;
        cout << "P1 (khoi tao mac dinh): " << P1 << endl;

        //1.2 Parameterized constructor 
        double Ex_coef[] = {1,2,3};
        Polynomial P2(2, Ex_coef);
        cout << "P2 (Khoi tao 3x^2 + 2x + 1): " << P2 << endl;

        //1.3 Copy constructor
        Polynomial* P3 = new Polynomial(P2);
        cout << "P3 (sao chep tu P2): " << (*P3) << endl;


        // Get/Set 
        cout << "Bac cua P2: " << P2.getDegree() << endl;

        cout << "He so bac 1 cua P2: " << P2.getCoeff(1) << endl;

        P2.setCoeff(0,5);
        cout << "P2 sau khi setCoeff(0,5): " << P2 << endl;

        P2.setDegree(1);
        cout << "P2 sau khi giam bac xuong 1: " << P2 << endl;


        // Demo phep toan
        double Coef_A[] = {2,5};
        Polynomial A(1, Coef_A);
        cout << "A = " << A << endl;

        double Coef_B[] = {1, -3, 2};
        Polynomial B(2, Coef_B);
        cout << "B = " << B << endl;

        Polynomial C_cong = A + B;
        cout << "A + B = " << C_cong << endl;

        Polynomial C_tru = A - B;
        cout << "A - B = " << C_tru << endl;

        Polynomial C_nhan = A * B;
        cout << "A * B = " << C_nhan << endl;

        // Demo phep gan = 
        Polynomial D;
        cout << "D mac dinh: " << D << endl;
        D = A;
        cout << "Gan D = A, D = " << D << endl;
        D = B;
        cout << "Gan D = B, D = " << D << endl;

        // Demo phep so sanh
        cout << "A = " << A << endl;
        cout << "B = " << B << endl;
        Polynomial A_copy = A;
        cout << "A_copy = " << A_copy << endl;

        cout << "A == B: " << ((A == B) ? "true": "false") << endl;
        cout << "A != B: " << ((A != B) ? "true" : "false") << endl;
        cout << "A == A_copy" << ((A == A_copy) ? "true" : "false") << endl;
        cout << "A > B: " << ((A > B) ? "true" : "false") << endl;
        cout << "A < B: " << ((A < B) ? "true" : "false") << endl;
        cout << "A >= A.Copy: "  << ((A >= A_copy) ? "true": "false") << endl;
        cout << "A <= B: " << ((A <= B) ? "true": "false") << endl;

        // Demo Nguyen ham & Dao ham
        cout << "B = " << B << endl;
        !B;
        cout << "Dao ham cua B: " << B << endl;

        cout << "A = " << A << endl;
        ~A;
        cout << "Nguyen ham cua A: " << A << endl;

        // Demo nhap phan tu: 
        Polynomial P_input;
        cout << "Moi ban nhap mot da thuc moi:" << endl;
        cin >> P_input;

        cout << "Da thuc ban da nhap la: " << P_input;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}