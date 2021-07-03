#include "model/Client.h"
#include "model/ClientType.h"
#include <string>
#include <algorithm>
#include "typedefs.h"
#include "exceptions/ClientException.h"

Client::Client(const std::string &firstName, const std::string &lastName, const std::string &personalID, AddressPtr ClientAddress, ClientTypePtr clientType) : firstName(firstName), lastName(lastName), personalID(personalID), ClientAddress(ClientAddress), clientType(clientType)
{
    if(firstName.empty()){
        throw exceptionFirstName(" ERROR FIRST NAME");
    }
    if(lastName.empty()){
        throw exceptionLastName(" ERROR LAST NAME ");
    }
    if ( ClientAddress == nullptr){
        throw exceptionAddress(" ERROR ADRESS ");
    }
    if ( clientType == nullptr){
        throw exceptionClientType(" ERROR CLIENT TYPE ");
    }

}

std::string Client::getClientInfo()
{
    std::string output;
    std::string address = ClientAddress->getAddressInfo();
    std::string cTypeInfo = clientType->getTypeInfo();

    output = firstName + " " + lastName + " " + personalID + " " + address + " " + cTypeInfo;
    return output;
}

void Client::setFirstName(const std::string &givenFirstName)
{
    if(givenFirstName.empty())
    {
        throw exceptionFirstName(" ERROR FIRST NAME");
    }
    else firstName = givenFirstName;
}

void Client::setLastName(const std::string &givenLastName)
{
    if(givenLastName.empty())
    {
        throw exceptionLastName(" ERROR LAST NAME ");
    }
    else
    {
        lastName = givenLastName;
    }

}
const std::string & Client::getFirstName() const
{
    return firstName;
}

const std::string & Client::getLastName() const
{
    return lastName;
}
const std::string & Client::getPersonalID() const
{
    return personalID;
}

const AddressPtr Client::getAddress() const
{
    return ClientAddress;
}

void Client::setAddress(AddressPtr someAddress)
{
    if ( someAddress == nullptr){
        throw exceptionAddress(" ERROR ADRESS ");
    }
    else
    {
        ClientAddress = someAddress;
    }
}

void Client::setClientType(ClientTypePtr clientType1) {
    if ( clientType1 == nullptr){
        throw exceptionClientType(" ERROR CLIENT TYPE ");
    }
    else
    {
        clientType = clientType1;
    }
}

int Client::getMaxVehicles() {
    return clientType->getMaxVehicles();
}

double Client::applyDiscount(double price) {
    return clientType->applyDiscount(price);
}

bool Client::isArchive() {
    return archive;
}

void Client::setIsArchive(bool archive) {
    this->archive = archive;
}
/*
const RentPtr Client::getRents(unsigned int n) const {
    return currentRents[n];
}

void Client::newRent(RentPtr new_rent) {
    //vector push_back
    currentRents.push_back(new_rent);
}

std::string Client::getFullClientInfo()
{
    std::string address = ClientAddress->getAddressInfo();
    std::string rentData ="";
    std::string output;
    for(const auto& value: currentRents) {
        rentData + " " + std::to_string(value->getID());
    }

    output = firstName + " " + lastName + " " + personalID + " " + address + " " + rentData;
    return output;
}

void Client::delRent(RentPtr givenRent) {
    std::remove(currentRents.begin(), currentRents.end(), givenRent);
}
 */