#ifndef CARRENTAL_STORAGECONTAINER_H
#define CARRENTAL_STORAGECONTAINER_H
#include "RentRepository.h"
#include "ClientRepository.h"
#include "VehicleRepository.h"

class StorageContainer {
    VehicleRepository vR;
    ClientRepository cR;
    RentRepository rR;
public:
    StorageContainer(VehicleRepository testV, ClientRepository testC, RentRepository testR);
    VehicleRepository getVehicleRepo();
    ClientRepository getClientRepo();
    RentRepository getRentRepo();

};







#endif //CARRENTAL_STORAGECONTAINER_H
