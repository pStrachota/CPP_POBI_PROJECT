#include "managers/RentManager.h"
#include "model/Client.h"
#include "model/RentableItem.h"
#include <memory>
#include "repositories/Templates.h"
#include "exceptions/RentExceptions.h"

std::vector<RentPtr> RentManager::findRents(const RentPredicate & predicate) {
    return currentRents.findByPredicate(predicate);
}

std::vector<RentPtr> RentManager::getAllClientRents(const ClientPtr &client) {

    std::vector<RentPtr> fonde;
    for(int i = 0; i < currentRents.objectSize(); i++) {
        if (currentRents.getObject(i) != nullptr) {
            if (currentRents.getObject(i)->getClient() == client) {
                fonde.push_back(currentRents.getObject(i));
            }
        }
    }
    return fonde;
}

RentPtr RentManager::getRentableItemRent(const RentableItemPtr& rentableItem) {

    for(int i = 0; i < currentRents.objectSize(); i++) {
        if (currentRents.getObject(i) != nullptr) {
            if (currentRents.getObject(i)->getRentableItem() == rentableItem) {
                return currentRents.getObject(i);
            }
        }
    }
    return nullptr;
}

RentPtr RentManager::rentRentableItem(const ClientPtr &client, const RentableItemPtr &rentableItem,
                                      pt::ptime beginTime) {

   if(!client->isArchive()) {
        if(getAllClientRents(client).size() < client->getMaxItems()) {
            if(getRentableItemRent(rentableItem) == nullptr) {
                RentPtr newRent = std::make_shared<Rent>(beginTime, client, rentableItem);
                currentRents.add(newRent);
                if(observers.empty()) {
                    return newRent;
                } else {
                    observers[0]->notify(newRent);
                    return newRent;
                }

            }
        }
    }
    return nullptr;
}


void RentManager::removeRentableItem(RentableItemPtr& rentableItem) {

    if(observers.size() == 2) {

        for (int i = 0; i <= currentRents.objectSize(); i++) {
            if (currentRents.getObject(i) != nullptr) {
                if (currentRents.getObject(i)->getRentableItem() == rentableItem) {
                    observers[1]->notify(currentRents.getObject(i));
                    currentRents.getObject(i)->endRent(pt::second_clock::local_time());
                    archiveRents.add(currentRents.getObject(i));
                    currentRents.removeObject(currentRents.getObject(i));
                }
            }
        }
    } else {
        for (int i = 0; i <= currentRents.objectSize(); i++) {
            if (currentRents.getObject(i) != nullptr) {
                if (currentRents.getObject(i)->getRentableItem() == rentableItem) {
                    observers[1]->notify(currentRents.getObject(i));
                    currentRents.getObject(i)->endRent(pt::second_clock::local_time());
                    archiveRents.add(currentRents.getObject(i));
                    currentRents.removeObject(currentRents.getObject(i));
                }
            }
        }
    }
}




unsigned int RentManager::countRents() const {
    return currentRents.objectSize();
}

void RentManager::saveRentsToFileByPredicate(const RentPredicate &predicate) {
    RentPredicate sum = [&predicate](const RentPtr& test) {
        return predicate(test);
    };
    std::vector<RentPtr> result = currentRents.findByPredicate(sum);

    std::ofstream proba;
    proba.open("/home/student/RentsbyPredicateInfo");

    if (!proba) {
        throw exceptionUnableToOpenFile("CANNOT OPEN FILE TO SAVE DATA");
    } else {
        for (auto &i : result) {
            proba << i->getInfo() << std::endl;
        }
        proba.close();
    }
}



void RentManager::attachObserver(ObserverPtr observer) {
    observers.push_back(observer);
}

