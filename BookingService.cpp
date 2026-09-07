#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Customer.cpp"
#include "Booking.cpp"
#include "Show.cpp"
#include "Payment.cpp"
#include "PriceCalculator.cpp"
using namespace std;

class BookingService{
    private:
        Booking booking;
        Show show;
        Payment *payment;
        PriceCalculator priceCalculator;
    public:
        BookingService(Booking booking, Show show, Payment *payment, PriceCalculator priceCalculator)
        {
            this->booking = booking;
            this->show = show;
            this->payment = payment;
            this->priceCalculator = priceCalculator;
        }
         Booking bookTicket(Show &show, vector<Seat> seats)
    {
        if (!validateSeats(show, seats))
        {
            cout << "Some seats are already booked." << endl;
            return booking;
        }

        double amount = priceCalculator.calculatePrice(seats);

        cout << "Total Amount: " << amount << endl;

        bool paymentSuccess = payment->pay(amount);

        if (paymentSuccess)
        {
            for (Seat seat : seats)
            {
                ShowSeat *showSeat = show.getShowSeat(seat.getSeatNumber());

                if (showSeat != NULL)
                {
                    showSeat->bookSeat();
                }
            }

            booking.confirmBooking();

            cout << "Booking Confirmed!" << endl;
        }
        else
        {
            cout << "Payment Failed!" << endl;
        }

        return booking;
    }

    bool validateSeats(Show &show, vector<Seat> seats)
    {
        for (Seat seat : seats)
        {
            ShowSeat *showSeat = show.getShowSeat(seat.getSeatNumber());

            if (showSeat == NULL || !showSeat->isAvailable())
            {
                return false;
            }
        }

        return true;
    }
    void cancelBooking()
    {
        booking.cancelBooking();

        cout << "Booking Cancelled!" << endl;
    }
};