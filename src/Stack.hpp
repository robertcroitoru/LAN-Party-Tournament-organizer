#pragma once
#include "Node.hpp"
#include <iostream>
#include <fstream>

using namespace std;

class Stack{

private:

    Node *top;

public:

    Stack();
    Stack(Node *);
    Stack(const Stack&);
    Stack & operator=(const Stack &);
    void push(Team );
    Node* peek();
    void Reset();
    ~Stack();
    void Write(int, ofstream &);


};
