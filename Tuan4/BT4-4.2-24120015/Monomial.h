#pragma once
#include <iostream>
using std::ostream;
using std::istream;

class Monomial {
private:
    double Coef;
    int Expo;
public:
    Monomial();
    Monomial(double Coeff, int Expoo); 

    int GetExpo();

    Monomial operator + (const Monomial& other);
    Monomial operator * (const Monomial& other);
    
    bool operator > (const Monomial& other);
    bool operator < (const Monomial& other);
    bool operator == (const Monomial& other);
    bool operator >= (const Monomial& other);
    bool operator <= (const Monomial& other);
    bool operator != (const Monomial& other);

    Monomial& operator = (const Monomial& other);
    Monomial& operator += (const Monomial& other);
    Monomial& operator *= (const Monomial& other);

    Monomial& operator ++ ();
    Monomial operator ++ (int Fake_arg);
    Monomial& operator -- ();
    Monomial operator -- (int Fake_arg);
    Monomial& operator ! ();

    friend istream& operator >> (istream& input, Monomial& a);
    friend ostream& operator << (ostream& output, const Monomial& a);
};