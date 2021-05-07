#ifndef CARRENTAL_BICYCLE_H
#define CARRENTAL_BICYCLE_H
#include "Vehicle.h"
#include <iostream>

class Bicycle : public Vehicle {
public:
    Bicycle(const std::string &platenumber, const unsigned int &baseprice);
    //virtual ~Bicycle();
    virtual double getActualRentalPrice();
    virtual std::string getVehicleInfo();
};




#endif //CARRENTAL_BICYCLE_H
