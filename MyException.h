//
// Created by eliran on 13/01/18.
//

#ifndef MEMORY_MYEXCEPTION_H
#define MEMORY_MYEXCEPTION_H


#include <exception>

class MyException: public std::exception {

public:
    virtual const char *what() const noexcept override=0;

    virtual ~MyException();
};



#endif //MEMORY_MYEXCEPTION_H
