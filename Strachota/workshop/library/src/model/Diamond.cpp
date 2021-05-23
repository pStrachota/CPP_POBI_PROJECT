#include <model/Diamond.h>

double Diamond::applyDiscount(int price) {
    if (price <= 125) return 90.0 / 100.0 * price;
    else if (price <= 250) return 80.0 / 100.0 * price;
    else if (price <= 500) return 70.0 / 100.0 * price;
    else return 60.0 / 100.0 * price;
}

int Diamond::getMaxVehicles() const {
    return 10;
}

std::string Diamond::getTypeInfo() const {
    return "DIAMOND";
}

