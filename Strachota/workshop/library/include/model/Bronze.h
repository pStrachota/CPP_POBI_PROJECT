#ifndef CARRENTAL_BRONZE_H
#define CARRENTAL_BRONZE_H

#include "model/ClientType.h"
#include <iostream>

class Bronze : public ClientType
{
public:
    double applyDiscount(int) override;
    int getMaxVehicles() override;
    std::string getTypeInfo() override;
};


#endif //CARRENTAL_BRONZE_H
