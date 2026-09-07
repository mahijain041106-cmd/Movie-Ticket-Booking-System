
#pragma once
#include <iostream>
#include <vector>
#include "Seat.cpp"

using namespace std;

class PriceCalculator
{
private:
    int silverPrice;
    int goldPrice;
    int platinumPrice;

public:
    PriceCalculator()
    {
        silverPrice = 150;
        goldPrice = 250;
        platinumPrice = 400;
    }

     int calculatePrice(vector<Seat> seats)
    {
        int totalPrice = 0;

        for (Seat seat : seats)
        {
            if (seat.getType() == "SILVER")
            {
                totalPrice += silverPrice;
            }
            else if (seat.getType() == "GOLD")
            {
                totalPrice += goldPrice;
            }
            else if (seat.getType() == "PLATINUM")
            {
                totalPrice += platinumPrice;
            }
        }

        return totalPrice;
    }
};