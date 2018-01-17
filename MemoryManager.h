//
// Created by eliran on 11/01/18.
//

#ifndef MEMORY_MEMORYFROMMEMPOOL_H
#define MEMORY_MEMORYFROMMEMPOOL_H


#include "MemPool.h"
#include "LinkedList.h"

class MemoryManager{
public:
    int static valgrind;
    /*
    * @brief newPlacment check first if there is room in the freelist and return Node.data addrress,
     * otherwise take from the Mempool if can.
    * @return void* for the Operator new
    */
    static void* newPlacment(std::size_t n) throw (linklistException);
    /*
    * @brief deletePlacment add the address (void* n) to the freelist,
    * @param void* n (the address to delete) throw Exception if add() to freelist fails.
    * @return void
    */
    static void deletePlacment(void* n) throw (linklistException);
private:
    static LinkedList freelist[9];
    /*
    * @brief check if there is free address from the freelist in position index
     * if index > 9 (2^9) so go to the freelist in position 9 and check there who the address that
     * fit to the request!
    * @param char
    * @return void
    */
    static bool check_if_in_freelist(char size);
    /*
    * @brief check if there is free address in the MemPool
    * @param const in size
    * @return true if can allocate memory, otherwise false for no more free memory in Mempool.
    */
    static bool check_if_place_pool(const int size);
};
#endif // MEMORY_MEMORYFROMMEMPOOL_H
