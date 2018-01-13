//
// Created by eliran on 13/01/18.
//

#ifndef MEMORY_LINKLISTEXCEPTION_H
#define MEMORY_LINKLISTEXCEPTION_H


#include "MyException.h"

class linklistException: public MyException {
public:
    const char *what() const noexcept override;

    virtual ~linklistException();

};




#endif //MEMORY_LINKLISTEXCEPTION_H
