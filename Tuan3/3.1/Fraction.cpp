#pragma once
#include "Fraction.h"
#include "stdexcept"
#include <iostream>
using namespace std;

Fraction::Fraction() {
    num = 0;
    den = 1;
}

Fraction::Fraction(int numm, int denn) {
    if (denn == 0) throw std::invalid_argument("Loi mau so = 0");
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

void Fraction::output() {
    cout << num << "/" << den;
}

Fraction::~Fraction() {
    
}