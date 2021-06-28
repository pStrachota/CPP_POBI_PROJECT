//
// Created by student on 28.06.2021.
//

#ifndef CARRENTAL_BRONZE_H
#define CARRENTAL_BRONZE_H

#include "model/ClientType.h"

class Bronze : public ClientType {
public:
    int getMaxVehicles() override;
    double applyDiscount(int price) override;
    std::string getTypeInfo() override;
};


#endif //CARRENTAL_BRONZE_H
