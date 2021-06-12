//
// Created by student on 27.05.2021.
//

#ifndef STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_CLIENTEXCEPTION_H
#define STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_CLIENTEXCEPTION_H



#include <stdexcept>

/**
 * @brief klasa wyjatkow dla klasy Client
 */

/**
 * @attention NOTATKA JAK BEDZIEDZ TU PAWEL ZAGLADAL
 *
 * po mojej zmianie dziedziczenie wyjatkow stalo sie bardziej przejrzyste
 * wczesniej wszystkie typy byly w jednej klasie, teraz -
 * istnieja oddzielne klasy dla oddzeidzlnych typow wyjatkow
 * komunikat jaki wyskakuje podajemy sami -> sprawdz pliki .cpp
 * [chyba wlasnie tak bylo na wykladzie]
 * jakby ci cos nie pasowalo to pisz, bo moze gdzies mam blad albo powinno byc inaczej
 * bardziej oficjalne komentarze dodam pozniej
 *
 * !!!!!!
 * pamietaj aby zmienic tez w testach i w plikach .cpp obsluge bledow -> zobacz jak ja mam - chyba tak jest dobrze
 *
 * i skoro juz tu jestes, to napisze zebys nie przejsmowal sie interfejsem/obserwatorem -> pozniej go naprawimy
 */

class ClientException : public std::logic_error
{
public:
    explicit ClientException(const std::string&);
    virtual std::string message() const;

};

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
