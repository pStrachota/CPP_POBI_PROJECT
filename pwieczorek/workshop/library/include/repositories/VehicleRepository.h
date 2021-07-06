#ifndef CARRENTAL_VEHICLEREPOSITORY_H
#define CARRENTAL_VEHICLEREPOSITORY_H
#include "typedefs.h"
#include <vector>
#include <string>
#include "repositories/Repository.h"


class VehicleRepository {
    std::vector<VehiclePtr> vehicleVector;
public:
    VehiclePtr getVehicle(unsigned int index);
    void addVehicle(VehiclePtr);

    void removeVehicle(VehiclePtr);
    std::string getReport();
    const unsigned int getSize() const;
    bool testPlate(const VehiclePtr &vehicle);
    VehiclePtr findByPlateNumber(std::string plate);
    //pozostawic
    std::vector<VehiclePtr>  findBy(VehiclePredicate);

};


#endif //CARRENTAL_VEHICLEREPOSITORY_H
