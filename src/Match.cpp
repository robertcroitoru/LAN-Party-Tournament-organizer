#include "Match.hpp"

Match &Match::operator=(const Match &m) {

    Team1 = m.Team1;
    Team2 = m.Team2;
    return *this;
}

void Match::setTeam1(Team &t){

    Team1 = t;
}


void Match::setTeam2(Team &t){

    Team2 = t;
}

Team &Match::getTeam1(){

    return Team1;
}

Team  &Match::getTeam2(){

    return Team2;
}
