#pragma once

class Account
{
private:
    float m_balance;
public:
    Account(float initial_balance = 0.0f);
    float getBalance() const;
    void deposit(float money);
    bool withdraw(float money);
};