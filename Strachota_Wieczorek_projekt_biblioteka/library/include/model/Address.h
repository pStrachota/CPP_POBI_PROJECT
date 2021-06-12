//
// Created by student on 27.05.2021.
//

#ifndef STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_ADDRESS_H
#define STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_ADDRESS_H
#include <iostream>

class Address {
private:
    std::string city;
    std::string street;
    std::string number;
public:
    Address(const std::string &city, const std::string &street, const std::string &number);
    const std::string &getCity() const;
    const std::string &getStreet() const;
    std::string getInfo() const;
    const std::string &getNumber() const;
};


#endif //STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_ADDRESS_H
