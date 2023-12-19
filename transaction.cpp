#include "transaction.h"

Transaction::Transaction (unsigned id, double size, unsigned day, unsigned month, unsigned year, unsigned account1_id, unsigned account2_id):
                          id (id), size (size), day (day), month (month), year (year), account_to(account1_id), account_from (account2_id)
{

}

Transaction& Transaction::operator = (const Transaction &other)
{
    if (this != &other)
    {
        id = other.id;
        size = other.size;
        day = other.day;
        month = other.month;
        year = other.year;
        account_to = other.account_to;
        account_from = other.account_from;
    }
    return *this;
}

std::ostream& operator << (std::ostream& os, Transaction& transaction)
{
    os << transaction.get_id() << ' ' << transaction.get_size() << ' ' << transaction.get_day() << ' ' <<transaction.get_month() << ' '
       << transaction.get_year() << ' ' << transaction.get_account_to () << ' ' << transaction.get_account_from() << std::endl;
    return os;
}
