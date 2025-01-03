#include <iostream>
#include "Repository.h"
#include "Service.h"
#include "UI.h"

int main() {
    cout<<endl;
    RepositoryFile<Book> entity("C:\\Users\\Denisa\\CLionProjects\\lab10Tonomat\\Book");
    RepositoryFile<Money> money("C:\\Users\\Denisa\\CLionProjects\\lab10Tonomat\\money");
    Service service(entity, money);
    UI ui(service);
    ui.menu();
    return 0;
}
