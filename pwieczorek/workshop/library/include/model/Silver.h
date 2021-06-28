//
// Created by student on 28.06.2021.
//

#ifndef CARRENTAL_SILVER_H
#define CARRENTAL_SILVER_H

#include "model/ClientType.h"


class Silver : public ClientType{
public:
    int getMaxVehicles() override;
    double applyDiscount(int price) override;
    std::string getTypeInfo() override;
};


#endif //CARRENTAL_SILVER_H
