#include <model/Default.h>

int Default::getMaxVehicles() {
    return 1;
}

double Default::applyDiscount(int base) {
    return base;
}

std::string Default::getTypeInfo() {
    return "DEFAULT";
}

