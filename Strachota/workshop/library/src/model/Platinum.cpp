#include <model/Platinum.h>

double Platinum::applyDiscount(int base) {
    base *= 0.90;
    return base;
}

int Platinum::getMaxVehicles() const {
    return 5;
}

std::string Platinum::getTypeInfo() const {
    return "PLATINUM";
}

