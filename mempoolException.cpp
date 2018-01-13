//
// Created by eliran on 13/01/18.
//

#include "mempoolException.h"

const char *mempoolException::what() const noexcept {
    return "No more space in MemPool to move the current brk";
}

mempoolException::~mempoolException() {

}
