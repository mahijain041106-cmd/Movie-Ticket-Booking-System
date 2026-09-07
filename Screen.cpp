#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Seat.cpp"

using namespace std;

class Screen
{
private:
    int screenNumber;
    vector<Seat> seats;

public:
    Screen(){
        screenNumber=-1;
    }
    Screen(int screenNumber)
    {
        this->screenNumber = screenNumber;
        createSeats();
    }
    void createSeats()
    {
        for (int i = 1; i <= 10; i++)
        {
            seats.push_back(Seat(i,"SILVER"));
        }

        for (int i = 11; i <= 20; i++)
        {
            seats.push_back(Seat(i,"GOLD"));
        }

        for (int i = 21; i <= 30; i++)
        {
            seats.push_back(Seat(i,"PLATINUM"));
        }
    }
    void displaySeats()
    {
        for (Seat &seat : seats)
        {
            seat.display();
        }
    }
    Seat *getSeat(int number)
    {
        for (auto &seat : seats)
        {
            if (seat.getSeatNumber() == number){
                return &seat;
            }
        }
        return NULL;
    }
    int getScreenNumber()
    {
        return screenNumber;
    }
    vector<Seat> getSeats(){
        return seats;
    }
};