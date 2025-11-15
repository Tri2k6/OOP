#pragma once

class Account
{
private:
    float m_balance;
public:
    Account(float initial_balance = 0.0f);
    float getBalance() const;
    virtual void deposit(float money);
    virtual bool withdraw(float money);
    virtual ~Account();
};