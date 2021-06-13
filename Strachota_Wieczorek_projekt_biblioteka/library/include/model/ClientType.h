//
// Created by student on 27.05.2021.
//

#ifndef STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_CLIENTTYPE_H
#define STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_CLIENTTYPE_H

#include <string>
#include <iostream>

/**
 * @brief ClientType to klasa reprezentujaca dany typ klienta
 * w zaleznosci od typu klienta, przysluguja inne kary
 * i maksymalna liczba wypozyczen oraz dni wypozyczenia
 */

class ClientType {
public:
    /**
  * @brief getMaxDays zwaca maksymalna liczbe dni wypozyczen ksiazki lub artyukulu
  * @return int
  */
    virtual int getMaxDays() const  = 0;
    /**
  * @brief getMaxitems zwaca maksymalna liczbe wypozyczen danego typu klienta
  * @return int
  */
    virtual int getMaxItems() const  = 0;
    /**
    * @brief getter dla kary za przekroczenie wypozyczenia
    * rozny dla roznych typow klienta
    * @return double
    */
    virtual double getPenalty() const  = 0;
    /**
   * @brief getInfo konkatenuje i zwraca informacje o kliencie
   * @return wartosc typu string
   */
    virtual std::string getTypeInfo() const = 0;
};

#endif //STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_CLIENTTYPE_H
