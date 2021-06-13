//
// Created by student on 27.05.2021.
//

#ifndef STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_STUDENT_H
#define STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_STUDENT_H

#include "ClientType.h"

/**
 * @brief klasa reprezentujaca klienta typu outsider, dziedziczace z ClientType
 * ten typ klienta oznacza, ze osoby wypozyczajace ucza sie na danej uczelni
 */

class Student : public ClientType {

public:
    /**
* @brief getMaxDays zwaca maksymalna liczbe dni wypozyczen ksiazki lub artyukulu
    * dla studenta wynosi: 20 dni
* @return int
*/
    int getMaxDays() const override;
    /**
    * @brief getMaxitems zwaca maksymalna liczbe wypozyczen danego typu klienta
    * dla studenta wynosi: 2 przedmioty
    * @return int
    */
    int getMaxItems() const override;
    /**
       * @brief getter dla kary za przekroczenie wypozyczenia
       * dla studenta wynosi: 50gr za każdy przekroczony dzień
       * @return double
       */
    double getPenalty() const override;
    /**
      * @brief getTypeInfo zwraca informacje o typie klienta
      * @return wartosc typu string
      */
    std::string getTypeInfo() const override;

    virtual ~Student();

};


#endif //STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_STUDENT_H
