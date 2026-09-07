#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Movie
{
private:
    string movieName;
    string language;
    int duration;

public:
    Movie()
    {
        movieName = "";
        language = "";
        duration = 0;
    }
    Movie(string movieName, string language, int duration)
    {
        this->movieName = movieName;
        this->language = language;
        this->duration = duration;
    }
    int getDuration()
    {
        return duration;
    }
    string getMovie()
    {
        return movieName;
    }
    string getLanguage()
    {
        return language;
    }

    void displayMovie()
    {
        cout<<" ";
        cout<<movieName<<"  ";
        cout<<language<<"  ";
        cout<<duration<<endl;;
    }
};