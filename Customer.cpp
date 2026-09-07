#pragma once
#include <iostream>
#include <string>

using namespace std;

class Customer
{
private:
    string name;
    long phone;

public:
    Customer(string name, int phoneNumber)
    {
        this->name = name;
        this->phone = phone;
    }
    void displayCustomer()
    {
        cout << "Name : " << name << " | " << " Phone Number : " << phone<< endl;
    }
    string getName()
    {
        return name;
    }

    long getPhone()
    {
        return phone;
    }
};