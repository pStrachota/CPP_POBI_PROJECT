#ifndef CARRENTAL_VEHICLEEXCEPTION_H
#define CARRENTAL_VEHICLEEXCEPTION_H

#include <stdexcept>

/**
 * @brief klasa wyjatkow dla klasy Vehicle
 */
class VehicleException : public std::logic_error
{
public:
    explicit VehicleException(const std::string&);
    /**
     * exceptionPrice - ujemna cena
     */
    static const std::string exceptionPrice;
    /**
     * exceptionRegistration - "pusta" tablica rejestracyjna
     */
    static const std::string exceptionRegistration;
};





#endif //CARRENTAL_VEHICLEEXCEPTION_H
