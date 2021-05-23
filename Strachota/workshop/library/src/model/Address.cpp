#include "model/Address.h"

Address::Address(const std::string &miasto, const std::string &ulica, const std::string &numer) : city(miasto), street(ulica), number(numer) {}

std::string Address::getInfo() const{
    std::string result = city + " " + street + " " + number;
    return result;
}

const std::string &Address::getCity() const{
    return city;
}

const std::string &Address::getStreet() const{
    return street;
}

const std::string &Address::getNumber() const{
    return number;
}

/*
void Address::setCity(std::string newCity) {
    city = newCity;
}

void Address::setStreet(std::string newStreet) {
    street = newStreet;
}

void Address::setNumber(std::string newNumber) {
    number = newNumber;
}
 */