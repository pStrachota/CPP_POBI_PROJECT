//
// Created by student on 12.06.2021.
//

#ifndef STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_RENTABLEITEMMANAGER_H
#define STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_RENTABLEITEMMANAGER_H

#include "typedefs.h"
#include <memory>
#include <vector>
#include <repositories/RentableItemRepository.h>
#include "repositories/Templates.h"



class RentableItemManager {

private:
    RentableItemRepository rItemRepo;
public:
    RentableItemPtr getRentableItem(const std::string& serialNumber);
    RentableItemPtr registerBook(const std::string& serialNumber, const std::string& author, const std::string& title, const std::string& publishingHouse);


};


#endif //STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_RENTABLEITEMMANAGER_H
