//
// Created by student on 25.05.2021.
//

#include <string>
#include <memory>
#include <model/Client.h>
#include "model/Address.h"
#include "model/ClientType.h"
#include "exceptions/ClientException.h"
#include "repositories/Templates.h"


Client::Client(const std::string &name, const std::string &surname, const std::string &personalId,
               const AddressPtr &address, const ClientTypePtr &clientType) : name(name), surname(surname),
                                                                             personalID(personalId), address(address),
                                                                             clientType(clientType) {

    if (name.empty()) throw ClientException(ClientException::exceptionFirstName);
    if (surname.empty()) throw ClientException(ClientException::exceptionLastName);
    if (personalID.empty()) throw ClientException(ClientException::exceptionPersonalID);
    if (address == nullptr or address->getStreet().empty() or address->getCity().empty()) throw ClientException(ClientException::exceptionAddress);
    if (clientType == nullptr) throw ClientException(ClientException::exceptionClientType);
}

const std::string &Client::getName() const {
    return name;
}

const std::string &Client::getSurname() const {
    return surname;
}

const std::string &Client::getId() const {
    return personalID;
}

const AddressPtr &Client::getAddress() const {
    return address;
}

bool Client::isArchive() const {
    return archive;
}

void Client::setClientType(const ClientTypePtr &clientType) {
    if(clientType == nullptr) {
        throw ClientException(ClientException::exceptionClientType);
    } else {
        this->clientType = clientType;
    }
}

void Client::setArchive(bool archive) {
    Client::archive = archive;
}

void Client::setName(const std::string &name) {
    if(name.empty()) {
        throw ClientException(ClientException::exceptionFirstName);
    } else {
        this->name = name;
    };
}

void Client::setSurname(const std::string &surname) {
    if(surname.empty()) {
        throw ClientException(ClientException::exceptionLastName);
    } else {
        this->surname = surname;
    }
}

void Client::setPersonalId(const std::string &personalId) {
    personalID = personalId;
}

void Client::setAddress(const AddressPtr &address) {
    if(address == nullptr) {
        throw ClientException(ClientException::exceptionAddress);
    } else {
        this->address = address;
    }
}

std::string Client::getInfo() const {
    std::string chain;
    chain = clientType->getTypeInfo() + " " + name + " " + surname + " " + personalID + " " + ::getInfo(address);// + add
    return chain;
}

int Client::getMaxDays() const {
    return clientType->getMaxDays();
}

int Client::getMaxItems() const {
    return clientType->getMaxItems();
}

double Client::getPenalty() const {
    return clientType->getPenalty();
}
