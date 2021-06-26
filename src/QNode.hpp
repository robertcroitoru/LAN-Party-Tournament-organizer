#pragma once
#include "Match.hpp"

class QNode {

private:

    Match data;
    QNode* next;

public:

    QNode();
    QNode(Match, QNode *);
    QNode(const QNode &);
    QNode & operator=(const QNode &);
    void setData(Match );
    void setNext(QNode *);
    Match & getData();
    QNode * getNext();
    ~QNode();
};
