#ifndef CARRENTAL_DIAMOND_H
#define CARRENTAL_DIAMOND_H


#include "model/ClientType.h"

class Diamond : public ClientType
{
public:
    double applyDiscount(int) override;
    int getMaxVehicles() override;
    std::string getTypeInfo() override;
};

#endif //CARRENTAL_DIAMOND_H
