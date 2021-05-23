#ifndef CARRENTAL_RENTEXCEPTION_H
#define CARRENTAL_RENTEXCEPTION_H
#include <stdexcept>

/**
 * @brief klasa wyjatkow dla klasy Rent
 */


class RentException : public std::logic_error
{
public:
    explicit RentException(const std::string&);
    /**
   * xceptionClientNullPtr - nullptr zamiast wskaznika na klienta
   */
    static const std::string exceptionClientNullPtr;
    /**
  * exceptionVehicleNullPtr - nullptr zamiast wskaznika na pojazd
  */
    static const std::string exceptionVehicleNullPtr;
    /**
     * exceptionDays - ujemna liczba dni wypozyczen
     */
    static const std::string exceptionDays;
};








#endif //CARRENTAL_RENTEXCEPTION_H
