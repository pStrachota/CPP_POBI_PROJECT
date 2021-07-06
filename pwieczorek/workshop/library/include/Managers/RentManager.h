

#ifndef CARRENTAL_RENTMANAGER_H
#define CARRENTAL_RENTMANAGER_H

#include <vector>
#include "repositories/RentRepository.h"
#include "typedefs.h"
#include <memory>
#include <boost/date_time.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

namespace pt = boost::posix_time;

class RentManager {
RentRepository currentRents;
RentRepository archiveRents;
public:
    RentPtr rentVehicle(ClientPtr client, VehiclePtr vehicle,pt::ptime beginTime);
    void returnVehicle(VehiclePtr vehicle);
    std::vector<RentPtr> getAllClientRents(ClientPtr client);
    RentPtr getVehicleRent(VehiclePtr vehicle);
    double checkClientRentBalance(ClientPtr client);
    void changeClientType(ClientPtr client);
    std::vector<RentPtr> findRents(RentPredicate predicate);
    std::vector<RentPtr> findAllRents();

};


#endif //CARRENTAL_RENTMANAGER_H
