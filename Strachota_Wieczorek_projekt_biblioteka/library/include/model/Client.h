//
// Created by student on 25.05.2021.
//

#ifndef STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_CLIENT_H
#define STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_CLIENT_H

#include <string>
#include <iostream>
#include <vector>
#include "typedefs.h"
#include <memory>


class Rent;
class Address;
class ClientType;

/**
 * @brief Client jest to klasa reprezentujaca klienta biblioteki
 */


class Client : public std::enable_shared_from_this<Client> {

private:
    std::string name;
    std::string surname;
    std::string personalID;
    AddressPtr address;
public:
    virtual ~Client();

private:
    ClientTypePtr clientType;
    bool archive = false;

public:
    /**
     * dla wskaznika na adres oraz typ klienta, uzytko obslugi wyjatkow, gdy podany adres bedzie nullptr
     * @param name imie
     * @param surname nazwisko
     * @param personalId pesel
     * @param address wskaznik na adres
     * @param clientType wskaznik na typ klienta
     */
    Client(const std::string &name, const std::string &surname, const std::string &personalId,
           const AddressPtr &address, const ClientTypePtr &clientType);
    const std::string &getName() const;
    void setClientType(const ClientTypePtr &clientType);
    /**
    * @brief getInfo konkatenuje i zwraca informacje o kliencie
    * @return wartosc typu string
    */
    std::string getInfo() const;
    /**
   * @brief setter dla "bycia w archiwum"
   * @param archive
   */
    void setArchive(bool archive);
    /**
   * @brief setter dla imienia
   * @param name
   */
    void setName(const std::string &name);
    /**
   * @brief setter dla nazwiska
   * @param surname
   */
    void setSurname(const std::string &surname);
    /**
   * @brief setter dla peselu
   * @param personalId
   */
    void setPersonalId(const std::string &personalId);
    /**
   * @brief setter dla wskaznika na adres
   * @param address
   */
    void setAddress(const AddressPtr &address);
    /**
  * @brief getter dla nazwiska
  * @param surname
  */
    const std::string &getSurname() const;
    /**
  * @brief setter dla umieszczenia w archiwum
  * @param archive
  */
    bool isArchive() const;
    /**
  * @brief getter dla personalId (peselu)
  * @param personalId
  */
    const std::string &getId() const;
    /**
  * @brief getter dla wskaznika na adres
  * @param address
  */
    const AddressPtr &getAddress() const;
    /**
   * @brief getMaxDays zwaca maksymalna liczbe dni wypozyczen ksiazki lub artyukulu
   * @return int
   */
    int getMaxDays() const;
    /**
   * @brief getMaxitems zwaca maksymalna liczbe wypozyczen danego typu klienta
   * @return int
   */
    int getMaxItems() const;
    /**
     * @brief getter dla kary za przekroczenie wypozyczenia
     * rozny dla roznych typow klienta
     * @return double
     */
    double getPenalty() const;

};

#endif //STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_CLIENT_H
