#include "model/Moped.h"

Moped::Moped(int capacity, const std::string &platenumber, const unsigned int &baseprice) : MotorVehicle(capacity, platenumber, baseprice) {}

double Moped::getActualRentalPrice() {
    return MotorVehicle::getActualRentalPrice();
}

std::string Moped::getVehicleInfo() {
    return MotorVehicle::getVehicleInfo();
}

//Moped::~Moped() {}
