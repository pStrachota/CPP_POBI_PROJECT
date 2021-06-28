//
// Created by student on 28.06.2021.
//

#ifndef CARRENTAL_DEFAULT_H
#define CARRENTAL_DEFAULT_H

#include "model/ClientType.h"

class Default : public ClientType{
public:
    int getMaxVehicles() override;
    double applyDiscount(int price) override;
    std::string getTypeInfo() override;
};


#endif //CARRENTAL_DEFAULT_H
