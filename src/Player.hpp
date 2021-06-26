#pragma once
#include <iostream>
#include <string>

using namespace std;


class Player
{
private:
    string firstName;
    string secondName;
    int points;

public:
    //void read();
    ostream & write(ostream &);
    void setFirstName();
    void setSecondName();
    void setPoints();
    int getPoints();
    friend istream & operator>>(istream &, Player &);
};


