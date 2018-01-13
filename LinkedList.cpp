//
// Created by eliran on 11/01/18.
//

#include <iostream>
#include "LinkedList.h"


LinkedList::LinkedList():head(nullptr){}


void LinkedList::add(void* _data){
    try {
        if (!head) { //the list is empty
            Node *temp = new Node();
            temp->data = _data;
            head = temp;
        } else { // the list is not empty
            Node *temp = new Node();
            temp->data = _data;
            temp->next = head;
            head = temp;

        }
    }
    catch (std::bad_alloc){
        std::cerr<<"No more space in the pool!!!"<<std::endl;
        exit(1);
    }



}

bool LinkedList::remove(){
    if(!head){ //the list is empty
        return false;
    }
    else{ // the list is not empty
        Node* temp=head;
        head = head->next;
        delete temp;
        return true;
    }
}
LinkedList::Node *LinkedList::getHead() const {
    return head;
}
void LinkedList::toString(std::ostream &os) const{
    Node* temp=head;
    while(temp){
        os<<temp->data<<", ";
        temp=temp->next;
    }
    os<<std::endl;
}

std::ostream &operator<<(std::ostream &os, const LinkedList &list) {
    list.toString(os);
    return os;
}

//LinkedList::~LinkedList(){
//    while(remove()){}
//}
