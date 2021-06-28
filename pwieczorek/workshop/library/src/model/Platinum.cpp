//
// Created by student on 28.06.2021.
//

#include "model/Platinum.h"


std::string Platinum::getTypeInfo() {
    return "Client Type: Platinum";
}

double Platinum::applyDiscount(int price) {
    return price*0.1;
}

int Platinum::getMaxVehicles() {
    return 5;
}