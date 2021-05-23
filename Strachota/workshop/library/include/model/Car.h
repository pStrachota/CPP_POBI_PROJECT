#ifndef CARRENTAL_CAR_H
#define CARRENTAL_CAR_H

#include "MotorVehicle.h"
#include <iostream>

/**
 * @brief klasa pojazdu dziedziczaca z klasy Vehicle
 */

enum SegmentType {
    A,
    B,
    C,
    D,
    E
};

class Car : public MotorVehicle {
    SegmentType segment;
public:
    Car(SegmentType test, const int &engineDisplacement, const std::string &platenumber, const unsigned int &baseprice);
    /**
     * @brief getActualRentalPrice oblicza cene "uzywania" danego pojazdu,
     * cena zalezy od typu pojazdu i jego cech
     * @return cena za korzystanie z pojazdu
     */
    double getActualRentalPrice() const override;
    std::string getInfo() const override;
};









#endif //CARRENTAL_CAR_H
