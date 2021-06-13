#include "managers/ClientManager.h"
#include "model/Client.h"
#include <memory>
#include <functional>
#include "repositories/Templates.h"
#include <fstream>
#include "exceptions/ClientException.h"

ClientPtr ClientManager::registerClient(const std::string& name, const std::string& surname, const std::string& personalID, const AddressPtr& address, const ClientTypePtr& type) {

    ClientPtr clientCheck = getClient(personalID);
    if (clientCheck == nullptr) {
        ClientPtr newClient = std::make_shared<Client>(name, surname, personalID, address, type);
        clientRepo.add(newClient);
        if(observers.empty()) {
            return newClient;
        } else {
            observers[0]->notify(newClient);
            return newClient;
        }

    } else {
        return clientCheck;
    }
}

ClientPtr ClientManager::getClient(const std::string& personalId) {
    return clientRepo.findById(personalId);
}

void ClientManager::unregisterClient(const ClientPtr& toDel) {
    if(observers.size() == 2) {
        observers[1]->notify(toDel);
        toDel->setArchive(true);
    } else {
        if (toDel != nullptr) {
            toDel->setArchive(true);
        }
    }
}

std::vector<ClientPtr> ClientManager::findClients(const ClientPredicate& predicate) {
    /*bool check = false;
    ClientPredicate predicateFalse = [check](ClientPtr ptr) {
        return ptr->isArchive() == check;
    };*/
    ClientPredicate sum = [&predicate](const ClientPtr& test) {
        return predicate(test) && !test->isArchive();
    };

    return clientRepo.findByPredicate(sum);
}

std::vector<ClientPtr> ClientManager::findAllClients() {
    return clientRepo.findAllClients();
}

void ClientManager::saveAllClientsInfoToFile() {

    std::ofstream proba;
    proba.open("/home/student/AllClientsInfo");

    if (!proba) {
        throw exceptionCannotOpenFile("CANNOT OPEN FILE TO SAVE DATA");
    } else {
        for (auto &i : findAllClients()) {
            proba << i->getInfo() << std::endl;
        }
        proba.close();
    }
}

void ClientManager::saveClientsToFileByPredicate(const ClientPredicate &predicate) {
    ClientPredicate sum = [&predicate](const ClientPtr& test) {
        return predicate(test) && !test->isArchive();
    };
    std::vector<ClientPtr> result = clientRepo.findByPredicate(sum);

    std::ofstream proba;
    proba.open("/home/student/ClientsbyPredicateInfo");

    if (!proba) {
        throw exceptionCannotOpenFile("CANNOT OPEN FILE TO SAVE DATA");
    } else {
        for (auto &i : result) {
            proba << i->getInfo() << std::endl;
        }
        proba.close();
    }
}

unsigned int ClientManager::countClientRent() const{
    return clientRepo.objectSize();
}

void ClientManager::attachObserver(Observer2Ptr observer2) {
    observers.push_back(observer2);
}





