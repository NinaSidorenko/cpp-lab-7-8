#include "checkingaccount.h"

void CheckingAccount::add_money (double sum)
{
    if (sum >= 0)
        balance += sum;
}

void CheckingAccount::withdraw_money (double sum)
{
    if (sum >= 0)
        balance -= sum;
}
