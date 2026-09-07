#pragma once
#include <iostream>
#include <string>
using namespace std;

class Seat
{
private:
    int seatNumber;
    string seatType;

public:
    Seat(){
    }
    Seat(int seatNumber,string seatType)
    {
        this->seatNumber = seatNumber;
        this->seatType =seatType;
    }

    int getSeatNumber()
    {
        return seatNumber;
    }

    string getType()
    {
        return seatType;
    }
    void display()
    {
        cout << "Seat " << seatNumber<<" | Type: "<<seatType<<endl;
    }
};