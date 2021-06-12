#include "exceptions/ClientException.h"

ClientException::ClientException(const std::string &arg) : logic_error(arg)
{}

std::string ClientException::message() const {
    return what();
}

exceptionFirstName::exceptionFirstName(const std::string &message) : ClientException(message){

}

exceptionLastName::exceptionLastName(const std::string &message) : ClientException(message) {

}

exceptionPersonalID::exceptionPersonalID(const std::string &message) : ClientException(message) {

}

exceptionAddress::exceptionAddress(const std::string &message) : ClientException(message) {

}

exceptionClientType::exceptionClientType(const std::string &message) : ClientException(message) {

}
