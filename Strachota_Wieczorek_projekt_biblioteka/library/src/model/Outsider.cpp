//
// Created by student on 27.05.2021.
//

#include "model/Outsider.h"

int Outsider::getMaxDays() const {
    return 10;
}

int Outsider::getMaxItems() const {
    return 1;
}

double Outsider::getPenalty() const {
    return 1;
}

std::string Outsider::getTypeInfo() const {
    return "OUTSIDER";
}
