#include "Monomial.h"

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

Monomial::Monomial() {
    Coef = 0;
    Expo = 0;
}

Monomial::Monomial(double Coeff, int Expoo) {
    Coef = Coeff;
    Expo = Expoo;
}

void Monomial::input() {
    string str,buffer;
    cout << "Moi ban nhap he so: ";
    getline(cin,str);
    stringstream ss(str);
    
    double Coeff;
    if (!(ss >> Coeff)) throw invalid_argument("Loi nhap he so");
    while (ss >> buffer) throw invalid_argument("Loi nhap he so");
    Coef = Coeff;

    cout << "Moi ban nhap so mu: ";
    ss.clear();
    getline(cin,str);
    ss.str(str);
    int Expoo;
    if (!(ss >> Expoo)) throw invalid_argument("Loi nhap so mua");
    while (ss >> buffer) throw invalid_argument("Loi nhap so mua");
    Expo = Expoo;
}

void Monomial::output() {
    cout << Coef << "x^" << Expo; 
}

double Monomial::getCoef() {
    return Coef;
}

int Monomial::getExpo() {
    return Expo;
}

void Monomial::setCoef(double Coeff) {
    Coef = Coeff;
}

void Monomial::setExpo(int Expoo) {
    Expo = Expoo;
}

double Monomial::evaluate(double x) {
    if (x == 0.0 && Expo < 0) throw invalid_argument("Error: Loi so mu am voi co so = 0");
    double ans = 1;
    for (int i = 1;i <= Expo;i++) {
        ans = ans * x;
    }
    return 1.0 * Coef * ans;
}

Monomial Monomial::derive() {
    return Monomial(Coef * Expo, Expo - 1);
}

Monomial Monomial::mul(Monomial M) {
    return Monomial(Coef * M.Coef, Expo + M.Expo);
}
