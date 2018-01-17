//
// Created by eliran on 11/01/18.
//

#ifndef MEMORY_MEMPOOL_H
#define MEMORY_MEMPOOL_H



class MemPool {

public:
    /*
     * @brief getInstance for create 1 instance of the MemPool(Singleton)
     * @param size_t bytes,default argument for the sizeof Mempool
     * @return static MemPool*
     */
    static MemPool* getInstance(size_t bytes = 0);
    /*
    * @brief deleteInstance for delete 1 instance of the MemPool(Singleton)
    */
    static void deleteInstance();
    /*
    * @brief to move the current pointer in the MemPool to the current location of the valid address
    * @param index
    */
    void movebrk(const int index);
    /*
    * @brief return the address of the current brk
    * @return void* currentbrk
    */
    void* getCurrentbrk() const;
    /*
    * @brief return the last address of the pool
    * @return void* lastbytes
    */
    void *getLastbytes() const;

    ~MemPool();

    char *getPool() const;

private:
    void* lastbytes;
    char* pool;
    void* currentbrk;
    static MemPool* Mypool;

};


#endif //MEMORY_MEMPOOL_H
