#include <iostream>
#include "LinkedList.h"
#include "argumentException.h"
#include "MemPool.h"

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
        char* o=new char[900];
        delete[](o);
        char* q=new char[900];
        delete [] q;
        char *u = new char('a');
        std::cout << *u << std::endl;
        delete (u);
        int *x = new int(240);
        std::cout<< *x << std::endl;
        delete (x);
        char* w=new char[4];
        delete[](w);
        double *y = new double(250);
        delete(y);
        std::cout<< *y << std::endl;
        int* j=new int(8);
        delete (j);
        double* l=new double[5];
        delete [] l;

        Complex* complex=new Complex(2,-6.8);
        std::cout<<"Fake: "<<complex->fake << " Real: "<<complex->real<<std::endl;
        delete(complex);
        Complex** bdika= new Complex*[10] ;
        bdika[5]=new Complex(7,9.5);
        std::cout<<"Fake: "<<bdika[5]->fake << " Real: "<<bdika[5]->real;
        delete [] bdika;


    }
    catch (const MyException& e){
        std::cerr<<e.what()<<std::endl;
        MemPool::deleteInstance();
        exit(1);
    }
    MemPool::deleteInstance();
    return 0;
}