#ifndef CARRENTAL_CLIENTTYPE_H
#define CARRENTAL_CLIENTTYPE_H

#include <string>

/**
 * @brief klasa ClientType oznacz typ klienta
 */

class ClientType{
public:
    /**
     * @brief getter maxymalna możliwa liczba pojazdow do wypozyczenia
     */
    virtual int getMaxVehicles();
    /**
     * @brief oblicza upust cenowy dla danego klienta
     * @param cena wypożyczenia
     */
    virtual double applyDiscount(int price);
    /**
     * @brief getTypeInfo agreguje informacje o typie klienta
     * @return string z informacją
     */
    virtual std::string getTypeInfo() = 0;
    //virtual ~ClientType() = 0;
};



#endif //CARRENTAL_CLIENTTYPE_H
