#ifndef CARRENTAL_DEFAULT_H
#define CARRENTAL_DEFAULT_H


#include "model/ClientType.h"

class Default : public ClientType
{
public:
    double applyDiscount(int) override;
    int getMaxVehicles() override;
    std::string getTypeInfo() override;
};

#endif //CARRENTAL_DEFAULT_H
