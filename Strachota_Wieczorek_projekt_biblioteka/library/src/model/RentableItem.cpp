
#include "model/RentableItem.h"

RentableItem::RentableItem(const std::string &serialNumber, const std::string &author, const std::string &title) :
serialNumber(serialNumber), author(author), title(title) {

}

std::string RentableItem::getRentableItemInfo() const {
    std::string output;
    output = "Serial number: " + serialNumber + " author: " + author + " title " + title;
    return output;
}


const std::string & RentableItem::getSerialNumber() const {
    return serialNumber;
}

const std::string & RentableItem::getAuthor() const {
    return author;
}

const std::string & RentableItem::getTitle() const {
    return title;
}

bool RentableItem::isArchive() const {
    return archive;
}