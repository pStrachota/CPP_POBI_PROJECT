#include "exceptions/RentExceptions.h"

RentException::RentException(const std::string &arg) : logic_error(arg)
{}

std::string RentException::message() const {
    return what();
}

exceptionBeginTime::exceptionBeginTime(const std::string &message) : RentException(message){

}

exceptionClient::exceptionClient(const std::string &message) : RentException(message){

}

exceptionRentableItem::exceptionRentableItem(const std::string &message) : RentException(message){

}

exceptionUnableToOpenFile::exceptionUnableToOpenFile(const std::string &message) : RentException(message){

}