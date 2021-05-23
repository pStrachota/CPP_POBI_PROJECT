#ifndef CARRENTAL_ADDRESS_H
#define CARRENTAL_ADDRESS_H
#include <string>
#include <iostream>

/**
 * @brief klasa Address, polaczone relacja z klasa Client
 * polacznie zgodnie z zasada, iz wielu klientow moze miec
 * ten sam adress
 */

class Address {
private:
    std::string city;
    std::string street;
    std::string number;
public:
    Address(const std::string &miasto, const std::string &ulica, const std::string &numer);
    /**
     * @brief getInfo konkatenuje informacje o adresie
     * @return string zawierajacy informacje o adresie
     */
    std::string getInfo() const;
    /**
     * @brief getter dla miasta
     * @return nazwa miasta
     */
    const std::string &getCity() const;
    /**
    * @brief getter dla ulicy
    * @return nazwa ulicy
    */
    const std::string &getStreet() const;
    /**
    * @brief getter dla numeru domu
    * @return numer domu
    */
    const std::string &getNumber() const;
};






#endif //CARRENTAL_ADDRESS_H
