#include "repositories/RentRepository.h"
#include "model/Rent.h"
#include <iostream>
#include "repositories/Templates.h"

std::vector<RentPtr> RentRepository::findByPredicate(const RentPredicate& predicate) {
    {
        std::vector<RentPtr> result;
        for(int i = 0; i<objects.size(); ++i)
        {
            RentPtr rent = objects[i];
            if(predicate(rent))
            {
                result.push_back(rent);
            }
        }
        return result;
    }
}

std::vector<RentPtr> RentRepository::findAllRents() {
    std::vector<RentPtr> result;
    for(int i = 0; i<objects.size(); ++i)
    {
        RentPtr rent = objects[i];
        result.push_back(rent);
    }
    return result;
}

