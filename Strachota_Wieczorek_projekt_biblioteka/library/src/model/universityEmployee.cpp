//
// Created by student on 27.05.2021.
//

#include "model/universityEmployee.h"

int universityEmployee::getMaxDays() const {
    return 30;
}

int universityEmployee::getMaxItems() const {
    return 3;
}

double universityEmployee::getPenalty() const {
    return 0.2;
}

std::string universityEmployee::getTypeInfo() const {
    return "UNIVERSITY EMLOYEE";
}
