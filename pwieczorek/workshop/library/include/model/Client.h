#ifndef CARRENTAL_CLIENT_H
#define CARRENTAL_CLIENT_H

#include <string>
#include <iostream>
#include "model/Address.h"
#include "model/Rent.h"
#include <vector>
#include "typedefs.h"

/**
 * @brief klasa Client reprezentuje klienta
 */

class Rent;

class Client {
private:
    std::string firstName;
    std::string lastName;
    std::string personalID;
    AddressPtr ClientAddress;
    ClientTypePtr clientType;
    bool archive = false;
public:
    Client(const std::string &firstName, const std::string &lastName, const std::string &personalID, AddressPtr ClientAddress, ClientTypePtr clientType);
    /**
     * @brief getClientInfo agreguje informacje o pojezdzie
     * @return string z informacja
     */
    std::string getClientInfo();
    /**
     * @brief getInfo deleguje odpowiedzialność na getClientInfo
     * @return string z informacja
     */
    std::string getInfo() const;
    /**
    * @brief getter ID
    * @return string ID
    */
    std::string getId() const;
    //std::string getFullClientInfo();
    /**
     * @brief setter imie klienta
     * @param string imie
     */
    void setFirstName(const std::string & ) ;
    /**
     * @brief setter nazwisko klienta
     * @param string nazwisko
     */
    void setLastName(const std::string & ) ;
    /**
     * @brief setter czy klient jest zarchiwizowany
     * @param bool archive
     */
    void setIsArchive(bool archive);
    /**
    * @brief getter statusu archiwizacji
    * @return bool czy zarchowizowany
    */
    bool isArchive();
    /**
     * @brief setter adresu
     * @param wskaznika na adres
     */
    void setAddress(AddressPtr);
    /**
    * @brief getter imienia
    * @return string imie
    */
    const std::string &getFirstName() const;
    /**
    * @brief getter nazwisko
    * @return string nazwisko
    */
    const std::string &getLastName() const;
    /**
    * @brief getter nr pesel
    * @return string nr pesel
    */
    const std::string &getPersonalID() const;
    /**
    * @brief getter adresu
    * @return wskaznik na adres
    */
    const AddressPtr getAddress() const;
    /**
    * @brief getter typu klienta
    * @return wskaznik na typ klienta
    */
    const ClientTypePtr getClientType() const;
    /**
    * @brief getter maxymalnej liczby wypozyczen
    * @return int max liczba wypozyczen
    */
    int getMaxVehicles();
    /**
     * @brief aplikowanie upustu dla klienta
     * @param double suma
     */
    double applyDiscount(double);
    /**
     * @brief setter typ klienta
     * @param wskaznika na typ klienta
     */
    void setClientType(ClientTypePtr clientType1);

};

#endif //CARRENTAL_CLIENT_H