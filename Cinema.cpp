#include <iostream>
#include <string>
#include <vector>
#include "Screen.cpp"
#include "Movie.cpp"
#include "Show.cpp"

using namespace std;
class Cinema
{
private:
    string cinemaName;
    vector<Screen> screens;
    vector<Movie> movies;
    vector<Show> shows;

public:
    Cinema(string cinemaName)
    {
        this->cinemaName=cinemaName;
    }
    void displayCinema()
    {
        cout<<"Cinema: "<<cinemaName<<endl;
        displayMovies();
    }
    void addMovie(Movie movie)
    {
        movies.push_back(movie);
    }
    void addScreen(Screen screen)
    {
        screens.push_back(screen);
    }
    void addShow(Show show)
    {
        shows.push_back(show);
    }
    void displayMovies()
    {
        int c=1;
        for (auto &i : movies)
        {
            cout<<"["<<c++<<"]";
            i.displayMovie();
        }
    }
    void displayScreens()
    {
        for (auto &i : screens)
        {
            cout<<i.getScreenNumber() << endl;
        }
    }
    void displayShows(){
        for (auto &i : shows)
        {
            i.displayShow();
        }
        
    }
    Show *findShow(int showId){
         for (auto &i : shows)
        {
            if (showId == i.getShowId())
            {
                return &i;
            }
        }
        return NULL;
    }
};
