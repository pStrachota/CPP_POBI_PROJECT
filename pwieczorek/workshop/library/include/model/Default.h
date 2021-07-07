
#ifndef CARRENTAL_DEFAULT_H
#define CARRENTAL_DEFAULT_H

#include "model/ClientType.h"

/**
 * @brief klasa Default oznacza standardowy typ klienta, dzidziczy z ClientType
 */

class Default : public ClientType{
public:
    /**
     * @brief getter maxymalna możliwa liczba pojazdow do wypozyczenia
     */
    int getMaxVehicles() override;
    /**
    * @brief oblicza upust cenowy dla danego klienta
    * @param cena wypożyczenia
    */
    double applyDiscount(int price) override;
    /**
     * @brief getTypeInfo agreguje informacje o typie klienta
     * @return string z informacją
     */
    std::string getTypeInfo() override;
};


#endif //CARRENTAL_DEFAULT_H
