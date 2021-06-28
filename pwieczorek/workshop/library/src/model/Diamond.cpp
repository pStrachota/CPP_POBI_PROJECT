//
// Created by student on 28.06.2021.
//

#include "model/Diamond.h"


int Diamond::getMaxVehicles() {
    return 10;
}

std::string Diamond::getTypeInfo() {
    return "Client Type: Diamond";
}

double Diamond::applyDiscount(int price) {
    double discount = 1.0;
    if (price <= 125) discount = 0.1;
    else if (price > 125 && price <= 250) discount = 0.2;
    else if (price > 250 && price <= 500) discount = 0.3;
    else if (price > 500) discount = 0.4;

    return  price*discount;

}
