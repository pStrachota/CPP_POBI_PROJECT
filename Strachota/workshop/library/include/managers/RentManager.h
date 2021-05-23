#ifndef CARRENTAL_RENTMANAGER_H
#define CARRENTAL_RENTMANAGER_H

#include "typedefs.h"
#include <memory>
#include <vector>
#include "repositories/RentRepository.h"
#include "model/Rent.h"

/**
 * @brief RentManager zarzadza repozytoriami wypzyczen oraz dodaje skonczone wypozyczenia do archiwum
 */

class RentManager {
    RentRepository currentRents;
    RentRepository archiveRents;

public:

    /**
     * @brief getAllClientRents zwraca wypozyczenia dla danego klienta
     * @param ClientPtr - klient
     * @return wektor wypozyczen danego klienta
     */
    std::vector<RentPtr> getAllClientRents(const ClientPtr&);
    /**
     * @brief getVehicleRent zwraca okreslony pojazd na postawie jego wskaznika
     * @return wskoznik na pojazd
     */
    RentPtr getVehicleRent(const VehiclePtr&);
    /**
     * @briej findAllRents zwraca wyszystkie NIEARCHIWALNE wypozyczenia
     * @return wektor wypozyczen
     */
    std::vector<RentPtr> findAllRents();
    /**
     * @brief checkClientRentBalance - zwraca ile dany klient zaplacil za zakonczone wypoczyenia
     * ta informacja pozwoli zmienic typ klienta, w zaleznosci ile juz zaplacil
     * @param cPtr - wskaznik na klienta
     * @return double - ile klient wydal
     */
    double checkClientRentBalance(const ClientPtr& cPtr);
    /**
     * @brief return usuwa nieuzwyany pojazd
     * @param - pojazd do usuniecia
     */
    void returnVehicle(const VehiclePtr& );
    /**
     * @brief changeClientType zmienia typ klienta po "wydaniu" okreslonej sumy
     */
    void changeClientType(const ClientPtr&);
    /**
    * @brief zwraca wektor wszystkich NIEARCHIWALNYCH wypozyczen spelniajacych podany predykat
    * @param predykat na podsawie ktorego bedziemy szukac
    * @return wektor znalezionych wypozyczen
    */
    std::vector<RentPtr> findRents(const RentPredicate& predicate);
    /**
     * @brief rentVehicle dodaje nowy obiekt wypozyczenia
     * @param client - klient
     * @param vehicle - pojazd
     * @param beginTime - poczatek wypozyczenia
     * @return - wskaznik na nowo utowrzony obiekt
     */
    RentPtr rentVehicle(const ClientPtr& client, const VehiclePtr& vehicle, pt::ptime beginTime);
};


#endif //CARRENTAL_RENTMANAGER_H
