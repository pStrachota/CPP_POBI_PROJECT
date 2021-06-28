//
// Created by student on 28.06.2021.
//

#ifndef CARRENTAL_GOLD_H
#define CARRENTAL_GOLD_H
#include "model/ClientType.h"

class Gold : public ClientType{
public:
    int getMaxVehicles() override;
    double applyDiscount(int price) override;
    std::string getTypeInfo() override;
};


#endif //CARRENTAL_GOLD_H
