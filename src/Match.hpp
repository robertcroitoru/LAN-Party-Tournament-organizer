#pragma once
#include "Team.hpp"

class Match {

private:

    Team Team1;
    Team Team2;

public:

    Match &operator=(const Match &);
    void setTeam1(Team &);
    void setTeam2(Team &);
    Team & getTeam1();
    Team &getTeam2();

};

