#include <model/Bicycle.h>

Bicycle::Bicycle(const std::string &platenumber, const unsigned int &baseprice) : Vehicle(platenumber, baseprice) {}

double Bicycle::getActualRentalPrice() const {
    return getBasePrice();
}

std::string Bicycle::getInfo() const{
    return Vehicle::getInfo();
}

//Bicycle::~Bicycle() {}

