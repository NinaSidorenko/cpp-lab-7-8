#ifndef bankaccount_h
#define bankaccount_h

#include "customer.h"
#include <iostream>
#include <string>

class BankAccount
{
        protected:
                unsigned number;
                double balance;
                std::string currency;
                unsigned person_id;
                unsigned day;
                unsigned month;
                unsigned year;

        public:
        BankAccount ();
        BankAccount (int number, double balance, std::string currency, unsigned person_id, int day, int month, int year);
        BankAccount (const BankAccount& other);
        ~BankAccount ();

        unsigned    get_number ()  const {return number;}
        double      get_balance () const {return balance;}
        std::string get_currency () const {return currency;}
        unsigned    get_person_id() const {return person_id;}
        unsigned    get_day ()     const {return day;}
        unsigned    get_month ()   const {return month;}
        unsigned    get_year ()    const {return year;}

        virtual void print () const;

        BankAccount& operator = (const BankAccount& right);
        bool operator == (BankAccount& other) const;
        bool operator != (BankAccount& other) const;

        friend std::istream& operator >> (std::istream& is, BankAccount& account);

};

std::ostream& operator << (std::ostream& os, BankAccount& account);

#endif //bankaccount_h
