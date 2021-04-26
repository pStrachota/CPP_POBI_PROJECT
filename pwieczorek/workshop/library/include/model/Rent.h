#ifndef CARRENTAL_RENT_H
#define CARRENTAL_RENT_H

#include "model/Client.h"
#include "model/Vehicle.h"
#include <boost/date_time.hpp>

namespace pt = boost::posix_time;
namespace gr = boost::gregorian;


class Client;

class Rent {
private:
    unsigned int rentID;
    Client* const ptrClient;
    Vehicle* const ptrVehicle;
    pt::ptime beginTime;
    pt::ptime endTime;
    unsigned int rentCost= 0;
public:

    Rent(const unsigned int &,Client* const, Vehicle* const, const pt::ptime);
    std::string getRentInfo();
    const unsigned int & getID() const;
    const Vehicle* getVehicle() const;
    const Client* getClient() const;
    unsigned int getRentDays();
    const pt::ptime &getBeginTime() const;
    const pt::ptime &getEndTime() const;
    void endRent(pt::ptime);
    unsigned int getRentCost();
};


#endif //CARRENTAL_RENT_H
