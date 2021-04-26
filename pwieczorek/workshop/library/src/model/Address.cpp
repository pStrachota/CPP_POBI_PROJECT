#include "model/Address.h"

Address::Address() {
    city = "cityName";
    street = "streetName";
    number = "homeNumber";
}

Address::~Address() {}

Address::Address(const std::string &city, const std::string &street, const std::string &number) : city(city), street(street), number(number){}

std::string Address::getAddressInfo() {
    std::string output = "The Address: " + city + " " + street + " " + number;
    return output;
}

//getters
const std::string & Address::getCity() const { return city; };
const std::string & Address::getStreet() const { return street; };
const std::string & Address::getNumber() const { return number; };



