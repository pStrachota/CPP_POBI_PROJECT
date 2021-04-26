#include <model/Vehicle.h>

Vehicle::Vehicle(const std::string &platenumber, const unsigned int &baseprice) : plateNumber(platenumber), basePrice(baseprice) {}

std::string Vehicle::getVehicleInfo() {
    std::string text;
    text = plateNumber + " " + std::to_string(basePrice);
    return text;
}

const std::string & Vehicle::getPlateNumber() const {
    return plateNumber;
}

const unsigned int &Vehicle::getBasePrice() const {
    return basePrice;
}

void Vehicle::setPlateNumber(const std::string &platenumber) {
    if(platenumber == "") {
        std::cout << "invalid output" << std::endl;
    } else {
        plateNumber = platenumber;
    }
}

void Vehicle::setBasePrice(const unsigned int &baseprice) {
    basePrice = baseprice;
}

const bool &Vehicle::isRented() const {
    return rented;
}

void Vehicle::setRented(const bool &crented) {
    rented = crented;
}

Vehicle::~Vehicle() {}

double Vehicle::getActualRentalPrice() {
    return getBasePrice();
}
