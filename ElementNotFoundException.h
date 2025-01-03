//
// Created by Denisa on 5/13/2024.
//

#ifndef LAB10TONOMAT_ELEMENTNOTFOUNDEXCEPTION_H
#define LAB10TONOMAT_ELEMENTNOTFOUNDEXCEPTION_H
#include <stdexcept>

class ElementNotFoundException :
        public std::runtime_error{
private:
    char* message;
public:
    ElementNotFoundException(char* msg):
            std::runtime_error(msg), message(msg){
    }
    char* what(){
        return message;
    }

};

#endif //LAB10TONOMAT_ELEMENTNOTFOUNDEXCEPTION_H
