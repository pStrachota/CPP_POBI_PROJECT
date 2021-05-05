#ifndef CARRENTAL_GOLD_H
#define CARRENTAL_GOLD_H

#include "model/ClientType.h"

class Gold : public ClientType
{
public:
    double applyDiscount(int) override;
    int getMaxVehicles() override;
    std::string getTypeInfo() override;
};

#endif //CARRENTAL_GOLD_H
