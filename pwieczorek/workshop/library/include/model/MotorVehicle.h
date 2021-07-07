#ifndef CARRENTAL_MOTORVEHICLE_H
#define CARRENTAL_MOTORVEHICLE_H

#include <string>
#include "Vehicle.h"

/**
 * @brief klasa MotorVehicle; dziedziczy z Vehicle
 */

class MotorVehicle : public Vehicle {
private:
    int engineDisplacement;
public:
    MotorVehicle(const int & engineDis,const std::string &numerRejestracyjny, const unsigned int &cenaBazowa);
    virtual  ~MotorVehicle();
    /**
     * @brief getVehicleInfo agreguje informacje o pojezdzie
     * @return string z informacja
     */
    virtual  std::string getVehicleInfo();
    /**
     * @brief getActualRentalPrice oblicza cene wypozyczenia
     * @return double cena wypozyczenia
     */
    virtual  double getActualRentalPrice();
};

#endif //CARRENTAL_MOTORVEHICLE_H
