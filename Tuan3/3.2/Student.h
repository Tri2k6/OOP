#pragma once

class Student {
private:
    char* Name;
    double Math, Lit;
public:
    Student();
    Student(char* Namee);
    Student(char* Namee, double Mathh, double Litt);
    Student(const Student& other);
    void output();
    ~Student();
};