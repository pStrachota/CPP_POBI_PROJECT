#ifndef CARRENTAL_RENTREPOSITORY_H
#define CARRENTAL_RENTREPOSITORY_H
#include <vector>
#include "typedefs.h"
#include <string>
#include "repositories/Repository.h"

class RentRepository : public Repository<Rent>{
public:
    std::vector<RentPtr> findBy(RentPredicate);
    std::vector<RentPtr> getAllRents();
};


#endif //CARRENTAL_RENTREPOSITORY_H
