#ifndef CARRENTAL_VEHICLEREPOSITORY_H
#define CARRENTAL_VEHICLEREPOSITORY_H

#include <iostream>
#include "model/Vehicle.h"
#include "model/Client.h"
#include <vector>

class VehicleRepository {
    std::vector<VehiclePtr> currentVehicles;
public:
    VehiclePtr getVehicle(unsigned int index);
    void addVehicle(VehiclePtr);
    void removeVehicle(VehiclePtr);
    VehiclePtr findByPlateNumber(std::string);
    std::string getReport();
    const unsigned int vehicleSize() const;
    std::vector<VehiclePtr> findBy(VehiclePredicate);
    std::vector<VehiclePtr> findAll();


};




#endif //CARRENTAL_VEHICLEREPOSITORY_H
