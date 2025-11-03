#include <string>
#include <sstream>
#include <iostream>
#include "Student.h"
using namespace std;

bool isDigit(char c) {
    return '0' <= c && c <= '9';
}

void Student::input() {
    string str,str_buffer;
    cout << "Moi ban nhap ten sinh vien: ";
    getline(cin, str);
    Name = str;

    cout << "Moi ban nhap diem van: ";
    getline(cin, str);
    stringstream ss(str);
    double buffer;
    if (!(ss >> buffer) || buffer < 0.0 || buffer > 10.0) {
        throw invalid_argument("Loi nhap diem van");
    }
    while (ss >> str_buffer) throw invalid_argument("Loi nhap diem van");
    Lit = buffer;

    cout << "Moi ban nhap diem toan: ";
    getline(cin, str);
    ss.clear();
    ss.str(str);
    if (!(ss >> buffer) || buffer < 0.0 || buffer > 10.0) {
        throw invalid_argument("Loi nhap diem toan");
    }
    while (ss >> str_buffer) throw invalid_argument("Loi nhap diem toan");
    Math = buffer;
}

void Student::output() {
    cout << Name << "  " << Lit << "  " << Math << endl;
}

string Student::getName() {
    return Name;
}

double Student::getLit() {
    return Lit;
}

double Student::getMath() {
    return Math;
}

void Student::setName(string NewName) {
    Name = NewName;
}

void Student::setLit(double Litt) {
    Lit = Litt;
} 

void Student::setMath(double Mathh) {
    Math = Mathh;
}

double Student::calculateGPA() {
    return (Lit + Math) / 2;
}

char Student::grade() {
    double GPA = this->calculateGPA();
    if (GPA >= 9.0) return 'A';
    if (GPA >= 7.0) return 'B';
    if (GPA >= 5.0) return 'C';
    return 'D';
}