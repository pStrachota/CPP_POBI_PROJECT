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
#include "model/Rent.h"
#include "managers/RentManager.h"


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
    AddressPtr testaddress1 = std::make_shared<Address>("London", "Accacia Avenue", "22");
    pt::ptime testDate1 = pt::ptime(gr::date(2021,3,1), pt::hours(12) + pt::minutes(30));
    ClientPtr c1 = std::make_shared<Client>("Piotrus", "Strachota", "420", testaddress1, testClientTypeStudent);

    RentableItemPtr book = std::make_shared<Book>("123", "Edison", "Harry Potter","Zodiac");
    RentableItemPtr article = std::make_shared<Article>("777", "Watts", "Harry Potter 2","Harvard");

    RentManager r;
    r.rentRentableItem(c1, book, testDate1);
    r.rentRentableItem(c1, article, testDate1);

    std::string test = "Strachota";
        RentPredicate predicate = [test](const RentPtr& ptr) {
            return ptr->getClient()->getSurname() == test;
       };
    std::vector<RentPtr> proba = r.findRents(predicate);
    std::cout << "powinno byc 2 wypozyczenia, a sa: " << proba.size() << std::endl;

    for(int i = 0; i < proba.size(); i++) {
        std::cout << proba[i]->getRentInfo() << std::endl;
    }

    //std::cout << r.countRents() << std::endl;

//    ClientTypePtr testClientTypeStudent = std::make_shared<Student>();
//
//
//    RentableItemPtr book = std::make_shared<Book>("123", "Edison", "Harry Potter","Zodiac");
//
//
//    AddressPtr testAddress1 = std::make_shared<Address>("London", "Rue Morgue", "13");
//    AddressPtr testAddress2 = std::make_shared<Address>("London", "BakerSt", "21");
//
//    pt::ptime testDate1 = pt::ptime(gr::date(2021,3,1), pt::hours(12) + pt::minutes(30));
//    pt::ptime testDate2 = pt::ptime(gr::date(2021,3,21), pt::hours(12) + pt::minutes(30));
//
//    ClientPtr client1 = std::make_shared<Client>("Jake", "Paul", "007", testAddress1, testClientTypeStudent);
//
//    RentPtr r = std::make_shared<Rent>(testDate1, client1, book);
//
//    RentableItemPtr taniec = r->getRentableItem();
//    std::cout << taniec->getTitle() << std::endl;



//    ClientTypePtr testClientTypeStudent = std::make_shared<Student>();
//    AddressPtr testAddress = std::make_shared<Address>("London", "Rue Morgue", "13");
//    clientManager c;
//    ObserverPtr ct = std::make_shared<ChangeObserver>();
//    ClientPtr tancerz = std::make_shared<Client>("Piotr", "Strachota", "1", testAddress, testClientTypeStudent, ct);
//    ClientPtr client = c.registerClient("Piotr", "Strachota", "1", testAddress, testClientTypeStudent);
//    ClientPtr client2 = c.registerClient("Adam", "Strachot4a", "2", testAddress, testClientTypeStudent);
//    ClientPtr client3 = c.registerClient("Janek", "Strachota", "3", testAddress, testClientTypeStudent);
//    ClientPtr client4 = c.registerClient("Olgierd", "Strach4ota", "4", testAddress, testClientTypeStudent);
//
//
//    //testy predykatow/funktorow
//    std::regex tango("(Strachyyyy)(.*)");
//    LastNamePredicate predicate(tango);
//    std::cout << std::boolalpha << predicate(tancerz) << std::endl;
//
//    c.saveAllClientsInfoToFile();
//    //tancerz->setName("TancerzPogo");
//
//    try {
//        tancerz->setName("");
//    }
//    catch (const exceptionFirstName &e) {
//        std::cout << e.message() << std::endl;
//    }





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
