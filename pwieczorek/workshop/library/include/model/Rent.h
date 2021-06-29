#ifndef CARRENTAL_RENT_H
#define CARRENTAL_RENT_H

#include "model/Client.h"
#include "model/Vehicle.h"
#include <boost/date_time.hpp>
#include "typedefs.h"

namespace pt = boost::posix_time;
namespace gr = boost::gregorian;


class Client;

class Rent {
private:
    unsigned int rentID;
    ClientPtr const ptrClient;
    VehiclePtr const ptrVehicle;
    pt::ptime beginTime;
    pt::ptime endTime;
    unsigned int rentCost = 0;
public:

    Rent(const unsigned int &,ClientPtr const, VehiclePtr const, const pt::ptime);
    std::string getRentInfo();
    const unsigned int & getID() const;
    const VehiclePtr getVehicle() const;
    const ClientPtr getClient() const;
    unsigned int getRentDays();
    const pt::ptime &getBeginTime() const;
    const pt::ptime &getEndTime() const;
    void setEndTime(pt::ptime time);
    void endRent(pt::ptime);
    unsigned int getRentCost();
};


#endif //CARRENTAL_RENT_H
