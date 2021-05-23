#ifndef CARRENTAL_MOPED_H
#define CARRENTAL_MOPED_H
#include "MotorVehicle.h"
#include <iostream>

/**
 * @brief klasa pojazdu dziedziczaca z klasy MotorVehicle
 */

class Moped : public MotorVehicle {
public:
    Moped(const int &engineDisplacement, const std::string &platenumber, const unsigned int &baseprice);
    /**
     * @brief getActualRentalPrice oblicza cene "uzywania" danego pojazdu,
     * cena zalezy od typu pojazdu i jego cech
     * @return cena za korzystanie z pojazdu
     */
    virtual double getActualRentalPrice() const ;
    /**
    * @brief getInfo konkatenuje informacje o okreslonym typie pojazdu
    * @return string zawierajacy informacje o pojezdzie
    */
    virtual std::string getInfo() const ;
};


#endif //CARRENTAL_MOPED_H
