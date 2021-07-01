#include "repositories/VehicleRepository.h"
#include "model/Vehicle.h"
#include <algorithm>

VehiclePtr VehicleRepository::getVehicle(unsigned int index) {
    if ( index > (vehicleVector.size()-1)) return nullptr;
    return vehicleVector[index];
}

VehiclePtr VehicleRepository::findByPlateNumber(std::string plate) {
    VehiclePtr found = nullptr;
    for (int i = 0; i < vehicleVector.size();i++){
        if (vehicleVector[i]->getPlateNumber() == plate) found = vehicleVector[i];
    }
    return found;
}

std::string VehicleRepository::getReport() {
    std::string output;
    for(std::vector<VehiclePtr>::iterator it = vehicleVector.begin(); it != vehicleVector.end(); ++it) {
        output += " " + (*it)->getVehicleInfo() + "\n";
    }
    return output;
}

void VehicleRepository::addVehicle(VehiclePtr someVehicle) {
    if (someVehicle == nullptr) {}
    else vehicleVector.push_back(someVehicle);
}

const unsigned int VehicleRepository::getSize() const {
    return vehicleVector.size();
}

void VehicleRepository::removeVehicle(VehiclePtr someVehicle) {
    if (someVehicle != nullptr)
    {
        std::vector<VehiclePtr>::iterator itr = std::find(vehicleVector.begin(), vehicleVector.end(), someVehicle);
        unsigned int index = std::distance(vehicleVector.begin(), itr);
        vehicleVector.erase(vehicleVector.begin() + index);
    }
}

std::vector<VehiclePtr> VehicleRepository::findBy(VehiclePredicate predicate) {
    std::vector<VehiclePtr> found;
    for (unsigned int i = 0; i < vehicleVector.size(); i++) {
        VehiclePtr vehicle = getVehicle(i);
        if (vehicle != nullptr && predicate(vehicle)) {
            found.push_back(vehicle);
        }
    }
    return found;
}

bool VehicleRepository::testPlate(const VehiclePtr &vehicle) {
    return vehicle->getPlateNumber() == "123";
}