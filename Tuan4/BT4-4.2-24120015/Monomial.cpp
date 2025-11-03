#include "Monomial.h"
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

Monomial::Monomial() {
    Expo = 0;
    Coef = 0;
}

Monomial::Monomial(double Coeff, int Expoo) {
    Coef = Coeff;
    Expo = Expoo;
}

int Monomial::GetExpo() {
    return Expo;
}

Monomial Monomial::operator + (const Monomial& other) {
    if (Expo != other.Expo) throw std::invalid_argument("Error different exponent");
    return Monomial(Coef + other.Coef, Expo);
}

Monomial Monomial::operator * (const Monomial& other) {
    return Monomial(Coef * other.Coef, Expo + other.Expo);
}

bool Monomial::operator > (const Monomial& other) {
    if (Expo != other.Expo) return Expo > other.Expo;
    return Coef > other.Coef;
}

bool Monomial::operator < (const Monomial& other) {
    if (Expo != other.Expo) return Expo < other.Expo;
    return Coef < other.Coef;
}

bool Monomial::operator == (const Monomial& other) {
    return (Expo == other.Expo) && (Coef == other.Coef);
}

bool Monomial::operator >= (const Monomial& other) {
    if (Expo != other.Expo) return Expo >= other.Expo;
    return Coef >= other.Coef;    
}

bool Monomial::operator <= (const Monomial& other) {
    if (Expo != other.Expo) return Expo <= other.Expo;
    return Coef <= other.Coef;
}

bool Monomial::operator != (const Monomial& other) {
    return (Coef != other.Coef) || (Expo != other.Expo);
}

Monomial& Monomial::operator = (const Monomial& other) {
    Coef = other.Coef;
    Expo = other.Expo;
    return *this;
}

Monomial& Monomial::operator += (const Monomial& other) {
    if (Expo != other.Expo) throw std::invalid_argument("Error different exponent");
    (*this) = (*this) + other;
    return *this;   
}

Monomial& Monomial::operator *= (const Monomial& other) {
    (*this) = (*this) * other;
    return *this;
}

Monomial& Monomial::operator ++ () {
    Expo++;
    return *this;
}

Monomial Monomial::operator ++ (int Fake_arg) {
    Monomial tmp = Monomial(Coef, Expo);
    Expo++;
    return tmp;
}

Monomial& Monomial::operator -- () {
    Expo--;
    return *this;
}

Monomial Monomial::operator -- (int Fake_arg) {
    Monomial tmp = Monomial(Coef, Expo);
    Expo--;
    return tmp;
}

Monomial& Monomial::operator! () {
    Coef = Coef * Expo;
    Expo--;
    return *this;
}

istream& operator >> (istream& input, Monomial& a) {
    string str,buffer;
    cout << "Moi ban nhap he so: ";
    getline(input,str);
    stringstream ss(str);
    
    double Coeff;
    if (!(ss >> Coeff)) throw invalid_argument("Loi nhap he so");
    while (ss >> buffer) throw invalid_argument("Loi nhap he so");


    cout << "Moi ban nhap so mu: ";
    ss.clear();
    getline(input,str);
    ss.str(str);
    int Expoo;
    if (!(ss >> Expoo)) throw invalid_argument("Loi nhap so mua");
    while (ss >> buffer) throw invalid_argument("Loi nhap so mua");

    a.Coef = Coeff;
    a.Expo = Expoo;
    
    return input;
}

ostream& operator << (ostream& output, const Monomial& a) {
    cout << a.Coef << "x^" << a.Expo; 
    return output;
}