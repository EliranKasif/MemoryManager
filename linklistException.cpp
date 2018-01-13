//
// Created by eliran on 13/01/18.
//

#include "linklistException.h"

const char *linklistException::what() const noexcept {
    return "Can't create freelist Node on MemPool, there is no space in MemPool";
}

linklistException::~linklistException() {

}