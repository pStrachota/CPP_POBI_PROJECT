#ifndef CARRENTAL_VEHICLE_H
#define CARRENTAL_VEHICLE_H
#include <string>
#include <iostream>
#include "typedefs.h"

/**
 * @brief Vehicle to klasa abstrakcyjna, z ktorej dziedzicza odpowiednie typy pojazow
 */

class Vehicle {
private:
    std::string plateNumber;
    unsigned int basePrice;
    bool archive = false;


public:
    /**
     * dla tablicy oraz ceny zaimplementowano obsluge wyjatkow
     * @param platenumber - number tablicy
     * @param baseprice - cena bazowa
     */
    Vehicle(const std::string &platenumber, const unsigned int &baseprice);
    /**
    * @brief getInfo konkatenuje informacje o okreslonym typie pojazdu
    * @return string zawierajacy informacje o pojezdzie
    */
    virtual std::string getInfo() const;
    /**
     * @brief setter dla umieszczenia w archiwum - dokonuje tego zarzadca
     * @param archive
     */
    void setArchive(bool archive);
    /**
     * @brief getter dla sprawdzenia, czy pojazd jest archiwalny
     * @return bool informujacy o stanie pojazdu
     */
    bool isArchive() const;
    /**
     * @brief getId - to metoda korzystajaca z szablonu znajdujacego sie w repository.h
     * @return informacje o tablicy rejestracyjnej
     */
    const std::string &getId() const;
    /**
     * @brief getter dla ceny bazowej pojazdu
     * @return unsigned int informujacy o cenie pojazdu
     */
    const unsigned int &getBasePrice() const;
    /**
     * @brief setter dla tablicy rejestracyjnej
     * @param platenumber - numer tablicy
     */
    void setPlateNumber(const std::string &platenumber);
    /**
     * @brief setter dla ceny bazowej
     * @param baseprice - cena bazowa
     */
    void setBasePrice(const unsigned int &baseprice);
    /**
     * @brief getActualRentalPrice oblicza cene "uzywania" danego pojazdu,
     * cena zalezy od typu pojazdu i jego cech
     * @return cena za korzystanie z pojazdu
     */
    virtual double getActualRentalPrice() const;
};




#endif //CARRENTAL_VEHICLE_H
