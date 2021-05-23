#ifndef CARRENTAL_BRONZE_H
#define CARRENTAL_BRONZE_H

#include "model/ClientType.h"
#include <iostream>

/**
 * @brief klasa reprezentujaca typ klienta, dziedziczace z ClientType
 */

class Bronze : public ClientType
{
public:
    /**
     * @brief apply Discount oblicza znizke w zaleznosci od typu klienta
     * @return obliczona wartosc znizki
     */
    double applyDiscount(int) override;
    /**
   * @brief getMaxVehicles zwaca maksymalna liczbe wypozyczen danego typu klienta
   * @return int
   */
    int getMaxVehicles() const override;
    /**
     * @brief zwraca informacje o typie pojazdu
     * @return string
     */
    std::string getTypeInfo() const override;
};


#endif //CARRENTAL_BRONZE_H
