//
// Created by Denisa on 5/13/2024.
//

#ifndef LAB10TONOMAT_ENTITYVALIDATOR_H
#define LAB10TONOMAT_ENTITYVALIDATOR_H
#include "InvalidCodeException.h"
class EntityValidator{
private:
    int validId;
public:
    EntityValidator(int id) : validId(id) {}
    void validate (int id) {
        if (id < validId) {
            throw InvalidCodeException("The given id already exists!!");
        }
    }
};

#endif //LAB10TONOMAT_ENTITYVALIDATOR_H
