#include <model/Gold.h>

int Gold::getMaxVehicles() {
    return 4;
}

double Gold::applyDiscount(int base) {
    base *= 0.95;
    return base;
}

std::string Gold::getTypeInfo() {
    return "GOLD";
}

