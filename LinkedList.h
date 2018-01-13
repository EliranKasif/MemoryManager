//
// Created by eliran on 11/01/18.
//

#ifndef MEMORY_LINKEDLIST_H
#define MEMORY_LINKEDLIST_H


#include <ostream>
#include "linklistException.h"

class LinkedList {
private:
    struct Node{
        Node():data(0),next(nullptr){}
        void* data;
        Node* next;
    };
    Node* head;

public:
    LinkedList();
    void add(void* _data) throw (linklistException);
    bool remove() throw (linklistException);
    bool checkifin(char index);
    Node *getHead() const;
    void toString(std::ostream &os) const;
    friend std::ostream &operator<<(std::ostream &os, const LinkedList &list);
    //~LinkedList();
};




#endif //MEMORY_LINKEDLIST_H
