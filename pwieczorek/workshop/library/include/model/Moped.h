#ifndef CARRENTAL_MOPED_H
#define CARRENTAL_MOPED_H

#include "model/MotorVehicle.h"

/**
 * @brief klasa Moped; dziedziczy z MotorVehicle
 */

class Moped : MotorVehicle {
private:
public:
    Moped(const int & engineDis, const std::string &numerRejestracyjny, const unsigned int &cenaBazowa);
    virtual ~Moped();
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

#endif //CARRENTAL_MOPED_H
