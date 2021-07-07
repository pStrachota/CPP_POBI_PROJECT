#ifndef CARRENTAL_CLIENTREPOSITORY_H
#define CARRENTAL_CLIENTREPOSITORY_H
#include "typedefs.h"
#include <vector>
#include <string>
#include "repositories/Repository.h"


class ClientRepository : public Repository<Client>{
public:
    std::vector<ClientPtr> findBy(ClientPredicate);
    std::vector<ClientPtr> findAllClients();
};


#endif //CARRENTAL_CLIENTREPOSITORY_H
