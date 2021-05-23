#ifndef CARRENTAL_RENT_H
#define CARRENTAL_RENT_H
#include <string>
#include <iostream>
#include<iostream>
#include <boost/date_time.hpp>
#include "typedefs.h"
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

/**
 * @brief klasa Rent reprezentuje obiekt wypozyczenia
 *
 */

class Client;
class Vehicle;
class ClientType;

class Rent {

private:
    ClientPtr client;
    VehiclePtr vehicle;
    pt::ptime beginTime;
    pt::ptime endTime = pt::not_a_date_time;
    unsigned int rentCost = 0;
    boost::uuids::uuid id;

public:
    /**
     * dla klienta oraz pojazdu zaimplementowano obsluge wyjatkow
     * @param client - wskaznik na klienta
     * @param vehicle - wskaznik na pojazd
     * @param beginTime - czas rozpoczecia wypozyczenia
     */
    Rent(const ClientPtr &client, const VehiclePtr &vehicle, const pt::ptime &beginTime);
    /**
     * @brief getClient zwraca klienta wypozyczenia
     */
    const ClientPtr &getClient() const;
    /**
     * getter dla wartosc id - odrebnej dla kazdego wypozyczenia
     * @return wartosc id
     */
    const boost::uuids::uuid &getId() const;
    /**
    * getter dla poczatku wypozyczenia - uzywany do ustalenia ceny
    * @return czas koncowy
    */
    const pt::ptime &getBeginTime() const;
    /**
     * getter dla konca wypozyczenia - uzywany do ustalenia ceny
     * @return czas koncowy
     */
    const pt::ptime &getEndTime() const;
    /**
     * @brief getRentDays oblicza ile dni trwalo wypozyczenie
     * ta informacja jest potrzebna do obliczenia kosztu wypozyczenia
     */
    unsigned int getRentDays();
    /**
     * @brief getRentDays oblicza ile kosztowalo wypozyczenie na podstawie czasu trwania i ceny bazowej, oraz odpowiedniej znizki
     */
    unsigned int getRentCost() const;
    /**
     * @brief getVehicle zwraca pojazd wypozyczenia
     */
    const VehiclePtr &getVehicle() const;
    /**
     * @brief endRent konczy wypozycznie i oblicza cene wypozyczenia (przed obliczeniem znizki)
     * @param exampleTime - czas zakonczenia wypozycznenia
     */
    void endRent(pt::ptime exampleTime);
    /**
     * @brief zwraca informacje o wypozyczeniu
     * @return string
     */
    std::string getInfo() const;
};







#endif //CARRENTAL_RENT_H
