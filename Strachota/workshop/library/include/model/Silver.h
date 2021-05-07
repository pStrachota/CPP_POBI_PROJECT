#ifndef CARRENTAL_SILVER_H
#define CARRENTAL_SILVER_H


#include "model/ClientType.h"

class Silver : public ClientType
{
public:
    double applyDiscount(int ) override;
    int getMaxVehicles() override;
    std::string getTypeInfo() override;
};

#endif //CARRENTAL_SILVER_H
