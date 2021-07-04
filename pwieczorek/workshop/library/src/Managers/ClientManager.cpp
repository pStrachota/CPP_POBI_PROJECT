
#include "model/Client.h"
#include "Managers/ClientManager.h"
#include "repositories/ClientRepository.h"
#include <memory>
#include <functional>

ClientPtr ClientManager::registerClient( std::string &firstName, std::string lastName, std::string personalID,
                                   ClientTypePtr clientType, AddressPtr address) {
    ClientPtr foundClient = nullptr;
    // spr czy w bazie
    foundClient = getClient(personalID);
    if (foundClient == nullptr){
        ClientPtr newClient = std::make_shared<Client>(firstName, lastName, personalID,address,clientType);
        clientRep.addClient(newClient);
        return newClient;
    }
    else return foundClient;

}


ClientPtr ClientManager::getClient(std::string personalID) {
    return clientRep.findByPersonalId(personalID);
}

void ClientManager::unregisterClient(ClientPtr client) {
    if (getClient(client->getPersonalID()) != nullptr){
        getClient(client->getPersonalID())->setIsArchive(true);
    }
}

std::vector<ClientPtr> ClientManager::findClients(ClientPredicate predicate) {
    ClientPredicate notArchived = [](ClientPtr cPtr){
        return !cPtr->isArchive();
    };

    ClientPredicate combined = [notArchived,predicate](ClientPtr cPtr2){
        return notArchived && predicate;
    };

    return clientRep.findBy(combined);
}

std::vector<ClientPtr> ClientManager::findAllClients() {
    ClientPredicate combined = [](ClientPtr cPtr){
        return !cPtr->isArchive();
    };

    return clientRep.findBy(combined);
}