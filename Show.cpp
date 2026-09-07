#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Movie.cpp"
#include "Screen.cpp"
#include "ShowSeat.cpp"

using namespace std;

class Show
{
private:
    int showId;
    Movie movie;
    Screen screen;
    string startTime;
    vector<ShowSeat> showSeats;

public:
    Show(){
        showId=-1;
    }
    Show(int showId, Movie movie, Screen screen, string startTime)
    {
        this->showId = showId;
        this->movie = movie;
        this->screen = screen;
        this->startTime = startTime;

        createShowSeats();
    }
    void createShowSeats()
    {
        vector<Seat> seats = screen.getSeats();
        for (auto i : seats)
        {
            ShowSeat showSeat(i);
            showSeats.push_back(showSeat);
        }
    }
    void displayShow()
    {
        cout<<"["<<showId<<"]"<<" ";
        cout<<"Screen-"<<screen.getScreenNumber()<<" ";
        cout<<startTime<<endl;
    }
    void displaySeats()
    {
        cout << "\n";

    cout << "SILVER    ";
    for (auto &showSeat :showSeats)
    {
        if (showSeat.getSeat().getType() == "SILVER")
        {
            cout<< showSeat.getSeat().getSeatNumber()<< (showSeat.isAvailable() ? "[]" : "[X]")<< " ";
        }
    }
    cout << endl;
    cout << "GOLD      ";
    for (auto &showSeat : showSeats)
    {
        if (showSeat.getSeat().getType() == "GOLD")
        {
            cout<< showSeat.getSeat().getSeatNumber()<< (showSeat.isAvailable() ? "[]" : "[X]")<< " ";
        }
    }
    cout << endl;
    cout << "PLATINUM  ";
    for (auto &showSeat : showSeats)
    {
        if (showSeat.getSeat().getType() == "PLATINUM")
        {
            cout<< showSeat.getSeat().getSeatNumber()<< (showSeat.isAvailable() ? "[]" : "[X]")<< " ";
        }
    }
    cout << endl;
    }
    ShowSeat *getShowSeat(int seatNumber)
    {
        for (auto &i : showSeats)
        {
            if (i.getSeat().getSeatNumber() == seatNumber){
                return &i;
            }
        }
        return NULL;
    }
    string getStartTime()
    {
        return startTime;
    }
    Movie getMovie()
    {
        return movie;
    }
    Screen getScreen()
    {
        return screen;
    }
    int getShowId()
    {
        return showId;
    }
};