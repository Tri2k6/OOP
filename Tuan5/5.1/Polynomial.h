#pragma once
#include <string>
#include <iostream>
#include <sstream>
using std::istream;
using std::ostream;

class Polynomial {
private:
    size_t _degree;
    double* Coef_arr;
public:
    Polynomial();
    Polynomial(size_t degree, double* C_arr);
    Polynomial(const Polynomial& other);
    ~Polynomial();
public:
    int getDegree();
    double getCoeff(size_t idx);
    void setDegree(size_t D);
    void setCoeff(size_t idx, double val);
public:
    Polynomial operator + (const Polynomial& other);
    Polynomial operator - (const Polynomial& other);
    Polynomial operator * (const Polynomial& other);
    Polynomial& operator = (const Polynomial& other);

    bool operator > (const Polynomial& other);
    bool operator < (const Polynomial& other);
    bool operator == (const Polynomial& other);
    bool operator >= (const Polynomial& other);
    bool operator <= (const Polynomial& other);
    bool operator != (const Polynomial& other);

    Polynomial& operator ! ();
    Polynomial& operator ~ ();

    friend istream& operator >> (istream& input, Polynomial& a);
    friend ostream& operator << (ostream& output, const Polynomial& a);
};