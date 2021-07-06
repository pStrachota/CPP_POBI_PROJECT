#ifndef CARRENTAL_CLIENTREPOSITORY_H
#define CARRENTAL_CLIENTREPOSITORY_H
#include "typedefs.h"
#include <vector>
#include <string>
#include "repositories/Repository.h"


class ClientRepository {
private:
    std::vector<ClientPtr> clientVector;
public:
    ClientPtr getClient(unsigned int index);
    void addClient(ClientPtr);
    const unsigned int getSize() const;


    void removeClient(ClientPtr);
    std::string getReport();


    ClientPtr findByPersonalId(std::string personalId);

    bool testId1(const ClientPtr &ptr);

    //wymaga pozostawienia
    std::vector<ClientPtr> findBy(ClientPredicate);
};


#endif //CARRENTAL_CLIENTREPOSITORY_H
