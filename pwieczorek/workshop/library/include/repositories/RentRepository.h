#ifndef CARRENTAL_RENTREPOSITORY_H
#define CARRENTAL_RENTREPOSITORY_H
#include <vector>
#include "typedefs.h"
#include <string>
#include "repositories/Repository.h"

class RentRepository {
private:
    std::vector<RentPtr> rentVector;
public:
    RentPtr getRent(unsigned int index);
    void addRent(RentPtr);

    void removeRent(RentPtr);
    std::string getReport();
    const unsigned int getSize() const;
    std::vector<RentPtr> findBy(RentPredicate);
    std::vector<RentPtr> getAllRents();
    bool testId1(const RentPtr &ptr);

};


#endif //CARRENTAL_RENTREPOSITORY_H
