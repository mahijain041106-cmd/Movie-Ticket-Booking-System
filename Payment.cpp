#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Movie.cpp"
#include "Show.cpp"
#include "Seat.cpp"

using namespace std;

class Payment{
    public:
        virtual bool pay(int amount) = 0;
};
