#ifndef CARRENTAL_RENT_H
#define CARRENTAL_RENT_H
#include <string>
#include <iostream>
#include "model/Client.h"
#include "model/Vehicle.h"
#include<iostream>
#include <boost/date_time.hpp>
#include "typedefs.h"
#include <model/ClientType.h>
namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

class Client;

class Rent {
private:

    unsigned int id;
    ClientPtr const client;
    VehiclePtr vehicle;
    RentPtr r;
    pt::ptime beginTime;
    pt::ptime endTime = pt::not_a_date_time;
    unsigned int rentCost = 0;
public:
    Rent(const unsigned int &newId, ClientPtr const , VehiclePtr const v, const pt::ptime &begintime);
    const unsigned int &getId() const;
    const ClientPtr getClient() const;
    const pt::ptime &getBeginTime() const;
    const pt::ptime &getEndTime() const;
    unsigned int getRentCost();
    unsigned int getRentDays();
    VehiclePtr getVehicle();
    void endRent(pt::ptime exampleTime);
    std::string getRentInfo();
};







#endif //CARRENTAL_RENT_H
