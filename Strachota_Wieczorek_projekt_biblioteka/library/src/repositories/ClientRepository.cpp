#include <repositories/ClientRepository.h>
#include "model/Client.h"
#include <iostream>
#include "repositories/Templates.h"

std::vector<ClientPtr> ClientRepository::findByPredicate(const ClientPredicate& predicate) {
    {
        std::vector<ClientPtr> result;
        for(int i = 0; i<objects.size(); ++i)
        {
            ClientPtr client = objects[i];
            if(predicate(client))
            {
                result.push_back(client);
            }
        }
        return result;
    }
}

std::vector<ClientPtr> ClientRepository::findAllClients() {
    bool check = false;
    ClientPredicate predicateFalse = [check](ClientPtr ptr) {
        return ptr->isArchive() == check;
    };
    return findByPredicate(predicateFalse);
}
