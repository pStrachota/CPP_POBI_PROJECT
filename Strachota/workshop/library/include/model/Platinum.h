#ifndef CARRENTAL_PLATINUM_H
#define CARRENTAL_PLATINUM_H


#include "model/ClientType.h"

class Platinum : public ClientType
{
public:
    double applyDiscount(int) override;
    int getMaxVehicles() override;
    std::string getTypeInfo() override;
};

#endif //CARRENTAL_PLATINUM_H
