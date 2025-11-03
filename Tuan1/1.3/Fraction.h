#pragma once
#include <stdexcept>
#include <iostream>
using namespace std;

// Ham dung de tinh gcd(a,b)
template<class T>
T gcd(T a, T b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}


template<class T> 
struct Fraction {
    // num la tu so, den la mau so
    T num, den;

    // Khoi tao gia tri ban dau la phan so 0 / 1
    Fraction() {
        num = 0;
        den = 1;
    }

    // Khoi tao bien voi gia tri nhap vao la a va b => a / b
    Fraction(T a, T b) {
        if (b == 0) throw std::invalid_argument("Error: Phan so co mau so bang 0");
        num = a;
        den = b;
    }

    // Nap chong toan tu >> (de nhap phan so), chi chap nhan dang (a / b ________)
    friend istream& operator >> (istream& input, Fraction<T>& Frac) {
        char slash;
        input >> Frac.num >> slash >> Frac.den;
        // Xu ly truong hop nhap khong hop le
        if (!input || slash != '/') {
            throw std::invalid_argument("Error: Loi nhap khong dung format phan so");
        }
        // Truong hop mau so = 0
        if (Frac.den == 0) {
            throw std::invalid_argument("Error: Phan so co mau so bang 0");
        }
        return input;
    }

    // Nap chong toan tu << (de in phan so), in duoi dang a / b
    friend ostream& operator << (ostream& output, Fraction<T>& Frac) {
        output << Frac.num << "/" << Frac.den;
        return output;
    }    


    // 
    Fraction Reduce() {
        T GCD = gcd(num, den);
        num /= GCD;
        den /= GCD;
    }

    // 

    friend Fraction<T> Reduce(Fraction<T> Frac) {
        Frac.Reduce();
        return Frac;
    }

    // lap nguoc phan so 
    Fraction inverse() {
        // Tao bien tmp de swap
        T tmp = num;
        num = den;
        den = tmp;
    }

    // Nap chong toan tu + de cong 2 phan so a, b
    friend Fraction<T> operator + (Fraction<T> a, Fraction<T> b) {
        Fraction<T> c;
        // Mau so chung nho nhat LCD = mau_a / gcd(a, b) * mau_b
        T LCD = a.den / gcd(a.den,b.den) * b.den;
        c.den = LCD;
        // Tu so moi = tu_a * (LCD / mau_a) + tu_b * (LCD / mau_b)
        c.num = a.num * (LCD / a.den) + b.num * (LCD / b.den);
        c.Reduce();
        return c;
    }

    // Nap chong toan tu < de so sanh 2 phan so a, b
    friend bool operator < (Fraction<T> a, Fraction<T> b) {
        T LCD = a.den / gcd(a.den, b.den) * b.den;

        // Tu so moi cua phan so a sau khi quy dong
        T A = a.num * (LCD / a.den);
        // Tu so moi cua phan so b sau khi quy dong
        T B = b.num * (LCD / b.den);

        return A < B;
    }
};