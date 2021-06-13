//
// Created by student on 13.06.2021.
//

#ifndef STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_OBSERVERS_H
#define STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_OBSERVERS_H

#include "managers/RentableItemManager.h"
#include "managers/ClientManager.h"
#include "managers/RentManager.h"
#include "model/Client.h"
#include "exceptions/ClientException.h"
#include "model/Rent.h"

class AddRentObserver : public Observer {

public:
    void notify(RentPtr r) override {
        std::cout << "Dodano nowe wypozyczenie." << std::endl;
        std::cout << "Dane nowego wypozycznenia to: " << std::endl;
        std::cout << r->getInfo() << std::endl;

    }
};

class AddClientObserver : public ObserverC {

public:
    void notify(ClientPtr r) override {
        std::cout << "Dodano nowego klienta." << std::endl;
        std::cout << "Dane nowego klienta to: " << std::endl;
        std::cout << r->getInfo() << std::endl;

    }
};

class AddRentableItemObserver : public ObserverR {

public:
    void notify(RentableItemPtr r) override {
        std::cout << "Dodano nowy przedmiot." << std::endl;
        std::cout << "Dane nowego przedmiotu to: " << std::endl;
        std::cout << r->getInfo() << std::endl;

    }
};

class RemoveRentObserver : public Observer {

public:
    void notify(RentPtr r) override {
        std::cout << "Przeniesiono wypozyczenie do archiwum." << std::endl;
        std::cout << "Dane prziesionego wypozycznenia to: " << std::endl;
        std::cout << r->getInfo() << std::endl;

    }
};

class RemoveClientObserver : public ObserverC {

public:
    void notify(ClientPtr r) override {
        std::cout << "Przeniesiono klienta do archiwum." << std::endl;
        std::cout << "Dane przeniesionego klienta to: " << std::endl;
        std::cout << r->getInfo() << std::endl;

    }
};

class RemoveRentableItemObserver : public ObserverR {

public:
    void notify(RentableItemPtr r) override {
        std::cout << "Przeniesiono przedmiot do archiwum." << std::endl;
        std::cout << "Dane przeniesionego przedmiotu to: " << std::endl;
        std::cout << r->getInfo() << std::endl;

    }
};

#endif //STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_OBSERVERS_H
