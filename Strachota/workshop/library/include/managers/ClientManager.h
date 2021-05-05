#ifndef CARRENTAL_CLIENTMANAGER_H
#define CARRENTAL_CLIENTMANAGER_H
#include "typedefs.h"
#include <memory>
#include <vector>
#include "repositories/ClientRepository.h"

//class ClientRepository;

class clientManager {
    ClientRepository clientRepo;
public:
    ClientPtr getClient(std::string );
    ClientPtr registerClient(const std::string &firstName, const std::string &lastName, std::string personalID,
                   const AddressPtr &address, const ClientTypePtr &type);
    std::vector<ClientPtr> findClients(ClientPredicate);
    void unregisterClient(const std::string &);
};




#endif //CARRENTAL_CLIENTMANAGER_H
