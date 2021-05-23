#include <managers/ClientManager.h>
#include "model/Client.h"
#include <memory>
#include <functional>
#include <repositories/Repository.h>

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

void clientManager::unregisterClient(const std::string &personalId) {
    if(getClient(personalId) != nullptr) {
        getClient(personalId)->setArchive(true);
    }
}

std::vector<ClientPtr> clientManager::findClients(const ClientPredicate& predicate) {
    bool check = false;
    ClientPredicate predicateFalse = [check](ClientPtr ptr) {
        return ptr->isArchive() == check;
    };
    ClientPredicate sum = [predicateFalse, predicate](ClientPtr test) {
        return predicateFalse && predicate;
    };
    return clientRepo.findByPredicate(sum);
}

std::vector<ClientPtr> clientManager::findAllClients() {
    return clientRepo.findAllClients();
}

