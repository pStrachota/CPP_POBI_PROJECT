#include "model/MotorVehicle.h"

MotorVehicle::MotorVehicle(const int &engineDis, const std::string &numerRejestracyjny, const unsigned int &cenaBazowa)
: Vehicle(numerRejestracyjny,cenaBazowa), engineDisplacement(engineDis) {}


MotorVehicle::~MotorVehicle() {};

double MotorVehicle::getActualRentalPrice() {
    double total, param; // parameter
    if ( engineDisplacement < 1000)
    {
        param = 1.0;
    }
    else if(engineDisplacement <= 2000 && 1000 <= engineDisplacement) {
        param = 1 + ((engineDisplacement - 1000.0) / 2000.0);
    }
    else
    {
        param = 1.5;
    }
    total = param * double(getBasePrice());
    return total;
}

std::string MotorVehicle::getVehicleInfo() {
    return Vehicle::getVehicleInfo() + " pojemnosc " + std::to_string(engineDisplacement);
}