#include "repositories/StorageContainer.h"

StorageContainer::StorageContainer(VehicleRepository testVehicleRep, ClientRepository testClientRep,
                                   RentRepository testRentRep) : clientRep(testClientRep), rentRep(testRentRep), vehicleRep(testVehicleRep){

}

ClientRepository & StorageContainer::getClientRep() {
    return clientRep;
}

RentRepository & StorageContainer::getRentRep() {
    return rentRep;
}

VehicleRepository & StorageContainer::getVehicleRep() {
    return vehicleRep;
}
