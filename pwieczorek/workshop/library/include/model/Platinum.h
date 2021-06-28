//
// Created by student on 28.06.2021.
//

#ifndef CARRENTAL_PLATINUM_H
#define CARRENTAL_PLATINUM_H
#include "model/ClientType.h"

class Platinum : public ClientType{
public:
    int getMaxVehicles() override;
    double applyDiscount(int price) override;
    std::string getTypeInfo() override;
};


#endif //CARRENTAL_PLATINUM_H
