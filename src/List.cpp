#include "List.hpp"
#include "List.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
using namespace std;

List::List(){

    head = NULL;
}

List::List( Node *n){

    head = new Node;
    head = n;
}

List::List(const List &l){

    head = l.head;
}

List & List::operator=(const List&n){

    head = n.head;
    return *this;
}

void List::Add_last(Team t){

    Node *n = new Node();
    //n->setData(t);
    n->setNext(NULL);
    if(head != NULL){

        Node *current = head;
        while(current->getNext() != NULL){

            current = current->getNext();
        }
        current->setNext(n);
    }
    else {

        head = n;
    }
}

void List::Add_beginning(Team t){

    Node *temp = new Node;
    temp->setData(t);
    temp->setNext(head);
    head = temp;
}

void List::read_write(int no_teams, ifstream &date, ofstream &output, bool afisare){

    if(!date)
        cout << "eroare la fisiser!";
    //int nr;
    //date >> nr;
    Team *T;
    T = new Team[no_teams];
    for(int i = 0; i < no_teams; i++){
        date >> T[i];
        this->Add_beginning(T[i]);
    }

    if(!output)
        cout << "eroare la fisiser!";

    if(afisare)
        this->write(output);
    delete [] T;
    //cout << "test1 readwrite";

}

void List::write(ofstream &out){

    Node *temp = head;
    while(temp != NULL){
        temp->getData().write_Team(out);
        temp = temp->getNext();
    }
    //return out;
}

int List::highestPower2(int n){

    int p = (int)log2(n);
    return (int)pow(2, p);

}

void List::Delete_Node(Team t){

    /*Node *before = head;
    Node *aux;
    if(position == 0){

        head = before->getNext();
        delete before;

    }
    for(int i = 0; before != NULL && i < position-1; i++){

        aux = before;
        before = before->getNext();

    }
    Node *del; // = new Node;
    del = before;
    before = before->getNext();
    aux->setNext(before);
    delete del;
    */
    // When node to be deleted is head node
    if(this->head->getData().getName() == t.getName())
    {
        this->head->setData(head->getNext()->getData());
        //n = head->getNext();
        this->head->setNext(head->getNext()->getNext());
        //delete n;
        //return;
    }
    Node *prev = head;
    while(prev->getNext() != NULL && prev->getNext()->getData().getName() != t.getName())
        prev = prev->getNext();

    // Check if node really exists in Linked List
    if(prev->getNext() == NULL)
    {
        cout << "\nGiven node is not present in Linked List";
        return;
    }
    prev->getNext()->setNext(prev->getNext()->getNext());
}

double List::Team_lowestScore(){

    double min_score = 32000;

    Node *aux = head;
    //min_score = head->getData().getScore();
    while(aux != NULL){

        if(aux->getData().getScore() < min_score){
            min_score = aux->getData().getScore();
            //t = aux->getData();
        }

        aux = aux->getNext();
    }
    return min_score;

}

void List::Delete_Write(int no_teams, ofstream &out){

    //Delete_Teams(no_teams);
    //Delete_Node(t);
    int n = no_teams - highestPower2(no_teams);
    //Team t;
    //n = 0;
    Node *aux;
    Node *prv;
    //if(no_teams != highestPower2(no_teams)){

        while(n){
            double min_score = Team_lowestScore();
            aux = head;
            while(aux != NULL){

                aux->getData().setPoints(aux->getData().getScore());
                cout << aux->getData().getPoints_sub3() << endl;
                if(min_score == aux->getData().getScore())
                {
                    if(aux->getNext() != NULL)
                    {
                        aux->setData(aux->getNext()->getData());
                        aux->setNext(aux->getNext()->getNext());
                    }
                    else
                    {
                        prv->setNext(NULL);
                    }
                    break;
                }
                prv=aux;
                aux= aux->getNext();
            }
            n--;
        }

   // }
    write_sub2(out);
    //out.close();
    //in.close();
}

void List::write_sub2(ofstream &out){

    Node *temp = this->head;
    while(temp!= NULL){
        temp->getData().write_sub2(out);
        temp = temp->getNext();
    }
}

Node * List::getHead(){

    return head;
}

void List::setHead(Node *n){

    head = n;
}

List::~List(){

    delete head;
    head = NULL;
}

