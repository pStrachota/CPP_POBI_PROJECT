#ifndef CARRENTAL_CLIENTTYPE_H
#define CARRENTAL_CLIENTTYPE_H

#include <string>
#include <iostream>

/**
 * @brief ClientType to klasa reprezentujaca dany typ klienta
 * w zaleznosci od typu klienta, przysluguja inne znizki
 * i maksymalna liczba wypozyczen
 */


class ClientType
{
public:
    /**
     * @brief apply Discount oblicza znizke w zaleznosci od typu klienta
     * @return obliczona wartosc znizki
     */
    virtual double applyDiscount(int);
    /**
  * @brief getMaxVehicles zwaca maksymalna liczbe wypozyczen danego typu klienta
  * @return int
  */
    virtual int getMaxVehicles() const;
    /**
    * @brief zwraca informacje o typie pojazdu
    * @return string
    */
    virtual std::string getTypeInfo() const;
};



#endif //CARRENTAL_CLIENTTYPE_H
