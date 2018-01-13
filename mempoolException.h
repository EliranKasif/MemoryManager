//
// Created by eliran on 13/01/18.
//

#ifndef MEMORY_MEMPOOLEXCEPTION_H
#define MEMORY_MEMPOOLEXCEPTION_H


#include "MyException.h"

class mempoolException: public MyException {
public:
    const char *what() const noexcept override;

    virtual ~mempoolException();


};



#endif //MEMORY_MEMPOOLEXCEPTION_H
