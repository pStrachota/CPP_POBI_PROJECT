//
// Created by student on 18.04.2021.
//

#ifndef CARRENTAL_CLIENT_H
#define CARRENTAL_CLIENT_H

#include <string>
#include <iostream>
#include <vector>

class Client {

private:
    std::string firstName;
    std::string lastName;
    std::string personalID;
public:
    Client();
    Client(const std::string &firstName, const std::string &lastName, const std::string &personalID);
    ~Client();
    std::string getClientInfo();
    void setFirstName(const std::string & ) ;
    void setLastName(const std::string & ) ;
    const std::string & getFirstName() const;
    const std::string & getLastName() const;
    const std::string & getPersonalID() const;

};

#endif //CARRENTAL_CLIENT_H