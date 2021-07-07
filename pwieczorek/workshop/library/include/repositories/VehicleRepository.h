#ifndef CARRENTAL_VEHICLEREPOSITORY_H
#define CARRENTAL_VEHICLEREPOSITORY_H
#include "typedefs.h"
#include <vector>
#include <string>
#include "repositories/Repository.h"


class VehicleRepository : public Repository<Vehicle>{
public:
    std::vector<VehiclePtr>  findBy(VehiclePredicate);
    std::vector<VehiclePtr>  findAllVehicles();
};


#endif //CARRENTAL_VEHICLEREPOSITORY_H
