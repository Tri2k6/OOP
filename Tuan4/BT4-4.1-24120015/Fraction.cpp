#include "Fraction.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
const double EPSILON = 1e-18;

Fraction::Fraction() {
    num = den = 0;
}

Fraction::Fraction(int numm, int denn) {
    num = numm;
    den = denn;
}

Fraction::Fraction(int value) {
    num = value;
    den = 1;
}

Fraction::Fraction(const Fraction& other) { 
    num = other.num;
    den = other.den;
}

Fraction Fraction::operator + (const Fraction& other) {
    Fraction Frac = Fraction();
    Frac.den = den * other.den;
    Frac.num = num * other.den + other.num * den;
    return Frac;
}

Fraction Fraction::operator * (const Fraction& other) {
    return Fraction(num * other.num, den * other.den);
}

bool Fraction::operator > (const Fraction& other) {
    return (1.0 * num / den) > (1.0 * other.num / other.den);
}

bool Fraction::operator < (const Fraction& other) {
    return (1.0 * num / den) < (1.0 * other.num / other.den);
}

bool Fraction::operator >= (const Fraction& other) {
    return (1.0 * num / den) >= (1.0 * other.num / other.den);
}

bool Fraction::operator <= (const Fraction& other) {
    return (1.0 * num / den) <= (1.0 * other.num / other.den);
}

bool Fraction::operator == (const Fraction& other) {
    double tmp1 = 1.0 * num / den;
    double tmp2 = 1.0 * other.num / other.den;
    return abs(tmp1 - tmp2) < EPSILON;
}

bool Fraction::operator != (const Fraction& other) {
    double tmp1 = 1.0 * num / den;
    double tmp2 = 1.0 * other.num / other.den;
    return abs(tmp1 - tmp2) > EPSILON;
}

Fraction& Fraction::operator = (const Fraction& other) {
    num = other.num;
    den = other.den;
    return *this;
}

Fraction& Fraction::operator += (const Fraction& other) {
    (*this) = (*this) + other;
    return *this;
}

Fraction& Fraction::operator *= (const Fraction& other) {
    (*this) = (*this) * other;
    return *this;
}

Fraction& Fraction::operator ++ () {
    num += den;
    return *this;
}

Fraction Fraction::operator ++ (int Fake_arg) {
    Fraction tmp = Fraction(num,den);
    num += den;
    return tmp;
}

Fraction& Fraction::operator -- () {
    num -= den;
    return *this;
}

Fraction Fraction::operator -- (int Fake_arg) {
    Fraction tmp = Fraction(num,den);
    num -= den;
    return tmp;
}

Fraction::operator int() const {
    return num / den;
}

Fraction::operator float() const {
    return 1.0f * num / den;
}

istream& operator >> (istream& input, Fraction& a) {
    int numm, denn;
    string str, tmp;
    
    cout << "Moi ban nhap tu so: ";
    getline(input,str);
    stringstream ss(str);
    
    if (!(ss >> numm && ss.eof())) throw invalid_argument("Loi nhap tu so");

    cout << "Moi ban nhap mau so: ";
    getline(input,str);
    ss = stringstream(str);
    if (!(ss >> denn && ss.eof())) throw invalid_argument("Loi nhap mau so");

    if (denn == 0) throw invalid_argument("Loi mau so = 0");

    a.num = numm;
    a.den = denn;

    return input;
}

ostream& operator << (ostream& output, const Fraction& a) {
    output << a.num << "/" << a.den;
    return output;
}



