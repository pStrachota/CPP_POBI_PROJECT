#include <iostream>
#include "model/Client.h"
#include "model/Student.h"
#include "model/Address.h"
#include "model/Article.h"
#include "model/Book.h"
#include "managers/ClientManager.h"
#include "managers/RentableItemManager.h"
#include "model/Rent.h"
#include "managers/RentManager.h"
#include "model/Observers.h"

int main() {

    ObserverPtr ct = std::make_shared<AddRentObserver>();
    ObserverPtr ct1 = std::make_shared<RemoveRentObserver>();
    Observer2Ptr ct2 = std::make_shared<AddClientObserver>();
    Observer2Ptr ct3 = std::make_shared<RemoveClientObserver>();
    Observer3Ptr ct4 = std::make_shared<AddRentableItemObserver>();
    Observer3Ptr ct5 = std::make_shared<RemoveRentableItemObserver>();

    ClientTypePtr testClientTypeStudent = std::make_shared<Student>();
    AddressPtr testaddress1 = std::make_shared<Address>("London", "Accacia Avenue", "22");
    pt::ptime testDate1 = pt::ptime(gr::date(2021,3,1), pt::hours(12) + pt::minutes(30));
    ClientPtr c1 = std::make_shared<Client>("Piotr", "Strachota", "100", testaddress1, testClientTypeStudent);

    RentableItemPtr book = std::make_shared<Book>("123", "Edison", "Harry Potter","Zodiac");
    RentableItemPtr article = std::make_shared<Article>("777", "Watts", "Harry Potter 2","Harvard");

    RentManager r;
    r.attachObserver(ct);
    r.attachObserver(ct1);

    r.rentRentableItem(c1, book, testDate1);
    r.rentRentableItem(c1, article, testDate1);

    ClientManager c;
    c.attachObserver(ct2);
    c.attachObserver(ct3);

    RentableItemManager k;
    k.attachObserver(ct4);
    k.attachObserver(ct5);

    k.registerArticle("123", "Edison", "Harry Potter","Zodiac");
    k.registerArticle("777", "Watts", "Harry Potter 2","Harvard");

    c.registerClient("Piotr", "Strachota", "100", testaddress1, testClientTypeStudent);

    std::cout << "---------------------------------------" << std::endl;

    r.removeRentableItem(book);
    c.unregisterClient(c1);
    k.unregisterRentableItem(book);

    return 0;
}
