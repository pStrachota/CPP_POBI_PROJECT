#include <repositories/ClientRepository.h>
#include "model/Client.h"
#include <iostream>

ClientPtr ClientRepository::getClient(unsigned int index) {
    unsigned int i = 1;
    for (std::vector<ClientPtr>::iterator it = currentClients.begin(); it != currentClients.end(); it++)
    {
        if(i == index)
        {
            return *it;
        }
        i++;
    }
}

void ClientRepository::addClient(ClientPtr newC) {
    if(newC == nullptr) {}
    else {
        currentClients.push_back(newC);
    }
}

void ClientRepository::removeClient(ClientPtr delC) {
    if(delC == nullptr) {}
    else {
        currentClients.erase(std::remove(currentClients.begin(), currentClients.end(), delC), currentClients.end());
    }
}

std::string ClientRepository::getReport(){
    std::string result;
    for (std::vector<ClientPtr>::iterator it = currentClients.begin(); it != currentClients.end(); it++) {
        result += ((*it)->getClientInfo() + '\n');
    }
    return result;
}

const unsigned int ClientRepository::clientSize() const{
    return currentClients.size();
}

std::vector<ClientPtr> ClientRepository::findBy(ClientPredicate predicate) {
    std::vector<ClientPtr> found;
    for (unsigned int i = 0; i < currentClients.size(); i++) {
        ClientPtr client = getClient(i);
        if (client != nullptr && predicate(client)) {
            found.push_back(client);
        }
    }
    return found;
}

std::vector<ClientPtr> ClientRepository::findAll() {
    std::vector<ClientPtr> found;
    for (unsigned int i = 0; i < currentClients.size(); i++) {
        ClientPtr client = getClient(i);
        if (client != nullptr) {
            found.push_back(client);
        }
    }
    return found;
}

ClientPtr ClientRepository::findByPersonalId(std::string personalId) {

    //  for (auto i = currentClients.begin(); i != currentClients.end(); ++i) {
    //    std::cout << "niec" <<std::endl;
    //  i->
    //}

    if (currentClients.empty()) {
        return nullptr;
    } else {
        for (auto & currentClient : currentClients) {
            if(currentClient->getPersonalId() == personalId) {
                return currentClient;
            }
        }

    }
    return nullptr;
}
      //  if(currentClients.)
        /*
   for(int i=1; i<currentClients.size(); i++)
    {
        if(currentClients[i]->getPersonalId() == personalId) {
            return currentClients[i];
        }

    }
        }
    }
    //return nullptr;

    /*

    for(int i = 1; i < currentClients.size(); i++) {
        if(currentClients.at(i)->getPersonalId() == personalId) {
            return currentClients.at(i);
        }
        return nullptr;
    }
*/



/*
bool ClientRepository::testId1(const ClientPtr &ptr) {
    return ptr->getPersonalId()==1;
}
*/
