#ifndef CARRENTAL_CLIENT_H
#define CARRENTAL_CLIENT_H

#include <string>
#include <iostream>
#include "model/Address.h"
#include "model/Rent.h"
#include <vector>
#include "typedefs.h"

class Rent;

class Client {

private:
    std::string firstName;
    std::string lastName;
    std::string personalID;
    AddressPtr ClientAddress;
    ClientTypePtr clientType;
    //std::vector<RentPtr> currentRents;

public:
    Client(const std::string &firstName, const std::string &lastName, const std::string &personalID, AddressPtr ClientAddress, ClientTypePtr clientType);
    //~Client();
    std::string getClientInfo();
    //std::string getFullClientInfo();
    void setFirstName(const std::string & ) ;
    void setLastName(const std::string & ) ;
    void setAddress(AddressPtr);
    const std::string &getFirstName() const;
    const std::string &getLastName() const;
    const std::string &getPersonalID() const;
    const AddressPtr getAddress() const;
    int getMaxVehicles();
    double applyDiscount( double );
    void setClientType(ClientTypePtr clientType1);
    //const RentPtr getRents(unsigned int) const;
    //void newRent(RentPtr);
    //void delRent(RentPtr);

};

#endif //CARRENTAL_CLIENT_H