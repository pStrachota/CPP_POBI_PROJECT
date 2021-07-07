#include "repositories/RentRepository.h"
#include "model/Rent.h"

/*
const unsigned int RentRepository::getSize() const {
    return rentVector.size();
}


std::string RentRepository::getReport() {
    std::string output;
    for(std::vector<RentPtr>::iterator it = rentVector.begin(); it != rentVector.end(); ++it) {
        output += " " + (*it)->getRentInfo() + "\n";
    }
    return output;
}

std::vector<RentPtr> RentRepository::getAllRents() {
    return rentVector;
}


void RentRepository::addRent(RentPtr someRent) {
    if (someRent != nullptr){
        rentVector.push_back(someRent);
    }
}

void RentRepository::removeRent(RentPtr someRent) {
    if (someRent != nullptr){
        rentVector.erase(std::remove(rentVector.begin(), rentVector.end(), someRent), rentVector.end());
    }
}

RentPtr RentRepository::getRent(unsigned int index) {
    if ( index > (rentVector.size()-1)) return nullptr;
    return rentVector[index];
}

std::vector<RentPtr> RentRepository::findBy(RentPredicate predicate) {
    std::vector<RentPtr> found;
    for (unsigned int i = 0; i < rentVector.size(); i++) {
        RentPtr rent = getRent(i);
        if ( rent != nullptr && predicate(rent)) {
            found.push_back(rent);
        }
    }
    return found;
}
bool RentRepository::testId1(const RentPtr &ptr) {
    return ptr->getID() == 1;
}
*/
std::vector<RentPtr> RentRepository::findBy(RentPredicate predicate) {
    std::vector<RentPtr> found;
    for (unsigned int i = 0; i < objects.size(); i++) {
        RentPtr rent = get(i);
        if ( rent != nullptr && predicate(rent)) {
            found.push_back(rent);
        }
    }
    return found;
}

std::vector<RentPtr> RentRepository::getAllRents() {
    std::vector<RentPtr> rents;
    for(unsigned int i = 0; i < objects.size();i++){
        rents.push_back(objects[i]);
    }
    return rents;
}