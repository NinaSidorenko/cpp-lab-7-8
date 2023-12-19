#ifndef customer_h
#define customer_h

#include <iostream>
#include <string>

class Customer
{
    unsigned id;
    std::string name;
    std::string surname;
    unsigned age;
    std::string country;
public:
    Customer();
    Customer(unsigned id, std::string name, std::string surname, int age, std::string country);
    Customer(const Customer& other);
    ~Customer();

    unsigned get_id() const { return id; }
    std::string get_name() const { return name; }
    std::string get_surname() const { return surname; }
    unsigned get_age() const { return age; }
    std::string get_country() const { return country; }

    void print() const;

    Customer& operator = (const Customer& right);

    bool operator == (Customer& other) const;
    bool operator != (Customer& other) const;

    friend std::istream& operator >> (std::istream& is, Customer& customer);
};

std::ostream& operator << (std::ostream& os, Customer& customer);

#endif //customer_h
