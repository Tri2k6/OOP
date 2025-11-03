#include "Student.h"
#include "string.h"
#include <iostream>

Student::Student() {
    Name = new char[1];
    Name[0] = '\0';
    Math = Lit = 0;
}

Student::Student(char* Namee) {
    if (Namee == nullptr) throw std::invalid_argument("Ten cua sinh vien khong hop le");
    int len = strlen(Namee);
    Name = new char[len + 1];
    for (int i = 0;i < len;i++) {
        Name[i] = Namee[i];
    }
    Name[len] = '\0';

    Math = Lit = 0;
}

Student::Student(char* Namee, double Mathh, double Litt) {
    if (Namee == nullptr) throw std::invalid_argument("Ten cua sinh vien khong hop le");
    int len = strlen(Namee);
    Name = new char[len + 1];
    for (int i = 0;i < len;i++) {
        Name[i] = Namee[i];
    }
    Name[len] = '\0';

    Math = Mathh;
    Lit = Litt;
}

Student::Student(const Student& other) {
    int len = strlen(other.Name);
    Name = new char[len + 1];
    for (int i = 0;i < len;i++) {
        Name[i] = other.Name[i];
    }
    Name[len] = '\0';

    Math = other.Math;
    Lit = other.Lit;
}

Student::~Student() {
    delete[] Name;  
}

void Student::output() {    
    std::cout << Name << ' ' << Math << ' ' << Lit << std::endl;
}
