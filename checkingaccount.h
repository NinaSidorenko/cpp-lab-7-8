#ifndef checkingaccount_h
#define checkingaccount_h

#include "bankaccount.h"

class CheckingAccount: public BankAccount
{
    public:
        using BankAccount::BankAccount;
        ~CheckingAccount () {}

        void add_money (double sum);
        void withdraw_money (double sum);
};

#endif //checkingaccount_h
