

#ifndef CARRENTAL_PLATINUM_H
#define CARRENTAL_PLATINUM_H
#include "model/ClientType.h"

/**
 * @brief klasa Platinum oznacza platynowy typ klienta, dzidziczy z ClientType
 */

class Platinum : public ClientType{
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


#endif //CARRENTAL_PLATINUM_H
