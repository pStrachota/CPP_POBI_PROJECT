#include "repositories/ClientRepository.h"
#include "model/Client.h"

ClientPtr ClientRepository::getClient(unsigned int index) {
    if ( index > (clientVector.size()-1)) return nullptr;
    return clientVector[index];
}

void ClientRepository::addClient(ClientPtr someClient) {
    if (someClient != nullptr){
        clientVector.push_back(someClient);
    }
}

void ClientRepository::removeClient(ClientPtr someClient) {
    if (someClient != nullptr)
    {
        clientVector.erase(std::remove(clientVector.begin(), clientVector.end(), someClient), clientVector.end());
    }

}

std::string ClientRepository::getReport() {
    std::string output;
    for(std::vector<ClientPtr>::iterator it = clientVector.begin(); it != clientVector.end(); ++it) {
        output += " " + (*it)->getClientInfo() + "\n";
    }
    return output;
}

const unsigned int ClientRepository::getSize() const {
    return clientVector.size();
}

std::vector<ClientPtr> ClientRepository::findBy(ClientPredicate predicate){
    std::vector<ClientPtr> found;
    for (unsigned int i = 0; i < clientVector.size(); i++) {
        ClientPtr client = getClient(i);
        if (client != nullptr && predicate(client)) {
            found.push_back(client);
        }
    }
    return found;
}

bool ClientRepository::testId1(const ClientPtr &ptr) {
    return ptr->getPersonalID() == "1";
}

ClientPtr ClientRepository::findByPersonalId(std::string personalId) {
    ClientPtr foundPtr = nullptr;
    for (unsigned int i = 0; i < clientVector.size(); i++) {
        if (clientVector[i] -> getPersonalID() == personalId) {
            foundPtr = clientVector[i];
        }
    }
    return foundPtr;
}