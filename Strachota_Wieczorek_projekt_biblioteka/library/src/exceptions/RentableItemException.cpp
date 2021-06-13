#include "exceptions/RentableItemException.h"

RentableItemException::RentableItemException(const std::string &arg) : logic_error(arg)
{}

std::string RentableItemException::message() const {
    return what();
}

exceptionSerialNumber::exceptionSerialNumber(const std::string &message) : RentableItemException(message) {}

exceptionTitle::exceptionTitle(const std::string &message) : RentableItemException(message){}

exceptionAuthor::exceptionAuthor(const std::string &message) : RentableItemException(message){}