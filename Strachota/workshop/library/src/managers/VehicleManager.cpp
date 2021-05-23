#include <managers/VehicleManager.h>
#include "model/Bicycle.h"
#include "repositories/Repository.h"

VehiclePtr VehicleManager::getVehicle(const std::string &plateNumber) {
    return vehicleRepo.findById(plateNumber);
}

VehiclePtr VehicleManager::registerBicycle( const std::string& platenumber, unsigned int baseprice) {

    VehiclePtr vehicleCheck = getVehicle(platenumber);
    if (vehicleCheck == nullptr) {
        VehiclePtr newVehicle = std::make_shared<Bicycle>(platenumber, baseprice);
        vehicleRepo.add(newVehicle);
        return newVehicle;

    } else {
        return vehicleCheck;
    }
}

VehiclePtr VehicleManager::registerMoped(int capacity, const std::string &platenumber, const unsigned int &baseprice) {

    VehiclePtr vehicleCheck = getVehicle(platenumber);
    if (vehicleCheck == nullptr) {
        VehiclePtr newVehicle = std::make_shared<MotorVehicle>(capacity, platenumber, baseprice);
        vehicleRepo.add(newVehicle);
        return newVehicle;

    } else {
        return vehicleCheck;
    }
}

VehiclePtr VehicleManager::registerCar(SegmentType test, int capacity, const std::string &platenumber, const unsigned int &baseprice) {

    VehiclePtr vehicleCheck = getVehicle(platenumber);
    if (vehicleCheck == nullptr) {
        VehiclePtr newVehicle = std::make_shared<Car>(test, capacity, platenumber, baseprice);
        vehicleRepo.add(newVehicle);
        return newVehicle;

    } else {
        return vehicleCheck;
    }
}

void VehicleManager::unregisterVehicle(const VehiclePtr& vehiclePtr) {
    if(vehiclePtr != nullptr) {
        if(getVehicle(vehiclePtr->getId())) {
            vehiclePtr->setArchive(true);
        }
    }

}

std::vector<VehiclePtr> VehicleManager::findAllVehicles() {
    return vehicleRepo.findAllVehicles();
}

std::vector<VehiclePtr> VehicleManager::findVehicles(const VehiclePredicate &predicate) {
    return vehicleRepo.findByPredicate(predicate);
}

