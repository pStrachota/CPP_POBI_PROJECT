#ifndef CARRENTAL_CAR_H
#define CARRENTAL_CAR_H

#include "model/MotorVehicle.h"

/**
 * @brief klasa Car; dziedziczy z MotorVehicle i reprezentuje auto
 */

enum klasyAut{
    A,B,C,D,E,
};

class Car : public MotorVehicle {
private:
    klasyAut klasa;
public:
    Car(klasyAut klasa, const int & engineDis,const std::string &numerRejestracyjny, const unsigned int &cenaBazowa);
    virtual ~Car();
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


#endif //CARRENTAL_CAR_H
