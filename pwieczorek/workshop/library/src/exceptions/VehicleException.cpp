#include "exceptions/VehicleException.h"

VehicleException::VehicleException(const std::string &arg) : logic_error(arg)
{}

std::string VehicleException::message() const {
    return what();
}

exceptionBasePrice::exceptionBasePrice(const std::string &message) : VehicleException(message){}

exceptionPlateNumber::exceptionPlateNumber(const std::string &message) : VehicleException(message){}