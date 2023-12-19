#include <iostream>

#include "customer.h"

using std::cin;
using std::cout;
using std::endl;

Customer::Customer() : name(""), surname(""), age(0), country("")
{
}
Customer::Customer(unsigned id, std::string name, std::string surname, int age, std::string country) :
    id(id), name(name), surname(surname), age(0), country(country)
{
    if (age < 0)
        throw "Age cannot be below zero!";
    this->age = age;
}

Customer::Customer(const Customer& other) :
    id(other.id), name(other.name), surname(other.surname), age(other.age), country(other.country)
{
}
Customer::~Customer()
{
}

void Customer::print() const
{
    cout << "Customer id: " << id << endl;
    cout << "Customer name: " << name << endl;
    cout << "Customer surname: " << surname << endl;
    cout << "Customer age: " << age << endl;
    cout << "Customer country: " << country << endl;
}

Customer& Customer::operator = (const Customer& right)
{
    if (this != &right)
    {
        name = right.name;
        surname = right.name;
        age = right.age;
        country = right.country;
    }
    return *this;
}

bool Customer::operator == (Customer& other) const
{
    if (name == other.name && surname == other.surname && age == other.age && country == other.country)
        return true;
    return false;
}

bool Customer::operator != (Customer& other) const
{
    if (name != other.name || surname != other.surname || age != other.age || country != other.country)
        return true;
    return false;
}

std::istream& operator >> (std::istream& is, Customer& customer)
{
    is >> customer.id;
    is >> customer.name;
    is >> customer.surname;
    is >> customer.age;
    is >> customer.country;
    return is;
}

std::ostream& operator << (std::ostream& os, Customer& customer)
{
    os << customer.get_id() << ' ' << customer.get_name() << ' ' << customer.get_surname() << ' '
        << customer.get_age() << ' ' << customer.get_country() << endl;
    return os;
}
