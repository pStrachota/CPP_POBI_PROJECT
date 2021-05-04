#ifndef CARRENTAL_BICYCLE_H
#define CARRENTAL_BICYCLE_H

#include "string"
#include "Vehicle.h"

class Bicycle : public Vehicle {
private:

public:
    Bicycle(const std::string &numerRejestracyjny, const unsigned int &cenaBazowa);
    virtual ~Bicycle();
    virtual std::string getVehicleInfo();
    virtual double getActualRentalPrice();
};


#endif //CARRENTAL_BICYCLE_H
