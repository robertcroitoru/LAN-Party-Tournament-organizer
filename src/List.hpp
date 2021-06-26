#pragma once
#include "Node.hpp"
#include "Team.hpp"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class List
{
private:
    Node *head;

public:
    List();
    List( Node *);
    List(const List &);
    List & operator=(const List &);
    ~List();
    void read_write(int, ifstream &, ofstream &,bool);
    void Add_last(Team );
    void Add_beginning(Team);
    void write(ofstream &);
    int highestPower2(int);
    void Delete_Node(Team);
    double Team_lowestScore();
    void Delete_Write(int, ofstream &);
    void write_sub2(ofstream &);
    Node * getHead();
    void setHead(Node *);
};

