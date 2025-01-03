//
// Created by Denisa on 5/13/2024.
//

#ifndef LAB10TONOMAT_INVALIDCODEEXCEPTION_H
#define LAB10TONOMAT_INVALIDCODEEXCEPTION_H
#include <iostream>
#include <stdexcept>

using namespace std;


class InvalidCodeException : public invalid_argument {
private:
    char* message;
public:
    InvalidCodeException(char* msg): invalid_argument(msg), message(msg) {}
    char* what() {
        return message;
    }
};

#endif //LAB10TONOMAT_INVALIDCODEEXCEPTION_H
