#ifndef __HIGH_CREDIT_ACCOUNT_H__
#define __HIGH_CREDIT_ACCOUNT_H__

#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount
{
private:
    int specialRate;

public:
    HighCreditAccount(int ID, int money, String name, int rate, int special)
        : NormalAccount(ID, money, name, rate), specialRate(special)
    { }
    virtual void Deposit(int money)
    {
        NormalAccount::Deposit(money);  // 원금과 이자추가
        Account::Deposit(money * (specialRate / 100.0));    // 특별이자추가
    }
};

#endif