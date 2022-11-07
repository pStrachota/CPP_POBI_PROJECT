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

class exceptionFirstName : public ClientException {
public:
    explicit exceptionFirstName(const std::string &message);
};

class exceptionLastName : public ClientException {
public:
    explicit exceptionLastName(const std::string &message);

};

class exceptionPersonalID : public ClientException {
public:
    explicit exceptionPersonalID(const std::string &message);

};

class exceptionAddress : public ClientException {
public:
    explicit exceptionAddress(const std::string &message);

};

class exceptionClientType : public ClientException {
public:
    explicit exceptionClientType(const std::string &message);

};

class exceptionCannotOpenFile : public ClientException {
public:
    explicit exceptionCannotOpenFile(const std::string &message);
};


#endif //STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_CLIENTEXCEPTION_H
