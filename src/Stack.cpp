#include "Stack.hpp"
#include <iomanip>
//#include <string>

using namespace std;

Stack::Stack(){

    top = NULL;
}

Stack::Stack(Node *n){

    top = new Node;
    top = n;
}

Stack::Stack(const Stack &s){

    top = s.top;
}

Stack & Stack::operator=(const Stack &s){

    top = s.top;
    return *this;
}

void Stack::push(Team t){

    Node *temp = new Node;
    temp->setData(t);
    temp->setNext(top);
    top = temp;
}
Node* Stack::peek(){

    if(top != NULL)

        return top;
    else

        exit(1);
}

void Stack::Reset()
{
    Node* tmp = new Node();
    Node* toDel= new Node();
    toDel = this->top;
    if(top != NULL)
    tmp = this->top->getNext();
    while(toDel != NULL)
    {
        toDel->setNext(NULL);
        toDel = tmp;
        if(tmp != NULL)
        tmp= tmp->getNext();
    }
}

void Stack::Write(int round_no, ofstream &out){

    if(top == NULL){

        cout << "\nUnderflow\n";
    }
    else{

        cout << "test 1";

        Node *temp = new Node;
        temp = top;
        out << endl << "WINNERS OF ROUND NO:" << round_no << endl;
        while(temp != NULL){

             out << setw(34) << left;
             out << temp->getData().getName() << "-";
             out << "  " << fixed << setprecision(2);
             out << temp->getData().getScore() << endl;
             //temp->getData().setPoints(temp->getData().getPoints_sub3());
             temp = temp->getNext();
        }
    }

}

Stack::~Stack(){
}
