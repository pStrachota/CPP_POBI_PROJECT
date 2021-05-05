#ifndef CARRENTAL_VEHICLE_H
#define CARRENTAL_VEHICLE_H
#include <string>
#include <iostream>
#include "typedefs.h"

class Vehicle {
private:
    std::string plateNumber;
    unsigned int basePrice;
    //bool rented = false;
public:
    Vehicle(const std::string &platenumber, const unsigned int &baseprice);
    //virtual ~Vehicle();
    virtual std::string getVehicleInfo();
    //const bool &isRented() const;
    //void setRented(const bool &crented);
    const std::string &getPlateNumber() const;
    const unsigned int &getBasePrice() const;
    void setPlateNumber(const std::string &platenumber);
    void setBasePrice(const unsigned int &baseprice);
    virtual double getActualRentalPrice();
};




#endif //CARRENTAL_VEHICLE_H
