//
// Created by eliran on 13/01/18.
//

#ifndef MEMORY_ARGUMENTEXCEPTION_H
#define MEMORY_ARGUMENTEXCEPTION_H


#include "MyException.h"

class argumentException: public MyException {
public:
    const char *what() const noexcept override;

    virtual ~argumentException();

};




#endif //MEMORY_ARGUMENTEXCEPTION_H
