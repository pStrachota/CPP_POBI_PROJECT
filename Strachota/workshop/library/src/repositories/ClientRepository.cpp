#include <repositories/ClientRepository.h>
#include "model/Client.h"
#include <iostream>
#include "repositories/Repository.h"
//class Client;


/*
std::vector<ClientPtr> ClientRepository::findBy(ClientPredicate predicate) {
    std::vector<ClientPtr> found;
    for (unsigned int i = 0; i < objects.size(); i++) {
       ClientPtr client = getObject(i);
        if (client != nullptr && predicate(client)) {
            found.push_back(client);
        }
    }
    return found;
}

std::vector<ClientPtr> ClientRepository::findAll() {
    std::vector<ClientPtr> found;
    for (unsigned int i = 0; i < objects.size(); i++) {
        ClientPtr client = getObject(i);
        if (client != nullptr) {
            found.push_back(client);
        }
    }
    return found;
}

/*
ClientPtr ClientRepository::findByPersonalId(std::string personalId) {

    //  for (auto i = objects.begin(); i != objects.end(); ++i) {
    //    std::cout << "niec" <<std::endl;
    //  i->
    //}

    if (objects.empty()) {
        return nullptr;
    } else {
        for (auto & currentClient : objects) {
            if(currentClient->getId() == personalId) {
                return currentClient;
            }
        }

    }
    return nullptr;
}
      //  if(objects.)
        /*
   for(int i=1; i<objects.size(); i++)
    {
        if(objects[i]->getPersonalId() == personalId) {
            return objects[i];
        }

    }
        }
    }
    //return nullptr;

    /*

    for(int i = 1; i < objects.size(); i++) {
        if(objects.at(i)->getPersonalId() == personalId) {
            return objects.at(i);
        }
        return nullptr;
    }
*/



/*
bool ClientRepository::testId1(const ClientPtr &ptr) {
    return ptr->getPersonalId()==1;
}
*/

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
