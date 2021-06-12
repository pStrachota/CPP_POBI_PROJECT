//
// Created by student on 27.05.2021.
//

#ifndef STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_CLIENTTYPE_H
#define STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_CLIENTTYPE_H

#include <string>
#include <iostream>

class ClientType {
public:
    virtual int getMaxDays() const  = 0;
    virtual int getMaxItems() const  = 0;
    virtual double getPenalty() const  = 0;
    virtual std::string getTypeInfo() const = 0;
};

#endif //STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_CLIENTTYPE_H
