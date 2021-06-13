
#ifndef STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_RENTMANAGER_H
#define STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_RENTMANAGER_H

#include "typedefs.h"
#include <memory>
#include <vector>
#include <repositories/RentRepository.h>
#include "repositories/Templates.h"
#include <boost/date_time.hpp>
#include "model/Rent.h"
#include "repositories/Templates.h"

/**
 * @brief RentManager zarzadza repozytorium wypozyczen
 */



namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

class RentManager {
    RentRepository currentRents;
    RentRepository archiveRents;
    std::vector<ObserverPtr> observers;
public:
    /**
     * @brief daloczam nowego obserwatora
     * @param observer - obserwator
     */
    void attachObserver(ObserverPtr observer);
    RentPtr rentRentableItem(const ClientPtr &client, const RentableItemPtr &rentableItem,pt::ptime beginTime);

    void removeRentableItem(RentableItemPtr& rentableItem);
    /**
     * @brief getRentableItemRent to getter wypozyczenia
     * @param entableItem - fizyczny obiekt przypisany do wypozyczenia
     * @return wskaznik na wypozyczenie
     */
    RentPtr getRentableItemRent(const RentableItemPtr &rentableItem);
    /**
     * @brief findRents znajduje wypozyczenia wedlug predykatu
     * @param predicate - predykat
     * @return wektor wkaznikow na wypozyczenia
     */
    std::vector<RentPtr> findRents(const RentPredicate& predicate);
    /**
     * @brief getAllClientRents znajduje wypozyczenia danego klienta
     * @param client - wskaznik na klienta
     * @return wektor wkaznikow na wypozyczenia
     */
    std::vector<RentPtr> getAllClientRents(const ClientPtr &client);
    /**
     * @brief countRents zlicza wszystkie wypozyczenia biblioteki
     * @return int
     */
    unsigned int countRents() const;
    /**
     * @brief saveRentsToFileByPredicate zapisuje wypozyczenia spelniajace dany predykat do pliku
     * @param predicate - warunek do spelnienia
     */
    void saveRentsToFileByPredicate(const RentPredicate &);

};


class Observer {

public:
    virtual void notify(RentPtr) = 0;
};




#endif //STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_RENTMANAGER_H
