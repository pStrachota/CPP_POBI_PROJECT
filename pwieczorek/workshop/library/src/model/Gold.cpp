//
// Created by student on 28.06.2021.
//

#include "model/Gold.h"

int Gold::getMaxVehicles() {
    return 4;
}

double Gold::applyDiscount(int price) {
    return  price*0.05;
}

std::string Gold::getTypeInfo() {
    return "Client Type: Bronze";
}