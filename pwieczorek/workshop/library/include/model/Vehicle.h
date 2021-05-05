#ifndef CARRENTAL_VEHICLE_H
#define CARRENTAL_VEHICLE_H

#include <iostream>

class Vehicle {

private:
    std::string plateNumber;
    unsigned int basePrice;
    bool rented = false;
public:
    Vehicle(const std::string &numerRejestracyjny, const unsigned int &cenaBazowa);
    virtual ~Vehicle(); // zmienic na abstrakcyjna

    const std::string &getPlateNumber() const;
    const unsigned int &getBasePrice() const;

    void setPlateNumber(const std::string &);
    void setBasePrice(const unsigned int &);
    const bool isRented() const;
    void setIsRented(bool);

    virtual std::string getVehicleInfo();
    virtual double getActualRentalPrice();

};


#endif //CARRENTAL_VEHICLE_H
