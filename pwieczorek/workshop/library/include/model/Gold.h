

#ifndef CARRENTAL_GOLD_H
#define CARRENTAL_GOLD_H
#include "model/ClientType.h"

/**
 * @brief klasa Gold oznacza złoty typ klienta, dzidziczy z ClientType
 */

class Gold : public ClientType{
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


#endif //CARRENTAL_GOLD_H
