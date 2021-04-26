#ifndef CARRENTAL_CLIENT_H
#define CARRENTAL_CLIENT_H

#include <string>
#include <iostream>
#include "model/Address.h"
#include "model/Rent.h"
#include <vector>

class Rent;

class Client {

private:
    std::string firstName;
    std::string lastName;
    std::string personalID;
    Address *ClientAddress;
    std::vector<Rent*> currentRents;

public:
    Client();
    Client(const std::string &firstName, const std::string &lastName, const std::string &personalID, Address *ClientAddress);
    ~Client();
    std::string getClientInfo();
    std::string getFullClientInfo();
    void setFirstName(const std::string & ) ;
    void setLastName(const std::string & ) ;
    void setAddress(Address*);
    const std::string &getFirstName() const;
    const std::string &getLastName() const;
    const std::string &getPersonalID() const;
    const Address* getAddress() const;
    const Rent* getRents(unsigned int) const;
    void newRent(Rent*);
    void delRent(Rent*);

};

#endif //CARRENTAL_CLIENT_H