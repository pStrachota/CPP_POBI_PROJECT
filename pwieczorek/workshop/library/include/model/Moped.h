#ifndef CARRENTAL_MOPED_H
#define CARRENTAL_MOPED_H

#include "model/MotorVehicle.h"

class Moped : MotorVehicle {
private:
public:
    Moped(const int & engineDis, const std::string &numerRejestracyjny, const unsigned int &cenaBazowa);
    virtual ~Moped();
    virtual std::string getVehicleInfo();
    virtual double getActualRentalPrice();
};

#endif //CARRENTAL_MOPED_H
