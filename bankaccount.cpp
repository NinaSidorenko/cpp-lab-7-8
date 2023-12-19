#include <iostream>

#include "bankaccount.h"

using std::cout;
using std::endl;

BankAccount::BankAccount ():
            number (0), balance (0), currency (""), person_id (0), day (0), month (0), year (0)
{
}

BankAccount::BankAccount (int number, double balance, std::string currency, unsigned person_id, int day, int month, int year):
                          number (number), balance (balance), currency (currency), person_id (person_id), day (day), month (month), year (year)
{
}

BankAccount::BankAccount (const BankAccount& other):
                          number (other.number), balance (other.balance), currency (other.currency), person_id (other.person_id),
                          day (other.day), month (other.month), year (other.year)
{
}

BankAccount::~BankAccount ()
{
}

void BankAccount::print () const
{
    cout << "Account number: " << number << endl;
    cout << "Account balance: " << balance << endl;
    cout << "Account Currency: " << currency << endl;
    cout << "Account owner's id: " << person_id << endl;
    cout << "Account opening date: " << day << '.' << month << '.' << year << endl;
}

BankAccount& BankAccount::operator = (const BankAccount& right)
{
    if (this != &right)
    {
        number = right.number;
        balance = right.balance;
        currency = right.currency;
        person_id = right.person_id;
        day = right.day;
        month = right.month;
        year = right.year;
    }
    return *this;
}

bool BankAccount::operator == (BankAccount& other) const
{
    if (number == other.number && balance == other.balance && currency == other.currency && person_id == other.person_id && day == other.day
        && month == other.month && year == other.year)
        return true;
    return false;
}

bool BankAccount::operator != (BankAccount& other) const
{
    if (number != other.number || balance != other.balance || currency != other.currency || person_id != other.person_id || day != other.day
        || month != other.month || year != other.year)
        return true;
    return false;
}

std::istream& operator >> (std::istream& is, BankAccount& account)
{
    is >> account.number;
    is >> account.balance;
    is >> account.currency;
    is >> account.person_id;
    is >> account.day;
    is >> account.month;
    is >> account.year;
    return is;
}

std::ostream& operator << (std::ostream& os, BankAccount& account)
{
    os << account.get_number() << ' ' << account.get_balance() << ' ' << account.get_currency() << ' ' << account.get_person_id() << ' '
       << account.get_day() << ' ' << account.get_month() << ' ' << account.get_year() << endl;
    return os;
}
