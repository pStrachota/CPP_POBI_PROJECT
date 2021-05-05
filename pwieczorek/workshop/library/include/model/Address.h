#ifndef CARRENTAL_ADDRESS_H
#define CARRENTAL_ADDRESS_H

#include <string>

class Address {
private:
    std::string city;
    std::string street;
    std::string number;
public:
    Address();
    Address(const std::string &city, const std::string &street, const std::string &number);
    ~Address();

    std::string getAddressInfo();
    //void setCity(const std::string & ) ;
    //void setStreet(const std::string & ) ;
    //void setNumber(const std::string & ) ;
    const std::string &getCity() const;
    const std::string &getStreet() const;
    const std::string &getNumber() const;

};


#endif //CARRENTAL_ADDRESS_H
