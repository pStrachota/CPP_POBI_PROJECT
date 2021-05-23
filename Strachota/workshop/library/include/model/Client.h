#ifndef CARRENTAL_CLIENT_H
#define CARRENTAL_CLIENT_H
#include <string>
#include <iostream>
#include <vector>
#include "typedefs.h"

/**
 * @brief Client jest to klasa reprezentujaca klienta wypozyczalni
 */

class Rent;
class Address;
class ClientType;

class Client {

private:
    std::string firstName;
    std::string lastName;
    std::string personalID;
    AddressPtr address;
    ClientTypePtr clientType;
    bool archive = false;

public:
    void setArchive(bool archive);
    bool isArchive() const;
    /**
     * @brief getInfo konkatenuje i zwraca informacje o kliencie
     * @return wartosc typu string
     */
    std::string getInfo() const;
    /**
     * dla wskaznika na adres oraz typ klienta, uzytko obslugi wyjatkow, gdy podany adres bedzie nullptr
     * @param firstName imie
     * @param lastName nazwisko
     * @param personalId pesel
     * @param address wskaznik na adres
     * @param clientType wskaznik na typ klienta
     */
    Client(const std::string &firstName, const std::string &lastName, const std::string &personalId,const AddressPtr &address, const ClientTypePtr &clientType);
    /**
     * @brief getMaxVehicles zwaca maksymalna liczbe wypozyczen danego typu klienta
     * @return int
     */
    int getMaxVehicles() const;
    /**
     * @brief setClientType zmienia typ klienta, np. gdy koszt jego wypozyczen przekroczy okreslona suma
     * @param clientType
     */
    void setClientType(const ClientTypePtr &clientType);
    /**
     * @brief apply Discount oblicza znizke w zaleznosci od typu klienta
     * @return obliczona wartosc znizki
     */
    double applyDiscount(int);
    /**
     * @brief setter dla nazwisko
     * @param lastName
     */
    void setLastName(const std::string &lastName);
    /**
     * @brief setter dla imienia
     * @param firstName
     */
    void setFirstName(const std::string &firstName);
    /**
     * @brief setter dla wskaznika na adres - tu takze dziala obsluga wyjatkow
     * @param Address
     */
    void setAddress(const AddressPtr &address);
    /**
     * @brief getter dla imienia
     * @param firstName
     */
    const std::string &getFirstName() const;
    /**
     * @brief getter dla nazwiska
     * @return lastName
     */
    const std::string &getLastName() const;
    /**
     * @brief getter dla peselu - ta funkcja dziedziczy z szablonu z repository.h
     * @return personelId
     */
    const std::string &getId() const;
    /**
     * @brief getter dla Adresu
     * @return Address
     */
    const AddressPtr &getAddress() const;

};

#endif //CARRENTAL_CLIENT_H
