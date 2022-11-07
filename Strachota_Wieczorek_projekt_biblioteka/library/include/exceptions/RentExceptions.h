#ifndef STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_RENTEXCEPTION_H
#define STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_RENTEXCEPTION_H

#include <stdexcept>

/**
 * @brief klasa wyjatkow dla klasy Rent
 */


class RentException : public std::logic_error
{
public:
    explicit RentException(const std::string&);
    virtual std::string message() const;
};

/**
 * @brief z głownej klasy wyjatkow dziedzicza poszczegolne typy wyjatkow
 */

class exceptionBeginTime : public RentException {
public:
    explicit exceptionBeginTime(const std::string &message);
};

class exceptionClient : public RentException {
public:
    explicit exceptionClient(const std::string &message);

};

class exceptionRentableItem : public RentException {
public:
    explicit exceptionRentableItem(const std::string &message);

};

class exceptionUnableToOpenFile : public RentException {
public:
    explicit exceptionUnableToOpenFile(const std::string &message);
};

#endif //STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_RENTEXCEPTION_H
