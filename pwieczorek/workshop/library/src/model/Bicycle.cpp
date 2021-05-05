#include "model/Bicycle.h"


Bicycle::Bicycle(const std::string &numerRejestracyjny, const unsigned int &cenaBazowa) : Vehicle(numerRejestracyjny,cenaBazowa){}

double Bicycle::getActualRentalPrice() {
    return getBasePrice();
}

std::string Bicycle::getVehicleInfo() {
    return getVehicleInfo();
}