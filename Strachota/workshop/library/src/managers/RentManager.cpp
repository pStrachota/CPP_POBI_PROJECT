#include <managers/RentManager.h>
#include "model/Bronze.h"
#include "model/Silver.h"
#include "model/Default.h"
#include "model/Gold.h"
#include "model/Platinum.h"
#include "model/Diamond.h"


std::vector<RentPtr> RentManager::getAllClientRents(ClientPtr client) {

    std::vector<RentPtr> fonde;
    unsigned int size = currentRents.rentSize();
    for(int i = 0; i <= currentRents.rentSize(); i++) {
        if (currentRents.getRent(i) != nullptr) {
            if (currentRents.getRent(i)->getClient() == client) {
                fonde.push_back(currentRents.getRent(i));
            }
        }
    }

    return fonde;



    //return currentRents.findBy(rPredicate);
}

RentPtr RentManager::getVehicleRent(VehiclePtr vehicle2) {

    //unsigned int size = currentRents.rentSize();
    //for(int i = 0; i < currentRents.rentSize(); i++) {
      //  if(currentRents.)
    //}
    //if(currentRents.getRent(a)->getVehicle() == vehicle2) {
     //   return currentRents.getRent(a);
    //}
    //return nullptr;
   for(int i = 0; i <= currentRents.rentSize(); i++) {
       if (currentRents.getRent(i) != nullptr) {
           if (currentRents.getRent(i)->getVehicle() == vehicle2) {
               return currentRents.getRent(i);
           }
       }
   }
    return nullptr;

}

std::vector<RentPtr> RentManager::findAllRents() {
    return currentRents.findAll();
}

double RentManager::checkClientRentBalance(ClientPtr cPtr) {

    double total = 0;
    for(int i = 0; i <= archiveRents.rentSize(); i++) {
        if (archiveRents.getRent(i) != nullptr) {
            if (archiveRents.getRent(i)->getClient() == cPtr) {
                total += archiveRents.getRent(i)->getRentCost();
            }
        }
    }
    return total;
}

void RentManager::returnVehicle(VehiclePtr vehiclePtr) {

    for(int i = 0; i <= currentRents.rentSize(); i++) {
        if (currentRents.getRent(i) != nullptr) {
            if (currentRents.getRent(i)->getVehicle() == vehiclePtr) {

                currentRents.getRent(i)->endRent(pt::not_a_date_time);
                archiveRents.addRent(currentRents.getRent(i));
                changeClientType(currentRents.getRent(i)->getClient());
                currentRents.getRent(i) = nullptr;
            }
        }
    }

}

RentPtr RentManager::rentVehicle(unsigned int id, ClientPtr client, VehiclePtr vehicle, pt::ptime beginTime) {

   // RentPtr newRent = std::make_shared<Rent>(0, client, vehicle, beginTime);
    //std::shared_ptr<Rent> new_one = std::make_shared<Rent>(0, client, vehicle, beginTime);
//    currentRents.addRent(newRent);
  //  return newRent;


    if(!client->isArchive()) {
        if((int)getAllClientRents(client).size() < client->getMaxVehicles()) {
          if(getVehicleRent(vehicle) == nullptr) {
                RentPtr newRent = std::make_shared<Rent>(id, client, vehicle, beginTime);
                //std::shared_ptr<Rent> new_one = std::make_shared<Rent>(0, client, vehicle, beginTime);
                currentRents.addRent(newRent);
                return newRent;
            }
        }
    }
    return nullptr;

}

void RentManager::changeClientType(ClientPtr client) {
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

