#include "managers/ClientManager.h"
#include "model/Client.h"
#include <memory>
#include <functional>
#include "repositories/Templates.h"
#include <fstream>
#include "exceptions/ClientException.h"

ClientPtr clientManager::registerClient(const std::string &firstName, const std::string &lastName, const std::string& personalID, const AddressPtr &address, const ClientTypePtr &type) {

    ClientPtr clientCheck = getClient(personalID);
    if (clientCheck == nullptr) {
        ClientPtr newClient = std::make_shared<Client>(firstName, lastName, personalID, address, type);
        clientRepo.add(newClient);
        return newClient;

    } else {
        return clientCheck;
    }
}

ClientPtr clientManager::getClient(const std::string& personalId) {
    return clientRepo.findById(personalId);
}

void clientManager::unregisterClient(const ClientPtr& toDel) {
    if(toDel != nullptr) {
        toDel->setArchive(true);
    }
}

std::vector<ClientPtr> clientManager::findClients(const ClientPredicate& predicate) {
    /*bool check = false;
    ClientPredicate predicateFalse = [check](ClientPtr ptr) {
        return ptr->isArchive() == check;
    };*/
    ClientPredicate sum = [&predicate](const ClientPtr& test) {
        return predicate(test) && !test->isArchive();
    };

    return clientRepo.findByPredicate(sum);
}

std::vector<ClientPtr> clientManager::findAllClients() {
    return clientRepo.findAllClients();
}

void clientManager::saveAllClientsInfoToFile() {

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

void clientManager::saveClientsToFileByPredicate(const ClientPredicate &predicate) {
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

int clientManager::countClientRent() {
    return clientRepo.objectSize();
}



