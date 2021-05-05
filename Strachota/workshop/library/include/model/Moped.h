#ifndef CARRENTAL_MOPED_H
#define CARRENTAL_MOPED_H
#include "MotorVehicle.h"
#include <iostream>

class Moped : public MotorVehicle {
public:
    Moped(int capacity, const std::string &platenumber, const unsigned int &baseprice);
    //virtual ~Moped();
    virtual double getActualRentalPrice();
    virtual std::string getVehicleInfo();
};


#endif //CARRENTAL_MOPED_H
