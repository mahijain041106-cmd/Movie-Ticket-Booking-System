#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Show.cpp"
#include "Seat.cpp"

using namespace std;

class Booking
{
private:
    int bookingId;
    Show show;
    vector<Seat> selectedSeats;
    int totalAmount;
    bool status;

public:
    Booking(){

    }
    Booking(int bookingId, Show show, vector<Seat> selectedSeats, int totalAmount)
    {
        this->bookingId = bookingId;
        this->show = show;
        this->selectedSeats = selectedSeats;
        this->totalAmount = totalAmount;
        this->status = status;
    }

    void displayBooking()
    {
        cout << "Booking ID: " << bookingId<<endl;
        cout<< "Movie: "<<show.getMovie().getMovie()<<endl;
        cout << "Show ID: " << show.getShowId()<<endl;
        cout << "Screen: " << show.getScreen().getScreenNumber() << endl;
        cout << "Seat Number: ";
        for(auto seat:selectedSeats){
            cout<< seat.getSeatNumber()<<" ";
        }
        cout<<endl;
        cout << "Total Amount: " << totalAmount<<endl;
        cout << "Booking Status: " << (status ? "Confirmed" : "Cancelled")<<endl;
    }
    int getTotalAmount()
    {
        return totalAmount;
    }
    Show getShow()
    {
        return show;
    }
    int getBookingId()
    {
        return bookingId;
    }
    vector<Seat> getSeats()
    {
        return selectedSeats;
    }

    bool getStatus(){
        return status;
    }

    void confirmBooking()
    {
        status = true;
    }
    
    void cancelBooking(){
        status=false;
    }
};