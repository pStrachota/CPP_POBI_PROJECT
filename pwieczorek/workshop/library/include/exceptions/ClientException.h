//
// Created by student on 03.07.2021.
//

#ifndef CARRENTAL_CLIENTEXCEPTION_H
#define CARRENTAL_CLIENTEXCEPTION_H

#include <stdexcept>

/**
 * @brief klasa wyjatkow dla klasy Client
 */

class ClientException : public std::logic_error{
public:
    explicit ClientException(const std::string&);
    virtual std::string message() const;
};

/**
     * exceptionFirstName - "puste" imie
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


#endif //CARRENTAL_CLIENTEXCEPTION_H
