#ifndef CARRENTAL_MOTORVEHICLE_H
#define CARRENTAL_MOTORVEHICLE_H

#include <string>
#include "Vehicle.h"

class MotorVehicle : public Vehicle {
private:
    int engineDisplacement;
public:
    MotorVehicle(const int & engineDis,const std::string &numerRejestracyjny, const unsigned int &cenaBazowa);
    virtual  ~MotorVehicle(); // zmienic na abstrakcyjna
    virtual  std::string getVehicleInfo();
    virtual  double getActualRentalPrice();
};

#endif //CARRENTAL_MOTORVEHICLE_H
