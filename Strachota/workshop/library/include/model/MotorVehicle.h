#ifndef CARRENTAL_MOTORVEHICLE_H
#define CARRENTAL_MOTORVEHICLE_H
#include "Vehicle.h"
#include <iostream>

class MotorVehicle : public Vehicle {
    int engineDisplacement;
public:
    MotorVehicle(const int &capacity, const std::string &platenumber, const unsigned int &baseprice);
    virtual ~MotorVehicle();
    virtual double getActualRentalPrice();
    virtual std::string getVehicleInfo();
};








#endif //CARRENTAL_MOTORVEHICLE_H
