#include <iostream>
#include "model/Client.h"
#include "model/Student.h"
#include "model/Address.h"
#include "model/Article.h"
#include "model/Book.h"
#include "managers/ClientManager.h"
#include "exceptions/ClientException.h"
#include <regex>
#include "model/FunctorPredicates.h"

class ChangeObserver : public Observer {

public:
    void notify(ClientPtr ptr) override {
        std::cout << "Informacje o kliencie ulegly zmianie." << std::endl;
        std::cout << "Nowe dane klienta to: " << std::endl;
        std::cout << ptr->getInfo() << std::endl;

    }
};

int main() {

    ClientTypePtr testClientTypeStudent = std::make_shared<Student>();
    AddressPtr testAddress = std::make_shared<Address>("London", "Rue Morgue", "13");
    clientManager c;
    ObserverPtr ct = std::make_shared<ChangeObserver>();
    ClientPtr tancerz = std::make_shared<Client>("Piotr", "Strachota", "1", testAddress, testClientTypeStudent, ct);
    ClientPtr client = c.registerClient("Piotr", "Strachota", "1", testAddress, testClientTypeStudent);
    ClientPtr client2 = c.registerClient("Adam", "Strachot4a", "2", testAddress, testClientTypeStudent);
    ClientPtr client3 = c.registerClient("Janek", "Strachota", "3", testAddress, testClientTypeStudent);
    ClientPtr client4 = c.registerClient("Olgierd", "Strach4ota", "4", testAddress, testClientTypeStudent);


    //testy predykatow/funktorow
    std::regex tango("(Strachyyyy)(.*)");
    LastNamePredicate predicate(tango);
    std::cout << std::boolalpha << predicate(tancerz) << std::endl;

    c.saveAllClientsInfoToFile();
    //tancerz->setName("TancerzPogo");

    try {
        tancerz->setName("");
    }
    catch (const exceptionFirstName &e) {
        std::cout << e.message() << std::endl;
    }


    /*c.unregisterClient("2");
    c.unregisterClient("3");

    std::string test = "Strachota";
    ClientPredicate predicate = [test](ClientPtr ptr) {
        return ptr->getSurname() == test;
    };
    std::vector<ClientPtr> taniec = c.findClients(predicate);
    for(int i = 0; i < taniec.size(); i++) {
        std::cout << taniec[i]->getInfo() << std::endl;
    }*/

    return 0;
}
