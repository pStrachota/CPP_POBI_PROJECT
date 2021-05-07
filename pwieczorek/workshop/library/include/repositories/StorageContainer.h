#ifndef CARRENTAL_STORAGECONTAINER_H
#define CARRENTAL_STORAGECONTAINER_H

#include "RentRepository.h"
#include "ClientRepository.h"
#include "VehicleRepository.h"

class StorageContainer {
private:
    ClientRepository clientRep;
    VehicleRepository vehicleRep;
    RentRepository rentRep;
public:
    StorageContainer(VehicleRepository testVehicleRep, ClientRepository testClientRep, RentRepository testRentRep);

    ClientRepository & getClientRep();
    VehicleRepository & getVehicleRep();
    RentRepository & getRentRep();

    /*
    ClientRepository* getClientRep();
    VehicleRepository* getVehicleRep();
    RentRepository* getRentRep();
     */
};


#endif //CARRENTAL_STORAGECONTAINER_H
