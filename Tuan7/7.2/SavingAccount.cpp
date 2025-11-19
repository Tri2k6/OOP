#include "SavingAccount.h"
#include <iostream>

SavingAccount::SavingAccount(float initial_balance, float rate, int period)
    : Account(initial_balance), m_rate(rate), m_period(period), m_duration(0) {}

float SavingAccount::calculateInterest() const {
    if (m_duration < m_period) return 0.0f;
    return getBalance() * (m_rate / 100.0f) * (1.0f * m_duration / 12.0f);
}

void SavingAccount::deposit(float money) {
    float interest = calculateInterest();

    if (interest > 0) {
        Account::deposit(interest);
    }

    Account::deposit(money);

    m_duration = 0;
}

bool SavingAccount::withdraw(float money) {
    float interest = calculateInterest();

    if (interest > 0) {
        Account::deposit(interest);
    }

    bool res = Account::withdraw(money);
    m_duration = 0;
    return res;
}

void SavingAccount::increaseDuration() {
    m_duration++;
}

void SavingAccount::printStatus() const {
    std::cout << "\n--- Saving Account Status ---" << std::endl;
    // Gọi getBalance() (hàm 'const' của lớp cha)
    std::cout << "Balance: " << getBalance() << " VND" << std::endl; 
    std::cout << "Rate: " << m_rate << "%/year" << std::endl;
    std::cout << "Duration since last transaction: " << m_duration << " months" << std::endl;
    std::cout << "-----------------------------" << std::endl;
}