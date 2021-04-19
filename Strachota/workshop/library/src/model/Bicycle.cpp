#include <model/Bicycle.h>

Bicycle::Bicycle(const std::string &platenumber, const unsigned int &baseprice) : Vehicle(platenumber, baseprice) {}

double Bicycle::getActualRentalPrice() {
    return getBasePrice();
}

std::string Bicycle::getVehicleInfo() {
    return Vehicle::getVehicleInfo();
}

Bicycle::~Bicycle() {}

