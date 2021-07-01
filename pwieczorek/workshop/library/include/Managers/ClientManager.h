

#ifndef CARRENTAL_CLIENTMANAGER_H
#define CARRENTAL_CLIENTMANAGER_H


#include "typedefs.h"
#include "repositories/ClientRepository.h"
#include <memory>
#include <vector>

class ClientManager {
private:
    ClientRepository clientRep;
public:
    ClientPtr registerClient(std::string firstName, std::string lastName,std::string personalID,ClientTypePtr clientType,AddressPtr address);
    void unregisterClient(ClientPtr client);
    ClientPtr getClient(std::string personalID);
    std::vector<ClientPtr> findClients(ClientPredicate predicate);
    std::vector<ClientPtr> findAllClients();

};


#endif //CARRENTAL_CLIENTMANAGER_H
