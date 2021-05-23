#include <model/Silver.h>

double Silver::applyDiscount(int base) {
    base -= 6;
    return base;
}

int Silver::getMaxVehicles() const {
    return 3;
}

std::string Silver::getTypeInfo() const{
    return "SILVER";
}

