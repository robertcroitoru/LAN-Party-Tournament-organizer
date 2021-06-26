#pragma once
#include "Team.hpp"
#include <iostream>
#include <string>

using namespace std;

class Node
{
private:

    Team data;
    Node *next;

public:

    Node();
    Node( Team , Node *);
    Node(const Node &);
    Node & operator=(const Node &);
    void setData(Team );
    void setNext(Node *);
    Team & getData();
    Node * getNext();
    ~Node();
};

