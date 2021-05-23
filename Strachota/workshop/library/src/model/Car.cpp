#include <model/Car.h>

Car::Car(SegmentType test, const int &engineDisplacement, const std::string &platenumber, const unsigned int &baseprice) : segment(test),
MotorVehicle(engineDisplacement, platenumber, baseprice) {}

double Car::getActualRentalPrice() const {
    float wage = 0;
    float price;
    if(segment == A) {
        wage = 1;
    }
    else if(segment == B) {
        wage = 1.1;
    }
    else if(segment == C) {
        wage = 1.2;
    }
    else if(segment == D) {
        wage = 1.3;
    }
    else if(segment == E) {
        wage = 1.5;
    }
    price = wage * getBasePrice();
    return price;
}

//Car::~Car() {}

std::string Car::getInfo() const{
    std::string chain;
    chain = segment + " " + MotorVehicle::getInfo();
    return chain;
}


