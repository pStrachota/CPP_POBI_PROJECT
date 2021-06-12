//
// Created by student on 12.06.2021.
//

#include "managers/RentableItemManager.h"
#include "model/Book.h"
#include "model/Article.h"
#include <memory>
#include "repositories/Templates.h"
#include "exceptions/ClientException.h"
#include <fstream>

RentableItemPtr
RentableItemManager::registerBook(const std::string& serialNumber, const std::string& author, const std::string& title, const std::string& publishingHouse) {

    RentableItemPtr rItemcheck = getRentableItem(serialNumber);
    if(rItemcheck == nullptr) {
        RentableItemPtr newRentableItem = std::make_shared<Book>(serialNumber, author, title,  publishingHouse);
        rItemRepo.add(newRentableItem);
        return newRentableItem;
    } else {
        return rItemcheck;
    }
}

RentableItemPtr RentableItemManager::getRentableItem(const std::string& serialNumber) {
    return rItemRepo.findById(serialNumber);
}

RentableItemPtr RentableItemManager::registerArticle(const std::string &serialNumber, const std::string &author,
                                                     const std::string &title, const std::string &parentOrganisation) {
    RentableItemPtr rItemcheck = getRentableItem(serialNumber);
    if(rItemcheck == nullptr) {
        RentableItemPtr newRentableItem = std::make_shared<Article>(serialNumber, author, title, parentOrganisation);
        rItemRepo.add(newRentableItem);
        return newRentableItem;
    } else {
        return rItemcheck;
    }
}

void RentableItemManager::unregisterRentableItem(const RentableItemPtr& toDel) {
    if(toDel != nullptr) {
        toDel->setArchive(true);
    }
}

std::vector<RentableItemPtr> RentableItemManager::findRentableItem(const RentableItemPredicate& predicate) {
    RentableItemPredicate sum = [&predicate](const RentableItemPtr & test) {
        return predicate(test) && !test->isArchive();
    };
    return rItemRepo.findByPredicate(sum);
}

void RentableItemManager::saveRentableItemsToFileByPredicate(const RentableItemPredicate &predicate) {
    RentableItemPredicate sum = [&predicate](const RentableItemPtr & test) {
        return predicate(test) && !test->isArchive();
    };
    std::vector<RentableItemPtr> result = rItemRepo.findByPredicate(sum);

    std::ofstream proba;
    proba.open("/home/student/RentableItemsbyPredicateInfo");

    if (!proba) {
        throw exceptionCannotOpenFile("CANNOT OPEN FILE TO SAVE DATA");
    } else {
        for (auto &i : result) {
            proba << i->getInfo() << std::endl;
        }
        proba.close();
    }
}



