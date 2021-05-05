#ifndef CARRENTAL_CLIENTREPOSITORY_H
#define CARRENTAL_CLIENTREPOSITORY_H

#include <iostream>
#include "model/Client.h"
#include <vector>

class ClientRepository {
    std::vector<ClientPtr> currentClients;
public:
    ClientPtr getClient(unsigned int index);
    std::vector<ClientPtr> findBy(ClientPredicate);
    ClientPtr findByPersonalId(std::string);
    std::vector<ClientPtr> findAll();
    bool testId1(const ClientPtr &ptr);
    void addClient(ClientPtr);
    void removeClient(ClientPtr);
    std::string getReport();
    const unsigned int clientSize() const;



};













#endif //CARRENTAL_CLIENTREPOSITORY_H
