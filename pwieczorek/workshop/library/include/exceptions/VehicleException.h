//
// Created by student on 03.07.2021.
//

#ifndef CARRENTAL_VEHICLEEXCEPTION_H
#define CARRENTAL_VEHICLEEXCEPTION_H
#include <stdexcept>

/**
 * @brief klasa wyjatkow dla klasy Vehicle
 */

class VehicleException : public std::logic_error{
public:
    explicit VehicleException(const std::string&);
    virtual std::string message() const;
};

/**
     * exceptionBasePrice - "pusta" tablica rejestracyjna
     */
class exceptionPlateNumber : public VehicleException {
public:
    explicit exceptionPlateNumber(const std::string &message);
};

/**
     * exceptionBasePrice - ujemna cena bazowa
     */

class exceptionBasePrice : public VehicleException {
public:
    explicit exceptionBasePrice(const std::string &message);

};


#endif //CARRENTAL_VEHICLEEXCEPTION_H
