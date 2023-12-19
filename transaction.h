#ifndef transaction_h
#define transaction_h

#include "checkingaccount.h"

class Transaction
{
        unsigned id;
        double   size;
        unsigned day;
        unsigned month;
        unsigned year;
        unsigned account_to;
        unsigned account_from;

    public:

        Transaction (unsigned id, double size, unsigned day, unsigned month, unsigned year, unsigned account_to, unsigned account_from);

        unsigned get_id()  const  {return id;}
        double   get_size() const  {return size;}
        unsigned get_day() const  {return day;}
        unsigned get_month() const{return month;}
        unsigned get_year() const {return year;}
        unsigned get_account_to() const {return account_to;}
        unsigned get_account_from() const {return account_from;}

        Transaction& operator = (const Transaction &other);

};

std::ostream& operator << (std::ostream& os, Transaction& transaction);

#endif //transaction_h
