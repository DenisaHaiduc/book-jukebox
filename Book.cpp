//
// Created by Denisa on 5/10/2024.
//

#include "Book.h"

Book::Book() {
    id = -1;
    name = "";
    price = -1;
}

Book::Book(const Book &e) {
    this->id = e.id;
    this->name = e.name;
    this->price = e.price;
}

Book::Book(int newId, string newName, int newPrice) {
    this->id = newId;
    this->name = newName;
    this->price = newPrice;
}

int Book::getId() {
    return this->id;
}

int Book::getPrice() {
    return this->price;
}

void Book::setId(int newId) {
    this->id = newId;
}

string Book::getName() {
    return this->name;
}

void Book::setName(string newName) {
    this->name = newName;
}

void Book::setPrice(int newPrice) {
    this->price = newPrice;
}

bool Book::operator==(const Book &e) const {
    return (this->id ==e.id && this->name == e.name && this->price == e.price) ;
}

Book &Book::operator=(const Book &e) {
    this->id = e.id;
    this->name = e.name;
    this->price = e.price;
    return *this;
}

bool Book::operator<(const Book &e) {
    return (this->price < e.price);
}

ostream &operator<<(ostream &os, const Book &e) {
    os <<e.id <<" "<<e.name<<" "<<e.price;
    return os;
}

istream &operator>>(istream &is, Book &e) {
    is>>e.id>>e.name>>e.price;
    return is;
}
