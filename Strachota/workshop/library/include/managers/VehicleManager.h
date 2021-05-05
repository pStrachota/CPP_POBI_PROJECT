#ifndef CARRENTAL_VEHICLEMANAGER_H
#define CARRENTAL_VEHICLEMANAGER_H

#include "typedefs.h"
#include <memory>
#include <vector>
#include "repositories/VehicleRepository.h"
#include "model/Car.h"
//class ClientRepository;

class VehicleManager {
    VehicleRepository vehicleRepo;
public:
    VehiclePtr getVehicle(const std::string &);
    VehiclePtr registerBicycle(std::string platenumber, unsigned int baseprice);
    VehiclePtr registerMoped(int capacity, const std::string &platenumber, const unsigned int &baseprice);
    VehiclePtr registerCar(SegmentType test, int capacity, const std::string &platenumber, const unsigned int &baseprice);
    void unregisterVehicle(const std::string &);

};






#endif //CARRENTAL_VEHICLEMANAGER_H
