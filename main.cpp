#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

#include "customer.h"
#include "checkingaccount.h"
#include "savingsaccount.h"
#include "transaction.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    char ans;
    unsigned customer_count = 0;
    unsigned checking_account_count = 0;
    unsigned saving_account_count = 0;
    unsigned transaction_count = 0;

    std::ofstream outc ("customers.txt");
    if (outc.is_open())
    {
        outc << "";
        outc.close();
    }

    std::ofstream outch ("checkingaccounts.txt");
    if (outch.is_open())
    {
        outch << "";
        outch.close();
    }

    std::ofstream outs ("savingsaccounts.txt");
    if (outs.is_open())
    {
        outs << "";
        outs.close();
    }

    std::ofstream outt ("transactions.txt");
    if (outt.is_open())
    {
        outt << "";
        outt.close();
    }

    do
    {
        cout << "If you want to add a customer, print \"p\"" << endl
            << "If you want to open a checking account, print \"c\"" << endl
            << "If you want to open a savings account, print \"s\"" << endl
            << "If you want to print customer's data, print \"1\"" << endl
            << "If you want to print data about a checking account, print \"2\"" << endl
            << "If you want to print data about a savings account, print \"3\"" << endl
            << "If you want to prolongate your savings account, print \"4\"" << endl
            << "If you want to predict sum on your savings account, print \"5\"" << endl
            << "If you want to capitalize money your savings account, print \"6\"" << endl
            << "If you want to add money to your checking account, print \"+\"" << endl
            << "If you want to take money from your savings account, print \"-\"" << endl;


        cin >> ans;

        switch (ans)
        {
        case ('p'):
        {
            std::string name;
            std::string surname;
            int age;
            std::string country;

            cout << "Write customer's name:" << endl;
            cin >> name;
            cout << "Write customer's surname:" << endl;
            cin >> surname;
            cout << "Write customer's age:" << endl;
            cin >> age;
            cout << "Write customer's country:" << endl;
            cin >> country;
            ++customer_count;

            try
            {
                Customer customer(customer_count, name, surname, age, country);
                std::ofstream out("customers.txt", std::ios::app);
                if (out.is_open())
                {
                    out << customer;
                    out.close();
                }

                cout << "new customer's id is " << customer_count << endl;
            }
            catch (const char* error_message)
            {
                std::cout << error_message << std::endl;
            }
            break;
        }

        case ('c'):
        {
            if (customer_count == 0)
            {
                cout << "Please firstly add a new customer" << endl;
                break;
            }
            double balance;
            std::string currency;
            unsigned id;

            cout << "Write account balance:" << endl;
            cin >> balance;
            cout << "Write account currency:" << endl;
            cin >> currency;
            cout << "Write account owner's id from 1 to " << customer_count << ':' << endl;
            cin >> id;

            if (id > customer_count)
            {
                cout << "There is no such a customer" << endl;
                break;
            }
            ++checking_account_count;

            time_t now = time(0);


            tm* ltm = localtime(&now);

            unsigned year = 1900 + ltm->tm_year;
            unsigned month = 1 + ltm->tm_mon;
            unsigned day = ltm->tm_mday;

            CheckingAccount account(checking_account_count, balance, currency, id, day, month, year);

            std::ofstream out("checkingaccounts.txt", std::ios::app);
            if (out.is_open())
            {
                out << account;
                out.close();
            }

            cout << "new checking account number " << checking_account_count << endl;
            break;
        }

        case ('s'):
        {
            if (customer_count == 0)
            {
                cout << "Please firstly add a new customer" << endl;
                break;
            }

            double balance;
            std::string currency;
            unsigned id;
            double percent;
            int period;

            cout << "Write account balance:" << endl;
            cin >> balance;
            cout << "Write account currency:" << endl;
            cin >> currency;
            cout << "Write account owner's id from 1 to " << customer_count << ':' << endl;
            cin >> id;
            if (id > customer_count)
            {
                cout << "There is no such a customer" << endl;
                break;
            }
            cout << "Write account percent:" << endl;
            cin >> percent;
            cout << "Write account period:" << endl;
            cin >> period;
            ++saving_account_count;

            time_t now = time(0);


            tm* ltm = localtime(&now);

            unsigned year = 1900 + ltm->tm_year;
            unsigned month = 1 + ltm->tm_mon;
            unsigned day = ltm->tm_mday;

            SavingsAccount account(saving_account_count, balance, currency, id, day, month, year, percent, period);

            std::ofstream out("savingsaccounts.txt", std::ios::app);
            if (out.is_open())
            {
                out << account;
                out.close();
            }

            cout << "new checking account number " << saving_account_count << endl;
            break;

        }

        case ('1'):
        {
            if (customer_count == 0)
            {
                cout << "there are no customers" << endl;
                break;
            }

            cout << "Print a number from 1 to " << customer_count << endl;
            int ans1;
            cin >> ans1;
            if (ans1 > customer_count)
            {
                cout << "there is no such customers" << endl;
                break;
            }
            Customer customer;

            std::ifstream in("customers.txt");

            if (in.is_open())
            {
                for (int i = 0; i < ans1; ++i)
                {
                    in >> customer;
                }
                customer.print();
                in.close();
            }
            break;
        }

        case ('2'):
        {
            if (checking_account_count == 0)
            {
                cout << "there are no checking accounts";
            }
            else
            {
                cout << "Print a number from 1 to " << checking_account_count << endl;
                int ans1;
                cin >> ans1;
                CheckingAccount account;

                std::ifstream in ("checkingaccounts.txt");


                if (in.is_open())
                {
                    for (int i = 0; i < ans1; ++i)
                    {
                        in >> account;
                    }
                    account.print();
                    in.close();
                }
            }
            break;
        }

        case ('3'):
        {
            if (saving_account_count == 0)
            {
                cout << "there are no saving accounts";
            }
            else
            {
                cout << "Print a number from 1 to " << saving_account_count << endl;
                int ans1;
                cin >> ans1;
                SavingsAccount account;

                std::ifstream in ("savingsaccounts.txt");

                if (in.is_open())
                {
                    for (int i = 0; i < ans1; ++i)
                    {
                        in >> account;
                    }
                    account.print();
                    in.close();
                }
            }
            break;
        }

        case ('4'):
        {
            if (saving_account_count == 0)
            {
                cout << "there are no saving accounts";
            }
            else
            {
                cout << "Print a number from 1 to " << saving_account_count << endl;
                int ans1;
                cin >> ans1;
                SavingsAccount account;

                std::ifstream in ("savingsaccounts.txt");

                if (in.is_open())
                {
                    for (int i = 0; i < ans1; ++i)
                    {
                        in >> account;
                    }
                    in.close();
                }
                cout << "Print period which you want add. If you want to prolongate on default period, print \"0\"" << endl;
                unsigned new_period;
                cin >> new_period;

                if (new_period == 0)
                    account.prolongation();
                else
                    account.prolongation (new_period);
                cout << "New period of ypur savings account is " << account.get_period() << endl;
            }
            break;
        }

        case ('5'):
        {
            if (saving_account_count == 0)
            {
                cout << "there are no saving accounts";
            }
            else
            {
                cout << "Print a number from 1 to " << saving_account_count << endl;
                int ans1;
                cin >> ans1;
                SavingsAccount account;

                std::ifstream in ("savingsaccounts.txt");

                if (in.is_open())
                {
                    for (int i = 0; i < ans1; ++i)
                    {
                        in >> account;
                    }
                    in.close();
                }
                cout << "Print period for which you want to predict your sum. If you want to prolongate on default period, print \"0\"" << endl;
                unsigned new_period;
                cin >> new_period;

                int ret;

                if (new_period == 0)
                    ret = account.prediction();
                else
                    ret = account.prediction (new_period);
                cout << "Sum in this period will be " << ret << endl;
            }
            break;
        }

        case ('6'):
        {
            if (saving_account_count == 0)
            {
                cout << "there are no saving accounts";
            }
            else
            {
                cout << "Print a number from 1 to " << saving_account_count << endl;
                int ans1;
                cin >> ans1;
                SavingsAccount account;

                std::ifstream in ("savingsaccounts.txt");

                if (in.is_open())
                {
                    for (int i = 0; i < ans1; ++i)
                    {
                        in >> account;
                    }
                    in.close();
                }
                cout << "Print period for which you want to capitalize your sum. If you want to capitalize for default period, print \"0\"" << endl;
                unsigned new_period;
                cin >> new_period;

                int before = account.get_balance();

                if (new_period == 0)
                    account.capitalization();
                else
                    account.capitalization (new_period);
                cout << "New balance of your saving account is " << account.get_balance () << endl;

                ++transaction_count;

                time_t now = time(0);


                tm *ltm = localtime(&now);

                unsigned year = 1900 + ltm->tm_year;
                unsigned month = 1 + ltm->tm_mon;
                unsigned day = ltm->tm_mday;

                Transaction transaction (transaction_count, account.get_balance () - before, day, month, year, account.get_number (), account.get_number ());

                std::ofstream out ("transactions.txt", std::ios::app);
                if (out.is_open())
                {
                    out << transaction;
                    out.close();
                }
            }
            break;
        }

        case ('+'):
        {
            if (checking_account_count == 0)
            {
                cout << "there are no checking accounts";
            }
            else
            {
                cout << "Print a number from 1 to " << checking_account_count << endl;
                int ans1;
                cin >> ans1;
                CheckingAccount account;

                std::ifstream in ("checkingaccounts.txt");

                if (in.is_open())
                {
                    for (int i = 0; i < ans1; ++i)
                    {
                        in >> account;
                    }
                    in.close();
                }
                cout << "Print sum which you want to add" << endl;
                unsigned new_sum;
                cin >> new_sum;

                account.add_money(new_sum);

                ++transaction_count;

                time_t now = time(0);


                tm *ltm = localtime(&now);

                unsigned year = 1900 + ltm->tm_year;
                unsigned month = 1 + ltm->tm_mon;
                unsigned day = ltm->tm_mday;

                Transaction transaction (transaction_count, new_sum, day, month, year, account.get_number (), 0);

                std::ofstream out ("transactions.txt", std::ios::app);
                if (out.is_open())
                {
                    out << transaction;
                    out.close();
                }
            }
            break;
        }

        case ('-'):
        {
            if (checking_account_count == 0)
            {
                cout << "there are no checking accounts";
            }
            else
            {
                cout << "Print a number from 1 to " << checking_account_count << endl;
                int ans1;
                cin >> ans1;
                CheckingAccount account;

                std::ifstream in ("checkingaccounts.txt");

                if (in.is_open())
                {
                    for (int i = 0; i < ans1; ++i)
                    {
                        in >> account;
                    }
                    in.close();
                }
                cout << "Print sum which you want to take" << endl;
                unsigned new_sum;
                cin >> new_sum;

                account.withdraw_money(new_sum);

                ++transaction_count;

                time_t now = time(0);


                tm *ltm = localtime(&now);

                unsigned year = 1900 + ltm->tm_year;
                unsigned month = 1 + ltm->tm_mon;
                unsigned day = ltm->tm_mday;

                Transaction transaction (transaction_count, new_sum, day, month, year, 0, account.get_number ());

                std::ofstream out ("transactions.txt", std::ios::app);
                if (out.is_open())
                {
                    out << transaction;
                    out.close();
                }
            }
            break;
        }
        }
        cout << "If you want to finish the session, print \"q\", else print any other symbol" << endl;
        cin >> ans;
    } while (ans != 'q');
    return 0;
}
