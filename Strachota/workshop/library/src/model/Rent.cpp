#include "model/Rent.h"
#include "model/Client.h"
#include <string>
#include "model/Vehicle.h"
#include "exceptions/RentException.h"
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include "repositories/Repository.h"

Rent::Rent(const ClientPtr &client, const VehiclePtr &vehicle, const pt::ptime &beginTime):id(boost::uuids::random_generator()()), client(client), vehicle(vehicle) {
    if(beginTime == pt::not_a_date_time) {
        this->beginTime = pt::second_clock::local_time();
    } else {
        this->beginTime = beginTime;
    }

    if (client == nullptr) throw RentException(RentException::exceptionClientNullPtr);
    if (vehicle == nullptr) throw RentException(RentException::exceptionVehicleNullPtr);
    if (getRentDays() < 0) throw RentException(RentException::exceptionDays);

}



const ClientPtr &Rent::getClient() const {
    return client;
}

const VehiclePtr &Rent::getVehicle() const {
    return vehicle;
}


std::string Rent::getInfo() const {

    std::string text;
    std::stringstream ss;
    std::stringstream ss2;
    ss << getBeginTime();
    ss2 << getEndTime();
    std::string text2 = ss.str();
    std::string text3 = ss2.str();
    std::string s = boost::lexical_cast<std::string>(id);
    text = s + " " + ::getInfo(vehicle) + " " + ::getInfo(client) + text2 + " " + text3;
    return text;

}

const pt::ptime &Rent::getBeginTime() const {
    return this->beginTime;
}

const pt::ptime &Rent::getEndTime() const {
    return this->endTime;
}

void Rent::endRent(pt::ptime exampleTime) {
    if(endTime == pt::not_a_date_time) {

        if (exampleTime == pt::not_a_date_time) {
            endTime = pt::second_clock::local_time();
        } else if (exampleTime < beginTime) {
            endTime = beginTime;
        }
        else {
        endTime = exampleTime;
        }
    }

    rentCost = vehicle->getBasePrice() * getRentDays();
}

unsigned int Rent::getRentDays() {
    if(endTime == pt::not_a_date_time) return 0;
    //if(endTime <= beginTime) return 0;
    pt::time_period period(beginTime, endTime);
    if(period.length().hours() == 0 && period.length().minutes() <= 1) {
        return 0;
    }
    int total = 0;
    for(int i = 0; i <= period.length().hours(); i+=23) {
        total += 1;
        i++;
    }
    return total;
}


unsigned int Rent::getRentCost() const{
    if(rentCost <= 0) return 0;
    //rentCost = client->applyDiscount(rentCost);
    return client->applyDiscount(rentCost);
}

const boost::uuids::uuid &Rent::getId() const {
    return id;
}




