#include <model/Default.h>

int Default::getMaxVehicles() const {
    return 1;
}

double Default::applyDiscount(int base) {
    return base;
}

std::string Default::getTypeInfo() const {
    return "DEFAULT";
}

