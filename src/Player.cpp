#include <iostream>
#include <string>
#include "Player.hpp"
#include <fstream>

using namespace std;

/*void Player::read(){

    ifstream f("d.in");
    if(!f)
        cout << "eroare la fisier!" << endl;
    f >> firstName;
    f >> secondName;
    f >> points;
}
*/
ostream &  Player::write(ostream &out){

    out << firstName << " " << secondName << " " <<  points << endl;
    return out;
}

void Player::setFirstName(){

    cin >> firstName;
}

void Player::setSecondName(){

    cin >> secondName;
}

void Player::setPoints(){

    cin >> points;
}

int Player::getPoints(){

    return points;
}

istream &operator>>(istream  &in, Player &p){

    in >> p.firstName;
    in >> p.secondName;
    in >> p.points;
    return in;
}

