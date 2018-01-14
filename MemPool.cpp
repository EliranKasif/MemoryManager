//
// Created by eliran on 11/01/18.
//

#include <cstdlib>
#include "MemPool.h"

MemPool* MemPool:: Mypool= nullptr;

 MemPool* MemPool:: getInstance(size_t bytes ){
     if(!Mypool){
         Mypool=(MemPool*)malloc(sizeof(MemPool)+bytes);
         Mypool->pool=(char*)malloc(bytes);
         Mypool->currentbrk= Mypool->pool;
         Mypool->lastbytes=&(Mypool->pool[bytes]);
         return Mypool;
     }
     return Mypool;
}
void MemPool::movebrk(const int index){
    currentbrk += index;
}


void* MemPool::getCurrentbrk() const {
    return currentbrk;
}
void *MemPool::getLastbytes() const {
    return lastbytes;
}

void MemPool::deleteInstance(){
    if(Mypool) {
        free(Mypool->pool);
        free(Mypool);
    }
}
MemPool::~MemPool(){
}

