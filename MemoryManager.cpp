//
// Created by eliran on 11/01/18.
//

#include <new>
#include <iostream>
#include <complex>
#include "MemoryManager.h"
#include "mempoolException.h"


LinkedList MemoryManager::freelist[9];//max is 2^9=512 bytes... every request more then 512 will enter in freelist[9]

void * operator new (std::size_t n)throw(mempoolException){
    void* ans=MemoryManager::newPlacment(n);
    if(!ans){
        throw mempoolException();
    }
    return ans;
}

void operator delete (void* n){
    try {
        MemoryManager::deletePlacment(n);
    }
    catch (const MyException& e){
        std::cerr<<e.what()<<std::endl;
        exit(1);
    }

}

void * operator new[] (std::size_t n)throw(mempoolException){
    void* ans=MemoryManager::newPlacment(n);
    if(!ans){
        throw mempoolException();
    }
    return ans;
}

void operator delete[] (void* n){
    try {
        MemoryManager::deletePlacment(n);
    }
    catch (const MyException& e){
        std::cerr<<e.what()<<std::endl;
        exit(1);
    }
}

void* MemoryManager:: newPlacment(std::size_t n){
    char index=0;
    void* ans=0;
    bool above512=false;
    while(n>std::pow(2,index)){
        index++;
    }
    char index2=index;
    if(index>9){
        index=9;
        above512=true;
    }
    if(check_if_in_freelist(above512 ? index2 : index)){
        void* temp=freelist[index].getHead()->data; //get the address to new placemnt
        char* size=(char*)temp-sizeof(char); //get the address to the num of bytes to alocated
        *size=above512 ? index2 : index; //change the number of bytes to allocated
        ans=temp;
        freelist[index].remove();
        return ans;

    }
    else if(check_if_place_pool((int)std::pow(2,above512 ? index2 : index)+sizeof(char))){
        ans=MemPool::getInstance()->getCurrentbrk();
        char* size=(char*)ans;
        *size=above512 ? index2 : index;//emplace the num of bytes to alocated
        ans+=sizeof(char);//move the address to the next byte to alocate
        MemPool::getInstance()->movebrk((int)std::pow(2,above512 ? index2 : index)+sizeof(char));
        return ans;
    }
    else
        return ans;



}


bool MemoryManager::check_if_in_freelist(char index){
    if(index>9){
        return freelist[9].checkifin(index);
    }
    return (bool)freelist[index].getHead();

}
bool MemoryManager::check_if_place_pool(const int index){
    if(MemPool::getInstance()->getCurrentbrk()+index <= MemPool::getInstance()->getLastbytes())
        return true;
    return false;

}

void MemoryManager::deletePlacment(void* n) throw (linklistException){
    char* size=(char*) (n - sizeof(char));
    char index=*size;
    if(*size>9)
    {
        index=9;
    }
    try {
        freelist[index].add(n);
    }
    catch (const MyException& e)
    {
        throw linklistException();
    }
}
