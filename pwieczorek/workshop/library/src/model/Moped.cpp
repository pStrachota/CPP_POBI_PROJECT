#include "model/Moped.h"

Moped::Moped(const int &engineDis, const std::string &numerRejestracyjny, const unsigned int &cenaBazowa) : MotorVehicle(engineDis,numerRejestracyjny,cenaBazowa){
// dziedziczy po MotorVehicle
}

Moped::~Moped() {}

std::string Moped::getVehicleInfo() {
    return MotorVehicle::getVehicleInfo();
}

double Moped::getActualRentalPrice() {
    return MotorVehicle::getActualRentalPrice();
}