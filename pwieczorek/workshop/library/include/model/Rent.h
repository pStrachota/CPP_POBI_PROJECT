#ifndef CARRENTAL_RENT_H
#define CARRENTAL_RENT_H

#include "model/Client.h"
#include "model/Vehicle.h"
#include <boost/date_time.hpp>
#include "typedefs.h"
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

/**
 * @brief rent  reprezentuje wypozyczenie
 */

class Client;

class Rent {
private:
    boost::uuids::uuid rentId;
    unsigned int rentID;
    ClientPtr const ptrClient;
    VehiclePtr const ptrVehicle;
    pt::ptime beginTime;
    pt::ptime endTime;
    unsigned int rentCost = 0;
public:
    Rent(boost::uuids::uuid rentId,ClientPtr const, VehiclePtr const, const pt::ptime);
    /**
     * @brief getClientInfo agreguje informacje o wypozyczeniu
     * @return string z informacja
     */
    std::string getRentInfo();
    /**
     * @brief getInfo deleguje odpowiedzialność na getRentInfo
     * @return string z informacja
     */
    std::string getInfo();
    /**
    * @brief getter ID wypozyczenia
    * @return int ID
    */
    const unsigned int & getID() const;
    /**
    * @brief getter pojazdu wypozyczonego
    * @return wskaznik na pojazd
    */
    const VehiclePtr getVehicle() const;
    /**
    * @brief getter klienta wypozyczającego
    * @return wskaznik na klienta
    */
    const ClientPtr getClient() const;
    /**
     * @brief oblicza czas trwania wypozyczenia w dniach
     * @param int liczba dni
     */
    unsigned int getRentDays();
    /**
    * @brief getter czasu rozpoczęcia wypozyczenia
    * @return data rozpoczęcia wypożyczenia
    */
    const pt::ptime &getBeginTime() const;
    /**
    * @brief getter czasu zakończenia wypozyczenia
    * @return data zakończenia wypożyczenia
    */
    const pt::ptime &getEndTime() const;
    /**
     * @brief setter daty zkonczenia wypozyczenia
     * @param data zakończenia
     */
    void setEndTime(pt::ptime time);
    /**
    * @brief zakończenie wypożyczenia
    * @param data zkończenia
    */
    void endRent(pt::ptime);
    /**
    * @brief wyliczanie kosztu wypożyczenia
    * @return int koszt
    */
    unsigned int getRentCost();
    boost::uuids::uuid getId() const;
};


#endif //CARRENTAL_RENT_H
