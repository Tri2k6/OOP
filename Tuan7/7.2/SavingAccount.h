#pragma once 

#include "Account.h"

class SavingAccount : public Account {
private:
    int m_period;
    float m_rate;
    int m_duration;
    

public:
    SavingAccount(float init, float rate, int period);

    float calculateInterest() const;

    void deposit(float money);
    bool withdraw(float money);

    void increaseDuration();
    void printStatus() const;
};