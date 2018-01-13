//
// Created by eliran on 11/01/18.
//

#include <cstdlib>
#include "MemPool.h"



MemPool::MemPool(size_t _bytes):bytes(_bytes){
    pool=(char*)malloc(_bytes);
    currentbrk=pool;
    lastbytes=&pool[_bytes];
}

void MemPool::movebrk(const int index){
    currentbrk += index;
}


void* MemPool::getCurrentbrk() const {
    return currentbrk;
}

char *MemPool::getPool() const {
    return pool;
}

void *MemPool::getLastbytes() const {
    return lastbytes;
}

MemPool::~MemPool(){
    free(pool);
}
