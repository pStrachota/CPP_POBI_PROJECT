#include "exceptions/RentException.h"

RentException::RentException(const std::string &arg) : logic_error(arg)
{}

std::string RentException::message() const {
    return what();
}

exceptionBeginTime::exceptionBeginTime(const std::string &message) : RentException(message){

}

exceptionClient::exceptionClient(const std::string &message) : RentException(message){

}

exceptionVehicle::exceptionVehicle(const std::string &message) : RentException(message){

}

exceptionID::exceptionID(const std::string &message) : RentException(message){

}

