#include <iostream>
#include "LinkedList.h"
#include "MemoryManager.h"


int main(int argc,char* argv[]) {
    try {
        char *u = new char('a');
        std::cout << *u << std::endl;
        delete (u);
        int *x = new int(240);
        std::cout<< *x << std::endl;
        delete (x);
        double *y = new double(250);
        std::cout<< *y << std::endl;
        int* j=new int[4];
        j[1]=80;
        j[2]=9;
        j[0]=8;
        j[3]=78;
        std::cout<<j[1]<<", "<< j[2]<<", " <<j[0]<<", " <<j[3];
        delete[](j);
        double* l=new double[5];
        delete l;

    }
    catch (std::bad_alloc){
        std::cerr<<"No more space in the pool!!!"<<std::endl;
        exit(1);
    }
    return 0;
}