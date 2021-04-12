#ifndef CARRENTAL_ADDRESS_H
#define CARRENTAL_ADDRESS_H
#include <string>
#include <iostream>

class Address {
private:
    std::string city;
    std::string street;
    std::string number;
public:
    Address(const std::string &miasto, const std::string &ulica, const std::string &numer);
    std::string getAddressInfo();
    //void setCity(std::string newCity);
    //void setStreet(std::string newStreet);
    //void setNumber(std::string newNumber);
    const std::string &getCity() const;
    const std::string &getStreet() const;
    const std::string &getNumber() const;
};






#endif //CARRENTAL_ADDRESS_H
