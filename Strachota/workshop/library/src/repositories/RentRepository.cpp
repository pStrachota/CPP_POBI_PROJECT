#include <repositories/RentRepository.h>

RentPtr RentRepository::getRent(unsigned int index) {
   // unsigned int i = 1;
    for(auto & currentRent : currentRents) {
        if(currentRent->getId() == index) {
            return currentRent;
        }
    }
    /*
    for (std::vector<RentPtr>::iterator it = currentRents.begin(); it != currentRents.end(); it++) {
        if(i == index)
        {
            return *it;
        }
        i++;
    }
     */
    return nullptr;
}

void RentRepository::addRent(RentPtr newR) {
    if(newR == nullptr) {}
    else {
        currentRents.push_back(newR);
    }
}

void RentRepository::removeRent(RentPtr delR) {
    if(delR == nullptr) {}
    else {
        currentRents.erase(std::remove(currentRents.begin(), currentRents.end(), delR), currentRents.end());
    }
}

std::string RentRepository::getReport() {
    std::string result;
    for (std::vector<RentPtr>::iterator it = currentRents.begin(); it != currentRents.end(); it++) {
        result += ((*it)->getRentInfo() + '\n');
    }
    return result;
}

const unsigned int RentRepository::rentSize() const {
    return currentRents.size();
}

bool RentRepository::testId1(const RentPtr &ptr) {
    return ptr->getId()==1;
}

std::vector <RentPtr> RentRepository::findBy(RentPredicate predicate) {

    std::vector<RentPtr> fonde;
    for(auto & currentRent : currentRents) {
        if(currentRent != nullptr && predicate(currentRent)) {
            fonde.push_back(currentRent);
        }
    }
    return fonde;
    /*
    std::vector<RentPtr> found;
    for (unsigned int i = 0; i < currentRents.size(); i++) {
        RentPtr rent = getRent(i);
        if (rent != nullptr && predicate(rent)) {
            found.push_back(rent);
        }
    }
    return found;
     */
}

std::vector<RentPtr> RentRepository::findAll() {
    std::vector<RentPtr> found;
    for(auto & currentRent : currentRents) {
        if(currentRent != nullptr) {
            found.push_back(currentRent);
        }
    }
    /*
    for (unsigned int i = 0; i < currentRents.size(); i++) {
        RentPtr rent = getRent(i);
        if (rent != nullptr) {
            found.push_back(rent);
        }
    }
     */
    return found;
}

