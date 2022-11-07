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

class exceptionSerialNumber : public RentableItemException {
public:
    explicit exceptionSerialNumber(const std::string &message);
};

class exceptionAuthor : public RentableItemException {
public:
    explicit exceptionAuthor(const std::string &message);

};

class exceptionTitle : public RentableItemException {
public:
    explicit exceptionTitle(const std::string &message);

};

#endif //STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_RENTABLEITEMEXCEPTION_H
