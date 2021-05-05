#ifndef CARRENTAL_CLIENT_H
#define CARRENTAL_CLIENT_H
#include "model/Address.h"
#include "model/Rent.h"
#include <string>
#include <iostream>
#include <vector>
#include "typedefs.h"
#include "model/ClientType.h"

class Rent;

class Client {

private:
    std::string firstName;
    std::string lastName;
    std::string personalID;
    AddressPtr CAddress;
    ClientTypePtr clientType;
    bool archive = false;
public:
    void setArchive(bool archive);

//public:
    bool isArchive() const;
    //std::vector<RentPtr> currentRents;
//public:
    //Client();
    Client(const std::string &imie, const std::string &nazwisko,  std::string id, AddressPtr caddress, ClientTypePtr cT);
    //~Client();
    std::string getClientInfo();
    void setClientType(ClientTypePtr);
    int getMaxVehicles();
    double applyDiscount(int);
    void setFirstName(const std::string &);
    void setLastName(const std::string &);
    void setAddress(AddressPtr newAddress);
    const std::string &getFirstName() const;
    const std::string &getLastName() const;
    const std::string &getPersonalId() const;
    const AddressPtr getAddress() const;
    //const RentPtr getRent(int number) const;
    //std::string getFullClientInfo();
    //void eraseRent(RentPtr r);
    //void addRent(RentPtr r);

};

#endif //CARRENTAL_CLIENT_H
