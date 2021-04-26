#ifndef CARRENTAL_RENTREPOSITORY_H
#define CARRENTAL_RENTREPOSITORY_H

#include <iostream>
#include "model/Rent.h"
#include <vector>

class RentRepository {
    std::vector<RentPtr> currentRents;
public:
    RentPtr getRent(unsigned int index);
    void addRent(RentPtr);
    void removeRent(RentPtr);
    std::string getReport();
    const unsigned int rentSize() const;
    std::vector<RentPtr> findBy(RentPredicate);
    std::vector<RentPtr> findAll();
    bool testId1(const RentPtr &ptr);


};





#endif //CARRENTAL_RENTREPOSITORY_H
