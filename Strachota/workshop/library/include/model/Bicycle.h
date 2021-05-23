#ifndef CARRENTAL_BICYCLE_H
#define CARRENTAL_BICYCLE_H
#include "Vehicle.h"
#include <iostream>

/**
 * @brief klasa pojazdu dziedziczaca z klasy Vehicle
 */

class Bicycle : public Vehicle {

public:
    Bicycle(const std::string &platenumber, const unsigned int &baseprice);
    /**
     * @brief getActualRentalPrice oblicza cene "uzywania" danego pojazdu,
     * cena zalezy od typu pojazdu i jego cech
     * @return cena za korzystanie z pojazdu
     */
    double getActualRentalPrice() const override;
    /**
    * @brief getInfo konkatenuje informacje o okreslonym typie pojazdu
    * @return string zawierajacy informacje o pojezdzie
    */
    std::string getInfo() const override;
};




#endif //CARRENTAL_BICYCLE_H
