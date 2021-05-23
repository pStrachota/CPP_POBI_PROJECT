#include <model/Vehicle.h>
#include "exceptions/VehicleException.h"

Vehicle::Vehicle(const std::string &platenumber, const unsigned int &baseprice) : plateNumber(platenumber), basePrice(baseprice) {

    if (baseprice <= 0) throw VehicleException(VehicleException::exceptionPrice);
    if (platenumber.empty()) throw VehicleException(VehicleException::exceptionRegistration);

}

std::string Vehicle::getInfo() const {
    std::string text;
    text = plateNumber + " " + std::to_string(basePrice);
    return text;
}

const std::string & Vehicle::getId() const {
    return plateNumber;
}

const unsigned int &Vehicle::getBasePrice() const {
    return basePrice;
}

void Vehicle::setPlateNumber(const std::string &platenumber) {
    if(platenumber.empty()) {
        throw VehicleException(VehicleException::exceptionRegistration);
    } else {
        plateNumber = platenumber;
    }
}

void Vehicle::setBasePrice(const unsigned int &baseprice) {
    if(baseprice < 0) {
        throw VehicleException(VehicleException::exceptionPrice);
    } else {
        basePrice = baseprice;
    }
}


double Vehicle::getActualRentalPrice() const {
    return getBasePrice();
}

void Vehicle::setArchive(bool archive) {
    Vehicle::archive = archive;
}

bool Vehicle::isArchive() const {
    return archive;
}
