#include "Managers/VehicleManager.h"
#include "model/Bicycle.h"
#include "model/Vehicle.h"
#include "model/Moped.h"
#include <memory>
#include <functional>

VehiclePtr VehicleManager::getVehicle(std::string plateNumber) {
    return vehicleRep.findByPlateNumber(plateNumber);
}

std::vector<VehiclePtr> VehicleManager::findVehicles(VehiclePredicate predicate) {
    return vehicleRep.findBy(predicate);
}

VehiclePtr VehicleManager::registerBicycle(std::string plateNumber, int basePrice) {
    VehiclePtr foundVehicle = nullptr;
    foundVehicle = vehicleRep.findByPlateNumber(plateNumber);

    if (foundVehicle == nullptr){
        VehiclePtr vehicle = std::make_shared<Bicycle>(plateNumber, basePrice);
        vehicleRep.addVehicle(vehicle);
    }

    return foundVehicle;
}

VehiclePtr VehicleManager::registerCar(klasyAut segment, std::string plateNumber, int basePrice,
                                       int engineDisplacement) {
    VehiclePtr foundVehicle = nullptr;
    foundVehicle = vehicleRep.findByPlateNumber(plateNumber);

    if (foundVehicle == nullptr){
        VehiclePtr vehicle = std::make_shared<Car>(segment,engineDisplacement,plateNumber, basePrice);
        vehicleRep.addVehicle(vehicle);
    }

    return foundVehicle;

}

VehiclePtr VehicleManager::registerMoped(std::string plateNumber, int basePrice, int engineDisplacement) {

    VehiclePtr foundVehicle = nullptr;
    foundVehicle = vehicleRep.findByPlateNumber(plateNumber);

    if (foundVehicle == nullptr){
        VehiclePtr vehicle = std::make_shared<MotorVehicle>(engineDisplacement,plateNumber, basePrice);
        vehicleRep.addVehicle(vehicle);
    }

    return foundVehicle;


}