#pragma once 

#include "Account.h"

class SavingAccount : public Account {
private:
    int m_period;
    float m_rate;
    int m_duration;
    
    float calculateInterest() const;
public:
    SavingAccount(float init, float rate, int period);
    void deposit(float money) override;
    bool withdraw(float money) override;

    void increaseDuration();
    void printStatus() const;
    ~SavingAccount() override;
};