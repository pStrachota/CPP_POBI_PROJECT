//
// Created by student on 25.05.2021.
//

#ifndef STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_CLIENT_H
#define STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_CLIENT_H

#include <string>
#include <iostream>
#include <vector>
#include "typedefs.h"


class Rent;
class Address;
class ClientType;

class Client {

private:
    std::string name;
    std::string surname;
    std::string personalID;
    AddressPtr address;
    ClientTypePtr clientType;
    bool archive = false;

public:
    Client(const std::string &name, const std::string &surname, const std::string &personalId,
           const AddressPtr &address, const ClientTypePtr &clientType);
    const std::string &getName() const;
    void setClientType(const ClientTypePtr &clientType);
    std::string getInfo() const;
    void setArchive(bool archive);
    void setName(const std::string &name);
    void setSurname(const std::string &surname);
    void setPersonalId(const std::string &personalId);
    void setAddress(const AddressPtr &address);
    const std::string &getSurname() const;
    bool isArchive() const;
    const std::string &getId() const;
    const AddressPtr &getAddress() const;
    int getMaxDays() const;
    int getMaxItems() const;
    double getPenalty() const;

};

#endif //STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_CLIENT_H
