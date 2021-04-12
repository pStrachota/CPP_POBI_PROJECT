#include "model/Rent.h"
#include "model/Client.h"
#include <string>

class Client;
class Rent;

Rent::Rent(const unsigned int &newId, Client *const c, Vehicle *const v, const pt::ptime &begintime):client(c), vehicle(v) {
    id = newId;
    //vehicle = v;
    //client = c;
    client->addRent(this);
    vehicle->setRented(true);
    if(begintime == pt::not_a_date_time) {
        beginTime = pt::second_clock::local_time();
    } else {
        beginTime = begintime;
    }

}


const unsigned int &Rent::getId() const {
    return id;
}

const Client *Rent::getClient() const {
    return client;
}

const Vehicle *Rent::getVehicle() const {
    return vehicle;
}


std::string Rent::getRentInfo() {
    std::string text;
    std::stringstream ss;
    std::stringstream ss2;
    ss << getBeginTime();
    ss2 << getEndTime();
    std::string text2 = ss.str();
    std::string text3 = ss2.str();
    text = std::to_string(id) + " " + vehicle->getVehicleInfo() + " " + client->getClientInfo() + text2 + " " + text3;
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
        vehicle->setRented(false);
        client->eraseRent(this);

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


unsigned int Rent::getRentCost() {
    return rentCost;
}

