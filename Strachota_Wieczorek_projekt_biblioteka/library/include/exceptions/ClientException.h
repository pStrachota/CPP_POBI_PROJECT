//
// Created by student on 27.05.2021.
//

#ifndef STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_CLIENTEXCEPTION_H
#define STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_CLIENTEXCEPTION_H



#include <stdexcept>

/**
 * @brief klasa wyjatkow dla klasy Client
 */

class ClientException : public std::logic_error
{
public:
    explicit ClientException(const std::string&);
    virtual std::string message() const;

};

/**
 * @brief z głownej klasy wyjatkow dziedzicza poszczegolne typy wyjatkow
 */

/**
 * expeptionFirstName - "puste imie"
 */

class exceptionFirstName : public ClientException {
public:
    explicit exceptionFirstName(const std::string &message);
};

/**
     * exceptionLastName - "puste" nazwisko
     */

class exceptionLastName : public ClientException {
public:
    explicit exceptionLastName(const std::string &message);

};
/**
     * exceptionPersonalId - "pusty" pesel
     */
class exceptionPersonalID : public ClientException {
public:
    explicit exceptionPersonalID(const std::string &message);

};
/**
    * exceptionAddress - nullptr zamiast wskaznika na adres
    */
class exceptionAddress : public ClientException {
public:
    explicit exceptionAddress(const std::string &message);

};
/**
   * exceptionClientType - nullptr zamiast wskaznika na typ klienta
   */
class exceptionClientType : public ClientException {
public:
    explicit exceptionClientType(const std::string &message);

};
/**
   * exceptionCannotOpenFile - nie udalo sie otworzyc pliku do zapisu
   */
class exceptionCannotOpenFile : public ClientException {
public:
    explicit exceptionCannotOpenFile(const std::string &message);
};


#endif //STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_CLIENTEXCEPTION_H
