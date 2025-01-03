//
// Created by Denisa on 5/9/2024.
//

#ifndef LAB10TONOMAT_SERVICE_H
#define LAB10TONOMAT_SERVICE_H


#include "Repository.h"
#include "RepoFile.h"
#include "Money.h"
#include "Book.h"

class Service {
    RepositoryFile<Book> EntityRepo;
    RepositoryFile<Money> MoneyRepo;
public:
    Service();
    Service(RepositoryFile<Book> &, RepositoryFile<Money> &);
    ~Service() = default;
    void add(int, string, int);
    void addMoney(int type, int value);
    void remove(int, string, int);
    void deleteMoney(int type, int value);
    void update(int, string, int, int, string, int);
    void updateMoney(int type, int value);
    int find(int, string, int);
    vector<Book> getAll();
    vector<Book> filterByPrice();
    Book getTopDrink();
    int size();
};


#endif //LAB10TONOMAT_SERVICE_H
