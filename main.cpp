#include <iostream>
#include "argumentException.h"
#include "MemPool.h"
#include "MemoryManager.h"

int MemoryManager:: valgrind=0;

class Complex{//for the tests.
public:
    Complex(double r, double i):real(r),fake(i){}
    Complex()= default;
    double real;
    double fake;
};

std::size_t checkArgument(int argc, char*argv[])throw(argumentException){
    if(argc < 3 || argc > 3){
        throw argumentException();
    }
    std::string setup (argv[1]);
    std::size_t bytes=0;
    if(!setup.compare("-S")){
        try {
            bytes = std::stoi(argv[2]);
        }
        catch (std::exception){
            throw argumentException();
        }
        return bytes;
    }
    else
        throw argumentException();

}

int main(int argc,char* argv[]) {
    try {
        std::size_t bytes=checkArgument(argc,argv);
        MemPool::getInstance((bytes));
        std::cout<<"Your Memory Pool size is: "<<bytes<<" Bytes."<<std::endl;
        char* w2=new char[3];
        int* p=new int(3);
        int* j=new int(8);
        delete p;
        delete (j);
        int* p1=new int(3);
        int* j2=new int(8);
        delete p1;
        delete (j2);
        Complex* comp=new Complex(3,8);
        Complex* comp2=new Complex[10];
        delete w2;
        delete comp;
        delete comp2;
        if(!MemoryManager::valgrind){
            std::cout<<"Valgrind: "<<MemoryManager::valgrind<<std::endl;
            std::cout<<"Congrat you dont have Memory Leaks"<<std::endl;
        }
        else{
            std::cout<<"Valgrind: "<<MemoryManager::valgrind<<std::endl;
            std::cout<<"You have Memory Leaks!! check the file main.cpp and run make"<<std::endl;

        }
    }
    catch (const MyException& e){
        std::cerr<<e.what()<<std::endl;
        MemPool::deleteInstance();
        exit(1);
    }
    MemPool::deleteInstance();
    return 0;
}