cmake_minimum_required(VERSION 3.9)
project(Memory)

set(CMAKE_CXX_STANDARD 11)

add_executable(Memory main.cpp LinkedList.cpp LinkedList.h MemPool.cpp MemPool.h MemoryManager.cpp MemoryManager.h MyException.cpp MyException.h argumentException.cpp argumentException.h mempoolException.cpp mempoolException.h linklistException.cpp linklistException.h)