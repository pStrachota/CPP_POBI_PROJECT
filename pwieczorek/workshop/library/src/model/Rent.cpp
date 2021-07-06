#include "model/Rent.h"
#include <string>
#include "typedefs.h"
#include "exceptions/RentException.h"


Rent::Rent(boost::uuids::uuid rentId, ClientPtr const ptrClient, VehiclePtr const ptrVehicle, const pt::ptime initTime) : rentId(rentId), ptrClient(ptrClient), ptrVehicle(ptrVehicle)
{
    if (initTime == pt::not_a_date_time) throw exceptionBeginTime(" ERROR BEGIN TIME ");
    if (ptrClient == nullptr) throw exceptionClient(" ERROR CLIENT ");
    if (ptrVehicle == nullptr) throw exceptionVehicle(" ERROR VEHICLE ");


    this->beginTime = initTime;
}

const unsigned int & Rent::getID() const {
    return rentID;
}

const ClientPtr Rent::getClient() const {
    return ptrClient;
}

const VehiclePtr Rent::getVehicle() const {
    return ptrVehicle;
}

std::string Rent::getRentInfo() {
    std::string output;
    std::stringstream ss1;
    std::stringstream ss2;
    std::string stringId = boost::uuids::to_string(rentId);
    ss1 << getBeginTime();
    ss2 << getEndTime();
    std::string s1 = ss1.str();
    std::string s2 = ss2.str();
    output = " rentID: " + stringId + " car: " + ptrVehicle->getVehicleInfo() + " client " + ptrClient->getClientInfo() + " rent begins: " + s1 + " rent ends: " + s2;
    return output;
}

unsigned int Rent::getRentDays() {
    /*
    if(endTime == pt::not_a_date_time) return 0;

    pt::time_period period(beginTime, endTime);
    if(period.length().hours() == 0 && period.length().minutes() <= 1) return 0;
    unsigned  int rentDays = 1;
    unsigned  int moreDays = period.length().hours() % 23;
    rentDays + moreDays;
    return rentDays;
    */

    if(endTime == pt::not_a_date_time) return 0;

    pt::time_period period(getBeginTime(), getEndTime());
    if(period.length().hours() == 0 && period.length().minutes() <= 1) return 0;

    unsigned  int rentDays = period.length().hours() / 24;
    return rentDays;


}

const pt::ptime &Rent::getBeginTime() const {
    return beginTime;
}

const pt::ptime &Rent::getEndTime() const {
    return endTime;
}

void Rent::setEndTime(pt::ptime time) {
    endTime = time;
}

void Rent::endRent(pt::ptime givenTime) {

    if(endTime == pt::not_a_date_time)
    {
        if (givenTime == pt::not_a_date_time)
        {
            endTime = pt::second_clock::local_time();
        } else if (givenTime < beginTime)
        {
            endTime = beginTime;
        } else endTime = givenTime;

    }

    rentCost += (ptrVehicle->getBasePrice() * getRentDays());

}

unsigned int Rent::getRentCost()
{
    if(rentCost >=  6 ) return rentCost - ptrClient->applyDiscount(rentCost);
    else return rentCost;
}

std::string Rent::getInfo() {
    return Rent::getRentInfo();
}

boost::uuids::uuid Rent::getId() const {
    return rentId;
}