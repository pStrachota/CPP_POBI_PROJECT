#include "model/Client.h"
#include "model/ClientType.h"
#include <string>
#include <algorithm>
#include "typedefs.h"
/*
Client::Client()
{
    firstName = "initial_first_name";
    lastName = "initial_last_name";
    personalID = "initial_personal_ID";
}
 */

Client::Client(const std::string &firstName, const std::string &lastName, const std::string &personalID, AddressPtr ClientAddress, ClientTypePtr clientType) : firstName(firstName), lastName(lastName), personalID(personalID), ClientAddress(ClientAddress), clientType(clientType){}
/*
Client::~Client()
{
}
*/
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
    if(givenFirstName == "")
    {
        std::cout << "incorrect name" << std::endl;
    }
    else firstName = givenFirstName;
}

void Client::setLastName(const std::string &givenLastName)
{
    if(givenLastName == "")
    {
        std::cout << "incorrect surname" << std::endl;
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
        std::cout << " Incorrect address. ";
    }
    else
    {
        ClientAddress = someAddress;
    }
}

void Client::setClientType(ClientTypePtr clientType1) {
    if ( clientType1 == nullptr){
        std::cout << " Incorrect address. ";
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