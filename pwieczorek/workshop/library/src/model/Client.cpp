//
// Created by student on 18.04.2021.
//

#include "model/Client.h"
#include <string>


//using namespace std;

Client::Client()
{
    firstName = "initial_first_name";
    lastName = "initial_last_name";
    personalID = "initial_personal_ID";
}

Client::Client(const std::string &firstName, const std::string &lastName, const std::string &personalID) : firstName(firstName), lastName(lastName), personalID(personalID){}

Client::~Client()
{

}

std::string Client::getClientInfo()
{
    std::string output;
    output = firstName + " " + lastName + " " + personalID ;
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



