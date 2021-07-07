#ifndef CARRENTAL_BICYCLE_H
#define CARRENTAL_BICYCLE_H

#include "string"
#include "Vehicle.h"

/**
 * @brief klasa Bicycle; dziedziczy z Vehicle i reprezentuje motocykl
 */

class Bicycle : public Vehicle {
public:
    Bicycle(const std::string &numerRejestracyjny, const unsigned int &cenaBazowa);
    virtual ~Bicycle();
    /**
     * @brief getVehicleInfo agreguje informacje o pojezdzie
     * @return string z informacja
     */
    virtual std::string getVehicleInfo();
    /**
     * @brief getActualRentalPrice oblicza cene wypozyczenia
     * @return double cena wypozyczenia
     */
    virtual double getActualRentalPrice();
};


#endif //CARRENTAL_BICYCLE_H
