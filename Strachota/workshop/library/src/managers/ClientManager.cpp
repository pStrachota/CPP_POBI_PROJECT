#include <managers/ClientManager.h>
#include "model/Client.h"
#include "repositories/ClientRepository.h"
#include <memory>
#include <functional>

ClientPtr clientManager::registerClient(const std::string &firstName, const std::string &lastName, std::string personalID, const AddressPtr &address, const ClientTypePtr &type) {

        ClientPtr clientCheck = getClient(personalID);
        if (clientCheck == nullptr) {
            ClientPtr newClient = std::make_shared<Client>(firstName, lastName, personalID, address, type);
            clientRepo.addClient(newClient);
            return newClient;


        } else {
            //clientCheck->setArchiveStatus(false);      // gdy klient był zarchiwizowany dokonuje się dearchiwizacja
            //clientCheck->setFirstName(firstName);            // ustawione zostają nowe dane klienta
            //clientCheck->setLastName(lastName);
            //clientCheck->setAddress(address);

            return clientCheck;
        }

    }

ClientPtr clientManager::getClient( std::string personalId) {
    return clientRepo.findByPersonalId(personalId);
    }

void clientManager::unregisterClient(const std::string &personalId) {
    if(getClient(personalId) != nullptr) {
        getClient(personalId)->setArchive(true);
    }
}

std::vector<ClientPtr> clientManager::findClients(ClientPredicate predicate) {
    bool check = false;
    ClientPredicate predicateFalse = [check](ClientPtr ptr) {
        return ptr->isArchive() == check;
    };
    ClientPredicate sum = [predicateFalse, predicate](ClientPtr test) {
        return predicateFalse && predicate;
    };
    return clientRepo.findBy(sum);


    //return std::vector<ClientPtr>();
}

