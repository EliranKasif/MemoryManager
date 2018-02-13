//
// Created by eliran on 11/01/18.
//

#include <new>
#include <iostream>
#include <complex>
#include "MemoryManager.h"
#include "mempoolException.h"


int MemoryManager::SIZE_OF_FREELIST_NODE = 4;
int MemoryManager::FREELIST_SIZE = 9;
LinkedList MemoryManager::freelist[9];//max is 2^9=512 bytes... every request more then 512 will enter to freelist[9]
void * operator new (std::size_t n)throw(mempoolException,linklistException){
    try {
        void *ans = MemoryManager::newPlacment(n);
        if(!ans){
            throw mempoolException();

        }
        else {
            MemoryManager::valgrind++;
            return ans;
        }
    }
    catch(const linklistException& e){
        throw e;
    }
    catch (const mempoolException& e){
        throw e;
    }

}

void operator delete (void* n){
    try {
        MemoryManager::deletePlacment(n);
        MemoryManager::valgrind--;

    }
    catch (const MyException& e){
        std::cerr<<e.what()<<std::endl;
        MemPool::deleteInstance();
        exit(1);
    }

}

void * operator new[] (std::size_t n)throw(mempoolException,linklistException){

    try {
        void *ans = MemoryManager::newPlacment(n);
        if(!ans){
            throw mempoolException();

        }
        else {
            MemoryManager::valgrind++;
            return ans;
        }
    }
    catch(const linklistException& e){
        throw e;
    }
    catch (const mempoolException& e){
        throw e;
    }
}

void operator delete[] (void* n){
    try {
        MemoryManager::deletePlacment(n);
        MemoryManager::valgrind--;
    }
    catch (const MyException& e){
        std::cerr<<e.what()<<std::endl;
        MemPool::deleteInstance();
        exit(1);
    }
}

void* MemoryManager:: newPlacment(std::size_t n)throw (linklistException){
    char index=0;
    void* ans=0;
    bool above512=false;
    while(n>std::pow(2,index)){
        index++;
    }
    char index2=index;
    if(index>FREELIST_SIZE){
        index=FREELIST_SIZE;
        above512=true;
    }
    if(freelistContain(above512 ? index2 : index)){
        void* temp=freelist[index].getHead()->data; //get the address to new placemnt
        char* size=(char*)temp-sizeof(char); //get the address to the num of bytes to alocated
        *size=above512 ? index2 : index; //change the number of bytes to allocated
        ans=temp;
        void* prev=freelist[index].getHead();//save the head before remove
        freelist[index].remove();//remove the head
        if(*size != SIZE_OF_FREELIST_NODE) {//if size is diffrent from sizeof(Node) so move the Previeus Head to the freelist[sizeOf(Node)]
            freelist[SIZE_OF_FREELIST_NODE].add(prev, prev);//add the Node to point to himself and it indicate to free location for new alloc with sizeof(Node)
        }
        return ans;

    }
    else if(ifMemPool((int)std::pow(2,above512 ? index2 : index)+sizeof(char))){
        ans=MemPool::getInstance()->getCurrentbrk();
        char* size=static_cast<char*>(ans); // adding a "header" to the address to allocate to indicate what the sizeof the type
        *size=above512 ? index2 : index;//emplace the num of bytes to alocated
        ans=static_cast<void*>(size+sizeof(char));//move the address to the next byte to alocate
        MemPool::getInstance()->movebrk((int)std::pow(2,above512 ? index2 : index)+sizeof(char));
        return ans;
    }
    else
        return ans;



}



bool MemoryManager::ifMemPool(const int size){
    char* temp= static_cast<char*>(MemPool::getInstance()->getCurrentbrk());
    if(temp+size <= MemPool::getInstance()->getLastbytes()){
        return true;
    }
    return false;
    //return (MemPool::getInstance()->getCurrentbrk()+size <= MemPool::getInstance()->getLastbytes());
}

bool MemoryManager::freelistContain(char size){
    if(size>FREELIST_SIZE){
        return freelist[FREELIST_SIZE].checkifin(size);
    }
    else {
        return (bool) freelist[size].getHead();
    }

}


void MemoryManager::deletePlacment(void* data) throw (linklistException){
    char* size= (static_cast<char*> (data) - sizeof(char));
    char index=*size;
    if(*size>FREELIST_SIZE)
    {
        index=FREELIST_SIZE;
    }
    if (*size==SIZE_OF_FREELIST_NODE){ //if the block to delete equal to sizeof(Node) make it a Node and add to the freelist[sizeof(Node)]
        freelist[SIZE_OF_FREELIST_NODE].add(data,data);
    }
    else if(freelistContain(SIZE_OF_FREELIST_NODE)){ //if there is alredy Node in the freelist take from it.
        void* temp=freelist[SIZE_OF_FREELIST_NODE].getHead()->data; //get the address to new placemnt
        char* size=(char*)temp-sizeof(char); //get the address to the num of bytes to alocated
        *size=SIZE_OF_FREELIST_NODE; //change the number of bytes to allocated
        void* next=freelist[SIZE_OF_FREELIST_NODE].getHead()->next;//Save the next of the list
        freelist[index].add(data,temp);//add to the freelist and create the new Node which data: pointer to free location and temp:where to Placment new Node.
        freelist[SIZE_OF_FREELIST_NODE].setHead(next);//make the head to point to the next
    }
    else if(ifMemPool((int)std::pow(2,SIZE_OF_FREELIST_NODE)+sizeof(char))) {//take from the Mempool to create new Node.
        void *location = MemPool::getInstance()->getCurrentbrk();
        char *header = static_cast<char*>(location);
        *header = SIZE_OF_FREELIST_NODE;
        location=static_cast<void*>(header+sizeof(char));
        freelist[index].add(data, location);//add new Node to the freelist[Index]
        MemPool::getInstance()->movebrk((int) std::pow(2, SIZE_OF_FREELIST_NODE) + sizeof(char));

    }
    else{
        throw linklistException();
    }
}