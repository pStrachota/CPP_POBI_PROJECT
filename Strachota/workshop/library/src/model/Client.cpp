#include <string>
#include "model/Client.h"
#include "model/Address.h"
#include "model/ClientType.h"
#include "exceptions/ClientException.h"
#include "repositories/Repository.h"

std::string Client::getInfo() const{
    std::string chain;
    chain = clientType->getTypeInfo() + " " + firstName + " " + lastName + " " + personalID + " " + ::getInfo(address);
    return chain;
}

void Client::setLastName(const std::string &lastName) {
    if(lastName.empty()) {
        throw ClientException(ClientException::exceptionLastName);
    } else {
        this->lastName = lastName;
    }
}

const std::string &Client::getFirstName() const {
    return firstName;
}

const std::string &Client::getLastName() const {
    return lastName;
}

const std::string &Client::getId() const {
    return personalID;
}

int Client::getMaxVehicles() const{
    return clientType->getMaxVehicles();
}

double Client::applyDiscount(int base){
    return clientType->applyDiscount(base);
}

bool Client::isArchive() const {
    return archive;
}

void Client::setArchive(bool archive) {
    Client::archive = archive;
}

void Client::setClientType(const ClientTypePtr &clientType) {
    Client::clientType = clientType;
}

void Client::setFirstName(const std::string &firstName) {
    if(firstName.empty()) {
        throw ClientException(ClientException::exceptionFirstName);
    } else {
        this->firstName = firstName;
    }
}

void Client::setAddress(const AddressPtr &address) {
    if(address == nullptr) {
        throw ClientException(ClientException::exceptionAddress);
    } else {
        this->address = address;
    }
}

const AddressPtr &Client::getAddress() const {
    return address;
}

Client::Client(const std::string &firstName, const std::string &lastName, const std::string &personalId,
               const AddressPtr &address, const ClientTypePtr &clientType) : firstName(firstName),
               lastName(lastName), personalID(personalId), address(address), clientType(clientType) {

    if (firstName.empty()) throw ClientException(ClientException::exceptionFirstName);
    if (lastName.empty()) throw ClientException(ClientException::exceptionLastName);
    if (personalID.empty()) throw ClientException(ClientException::exceptionPersonalID);
    if (address == nullptr or address->getStreet().empty() or address->getCity().empty()) throw ClientException(ClientException::exceptionAddress);
    if (clientType == nullptr) throw ClientException(ClientException::exceptionClientType);

}




