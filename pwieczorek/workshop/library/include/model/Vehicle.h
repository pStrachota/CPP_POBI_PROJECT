#ifndef CARRENTAL_VEHICLE_H
#define CARRENTAL_VEHICLE_H

#include <iostream>

/**
 * @brief klasa Vehicle reprezentuje pojazd
 */


class Vehicle {

private:
    std::string plateNumber;
    unsigned int basePrice;
public:
    Vehicle(const std::string &numerRejestracyjny, const unsigned int &cenaBazowa);
    virtual ~Vehicle();
    /**
    * @brief getter Id
    * @return string Id
    */
    std::string getId() const;
    /**
    * @brief getter tablica rejestracyjna
    * @return string tablica rejestracyjna
    */
    const std::string &getPlateNumber() const;
    /**
    * @brief getter ceny bazowej
    * @return int cena bazowa
    */
    const unsigned int &getBasePrice() const;
    /**
     * @brief setter tablica rejestracyjna
     * @param tablica rejestracyjna
     */
    void setPlateNumber(const std::string &);
    /**
     * @brief setter cena bazowa
     * @param cena bazowa
     */
    void setBasePrice(const int &);
    /**
     * @brief getVehicleInfo agreguje informacje o pojezdzie
     * @return string z informacja
     */
    virtual std::string getVehicleInfo();
    /**
     * @brief getInfo deleguje odpowiedzialność na getVehicleInfo
     * @return string z informacja
     */
    std::string getInfo();
    /**
     * @brief getActualRentalPrice oblicza cene wypozyczenia
     * @return double cena wypozyczenia
     */
    virtual double getActualRentalPrice();

};


#endif //CARRENTAL_VEHICLE_H
