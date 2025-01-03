//
// Created by Denisa on 5/10/2024.
//

#ifndef LAB10TONOMAT_BOOK_H
#define LAB10TONOMAT_BOOK_H
#include "iostream";
#include <cstring>
using namespace std;

class Book {
private:
    int id;
    string name;
    int price;
public:
    ///Constructor si destructor
    Book();
    Book(int , string, int);
    ~Book() = default;
    Book(const Book &e);
    int getId();
    void setId(int);
    string getName();
    void setName(string);
    int getPrice();
    void setPrice(int);
    bool operator == (const Book &) const;
    Book& operator=(const Book&);
    bool operator<(const Book&);
    string toString();
    friend ostream& operator<<(ostream& os, const Book& e);
    friend istream& operator>>(istream& is, Book& e);
};


#endif //LAB10TONOMAT_BOOK_H
