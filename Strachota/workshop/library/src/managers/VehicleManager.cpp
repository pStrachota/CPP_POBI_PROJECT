#include <managers/VehicleManager.h>
#include "model/Bicycle.h"

VehiclePtr VehicleManager::getVehicle(const std::string &plateNumber) {
    return vehicleRepo.findByPlateNumber(plateNumber);
}

VehiclePtr VehicleManager::registerBicycle( std::string platenumber, unsigned int baseprice) {

  //  VehiclePtr vehicleCheck = getVehicle(platenumber);
    //if (vehicleCheck == nullptr) {
        VehiclePtr newVehicle = std::make_shared<Bicycle>(platenumber, baseprice);
        vehicleRepo.addVehicle(newVehicle);
        return newVehicle;
    //} else {
        //clientCheck->setArchiveStatus(false);      // gdy klient był zarchiwizowany dokonuje się dearchiwizacja
        //clientCheck->setFirstName(firstName);            // ustawione zostają nowe dane klienta
        //clientCheck->setLastName(lastName);
        //clientCheck->setAddress(address);

      //  return vehicleCheck;
    //}


}

VehiclePtr VehicleManager::registerMoped(int capacity, const std::string &platenumber, const unsigned int &baseprice) {

    VehiclePtr vehicleCheck = getVehicle(platenumber);
    if (vehicleCheck == nullptr) {
        VehiclePtr newVehicle = std::make_shared<MotorVehicle>(capacity, platenumber, baseprice);
        vehicleRepo.addVehicle(newVehicle);
        return newVehicle;
    } else {
        //clientCheck->setArchiveStatus(false);      // gdy klient był zarchiwizowany dokonuje się dearchiwizacja
        //clientCheck->setFirstName(firstName);            // ustawione zostają nowe dane klienta
        //clientCheck->setLastName(lastName);
        //clientCheck->setAddress(address);

        return vehicleCheck;
    }
}

VehiclePtr VehicleManager::registerCar(SegmentType test, int capacity, const std::string &platenumber, const unsigned int &baseprice) {

    VehiclePtr vehicleCheck = getVehicle(platenumber);
    if (vehicleCheck == nullptr) {
        VehiclePtr newVehicle = std::make_shared<Car>(test, capacity, platenumber, baseprice);
        vehicleRepo.addVehicle(newVehicle);
        return newVehicle;
    } else {
        //clientCheck->setArchiveStatus(false);      // gdy klient był zarchiwizowany dokonuje się dearchiwizacja
        //clientCheck->setFirstName(firstName);            // ustawione zostają nowe dane klienta
        //clientCheck->setLastName(lastName);
        //clientCheck->setAddress(address);

        return vehicleCheck;
    }


}

/*
void VehicleManager::unregisterClient(const std::string &plateNumber) {
    if(getVehicle(plateNumber) != nullptr) {
        getVehicle(plateNumber)->setArchive(true);
    }
}

*/