#include <iostream>
#include <string>

#include "savingsaccount.h"

using std::cout;
using std::endl;

SavingsAccount::SavingsAccount (): BankAccount ()
{
    percent = 0;
    period = 0;
}

SavingsAccount::SavingsAccount (const SavingsAccount& other): BankAccount (other)
{
    percent = other.percent;
    period = other.period;
}

SavingsAccount::SavingsAccount (int number, double balance, std::string currency, unsigned person_id, int day, int month, int year,
                                double percent, unsigned period):
                                BankAccount (number, balance, currency, person_id, day, month, year)
    {
        this -> percent = percent;
        this -> period = period;
        this -> person_id = person_id;
    }

double SavingsAccount::prediction (unsigned months)
{
    return (months*(percent/100)*balance);
}

double SavingsAccount::prediction ()
{
    return (period*(percent/100)*balance);
}

void SavingsAccount::prolongation (unsigned new_period)
{
    period += new_period;
}

void SavingsAccount::prolongation ()
{
    period *= 2;
}

void SavingsAccount::capitalization (unsigned period)
{
    balance += period*(percent/100)*balance;
}

void SavingsAccount::capitalization ()
{
    balance += (percent/100)*balance;
}

void SavingsAccount::print () const
{
    cout << "Account number: " << number << endl;
    cout << "Account balance: " << balance << endl;
    cout << "Account Currency: " << currency << endl;
    cout << "Account owner's id: " << person_id << endl;
    cout << "Account opening date: " << day << '.' << month << '.' << year << endl;
    cout << "Account percent: "  << percent<< endl;
    cout << "Account period: "  << period<< endl;
}

bool SavingsAccount::operator == (SavingsAccount& other) const
{
        if (number == other.number && balance == other.balance && currency == other.currency && person_id == other.person_id && day == other.day
            && month == other.month && year == other.year && year == other.year && percent == other.percent && period == other.period)
        return true;
    return false;
}

bool SavingsAccount::operator != (SavingsAccount& other) const
{
        if (number != other.number || balance != other.balance || currency != other.currency || person_id != other.person_id || day != other.day
            || month != other.month || year != other.year || year != other.year || percent != other.percent || period != other.period)
        return true;
    return false;
}

std::istream& operator >> (std::istream& is, SavingsAccount& account)
{
    is >> account.number >> account.balance >> account.currency >> account.person_id >> account.day >> account.month >> account.year
       >> account.percent >> account.period;
       return is;
}

std::ostream& operator << (std::ostream& os, SavingsAccount& save_account)
{
    os << save_account.get_number() << ' ' << save_account.get_balance() << ' ' << save_account.get_currency() << ' '
       << save_account.get_person_id() << ' ' << save_account.get_day() << ' ' << save_account.get_month() << ' ' << save_account.get_year() << ' '
       << save_account.get_percent() << ' ' << save_account.get_period() << endl;
    return os;
}
