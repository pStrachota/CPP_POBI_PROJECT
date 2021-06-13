//
// Created by student on 27.05.2021.
//

#ifndef STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_OUTSIDER_H
#define STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_OUTSIDER_H
#include "ClientType.h"

/**
 * @brief klasa reprezentujaca klienta typu outsider, dziedziczace z ClientType
 * ten typ klienta oznacza, ze osoby wypozyczajace nie sa zwiazane z uczelnia
 */

class Outsider : public ClientType{
public:
    /**
 * @brief getMaxDays zwaca maksymalna liczbe dni wypozyczen ksiazki lub artyukulu
     * dla outsidera wynosi: 10 dni
 * @return int
 */
    int getMaxDays() const override;
    /**
     * @brief getMaxitems zwaca maksymalna liczbe wypozyczen danego typu klienta
     * dla outsidera wynosi: 1 przedmiot
     * @return int
     */
    int getMaxItems() const override;
    /**
       * @brief getter dla kary za przekroczenie wypozyczenia
       * dla outsidera wynosi: 1zł za każdy przekroczony dzień
       * @return double
       */
    double getPenalty() const override;
    /**
      * @brief getTypeInfo zwraca informacje o typie klienta
      * @return wartosc typu string
      */
    std::string getTypeInfo() const override;

    virtual ~Outsider();
};


#endif //STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_OUTSIDER_H
