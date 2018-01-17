#include <iostream>
#include "LinkedList.h"
#include "argumentException.h"
#include "MemPool.h"
#include "MemoryManager.h"

int MemoryManager:: valgrind=0;

class Complex{
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
    if(!setup.compare("-s")){
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
    std::size_t bytes=checkArgument(argc,argv);
    MemPool::getInstance((bytes));
    try {
        int* p=new int(3);
        int* j=new int(8);
        std::cout<<"Valgrind: "<<MemoryManager::valgrind<<std::endl;
        delete p;
        delete (j);
        std::cout<<"Valgrind-: "<<MemoryManager::valgrind<<std::endl;
        int* p1=new int(3);
        int* j2=new int(8);
        std::cout<<"Valgrind: "<<MemoryManager::valgrind<<std::endl;
        delete p1;
        delete (j2);
        int* p3=new int(3);
        int* j3=new int(8);
        delete p3;
        delete (j3);
        char* o=new char[16];
        std::cout<<"Valgrind: "<<MemoryManager::valgrind<<std::endl;
        Complex* co=new Complex(5,8);
        delete[](o);
        delete(co);
        Complex* co1=new Complex(5,8);
        Complex* co2=new Complex(5,8);
        delete(co1);
        delete(co2);
        char *u = new char('a');
        std::cout << *u << std::endl;
        delete (u);
        char *u1 = new char('a');
        delete u1;
        Complex* co3=new Complex(5,8);
        delete co3;
        int *x = new int(240);
        std::cout<< *x << std::endl;
        delete (x);
        char* w=new char[4];
        delete[](w);
        double *y = new double(250);
        delete(y);
        std::cout<< *y << std::endl;

        double* l=new double[5];
        delete [] l;

        Complex* complex=new Complex(2,-6.8);
        std::cout<<"Fake: "<<complex->fake << " Real: "<<complex->real<<std::endl;
        delete(complex);
        Complex** bdika= new Complex*[10] ;
        bdika[5]=new Complex(7,9.5);
        std::cout<<"Fake: "<<bdika[5]->fake << " Real: "<<bdika[5]->real<<std::endl;
        delete bdika[5];
        delete [] bdika;
        std::cout<<"Valgrind: "<<MemoryManager::valgrind<<std::endl;
    }
    catch (const MyException& e){
        std::cerr<<e.what()<<std::endl;
        MemPool::deleteInstance();
        exit(1);
    }
    MemPool::deleteInstance();
    return 0;
}