#pragma once
#include <iostream>
#include "Booking.cpp"

using namespace std;

class TicketPrinter
{
public:
    void printTicket(Booking booking)
    {
        cout << "\n========== TICKET ==========" << endl;
        booking.displayBooking();
        cout << "============================" << endl;
    }
};