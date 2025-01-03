#include <unistd.h>
#include <limits>
#include "UI.h"
#include "EntityValidator.h"
#include "MoneyValidator.h"
#include "ElementNotFoundException.h"
/// Constructor si destructor
UI::UI() {}

UI::UI(Service &service1) {
    this->service = service1;
}

UI::~UI() {}


/// Interfata

void UI::menu() {
    string role;
    cout << "Enter your role (user/admin):";
    cin >> role;
    if (role == "admin") {
        cout << "Enter the password:";
        int password;
        cin >> password;
        if (password == 1234) {
            adminMenu();
        } else {
            cout << "You are not authorized to access the admin page!!";
        }
    }
    else if (role == "user") {
        userMenu();
    }
}

void UI::adminMenu() {
    bool isTrue = true;
    while (isTrue) {
        cout << "      Menu: " << endl;
        cout << "1) Add a book" << endl;
        cout << "2) Delete a book" << endl;
        cout << "3) Update a book" << endl;
        cout << "4) Find a book by id" << endl;
        cout << "5) Show all books:" << endl;
        cout << "6) Sort books by price:" << endl;
        cout << "7) Show the most expensive book in the store: " << endl;
        cout << "8) Switch to user menu" << endl;
        cout << "0) Exit" << endl;
        int option;
        cout << "Choose an option:";
        cin >> option;
        switch (option) {
            case 1:
                add();
                break;
            case 2:
                remove();
                break;
            case 3:
                update();
                break;
            case 4:
                find();
                break;
            case 5:
                getAll();
                break;
            case 6:
                filterByPrice();
                break;
            case 7:
                topBook();
                break;
            case 8:
                userMenu();
                break;
            case 0:
                isTrue = false;
                break;
        }
    }
}

void UI::userMenu() {
    int opt=1;
    cout<<endl<<"Hello! Welcome to our shop!"<<endl;
    vector<Book> commands;
    while(opt!=0){
        cout<<"This is the list of books we have in our store!"<<endl;
        cout<<"___________________"<<endl;
        getAll();
        cout<<"-------------------";
        cout <<endl<< "Which book would you like to buy? Select one (enter the id):";
        int id;
        cin >> id;
        int price = -1;
        vector<Book> entities = service.getAll();
        for (auto entity : entities) {
            if (entity.getId() == id) {
                price = entity.getPrice();
                commands.push_back(entity);
            }
        }
        if (price == -1){
            cout << "Invalid book id. Please give us a correct one!!" << endl;
            continue;
        }
        cout << "The price of the selected book is " << price << " lei" << endl;
        cout << "You can insert banknotes of 1/5/10 lei to buy a book" << endl;
        cout << "Please insert a banknote:";
        int banknote;
        cin >> banknote;
        MoneyValidator val(1, 5, 10);
        while (banknote != 1 && banknote != 5 && banknote != 10) {
            val.validate(banknote);
            cin >> banknote;
        }
        while (banknote < price) {
            cout << "The entered value is insufficient! Please insert more banknotes:";
            int newBanknote;
            cin >> newBanknote;
            banknote += newBanknote;
        }
        int rest;
        rest = banknote - price;
        while (price) {
            if (price >= 10) {
                service.updateMoney(10, 10);
                price -= 10;
            } else if (price >= 5) {
                service.updateMoney(5, 5);
                price -= 5;
            }
            else if (price >= 1) {
                service.updateMoney(1, 1);
                price -= 1;
            }
        }
        cout << "Sufficient amount! Your balance is " << rest  << " lei" << endl;
        cout<<"Would you like to buy more books?  (Yes/No): ";
        string answer;
        cin>>answer;
        if(answer == "yes")
            continue;
        else if(answer == "no")
            opt=0;
    }
    cout << "Your book(s) is(are) being prepared..." << endl;
    sleep(5);
    cout << "Your book(s) is(are) ready! You can come and take it(them)!" << endl;
    cout<<"Your command(s) was(were): ";
    for(int i=0; i<commands.size();i++)
        cout<<commands[i].getName()<<" , ";
    cout<<endl;
    cout << "Have a great day !" << endl<<endl;
}

/// OPERATII CRUD

void UI::add() {
    int id;
    cout << "Enter the id:";
    cin >> id;
    string name;
    cout << "Enter the name:";
    cin >> name;
    int price;
    cout << "Enter the price:";
    cin >> price;
    int ok = false;
    vector<Book> entities = service.getAll();
    for (auto entity : entities) {
        if (entity.getId() == id) {
            ok = true;
        }
    }
    if (ok == false) {
        service.add(id, name, price);
    } else {
        EntityValidator val(service.size());
        val.validate(id);
    }
}

void UI::remove() {
    int id;
    bool ok = false;
    cout << "Enter the id:";
    cin >> id;
    cout << endl;
    vector<Book> entities = service.getAll();
    for (auto entity : entities) {
        if (entity.getId() == id) {
            ok = true;
            service.remove(entity.getId(), entity.getName(), entity.getPrice());
        }
    }
    if (!ok) {
        throw ElementNotFoundException("The book wasn't found!!");
    }
}

void UI::update() {
    int id;
    bool ok = false;
    cout << "Enter the id:";
    cin >> id;
    cout << endl;
    int newId;
    cout << "Enter new id:";
    cin >> newId;
    cout << endl;
    string newName;
    cout << "Enter new name:";
    cin >> newName;
    cout << endl;
    int newPrice;
    cout << "Enter new price:";
    cin >> newPrice;
    cout << endl;
    vector<Book> entities = service.getAll();
    for (auto entity : entities) {
        if (entity.getId() == id) {
            ok = true;
            service.update(entity.getId(), entity.getName(), entity.getPrice(), newId, newName, newPrice);
        }
    }
    if (!ok) {
        throw ElementNotFoundException("The book wasn't found!!");
    }
}

void UI::find() {
    int id;
    cout << "Enter the id:" << endl;
    cin >> id;
    bool ok = false;
    vector<Book> entities = service.getAll();
    for (auto entity : entities) {
        if (entity.getId() == id) {
            ok = true;
            cout << entity.getId() << " " << entity.getName() << " " << entity.getPrice() << endl;
        }
    }
    if (ok == false) {
        throw ElementNotFoundException("The book wasn't found!!");
    }
}

void UI::getAll() {
    vector<Book> entities = service.getAll();
    for (auto entity : entities) {
        cout << entity.getId() << " " << entity.getName() << " " << entity.getPrice() << endl;
    }
}


/// FUNCTIONALITATI

void UI::filterByPrice() {
    vector<Book> sortEntities = service.filterByPrice();
    for (auto entity : sortEntities) {
        cout << entity << endl;
    }
}

void UI::topBook() {
    cout<<service.getTopDrink()<<endl;
}



