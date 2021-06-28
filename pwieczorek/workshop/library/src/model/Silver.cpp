//
// Created by student on 28.06.2021.
//

#include "model/Silver.h"

std::string Silver::getTypeInfo() {
    return  "Client Type: Silver";
}

double Silver::applyDiscount(int price) {
    return 6;
}

int Silver::getMaxVehicles() {
    return 3;
}