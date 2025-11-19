#include "Account.h"

Account::Account(float initial_balance) {
    m_balance = (initial_balance > 0) ? initial_balance : 0;
}

float Account::getBalance() const { 
    return m_balance; 
}
    
void Account::deposit(float money) { 
    m_balance += money; 
}
    
bool Account::withdraw(float money) {
    if (money > m_balance)
        return false;
    m_balance -= money;
    return true;
}