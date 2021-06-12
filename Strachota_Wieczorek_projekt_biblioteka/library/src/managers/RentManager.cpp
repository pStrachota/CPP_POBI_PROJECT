#include "managers/RentManager.h"
#include "model/Client.h"
#include "model/RentableItem.h"
#include <memory>
#include "repositories/Templates.h"


std::vector<RentPtr> RentManager::findRents(const RentPredicate & predicate) {
    RentPredicate sum = [&predicate](const RentPtr& test) {
        return predicate(test);
    };

    return currentRents.findByPredicate(sum);
}

std::vector<RentPtr> RentManager::getAllClientRents(const ClientPtr &client) {
    RentPredicate predicator = [&client](const RentPtr& test) {
        return (test->getClient() == client);
    };
    return findRents(predicator);
}

RentPtr RentManager::rentRentableItem(const ClientPtr &client, const RentableItemPtr &rentableItem,
                                      pt::ptime beginTime) {
    RentPtr rentCheck = getRentableItemRent(rentableItem);
    if (rentCheck == nullptr) {
        RentPtr newRent = std::make_shared<Rent>(beginTime,client,rentableItem);
        currentRents.add(newRent);
        return newRent;

    } else {
        return rentCheck;
    }
}

RentPtr RentManager::getRentableItemRent(const RentableItemPtr &rentableItem) {
    RentPredicate predicator = [&rentableItem](const RentPtr& test) {
        return (test->getRentableItem() == rentableItem);
    };
    std::vector<RentPtr> vector = currentRents.findByPredicate(predicator);
    if (vector.size() != 1) return nullptr;
    return vector[0];
}

void RentManager::removeRentableItem(RentableItemPtr rentableItem) {
    RentPredicate predicator = [&rentableItem](const RentPtr& test) {
        return (test->getRentableItem() == rentableItem);
    };
    std::vector<RentPtr> vector = currentRents.findByPredicate(predicator);
    if (vector.size() == 1){
        currentRents.removeObject(vector[0]);
        archiveRents.add(vector[0]);
    }

}

