#include "model/Rent.h"
#include <string>
#include "typedefs.h"

Rent::Rent(const unsigned int &rentID, ClientPtr const ptrClient, VehiclePtr const ptrVehicle, const pt::ptime initTime) : rentID(rentID), ptrClient(ptrClient), ptrVehicle(ptrVehicle)
{
    ptrClient->newRent(this);
    ptrVehicle->setIsRented(true);
    if(initTime == pt::not_a_date_time) beginTime = pt::second_clock::local_time();
    else beginTime = initTime;
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
    ss1 << getBeginTime();
    ss2 << getEndTime();
    std::string s1 = ss1.str();
    std::string s2 = ss2.str();
    output = " rentID: " + std::to_string(rentID) + " car: " + ptrVehicle->getVehicleInfo() + " client " + ptrClient->getClientInfo() + " rent begins: " + s1 + " rent ends: " + s2;
    return output;
}

unsigned int Rent::getRentDays() {
    if(endTime == pt::not_a_date_time) return 0;

    pt::time_period period(beginTime, endTime);
    if(period.length().hours() == 0 && period.length().minutes() <= 1) return 0;
    //cout rent ddays
    unsigned  int rentDays = 1;
    unsigned  int moreDays = period.length().hours() % 23;
    rentDays + moreDays;
    return rentDays;

}

const pt::ptime &Rent::getBeginTime() const {
    return beginTime;
}

const pt::ptime &Rent::getEndTime() const {
    return endTime;
}

void Rent::endRent(pt::ptime givenTime) {
    if(endTime == pt::not_a_date_time)
    {
        ptrVehicle->setIsRented(false);
        ptrClient->delRent(this);

        if (givenTime == pt::not_a_date_time)
        {
            endTime = pt::second_clock::local_time();
        } else if (givenTime < beginTime)
        {
            endTime = beginTime;
        } else endTime = givenTime;

    }
    rentCost += ptrVehicle->getBasePrice() * getRentDays();
}

unsigned int Rent::getRentCost()
{
    return rentCost;
}