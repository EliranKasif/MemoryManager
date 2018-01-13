//
// Created by eliran on 11/01/18.
//

#ifndef MEMORY_MEMORYFROMMEMPOOL_H
#define MEMORY_MEMORYFROMMEMPOOL_H


#include "MemPool.h"
#include "LinkedList.h"

class MemoryManager{
public:
    static void* newPlacment(std::size_t n);
    static void deletePlacment(void* n);


private:
    static LinkedList freelist[9];
    static MemPool memPool;
    static bool check_if_in_freelist(int index);
    static bool check_if_place_pool(const int index);
};


#endif // MEMORY_MEMORYFROMMEMPOOL_H
