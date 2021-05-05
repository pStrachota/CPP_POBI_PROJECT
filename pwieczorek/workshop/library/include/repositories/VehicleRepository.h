#ifndef CARRENTAL_VEHICLEREPOSITORY_H
#define CARRENTAL_VEHICLEREPOSITORY_H
#include "typedefs.h"
#include <vector>
#include <string>

class VehicleRepository {
    std::vector<VehiclePtr> vehicleVector;
public:
    VehiclePtr getVehicle(unsigned int index);
    void addVehicle(VehiclePtr);
    void removeVehicle(VehiclePtr);
    std::string getReport();
    const unsigned int getSize() const;
    std::vector<VehiclePtr>  findBy(VehiclePredicate);
    bool testPlate(const VehiclePtr &vehicle);


};


#endif //CARRENTAL_VEHICLEREPOSITORY_H
