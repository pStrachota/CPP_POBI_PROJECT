#ifndef CARRENTAL_CLIENTREPOSITORY_H
#define CARRENTAL_CLIENTREPOSITORY_H
#include "typedefs.h"
#include <vector>
#include <string>

class ClientRepository {
private:
    std::vector<ClientPtr> clientVector;
public:
    ClientPtr getClient(unsigned int index);
    void addClient(ClientPtr);
    void removeClient(ClientPtr);
    std::string getReport();
    const unsigned int getSize() const;
    std::vector<ClientPtr> findBy(ClientPredicate);
    bool testId1(const ClientPtr &ptr);
};


#endif //CARRENTAL_CLIENTREPOSITORY_H
