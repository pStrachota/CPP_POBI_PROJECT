#ifndef CARRENTAL_VEHICLE_H
#define CARRENTAL_VEHICLE_H
#include <string>
#include <iostream>

class Vehicle {
private:
    std::string plateNumber;
    unsigned int basePrice;
    bool rented = false;
public:
    Vehicle(const std::string &platenumber, const unsigned int &baseprice);
    std::string getVehicleInfo();
    const bool &isRented() const;
    void setRented(const bool &crented);
    const std::string &getPlateNumber() const;
    unsigned int getBasePrice();
    void setPlateNumber(const std::string &platenumber);
    void setBasePrice(const unsigned int &baseprice);
};




#endif //CARRENTAL_VEHICLE_H
