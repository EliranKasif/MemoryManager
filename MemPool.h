//
// Created by eliran on 11/01/18.
//

#ifndef MEMORY_MEMPOOL_H
#define MEMORY_MEMPOOL_H



class MemPool {

public:
    static MemPool* getInstance(size_t bytes = 0);
    static void deleteInstance();
    void movebrk(const int index);
    void* getCurrentbrk() const;
    void *getLastbytes() const;

    ~MemPool();

private:
    void* lastbytes;
    char* pool;
    void* currentbrk;
    static MemPool* Mypool;

};


#endif //MEMORY_MEMPOOL_H
