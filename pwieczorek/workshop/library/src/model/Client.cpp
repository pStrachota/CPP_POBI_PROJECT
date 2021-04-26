#include "model/Client.h"
#include <string>
#include <algorithm>

Client::Client()
{
    firstName = "initial_first_name";
    lastName = "initial_last_name";
    personalID = "initial_personal_ID";
}

Client::Client(const std::string &firstName, const std::string &lastName, const std::string &personalID, Address *ClientAddress) : firstName(firstName), lastName(lastName), personalID(personalID), ClientAddress(ClientAddress){}

Client::~Client()
{
    //delete ClientAddress;
}

std::string Client::getClientInfo()
{
    std::string output;
    std::string address = ClientAddress->getAddressInfo();

    output = firstName + " " + lastName + " " + personalID + " " + address;
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

const Address* Client::getAddress() const
{
    return ClientAddress;
}

void Client::setAddress(Address* someAddress)
{
    if ( someAddress == nullptr){
        std::cout << " Incorrect address. ";
    }
    else
    {
        ClientAddress = someAddress;
    }
}

const Rent * Client::getRents(unsigned int n) const {
    return currentRents[n];
}

void Client::newRent(Rent * new_rent) {
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

void Client::delRent(Rent *givenRent) {
    std::remove(currentRents.begin(), currentRents.end(), givenRent);
}