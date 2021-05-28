
#include "model/Book.h"

Book::Book(const std::string &serialNumber, const std::string &author, const std::string &title,
           const std::string &publishingHouse) : RentableItem(serialNumber, author, title) , publishingHouse(publishingHouse){}


const std::string & Book::getPublishingHouse() const {
    return publishingHouse;
}

std::string Book::getRentableItemInfo() const {
    std::string output;
    output =  RentableItem::getRentableItemInfo();
    return output;
}

std::string Book::getBookInfo() const {
    std::string output;
    output =  Book::getRentableItemInfo() + " publishing house " + publishingHouse;
    return output;
}