#include "exceptions/RentableItemException.h"
#include "model/RentableItem.h"

RentableItem::RentableItem(const std::string &serialNumber, const std::string &author, const std::string &title) :
serialNumber(serialNumber), author(author), title(title) {
if(serialNumber.empty()) throw exceptionSerialNumber("INVALID SERIAL NUMBER");
if(author.empty()) throw exceptionAuthor("INVALID AUTHOR");
if(title.empty()) throw exceptionTitle("INVALID TITLE");
}

std::string RentableItem::getInfo() const {
    std::string output;
    output = "Serial number: " + serialNumber + " author: " + author + " title " + title;
    return output;
}


const std::string & RentableItem::getId() const {
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

void RentableItem::setArchive(bool archive) {
    RentableItem::archive = archive;
}
