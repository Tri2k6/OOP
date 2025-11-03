#pragma once

class Monomial {
    private:
        double Coef;
        int Expo;
    public:
        Monomial();
        Monomial(double Coeff, int Expoo); 
        void input();
        void output();
        double getCoef();
        void setCoef(double Coeff);
        int getExpo();
        void setExpo(int Expoo); 
        double evaluate(double x);
        Monomial derive();
        Monomial mul(Monomial M);
};