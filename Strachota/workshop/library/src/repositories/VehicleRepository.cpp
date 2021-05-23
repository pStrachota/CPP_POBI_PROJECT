#include <repositories/VehicleRepository.h>
#include "typedefs.h"
#include <memory>
#include <functional>
#include "model/Vehicle.h"



/*
std::vector<VehiclePtr> VehicleRepository::findBy(VehiclePredicate predicate) {
    std::vector<VehiclePtr> found;
    for (unsigned int i = 0; i < objects.size(); i++) {
        VehiclePtr vehicle = getObject(i);
        if (vehicle != nullptr && predicate(vehicle)) {
            found.push_back(vehicle);
        }
    }
    return found;
}

std::vector<VehiclePtr> VehicleRepository::findAll() {
    std::vector<VehiclePtr> found;
    for (unsigned int i = 0; i < objects.size(); i++) {
        VehiclePtr vehicle = getObject(i);
        if (vehicle != nullptr) {
            found.push_back(vehicle);
        }
    }
    return found;
}
/*
VehiclePtr VehicleRepository::findByPlateNumber(std::string plateNumber) {

    if (objects.empty()) {
        return nullptr;
    } else {
        for (auto & currentVehicle : objects) {
            if(currentVehicle->getId() == plateNumber) {
                return currentVehicle;
            }
        }

    }
    return nullptr;

    /*
    for(int i = 1; i < objects.size(); i++) {
        if(objects.at(i)->getPlateNumber() == plateNumber) {
            return objects.at(i);
        }
        return nullptr;
    }
    */
//}

std::vector<VehiclePtr> VehicleRepository::findByPredicate(const VehiclePredicate& predicate) {
    {
        std::vector<VehiclePtr> result;
        for(int i = 0; i<objects.size(); ++i)
        {
            VehiclePtr vehicle = objects[i];
            if(predicate(vehicle))
            {
                result.push_back(vehicle);
            }
        }
        return result;
    }
}

std::vector<VehiclePtr> VehicleRepository::findAllVehicles() {
    bool check = false;
    VehiclePredicate predicateFalse = [check](const VehiclePtr& ptr) {
        return ptr->isArchive() == check;
    };
    return findByPredicate(predicateFalse);
}
