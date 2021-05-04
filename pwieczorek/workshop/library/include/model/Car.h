#ifndef CARRENTAL_CAR_H
#define CARRENTAL_CAR_H

#include "model/MotorVehicle.h"

enum klasyAut{
    A,B,C,D,E,
};

class Car : public MotorVehicle {
private:
    klasyAut klasa;
public:
    Car(klasyAut klasa, const int & engineDis,const std::string &numerRejestracyjny, const unsigned int &cenaBazowa);
    virtual ~Car();
    virtual std::string getVehicleInfo();
    virtual double getActualRentalPrice();
};


#endif //CARRENTAL_CAR_H
