//
// Created by student on 27.05.2021.
//

#ifndef STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_UNIVERSITYEMPLOYEE_H
#define STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_UNIVERSITYEMPLOYEE_H

#include "ClientType.h"

class universityEmployee : public ClientType{
public:
    int getMaxDays() const override;

    int getMaxItems() const override;

    double getPenalty() const override;

    std::string getTypeInfo() const override;
};


#endif //STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_UNIVERSITYEMPLOYEE_H
