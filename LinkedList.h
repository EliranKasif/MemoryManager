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
        ~Node()= default;
    };
    Node* head;

public:
    LinkedList();
    ~LinkedList()=default;
    /*
    * @brief add new address to the Linkedlist
     * throw exception when new is faild.
    * @return void
    */
    void add(void* _data,void* _location);

    /*
    * @brief remove head of the LinkedList
    * throw exception when delete is faild.
    * @return void
    */
    bool remove() throw (linklistException);
    /*
    * @brief check the sizeof the Object in the address of the Node
     * if find sizeof(data)==index so swap between head of list with the Node,
    * @return true if in list , false otherwise
    */
    bool checkifin(char index);
    /*
    * @brief get the Head of the LinkedList
    * @return Node* head
    */
    Node *getHead() const;
    /*
    * @brief toString
    */
    void toString(std::ostream &os) const;

    /*
    * @brief Operator << to print the list
    * @return ostream
    */
    friend std::ostream &operator<<(std::ostream &os, const LinkedList &list);

    void setHead(void *head);
};




#endif //MEMORY_LINKEDLIST_H
