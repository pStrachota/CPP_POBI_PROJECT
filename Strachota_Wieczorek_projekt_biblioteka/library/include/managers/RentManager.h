
#ifndef STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_RENTMANAGER_H
#define STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_RENTMANAGER_H

#include "typedefs.h"
#include <memory>
#include <vector>
#include <repositories/RentRepository.h>
#include "repositories/Templates.h"
#include <boost/date_time.hpp>
#include "model/Rent.h"

/**
 * @brief RentManager zarzadza repozytorium wypozyczen
 */

namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

class RentManager {
    RentRepository currentRents;
    RentRepository archiveRents;
public:
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
    int countRents() const;
    /**
     * @brief saveRentsToFileByPredicate zapisuje wypozyczenia spelniajace dany predykat do pliku
     */
    void saveRentsToFileByPredicate(const RentPredicate &);

};



#endif //STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_RENTMANAGER_H
