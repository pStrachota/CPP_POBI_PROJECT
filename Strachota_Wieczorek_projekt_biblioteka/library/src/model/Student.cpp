//
// Created by student on 27.05.2021.
//

#include "model/Student.h"

int Student::getMaxDays() const {
    return 20;
}

int Student::getMaxItems() const {
    return 2;
}

double Student::getPenalty() const {
    return 0.5;
}

std::string Student::getTypeInfo() const {
    return "STUDENT";
}
