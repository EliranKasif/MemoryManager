//
// Created by eliran on 11/01/18.
//

#ifndef MEMORY_MEMPOOL_H
#define MEMORY_MEMPOOL_H



class MemPool {

public:
//    static MemPool* getInstance(size_t bytes);
    MemPool(std::size_t bytes);
    void movebrk(const int index);
    void* getCurrentbrk() const;
    char *getPool() const;
    void *getLastbytes() const;
    ~MemPool();

private:
    const std::size_t bytes;
    void* lastbytes;
    char* pool;
    void* currentbrk;
   // static MemPool* Mypool;

};


#endif //MEMORY_MEMPOOL_H
