#pragma once
#include <iostream>
#include <string>
#include "Player.hpp"
#include <fstream>
using namespace std;
class Team
{
private:
    int no_players;
    string name;
    Player *P;
    double team_points;

public:
    Team();
    Team(int, string, Player*);
    Team(const Team &);
    ~Team();
    Team & operator=(const Team &);
    bool operator==(const Team &);
    bool operator!=(const Team &);
    friend istream & operator>>(istream &, Team &);
    void write_Team(ofstream &);
    void write_sub2(ofstream &);
    string getName();
    void setPoints(double );
    double getPoints_sub3();
    double getScore();
    //void read();

};

