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
    /**
     * exceptionFirstName - "puste" imie
     */
    static const std::string exceptionFirstName;
    /**
     * exceptionLastName - "puste" nazwisko
     */
    static const std::string exceptionLastName;
    /**
     * exceptionPersonalId - "pusty" pesel
     */
    static const std::string exceptionPersonalID;
    /**
     * exceptionAddress - nullptr zamiast wskaznika na adres
     */
    static const std::string exceptionAddress;
    /**
    * exceptionClientType - nullptr zamiast wskaznika na typ klienta
    */
    static const std::string exceptionClientType;
};



#endif //STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_CLIENTEXCEPTION_H
