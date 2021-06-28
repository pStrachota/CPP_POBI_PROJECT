//
// Created by student on 28.06.2021.
//

#ifndef CARRENTAL_DIAMOND_H
#define CARRENTAL_DIAMOND_H
#include "model/ClientType.h"

class Diamond : public ClientType{
public:
    int getMaxVehicles() override;
    double applyDiscount(int price) override;
    std::string getTypeInfo() override;
};


#endif //CARRENTAL_DIAMOND_H
