#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Seat.cpp"

using namespace std;

class ShowSeat
{
private:
    Seat seat;
    bool seatStatus;

public:
    ShowSeat(Seat seat)
    {
        this->seat = seat;
        this->seatStatus = true;
    }

    bool isAvailable()
    {
        return seatStatus;
    }

    void display()
    {
        seat.display();
    }

    void bookSeat()
    {
        seatStatus = false;
    }
    void releaseSeat()
    {
        seatStatus = true;
    }
    Seat getSeat()
    {
        return seat; 
    }
};