//
// Created by eliran on 11/01/18.
//

#include <iostream>
#include "LinkedList.h"
#include "MemPool.h"


LinkedList::LinkedList():head(nullptr){}

void LinkedList::add(void* _data, void* _location){
        Node *temp = new (_location) Node();
        temp->data = _data;
        temp->next = head;
        head = temp;
}


bool LinkedList::remove() throw (linklistException){
    if(!head){ //the list is empty
        return false;
    }
    else{ // the list is not empty
        head = head->next;
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

void LinkedList::setHead(void *head) {
    LinkedList::head = (LinkedList::Node*)head;
}

//LinkedList::~LinkedList(){
//    while(remove()){}
//}
