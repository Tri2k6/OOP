#pragma once

class Fraction {
private:
    int den, num;
public:
    Fraction();
    Fraction(int numm, int denn);
    Fraction(int value);
    Fraction(const Fraction& other);
    ~Fraction();
    void output();
};