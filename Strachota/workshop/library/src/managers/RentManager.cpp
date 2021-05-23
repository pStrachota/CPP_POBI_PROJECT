#include <managers/RentManager.h>
#include "model/Bronze.h"
#include "model/Silver.h"
#include "model/Default.h"
#include "model/Gold.h"
#include "model/Platinum.h"
#include "model/Diamond.h"
#include "model/Client.h"


std::vector<RentPtr> RentManager::getAllClientRents(const ClientPtr& client) {

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

RentPtr RentManager::getVehicleRent(const VehiclePtr& vehicle2) {

   for(int i = 0; i < currentRents.objectSize(); i++) {
       if (currentRents.getObject(i) != nullptr) {
           if (currentRents.getObject(i)->getVehicle() == vehicle2) {
               return currentRents.getObject(i);
           }
       }
   }
    return nullptr;
}

std::vector<RentPtr> RentManager::findAllRents() {
    return currentRents.findAllRents();
}

double RentManager::checkClientRentBalance(const ClientPtr& cPtr) {

    double total = 0;
    for(int i = 0; i <= archiveRents.objectSize(); i++) {
        if (archiveRents.getObject(i) != nullptr) {
            if (archiveRents.getObject(i)->getClient() == cPtr) {
                total += archiveRents.getObject(i)->getRentCost();
            }
        }
    }
    return total;
}

void RentManager::returnVehicle(const VehiclePtr& vehiclePtr) {

    for(int i = 0; i <= currentRents.objectSize(); i++) {
        if (currentRents.getObject(i) != nullptr) {
            if (currentRents.getObject(i)->getVehicle() == vehiclePtr) {

                currentRents.getObject(i)->endRent(pt::not_a_date_time);
                archiveRents.add(currentRents.getObject(i));
                changeClientType(currentRents.getObject(i)->getClient());
                currentRents.getObject(i) = nullptr;
            }
        }
    }
}

RentPtr RentManager::rentVehicle(const ClientPtr& client, const VehiclePtr& vehicle, pt::ptime beginTime) {

    if(!client->isArchive()) {
        if(getAllClientRents(client).size() < client->getMaxVehicles()) {
            if(getVehicleRent(vehicle) == nullptr) {
                RentPtr newRent = std::make_shared<Rent>(client, vehicle, beginTime);
                currentRents.add(newRent);
                return newRent;
            }
        }
    }
    return nullptr;

}

void RentManager::changeClientType(const ClientPtr& client) {
    double balance = checkClientRentBalance(client);
    if(balance < 100) {
        client->setClientType(std::make_shared<Default>());
    }else if(balance >= 100 && balance < 200) {
        client->setClientType(std::make_shared<Bronze>());
    }else if(balance >= 200 && balance< 400) {
        client->setClientType(std::make_shared<Silver>());
    }else if(balance >= 400 and balance < 800) {
        client->setClientType(std::make_shared<Gold>());
    }else if(balance >= 800 and balance < 1600) {
        client->setClientType(std::make_shared<Platinum>());
    }else if(balance >= 1600) {
        client->setClientType(std::make_shared<Diamond>());
    }
}

std::vector<RentPtr> RentManager::findRents(const RentPredicate &predicate) {
    return currentRents.findByPredicate(predicate);
}

