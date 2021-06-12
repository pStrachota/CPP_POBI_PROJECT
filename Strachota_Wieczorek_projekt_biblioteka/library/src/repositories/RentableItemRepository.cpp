
#include "repositories/RentableItemRepository.h"
#include "model/Client.h"
#include <iostream>
#include "repositories/Templates.h"

std::vector<RentableItemPtr> RentableItemRepository::findByPredicate(const RentableItemPredicate& predicate) {
    {
        std::vector<RentableItemPtr> result;
        for(int i = 0; i<objects.size(); ++i)
        {
            RentableItemPtr rentableItem = objects[i];
            if(predicate(rentableItem))
            {
                result.push_back(rentableItem);
            }
        }
        return result;
    }
}

std::vector<RentableItemPtr> RentableItemRepository::findAllRentableItems() {
    std::vector<RentableItemPtr> result;
    for(int i = 0; i<objects.size(); ++i)
    {
        RentableItemPtr rentableItem = objects[i];
        result.push_back(rentableItem);
    }
    return result;
}