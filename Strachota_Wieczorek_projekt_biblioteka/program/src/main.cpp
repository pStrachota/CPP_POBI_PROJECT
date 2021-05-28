#include <iostream>
#include "model/Client.h"
#include "model/Student.h"
#include "model/Address.h"
#include "model/Article.h"
#include "model/Book.h"
#include "managers/ClientManager.h"

int main() {

    ClientTypePtr testClientTypeStudent = std::make_shared<Student>();
    AddressPtr testAddress = std::make_shared<Address>("London", "Rue Morgue", "13");
    clientManager c;

    ClientPtr client = c.registerClient("Piotr", "Strachota", "1", testAddress, testClientTypeStudent);
    ClientPtr client2 = c.registerClient("Adam", "Strachot4a", "2", testAddress, testClientTypeStudent);
    ClientPtr client3 = c.registerClient("Janek", "Strachota", "3", testAddress, testClientTypeStudent);
    ClientPtr client4 = c.registerClient("Olgierd", "Strach4ota", "4", testAddress, testClientTypeStudent);

    c.unregisterClient("2");
    c.unregisterClient("3");

    std::string test = "Strachota";
    ClientPredicate predicate = [test](ClientPtr ptr) {
        return ptr->getSurname() == test;
    };
    std::vector<ClientPtr> taniec = c.findClients(predicate);
    for(int i = 0; i < taniec.size(); i++) {
        std::cout << taniec[i]->getInfo() << std::endl;
    }

    /* kilka drobnych testow
    Book b1("123","john","WAWA2","MDM");
    std::cout << b1.getRentableItemInfo() << "\n";
    std::cout << b1.getBookInfo()<< "\n";
    Article a1("123","john","WAWA2","MDM");
    std::cout << a1.getRentableItemInfo() << "\n";
    std::cout << a1.getArticleInfo();
    */
    return 0;
}
