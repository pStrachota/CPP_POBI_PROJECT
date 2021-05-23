#ifndef CARRENTAL_SILVER_H
#define CARRENTAL_SILVER_H


#include "model/ClientType.h"

/**
 * @brief klasa reprezentujaca typ klienta, dziedziczace z ClientType
 */

class Silver : public ClientType
{
public:
    /**
     * @brief apply Discount oblicza znizke w zaleznosci od typu klienta
     * @return obliczona wartosc znizki
     */
    double applyDiscount(int ) override;
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

#endif //CARRENTAL_SILVER_H
