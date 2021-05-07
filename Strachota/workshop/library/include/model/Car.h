#ifndef CARRENTAL_CAR_H
#define CARRENTAL_CAR_H

#include "MotorVehicle.h"
#include <iostream>

enum SegmentType {
    A,
    B,
    C,
    D,
    E
};

class Car : public MotorVehicle {
    SegmentType segment;
public:
    Car(SegmentType test, int capacity, const std::string &platenumber, const unsigned int &baseprice);
    //virtual ~Car();
    virtual double getActualRentalPrice();
    virtual std::string getVehicleInfo();
};









#endif //CARRENTAL_CAR_H
