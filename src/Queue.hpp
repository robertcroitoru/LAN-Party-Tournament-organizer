//#pragma once
#include "Match.hpp"
#include "List.hpp"
#include "QNode.hpp"
#include "Stack.hpp"
#include <fstream>

using namespace std;

class Queue {

private:

    QNode *head;
    QNode *tail;
    //QNode *prev;
    //QNode *temp;


public:

    Queue();
    Queue(QNode *, QNode *);
    Queue(const Queue &);
    Queue & operator=(const Queue &);
    ~Queue();
    void Add_Queue(Match m);
    void Remove_First();
    void Form_Matches(List &L, ofstream &);
    void Form_MatchesStack(Stack s);
    bool isEmpty();
    void write_matches(int, ofstream &, Stack &, Stack&);

};

