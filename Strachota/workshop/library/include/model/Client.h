#ifndef CARRENTAL_CLIENT_H
#define CARRENTAL_CLIENT_H
#include "model/Address.h"
#include "model/Rent.h"
#include <string>
#include <iostream>
#include <vector>

class Rent;

class Client {

private:
    std::string firstName;
    std::string lastName;
    std::string personalID;
    Address *CAddress;
    std::vector<Rent *> currentRents;
public:
    Client();
    Client(const std::string &imie, const std::string &nazwisko, const std::string &id, Address *caddress);
    ~Client();
    std::string getClientInfo();
    void setFirstName(const std::string &);
    void setLastName(const std::string &);
    void setAddress(Address *newAddress);
    const std::string &getFirstName() const;
    const std::string &getLastName() const;
    const std::string &getPersonalId() const;
    const Address *getAddress() const;
    const Rent *getRent(int number) const;
    std::string getFullClientInfo();
    void eraseRent(Rent *r);
    void addRent(Rent *r);
    std::string allRents();

};

#endif //CARRENTAL_CLIENT_H
