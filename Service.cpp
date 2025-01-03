//
// Created by Denisa on 5/9/2024.
//

#include "Service.h"
#include "EntityValidator.h"
#include "MoneyValidator.h"
#include "ElementNotFoundException.h"

Service::Service() {
}
Service::Service(RepositoryFile<Book> &entityRepo, RepositoryFile<Money> &moneyRepo) :
EntityRepo(entityRepo), MoneyRepo(moneyRepo){}

void Service::add(int id, string name, int price) {
    Book entity(id, name, price);
    EntityValidator val(EntityRepo.getSize());
    val.validate(entity.getId());
    EntityRepo.addEntity(entity);
}
void Service::addMoney(int type, int value) {
    Money money(value, type);
    MoneyValidator val(1, 5, 10);
    val.validate(type);
    MoneyRepo.addEntity(money);
}
void Service::remove(int id, string name, int price) {
    Book entity(id, name, price);
    cout << EntityRepo.findEntity(entity) << endl;
    if (EntityRepo.findEntity(entity) == -1) {
        cout << EntityRepo.findEntity(entity);
        throw ElementNotFoundException("The book wasn't found!!");
    }
    EntityRepo.deleteEntity(entity);
}
void Service::deleteMoney(int type, int value) {
    Money money(value, type);
    MoneyRepo.loadFromFile();
    if (MoneyRepo.findEntity(money) == -1) {
        throw ElementNotFoundException("The money wasn't found!!");
    }
    MoneyRepo.deleteEntity(money);
}
void Service::update(int id, string name, int price, int newId, string newName, int newPrice) {
    Book entity(id, name, price);
    Book newEntity(newId, newName, newPrice);
    if (EntityRepo.findEntity(entity) == -1) {
        throw ElementNotFoundException("The book wasn't found!!");
    }
    EntityRepo.updateEntity(entity, newEntity);
}
void Service::updateMoney(int type, int value) {
    MoneyRepo.loadFromFile();
    Money money(value, type);
    Money newMoney(money.getValue() + value, type);
    MoneyRepo.updateEntity(money, newMoney);
}
int Service::find(int id, string name, int price) {
    Book entity(id, name, price);
    EntityRepo.loadFromFile();
    return EntityRepo.findEntity(entity);
}
vector<Book> Service::getAll() {
    EntityRepo.loadFromFile();
    return EntityRepo.getAll();
}
vector<Book> Service::filterByPrice() {
    vector<Book> sortEntities;
    vector<Book> entities = EntityRepo.getAll();
    sort(entities.begin(), entities.end());
    for (auto entity: entities) {
        sortEntities.push_back(entity);
    }
    return sortEntities;
}

int Service::size() {
    EntityRepo.loadFromFile();
    return EntityRepo.getSize();
}

Book Service::getTopDrink() {
    vector<Book> topDrink;
    topDrink = filterByPrice();
    int n= EntityRepo.getSize();
    return topDrink[n-1];
}
