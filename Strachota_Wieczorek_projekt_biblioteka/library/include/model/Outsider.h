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
    int getMaxDays() const override;
    
    int getMaxItems() const override;
   
    double getPenalty() const override;
  
    std::string getTypeInfo() const override;

    virtual ~Outsider();
};


#endif //STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_OUTSIDER_H
