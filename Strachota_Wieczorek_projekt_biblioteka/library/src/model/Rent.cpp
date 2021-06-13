#include "model/Rent.h"
#include "model/Client.h"
#include "model/RentableItem.h"
#include <math.h>
#include "exceptions/RentExceptions.h"

#include <utility>


//zmienic client i renetableItem na referencje (pisze zeby nie zapomniec)

Rent::Rent(pt::ptime rentBeginTime, const ClientPtr& client, const RentableItemPtr& rentableItem) : client(client), rentableItem(rentableItem) {
    this->rentCost = 0;
    if(rentBeginTime == pt::not_a_date_time) beginTime = pt::second_clock::local_time();
    else beginTime = rentBeginTime;

    boost::uuids::random_generator generator;
    this->RentId = generator();

    if (client == nullptr) throw exceptionClient("INVALID CLIENT");
    if (rentableItem == nullptr) throw exceptionRentableItem("INVALID RENTABLE ITEM");
    if (rentBeginTime == pt::not_a_date_time) throw exceptionBeginTime("INVALID DATE");
}

boost::uuids::uuid Rent::getRentId() const {
    return RentId;
}

pt::ptime Rent::getBeginTime() const {
    return beginTime;
}

pt::ptime Rent::getEndTime() const {
    return endTime;
}

float Rent::getRentCost() const{
    return rentCost;
}

void Rent::setRentCost( float cost) {
    rentCost = cost;
}

int Rent::getRentPenaltyDays() const {
    if(endTime == pt::not_a_date_time) return 0;

    pt::time_period period(getBeginTime(), getEndTime());
    if(period.length().hours() == 0 && period.length().minutes() <= 1) return 0;

    unsigned  int rentDays = period.length().hours() / 24;
    int maxDays = getClient()->getMaxDays();

    if (maxDays < rentDays) return (rentDays - maxDays);
    else return 0;
}

void Rent::setEndTime(pt::ptime time) {
    endTime = time;
}

void Rent::endRent(pt::ptime endTime) {
    setEndTime(endTime);
    double penalty = getClient()->getPenalty();
    float total_cost = float(int(getRentPenaltyDays())) * float(penalty);
    //roundf(total_cost);
    setRentCost(total_cost);
}

ClientPtr Rent::getClient() const{
    return client;
}

RentableItemPtr Rent::getRentableItem() const{
    return rentableItem;
}

const std::string Rent::getRentInfo() const {
    std::string output;
    output = "| Klient |" + getClient()->getInfo() + " wypozyczyl " + " " + getRentableItem()->getInfo();
    return output;
}
/*
bool Rent::isEnded() const {
    return ended;
}
*/