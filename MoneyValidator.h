//
// Created by Denisa on 5/13/2024.
//

#ifndef LAB10TONOMAT_MONEYVALIDATOR_H
#define LAB10TONOMAT_MONEYVALIDATOR_H

#include "InvalidCodeException.h"

class MoneyValidator {
private:
    int firstValidValue;
    int secondValidValue;
    int thirdValidValue;
public:
    MoneyValidator(int firstValue, int secondValue, int thirdValue) :
            firstValidValue(firstValue),
            secondValidValue(secondValue),
            thirdValidValue(thirdValue) {}
    void validate(int value) {
        if (value != firstValidValue && value != secondValidValue && value != thirdValidValue) {
            throw InvalidCodeException("Enter a valid value!!");
        }
    }

};

#endif //LAB10TONOMAT_MONEYVALIDATOR_H
