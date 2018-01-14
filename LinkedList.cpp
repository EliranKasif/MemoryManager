//
// Created by eliran on 11/01/18.
//

#include <iostream>
#include "LinkedList.h"


LinkedList::LinkedList():head(nullptr){}


void LinkedList::add(void* _data) throw (linklistException){
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
    catch (const MyException& e){
        throw linklistException();
    }



}

bool LinkedList::remove() throw (linklistException){
    if(!head){ //the list is empty
        return false;
    }
    else{ // the list is not empty
        Node* temp=head;
        head = head->next;
        try {
            delete temp;
        }
        catch(const MyException& e){
            throw linklistException();
        }
        return true;
    }
}

bool LinkedList::checkifin(char index){ // O(n) n=length of LinkedList
    bool ans=false;
    Node* temp=head;
    while(temp){
        char* size=(char*)(temp->data - sizeof(char));//to obttain the real allocate num
        if(*size==index){//swap between head data to temo data.
            void* data=head->data;
            head->data=temp->data;
            temp->data=data;
            ans=true;
            return ans;
        }
        temp=temp->next;
    }
    return ans;
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
