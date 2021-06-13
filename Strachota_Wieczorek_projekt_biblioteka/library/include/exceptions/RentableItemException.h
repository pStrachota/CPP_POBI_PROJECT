#ifndef STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_RENTABLEITEMEXCEPTION_H
#define STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_RENTABLEITEMEXCEPTION_H


#include <stdexcept>

/**
 * @brief klasa wyjatkow dla klasy RentableItem
 */


class RentableItemException : public std::logic_error
{
public:
    explicit RentableItemException(const std::string&);
    virtual std::string message() const;

};

/**
 * @brief z głownej klasy wyjatkow dziedzicza poszczegolne typy wyjatkow
 */

/**
 * exceptionSerialNumber - "puste numer seryjny"
 */

class exceptionSerialNumber : public RentableItemException {
public:
    explicit exceptionSerialNumber(const std::string &message);
};

/**
 * exceptionAuthor - "pusty autor"
 */

class exceptionAuthor : public RentableItemException {
public:
    explicit exceptionAuthor(const std::string &message);

};

/**
 * exceptionTitle - "pusty tytul"
 */

class exceptionTitle : public RentableItemException {
public:
    explicit exceptionTitle(const std::string &message);

};


/**
 * exceptionAuthor - " nullptr zamiast poprawnego wskaznika"
 */

#endif //STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_RENTABLEITEMEXCEPTION_H