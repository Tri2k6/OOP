#pragma once
#include <iostream>
using std::istream;
using std::ostream;

class Fraction {
private:
    int num, den;
public:
    Fraction();
    Fraction(int numm, int denn);
    Fraction(int value);
    Fraction(const Fraction& other);
public:
    Fraction operator + (const Fraction& other);
    Fraction operator * (const Fraction& other);
    
    bool operator > (const Fraction& other);
    bool operator < (const Fraction& other);
    bool operator == (const Fraction& other);
    bool operator >= (const Fraction& other);
    bool operator <= (const Fraction& other);
    bool operator != (const Fraction& other);

    Fraction& operator = (const Fraction& other);
    Fraction& operator += (const Fraction& other);
    Fraction& operator *= (const Fraction& other);

    Fraction& operator ++ ();
    Fraction operator ++ (int Fake_arg);
    Fraction& operator -- ();
    Fraction operator -- (int Fake_arg);

    operator int() const;
    operator float() const;

    friend istream& operator >> (istream& input, Fraction& a);
    friend ostream& operator << (ostream& output, const Fraction& a);
};