#include <iostream>
#include <string>
#include <string.h>
#include "Team.hpp"


using namespace std;

Team::Team(){

    name = "";
    no_players = 0;
    P = NULL;
}

Team::Team(int nrplayers, string tname, Player* Pl){

    name = tname;
    no_players = nrplayers;
    P = new Player[no_players];
    for(int i = 0; i < no_players; i++){

        P[i] = Pl[i];
    }

}

Team::Team(const Team &t){

    no_players = t.no_players;
    name = t.name;
    P = new Player[no_players];
    for(int i = 0; i < no_players; i++){

        P[i] = t.P[i];
    }
}

Team & Team::operator=(const Team &t){

    name = t.name;
    no_players = t.no_players;
    P = new Player[no_players];
    for(int i = 0; i < no_players; i++){

        P[i] = t.P[i];
    }
    return *this;
}

istream & operator>>(istream &in, Team &t){

    in >> t.no_players;
    /*string buf = "";
    char c;
    in >> c;
    while(c != '\n'){
        buf = buf + c;
        in >> c;
    }
    t.name = buf;
    */
    getline(in, t.name);
    t.P = new Player[t.no_players];
    for(int i = 0; i < t.no_players; i++){

       in >> t.P[i];
    }
    return in;
}

void Team::write_Team(ofstream &out){

    //out << no_players << " " << name << endl;
    out << name.erase(0, 1) << endl;
    /*for(int i = 0; i < no_players; i++){

        P[i].write(out);
    }
    out << endl;
    */

}

bool Team::operator==(const Team &t){

    if(no_players == t.no_players && name == t.name)
        return true;
    return false;
}

bool Team::operator!=(const Team &t){

    return (!(*this == t));
}

double Team::getScore(){

    double team_score = 0;
    for(int i = 0; i < no_players; i++)
        team_score = team_score + P[i].getPoints();

    team_score = (double)(team_score/no_players);
    return team_score;
}
string Team::getName()
{
    return this->name;
}

void Team::write_sub2(ofstream &out){

    out << this->name.erase(0,1) << endl;
}

void Team::setPoints(double p){

    team_points = p;
}

double Team::getPoints_sub3(){

    return this->team_points;
}

Team::~Team(){

    delete [] P;
}

