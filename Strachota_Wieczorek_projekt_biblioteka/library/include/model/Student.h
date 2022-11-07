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
 
    int getMaxDays() const override;
   
    int getMaxItems() const override;
   
    double getPenalty() const override;
   
    std::string getTypeInfo() const override;

    virtual ~Student();

};


#endif //STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_STUDENT_H
