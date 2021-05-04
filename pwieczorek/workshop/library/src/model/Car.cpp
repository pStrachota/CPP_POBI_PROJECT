#include "model/Car.h"

Car::Car(klasyAut klasa, const int &engineDis, const std::string &numerRejestracyjny, const unsigned int &cenaBazowa) : MotorVehicle(engineDis,numerRejestracyjny,cenaBazowa),
klasa(klasa) {}

Car::~Car() {}

double Car::getActualRentalPrice() {
    double param;
    if (klasa == A)
    {
        param = 1.0;
    }
    else if (klasa == B)
    {
        param = 1.1;
    }
    else if (klasa == C)
    {
        param = 1.2;
    }
    else if (klasa == D)
    {
        param = 1.3;
    }
    else if (klasa == E)
    {
        param = 1.5;
    }

    return getBasePrice() * param;
}

std::string Car::getVehicleInfo() {
    std::string klasaInfo = std::to_string(klasa);
    return MotorVehicle::getVehicleInfo() + " klasa " + klasaInfo;
}