#include "QNode.hpp"
#include <iostream>
#include <string>

using namespace std;

QNode::QNode(){

    //data = new Team(0, " ", NULL);
    next = NULL;
}

QNode::QNode(Match m, QNode *q){

//    data = new Team;
    data = m;
    next = q;
}

QNode::QNode(const QNode &q){

    data = q.data;
    next = q.next;
}

QNode &QNode::operator=(const QNode&q){

    data = q.data;
    next = q.next;
    return *this;
}

void QNode::setData(Match m){

    this->data = m;
}

void QNode::setNext(QNode *q){

    this->next = q;
}

Match&  QNode::getData(){

    return data;
}

QNode * QNode::getNext(){

    return next;
}

QNode::~QNode(){

    delete next;
    next = NULL;
}


