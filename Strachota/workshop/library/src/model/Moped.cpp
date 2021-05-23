#include "model/Moped.h"

Moped::Moped(const int &engineDisplacement, const std::string &platenumber, const unsigned int &baseprice) : MotorVehicle(engineDisplacement, platenumber, baseprice) {}

double Moped::getActualRentalPrice() const {
    return MotorVehicle::getActualRentalPrice();
}

std::string Moped::getInfo() const {
    return MotorVehicle::getInfo();
}
