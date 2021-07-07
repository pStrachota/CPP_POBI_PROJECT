#ifndef CARRENTAL_ADDRESS_H
#define CARRENTAL_ADDRESS_H

#include <string>

/**
 * @brief klasa Address; adres jest przypisany klientowi
 */

class Address {
private:
    std::string city;
    std::string street;
    std::string number;
public:
    Address();
    Address(const std::string &city, const std::string &street, const std::string &number);
    ~Address();
    /**
     * @brief getAddressInfo agreguje informacje o adresie
     * @return string z informacją adresową
     */
    std::string getAddressInfo();
    /**
    * @brief getter miasta z adresu
    * @return string miasto
    */
    const std::string &getCity() const;
    /**
    * @brief getter ulicy z adresu
    * @return string ulica
    */
    const std::string &getStreet() const;
    /**
    * @brief getter numer domu z adresu
    * @return string numer domu
    */
    const std::string &getNumber() const;

};


#endif //CARRENTAL_ADDRESS_H
