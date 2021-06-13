//
// Created by student on 28.05.2021.
//

#ifndef STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_RENT_H
#define STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_RENT_H

#include <boost/date_time.hpp>
#include "typedefs.h"
#include <boost/uuid/uuid.hpp>            // uuid class
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/uuid/uuid_io.hpp>
#include <vector>

/**
 * @brief Rent jest to klasa reprezentujaca wypozyczenie z biblioteki
 * rent jest zzwiązany z jednym i tylko jednym obiektem wypozyczanym
 */

namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

class Client;
class RentableItem;

class Rent {
private:
    boost::uuids::uuid RentId;
    pt::ptime beginTime;
    pt::ptime endTime;
    float rentCost;
    ClientPtr client;
    RentableItemPtr rentableItem;
public:
    Rent(pt::ptime beginTime, const ClientPtr& client, const RentableItemPtr& rentableItem);
    /**
    * @brief zakonczenie wypozyczenia
    * @param endTime
    */
    void endRent(pt::ptime endTime);
    /**
    * @brief getter informacji o wypozyczeniu
    * @return string
    */
    const std::string getRentInfo() const;
    /**
    * @brief wylicza o ile przekroczono czas wypozyczenia
    * @return int
    */
    int getRentPenaltyDays() const;
    /**
    * @brief getter klienta, wypozyczajacego
    */
    ClientPtr getClient() const;
    /**
    * @brief getter wypozyczanego przedmiotu
    */
    RentableItemPtr getRentableItem() const;
    /**
    * @brief getter czasu rozpoczecia wypozyczenia
    * @return czas wypozyczenia
    */
    pt::ptime getBeginTime() const;
    /**
    * @brief getter czasu zakonczenia wypozyczenia
    * @return czas zakonczenia wypozyczenia
    */
    pt::ptime getEndTime() const;
    /**
    * @brief getter kary za przetrzymanie wypozyczenia
    * @return float
    */
    float getRentCost() const;
    /**
    * @brief getter ID wypozyczenia
    */
    boost::uuids::uuid getRentId() const;
    /**
    * @brief setter kary za przetrzymanie
    * @param kara
    */
    void setRentCost(float);
    /**
    * @brief setter daty zakonczenia wypozyczenia
    * @param data
    */
    void setEndTime(pt::ptime);

};


#endif //STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_RENT_H
