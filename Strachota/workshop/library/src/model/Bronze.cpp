#include "model/Bronze.h"

double Bronze::applyDiscount(int base)
{
    base -= 3;
    return base;
}

int Bronze::getMaxVehicles()
{
    return 2;
}

std::string Bronze::getTypeInfo()
{
    return "BRONZE";
}
