//
// Created by eliran on 13/01/18.
//

#include "argumentException.h"


const char *argumentException::what() const noexcept {
    return "You should run the program like this:\n"
            "./Memory -S 2000\n"
            "which the flag -S is setup and the number 2000 is the size of the MemoryPool for example.\n";
}

argumentException::~argumentException() {

}