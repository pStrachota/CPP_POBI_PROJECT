//
// Created by student on 03.07.2021.
//

#ifndef CARRENTAL_RENTEXCEPTION_H
#define CARRENTAL_RENTEXCEPTION_H
#include <stdexcept>


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

/**
 * exceptionBeginTime - " niepoprawna data"
 */

class exceptionBeginTime : public RentException {
public:
    explicit exceptionBeginTime(const std::string &message);
};

/**
 * exceptionClient - " nullptr zamiast poprawnego wskaznika"
 */

class exceptionClient : public RentException {
public:
    explicit exceptionClient(const std::string &message);

};

/**
 * exceptionVehicle - " nullptr zamiast poprawnego wskaznika na Vehicle"
 */

class exceptionVehicle : public RentException {
public:
    explicit exceptionVehicle(const std::string &message);

};

/**
 * exceptionID - " ujemne ID "
 */

class exceptionID : public RentException {
public:
    explicit exceptionID(const std::string &message);

};




#endif //CARRENTAL_RENTEXCEPTION_H
