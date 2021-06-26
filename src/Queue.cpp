#include <iostream>
#include <fstream>
#include "Queue.hpp"
#include "List.hpp"
//#include "Stack.hpp"
#include <iomanip>

using namespace std;

Queue::Queue(){

//cout << "teste 1 constr";
    head = NULL;
    tail = NULL;
}

/*Queue::Queue(QNode *qh, QNode *qt){

    head = new QNode;
    tail = new QNode;
    head = qh;
    tail = qt;
}
*/
Queue::Queue(const Queue &q){

    head = q.head;
    tail = q.tail;
}

Queue & Queue::operator=(const Queue&q){

    head = q.head;
    tail = q.tail;

    return *this;
}

bool Queue::isEmpty(){

    if(head == NULL)
        return true;
    return false;
}

void Queue::Add_Queue(Match m){

    QNode *temp = new QNode;
    temp->setData(m);
    temp->setNext(NULL);
    if(isEmpty()){

        head = temp;
        tail = temp;
    }

    else {

        QNode *prev = new QNode;
        prev = tail;
        tail->setNext(temp);
        tail = temp;
    }
}

void Queue::Form_Matches(List &L, ofstream & out){

    while(L.getHead() != NULL){

        Match m;
        m.setTeam1(L.getHead()->getData());
        m.getTeam1().setPoints(m.getTeam1().getScore());
        // Verifica l.getHead()->getNext->getData() diferitde null
        m.setTeam2(L.getHead()->getNext()->getData());
        m.getTeam2().setPoints(m.getTeam2().getScore());
        Add_Queue(m);
        L.setHead(L.getHead()->getNext()->getNext());
    }
}
void Queue::Form_MatchesStack(Stack s)
{
    Node *tos = new Node();
    tos =s.peek();
    while(tos !=NULL)
    {
        Match m;
        m.setTeam1(tos->getData());
        m.getTeam1().setPoints(m.getTeam1().getScore());

        tos = tos->getNext();
        m.setTeam2(tos->getData());
        m.getTeam2().setPoints(m.getTeam2().getScore());

        tos = tos->getNext();
        cout<<m.getTeam1().getName()<<" vs "<<m.getTeam2().getName()<<"\n";
        this->Add_Queue(m);
    }
}

void Queue::write_matches(int round_no, ofstream &out, Stack& Winners, Stack& Losers){

    //cout <<"test1 write matches";
    out << endl << "--- ROUND NO:" << round_no << endl;
    if(this->isEmpty() == 0){

        for(QNode *temp = this->head; temp != NULL; temp = temp->getNext()){

            //out << temp->getData();
            out << setw(33) << left;
            out << temp->getData().getTeam1().getName() << "-";
            out << setw(33) << right;
            out << temp->getData().getTeam2().getName() << endl;
            ///cout<< temp->getData().getTeam1().getPoints_sub3() << endl;
            if(temp->getData().getTeam1().getPoints_sub3() >= temp->getData().getTeam1().getPoints_sub3()){

                //temp->getData().getTeam1().setPoints(temp->getData().getTeam1().getPoints_sub3() + 1 );
                Winners.push(temp->getData().getTeam1());
                Losers.push(temp->getData().getTeam2());

            }
            else{
                //temp->getData().getTeam2().setPoints(temp->getData().getTeam1().getPoints_sub3() + 1 );
                Losers.push(temp->getData().getTeam1());
                Winners.push(temp->getData().getTeam2());
            }

        }

}
}


void Queue::Remove_First(){

    cout << "test 2 remove";
    QNode *temp = new QNode;
    temp = head;
    head = head->getNext();

}

Queue::~Queue(){

    head = NULL;
    tail = NULL;
    //cout << "\ntest 2 destr";
}


