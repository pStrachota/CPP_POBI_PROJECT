

#ifndef CARRENTAL_VEHICLEMANAGER_H
#define CARRENTAL_VEHICLEMANAGER_H

#include "typedefs.h"
#include "repositories/VehicleRepository.h"
#include <memory>
#include <vector>
#include "model/Car.h"

class VehicleManager {
private:
    VehicleRepository vehicleRep;
public:
    VehiclePtr getVehicle(std::string plateNumber);
    std::vector<VehiclePtr> findVehicles(VehiclePredicate predicate);
    std::vector<VehiclePtr> findAllVehicles();

    VehiclePtr registerBicycle(std::string plateNumber, int basePrice);
    VehiclePtr registerMoped(std::string plateNumber, int basePrice, int engineDisplacement);
    VehiclePtr registerCar(klasyAut segment,std::string plateNumber, int basePrice, int engineDisplacement);

    void unregisterVehicle(VehiclePtr vehicle);

};


#endif //CARRENTAL_VEHICLEMANAGER_H
