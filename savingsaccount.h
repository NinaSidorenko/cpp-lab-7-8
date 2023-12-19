#ifndef savingsaccount_h
#define savingsaccount_h

#include "checkingaccount.h"

class SavingsAccount: public BankAccount
{
                double percent;
                unsigned period;
        public:
                SavingsAccount ();
                SavingsAccount (const SavingsAccount& other);
                SavingsAccount (int number, double balance, std::string currency, unsigned person_id, int day, int month, int year,
                                double percent, unsigned period);
                ~SavingsAccount () {};

                double          get_percent () const {return percent;}
                unsigned        get_period ()  const {return period;}


                double prediction (unsigned months);
                double prediction ();
                void   prolongation (unsigned period);
                void   prolongation ();
                void   capitalization (unsigned period);
                void   capitalization ();

                void   print () const override;

                bool operator == (SavingsAccount& other) const;
                bool operator != (SavingsAccount& other) const;

                friend std::istream& operator >> (std::istream& is, SavingsAccount& account);
};

std::ostream& operator << (std::ostream& os, SavingsAccount& account);

#endif //savingsaccount_h
