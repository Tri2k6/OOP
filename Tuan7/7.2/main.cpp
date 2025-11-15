#include <iostream>
#include <iomanip>
#include "SavingAccount.h"

using namespace std;

int main() {
    cout << fixed << setprecision(2);
    
    SavingAccount Acc(1000, 12.0, 12);

    Acc.printStatus();

    cout << "\n --------------Deposit (6 months later) --------" << endl;

    for (int i = 0;i < 6;i++) Acc.increaseDuration();

    Acc.deposit(500);
    Acc.printStatus();

    cout << "\n----------------Withdraw (3 months later)--------" << endl;

    for (int i = 0;i < 3;i++) Acc.increaseDuration();

    Acc.withdraw(200);
    Acc.printStatus();

    cout << "\n---------------Withdraw Failed -------------------" << endl;

    if (!Acc.withdraw(2000)) {
        cout << "Failed to withdraw 2000." << endl;
    }

    Acc.printStatus();

    return 0;
}