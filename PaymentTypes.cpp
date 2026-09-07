#include <iostream>
#include <string>
#include "Payment.cpp"

using namespace std;

class Upi : public Payment
{
private:
    string upiId;

public:
    Upi(string upiId)
    {
        this->upiId = upiId;
    }
    bool pay(int amount) override
    {
        cout << "Payment of " << amount
             << " made using UPI ID: " << upiId << endl;

        return true;
    }
};

class Card : public Payment
{

private:
    string cardNo;
public:
    Card(string cardNo)
    {
        this->cardNo = cardNo;
    }
    bool pay(int amount) override
    {
        cout << "Payment of " << amount
             << " made using Card: " << cardNo<< endl;

        return true;
    }
};

class Cash : public Payment
{
public:
    bool pay(int amount) override
    {
        cout << "Payment of " << amount
             << " made using Cash"<< endl;

        return true;
    }
};