#include <iostream>
#include <iomanip>
#include "SavingAccount.h"

using namespace std;

int main() {

    SavingAccount mySaver(0,6,12.0); 

    cout << "=== DEMO TAI KHOAN ===" << endl;
    
    mySaver.deposit(1000);
    
    cout << "\n--- Troi qua 3 thang ---" << endl;
    mySaver.increaseDuration();
    mySaver.increaseDuration();
    mySaver.increaseDuration();
    mySaver.printStatus();
    
    cout << "\n--- Nap them 500 ---" << endl;
    mySaver.deposit(500); 
    mySaver.printStatus();


    cout << "\n--- Troi qua 6 thang ---" << endl;
    for(int i=0; i<6; i++) mySaver.increaseDuration();
    mySaver.printStatus();


    cout << "\n--- Rut 200 ---" << endl;
    mySaver.withdraw(200);
    mySaver.printStatus();

    return 0;
}