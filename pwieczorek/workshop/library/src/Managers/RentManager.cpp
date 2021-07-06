

#include "Managers/RentManager.h"
#include "model/Default.h"
#include "model/Gold.h"
#include "model/Platinum.h"
#include "model/Bronze.h"
#include "model/Silver.h"
#include "model/Diamond.h"
#include "repositories/RentRepository.h"
#include "model/Rent.h"

std::vector<RentPtr> RentManager::findAllRents() {
    return currentRents.getAllRents();
}

RentPtr RentManager::getVehicleRent(VehiclePtr vehicle) {
    for (int i = 0; i < currentRents.getSize(); i++)
    {
        if ((currentRents.getRent(i) != nullptr) && (currentRents.getRent(i)->getVehicle() == vehicle)){
            return currentRents.getRent(i);
        }
    }
    return nullptr;
}

std::vector<RentPtr> RentManager::getAllClientRents(ClientPtr client) {
    std::vector<RentPtr> found;
    for (int i = 0; i < currentRents.getSize(); i++)
    {
        if ((currentRents.getRent(i) != nullptr) && (currentRents.getRent(i)->getClient() == client)){
            found.push_back(currentRents.getRent(i));
        }
    }
    return found;
}

double RentManager::checkClientRentBalance(ClientPtr client) {
    double sum = 0;
    for (int i = 0; i < archiveRents.getSize(); i++){
        if ((archiveRents.getRent(i) != nullptr) && (archiveRents.getRent(i)->getClient() == client)){
            sum += archiveRents.getRent(i)->getRentCost();
        }
    }
    return sum;
}

RentPtr RentManager::rentVehicle(ClientPtr client, VehiclePtr vehicle, pt::ptime beginTime) {
    boost::uuids::uuid ID;
    while(true){
        boost::uuids::random_generator gen;
        ID = gen();
        bool found = false;
        for(int i = 0; i<currentRents.getSize();i++){
            if(currentRents.getRent(i)->getId() == ID) found = true;
        }
        for(int i = 0; i<archiveRents.getSize() && !found ;i++){
            if(archiveRents.getRent(i)->getId() == ID) found = true;
        }
        if(found) break;
    }

    if (client->isArchive() == false && (client->getMaxVehicles() < getAllClientRents(client).size())){
        RentPtr rent = std::make_shared<Rent>(ID, client, vehicle, beginTime);
        currentRents.addRent(rent);
        return rent;
    }
    return nullptr;
}

void RentManager::returnVehicle(VehiclePtr vehicle) {
    for (int i = 0; i < currentRents.getSize(); i++)
    {
        if ((currentRents.getRent(i) != nullptr) && (currentRents.getRent(i)->getVehicle() == vehicle)){
            currentRents.getRent(i)->endRent(pt::not_a_date_time);
            archiveRents.addRent(currentRents.getRent(i));
            currentRents.getAllRents().erase(currentRents.getAllRents().begin() + i);
        }
    }
}

void RentManager::changeClientType(ClientPtr client) {
    double sum = checkClientRentBalance(client);

    if(sum >= 0 && sum < 100) {
        client->setClientType(std::make_shared<Default>());
    }else if(sum >= 100 && sum < 200) {
        client->setClientType(std::make_shared<Bronze>());
    }else if(sum >= 200 && sum < 400) {
        client->setClientType(std::make_shared<Silver>());
    }else if(sum >= 400 and sum < 800) {
        client->setClientType(std::make_shared<Gold>());
    }else if(sum>= 800 and sum < 1600) {
        client->setClientType(std::make_shared<Platinum>());
    }else if(sum >= 1600) {
        client->setClientType(std::make_shared<Diamond>());
    }
}