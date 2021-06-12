//
// Created by student on 12.06.2021.
//

#include "managers/RentableItemManager.h"

RentableItemPtr
RentableItemManager::registerBook(const std::string& serialNumber, const std::string& author, const std::string& title, const std::string& publishingHouse) {

    RentableItemPtr rItemcheck = getRentableItem(serialNumber);
    if(rItemcheck == nullptr) {
        RentableItemPtr newRentableItem = std::make_shared<RentableItem>(serialNumber, author, title,  publishingHouse);
    }
    return RentableItemPtr();
}

RentableItemPtr RentableItemManager::getRentableItem(const std::string& serialNumber) {
    return rItemRepo.findById(serialNumber);
}
