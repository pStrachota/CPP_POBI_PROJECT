//
// Created by student on 28.05.2021.
//

#ifndef STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_RENT_H
#define STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_RENT_H

#include <boost/date_time.hpp>
#include "typedefs.h"
#include <boost/uuid/uuid.hpp>            // uuid class
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/uuid/uuid_io.hpp>
#include <vector>

namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

class Client;
class RentableItem;

class Rent {
private:
    boost::uuids::uuid RentId;
    pt::ptime beginTime;
    pt::ptime endTime;
    float rentCost;
    ClientPtr client;
    RentableItemPtr rentableItem;
public:
    Rent(pt::ptime beginTime, const ClientPtr& client, const RentableItemPtr& rentableItem);
    void endRent(pt::ptime endTime);
    const std::string getRentInfo() const;
    int getRentPenaltyDays() const;
    ClientPtr getClient() const;
    RentableItemPtr getRentableItem() const;
    pt::ptime getBeginTime() const;
    pt::ptime getEndTime() const;
    float getRentCost() const;
    boost::uuids::uuid getRentId() const;
    void setRentCost(float);
    void setEndTime(pt::ptime);

};


#endif //STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_RENT_H
