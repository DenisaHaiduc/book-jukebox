//
// Created by Denisa on 5/13/2024.
//

#ifndef LAB10TONOMAT_MONEY_H
#define LAB10TONOMAT_MONEY_H

#include <ostream>
#include <istream>
using namespace std;

class Money {
private:
    int value;
    int type;
public:
    /// Constructori si destructor
    Money();
    Money(int, int);
    ~Money() = default;

    /// Getteri si setteri
    int getValue() const;
    void setValue(int);
    int getType() const;
    void setType(int);

    /// Operatori
    bool operator <(const Money& money) const;
    bool operator==(const Money&) const;
    Money operator *(int scalar) const;
    friend ostream& operator<<(ostream& os, const Money& money);
    friend istream &operator>>(istream &is, Money &money);
};

#endif //LAB10TONOMAT_MONEY_H
