#ifndef CARRENTAL_MOTORVEHICLE_H
#define CARRENTAL_MOTORVEHICLE_H
#include "Vehicle.h"
#include <iostream>

/**
 * @brief klasa pojazdu dziedziczaca z klasy Vehicle
 */

class MotorVehicle : public Vehicle {
    int engineDisplacement;
public:
    MotorVehicle(const int &engineDisplacement, const std::string &platenumber, const unsigned int &baseprice);
    /**
     * @brief getActualRentalPrice oblicza cene "uzywania" danego pojazdu,
     * cena zalezy od typu pojazdu i jego cech
     * @return cena za korzystanie z pojazdu
     */
    virtual double getActualRentalPrice() const;
    /**
    * @brief getInfo konkatenuje informacje o okreslonym typie pojazdu
    * @return string zawierajacy informacje o pojezdzie
    */
    virtual std::string getInfo() const;
};








#endif //CARRENTAL_MOTORVEHICLE_H
