#include <repositories/VehicleRepository.h>


VehiclePtr VehicleRepository::getVehicle(unsigned int index) {
    unsigned int i = 1;
    for (std::vector<VehiclePtr>::iterator it = currentVehicles.begin(); it != currentVehicles.end(); it++) {
        if(i == index)
        {
            return *it;
        }
        i++;
    }
}

void VehicleRepository::addVehicle(VehiclePtr newV) {
    if(newV == nullptr) {}
    else {
        currentVehicles.push_back(newV);
    }
}

void VehicleRepository::removeVehicle(VehiclePtr delV) {
    if(delV == nullptr) {}
    currentVehicles.erase(std::remove(currentVehicles.begin(), currentVehicles.end(), delV), currentVehicles.end());
}


std::string VehicleRepository::getReport() {
    std::string result;
    for (std::vector<VehiclePtr>::iterator it = currentVehicles.begin(); it != currentVehicles.end(); it++) {
        result += ((*it)->getVehicleInfo() + '\n');
    }
    return result;
}

const unsigned int VehicleRepository::vehicleSize() const {
    return currentVehicles.size();
}

std::vector<VehiclePtr> VehicleRepository::findBy(VehiclePredicate predicate) {
    std::vector<VehiclePtr> found;
    for (unsigned int i = 0; i < currentVehicles.size(); i++) {
        VehiclePtr vehicle = getVehicle(i);
        if (vehicle != nullptr && predicate(vehicle)) {
            found.push_back(vehicle);
        }
    }
    return found;
}

std::vector<VehiclePtr> VehicleRepository::findAll() {
    std::vector<VehiclePtr> found;
    for (unsigned int i = 0; i < currentVehicles.size(); i++) {
        VehiclePtr vehicle = getVehicle(i);
        if (vehicle != nullptr) {
            found.push_back(vehicle);
        }
    }
    return found;
}

