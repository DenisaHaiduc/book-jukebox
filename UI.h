//
// Created by Denisa on 5/9/2024.
//

#ifndef LAB10TONOMAT_UI_H
#define LAB10TONOMAT_UI_H
#include "Service.h"

class UI {
private:
    /// OPERATII CRUD
    Service service;
    void add();
    void remove();
    void update();
    void find();
    void getAll();
public:
    /// Constructor si destructor
    UI();
    UI(Service &);
    ~UI();

    /// Interfata
    void adminMenu();
    void userMenu();
    void menu();

    /// Functionalitati
    void filterByPrice();
    void topBook();


};


#endif //LAB10TONOMAT_UI_H
