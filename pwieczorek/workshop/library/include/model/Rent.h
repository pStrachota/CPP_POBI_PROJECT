#ifndef CARRENTAL_RENT_H
#define CARRENTAL_RENT_H

#include "model/Client.h"
#include "model/Vehicle.h"
#include <boost/date_time.hpp>
#include "typedefs.h"
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

namespace pt = boost::posix_time;
namespace gr = boost::gregorian;


class Client;

class Rent {
private:
    boost::uuids::uuid rentId;
    unsigned int rentID;
    ClientPtr const ptrClient;
    VehiclePtr const ptrVehicle;
    pt::ptime beginTime;
    pt::ptime endTime;
    unsigned int rentCost = 0;
public:

    Rent(boost::uuids::uuid rentId,ClientPtr const, VehiclePtr const, const pt::ptime);
    std::string getRentInfo();
    std::string getInfo();
    const unsigned int & getID() const;
    const VehiclePtr getVehicle() const;
    const ClientPtr getClient() const;
    unsigned int getRentDays();
    const pt::ptime &getBeginTime() const;
    const pt::ptime &getEndTime() const;
    void setEndTime(pt::ptime time);
    void endRent(pt::ptime);
    unsigned int getRentCost();
    boost::uuids::uuid getId() const;
};


#endif //CARRENTAL_RENT_H
