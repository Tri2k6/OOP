#pragma once

#include<string>
using namespace std;

class Student {
    private:
        string Name;
        double Math;
        double Lit;
    public:
        void input();
        void output();
        string getName();
        void setName(string NewName);
        double getLit();
        void setLit(double Litt);
        double getMath();
        void setMath(double Mathh);
        double calculateGPA();
        char grade();
};