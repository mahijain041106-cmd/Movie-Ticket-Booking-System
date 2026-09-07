#include <iostream>
#include <string>
#include <vector>

#include "Cinema.cpp"
#include "Screen.cpp"
#include "Show.cpp"
#include "ShowSeat.cpp"
#include "Movie.cpp"
#include "Seat.cpp"
#include "Customer.cpp"
#include "Payment.cpp"
#include "PaymentTypes.cpp"
#include "TicketPrinter.cpp"
#include "PriceCalculator.cpp"
#include "Booking.cpp"
#include "BookingService.cpp"

using namespace std;

int main() {
    cout << "==================================================" << endl;
    cout << "           Movie Ticket Booking System" << endl;
    cout << "==================================================" << endl;

    Cinema cinema("ABC Cinema");
    Movie movie1("3 Idiots","Hindi",170);
    Movie movie2("Interstellar","English",169);
    cinema.addMovie(movie1);
    cinema.addMovie(movie2);

    Screen screen1(1);
    Screen screen2(2);
    cinema.addScreen(screen1);
    cinema.addScreen(screen2);

    Show show1(1, movie1, screen1, "06:00 PM");
    Show show2(2, movie2, screen2, "09:00 PM");
    cinema.addShow(show1);
    cinema.addShow(show2);

    string customerName;
    long phone;

    vector<Booking> bookings;
    vector<Show*> bookingShows;

    cout <<"Enter customer name: ";
    getline(cin,customerName);
    cout << "Enter phone number: ";
    cin >> phone;
    Customer customer(customerName,phone);

    int choice;
    do{
        cout<<"1. Movies 2.Book 3.Cancel 4.My tickets 5.Exit\n";
        cin>>choice;
        if(choice==1){
            cinema.displayMovies();
        }
        else if(choice==2){
            int movie;
            cinema.displayMovies();
            cout<<"Choose Movie: ";
            cin>>movie;
            int showId;
            cinema.displayShows();
            cout<<"Choose show: ";
            cin>>showId;
            Show *selectedShow = cinema.findShow(showId);

            if (selectedShow == NULL)
            {
                cout << "Invalid show!" << endl;
                continue;
            }
            selectedShow->displayShow();
            cout << endl;
            selectedShow->displaySeats();
            cout << "\n( [ ] = available   [X] = booked )" << endl;
            int numberOfSeats;

            cout << "\nHow many seats do you want? ";
            cin >> numberOfSeats;
            vector<Seat> selectedSeats;
            bool invalidSeat = false;

            for (int i = 0; i < numberOfSeats; i++)
            {
                int seatNumber;
                cout << "Enter seat number " << i + 1 << ": ";
                cin >> seatNumber;
                ShowSeat *showSeat =selectedShow->getShowSeat(seatNumber);
                if (showSeat == NULL)
                {
                    cout << "Invalid seat number!" << endl;
                    invalidSeat = true;
                    break;
                }
                if (!showSeat->isAvailable())
                {
                    cout << "Seat " << seatNumber<< " is already booked!" << endl;
                    invalidSeat = true;
                    break;
                }
                selectedSeats.push_back(showSeat->getSeat());
            }

            if (invalidSeat)
            {
                cout << "Booking rejected." << endl;
                continue;
            }
             PriceCalculator priceCalculator;

            int totalAmount =priceCalculator.calculatePrice(selectedSeats);
            cout << "\n";
            for (Seat seat : selectedSeats)
            {
                cout << seat.getSeatNumber()<< " "<< seat.getType()<< "  Rs."<< priceCalculator.calculatePrice(vector<Seat>{seat})<< endl;
            }
            cout << "TOTAL Rs."<< totalAmount << endl;

            int paymentChoice;
            cout << "\nPay by: "<< "1.UPI  "<< "2.Card  "<< "3.Cash"<< endl;
            cout << "Choose: ";
            cin >> paymentChoice;
            Payment *payment = NULL;
            if (paymentChoice == 1)
            {
                string upiId;
                cout << "Enter UPI ID: ";
                cin >> upiId;
                payment = new Upi(upiId);
            }
            else if (paymentChoice == 2)
            {
                string cardNumber;
                cout << "Enter card number: ";
                cin >> cardNumber;
                payment = new Card(cardNumber);
            }
            else if (paymentChoice == 3)
            {
                payment = new Cash();
            }
            else
            {
                cout << "Invalid payment method!" << endl;
                continue;
            }
            bool paymentSuccess =payment->pay(totalAmount);
            if (!paymentSuccess)
            {
                cout << "Payment failed!" << endl;
                delete payment;
                continue;
            }
            for (Seat seat : selectedSeats)
            {
                ShowSeat *showSeat =selectedShow->getShowSeat(seat.getSeatNumber());
                if (showSeat != NULL)
                {
                    showSeat->bookSeat();
                }
            }
            static int bookingId = 1000;
            bookingId++;
            Booking booking(bookingId,*selectedShow,selectedSeats,totalAmount);
            booking.confirmBooking();
            cout << "\n[UPI/Card/Cash] Rs." << totalAmount<< " paid successfully"<< endl;
            TicketPrinter ticketPrinter;
            ticketPrinter.printTicket(booking);
            delete payment;
        }
        else if(choice==3){
            int bookingId;
            cout << "Enter Booking ID: ";
            cin >> bookingId;
            bool found = false;
            for (int i = 0; i < bookings.size(); i++)
            {
                if (bookings[i].getBookingId() == bookingId)
                {
                    found = true;
                    if (!bookings[i].getStatus())
                    {
                        cout << "This booking is already cancelled." << endl;
                        break;
                    }
                    Show *show = bookingShows[i];
                    vector<Seat> seats = bookings[i].getSeats();
                    for (Seat seat : seats)
                    {
                        ShowSeat *showSeat =show->getShowSeat(seat.getSeatNumber());
                        if (showSeat != NULL)
                        {
                        showSeat->releaseSeat();
                        }
                    }
                    bookings[i].cancelBooking();
                    cout << "\nBooking " << bookingId<< " has been cancelled successfully." << endl;
                    cout << "Selected seats are now available again." << endl;
                    break;
                }
            }
            if (!found)
            {
                cout << "Booking ID not found." << endl;
            }
            found = false;
        }
        else if(choice==4){
            for (int i = 0; i < bookings.size(); i++)
            {
                if (bookings[i].getStatus())
                {
                    bookings[i].displayBooking();
                }
            }
        }
        else if(choice==5){
            cout<<"======================THANKYOU=========================\n";
        }
    }while(choice!=5);
    return 0;
}