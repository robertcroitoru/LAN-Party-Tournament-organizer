#include "Node.hpp"
#include <iostream>
#include <string>
#include "Team.hpp"

using namespace std;

Node::Node(){

    //data = new Team(0, " ", NULL);
    next = NULL;
}

Node::Node( Team t, Node *n){

//    data = new Team;
    data = t;
    next = n;
}

Node::Node(const Node &n){

    data = n.data;
    next = n.next;
}

Node &Node::operator=(const Node&n){

    data = n.data;
    next = n.next;
    return *this;
}

void Node::setData(Team t){

    this->data = t;
}

void Node::setNext(Node *n){

    this->next = n;
}

Team&  Node::getData(){

    return data;
}

Node * Node::getNext(){

    return next;
}

Node::~Node(){

    delete next;
    next = NULL;
}


