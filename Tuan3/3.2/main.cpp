#include <iostream>
#include <stdexcept>
#include <string.h>
#include "Student.h"
using namespace std;

int main() {
    try
    {
        char ex_Name[] = "Nguyen Van A\0";

        double Lit = 7.8;
        double Math =  6.4;

        Student st1;
        cout << "st1: ";
        st1.output();
        cout << endl;

        Student st2 = Student(ex_Name);
        cout << "st2: ";
        st2.output();
        cout << endl;

        Student st3 = Student(ex_Name, Math, Lit);
        cout << "st3: ";
        st3.output();
        cout << endl;


        Student* st4 = new Student(st3);
        cout << "st4: ";
        st4->output();
        cout << endl;
        
        delete st4;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}