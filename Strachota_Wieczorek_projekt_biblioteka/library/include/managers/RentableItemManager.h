//
// Created by student on 12.06.2021.
//

#ifndef STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_RENTABLEITEMMANAGER_H
#define STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_RENTABLEITEMMANAGER_H

#include "typedefs.h"
#include <memory>
#include <vector>
#include <repositories/RentableItemRepository.h>
#include "repositories/Templates.h"



class RentableItemManager {

private:
    RentableItemRepository rItemRepo;
    std::vector<Observer3Ptr> observers;
public:
    /**
     * @brief daloczam nowego obserwatora
     * @param observer3 - obserwator
     */
    void attachObserver(Observer3Ptr observer3);
   /**
    * @brief zwraca wskaznik na przedmiot wypozyczenia na podstawie jego numeru seryjnego
    * @param serialNumber - numer seryjny
    * @return wskaznik na przedmiot
    */
    RentableItemPtr getRentableItem(const std::string& serialNumber);

    /**
     * @brief registerBook rejestruje nowy przedmiot typu ksiazka
     * @param serialNumber - numer seryjny
     * @param author - autor ksiazki
     * @param title - tytul ksiazki
     * @param publishingHouse - wydawca
     * @return wskaznik na nowo utworzony przedmiot
     */
    RentableItemPtr registerBook(const std::string& serialNumber, const std::string& author, const std::string& title, const std::string& publishingHouse);
    /**
    * @brief registerArticle rejestruje nowy przedmiot typu artykul
    * @param serialNumber - numer seryjny
    * @param author - autor ksiazki
    * @param title - tytul ksiazki
    * @param parentOrganisation - jaka organizacja wydaje artykul
    * @return @return wskaznik na nowo utworzony przedmiotu
    */
    RentableItemPtr registerArticle(const std::string& serialNumber, const std::string& author, const std::string& title, const std::string& parentOrganisation);
    /**
      * @brief unregisterRentableItem ustawiwa przedmiot jako archiwalny
      * @param wskaznik na usuwany przedmiot
      */
    void unregisterRentableItem(const RentableItemPtr& toDel);
    /**
* @brief findRentableItem znajduje wszystkie NIEARCHIWALNE przedmioty spelniajace dany predykat
* @param predicate - warunek do spelnienia
* @return wektor znalezionych przedmiotow
*/
    std::vector<RentableItemPtr> findRentableItem(const RentableItemPredicate& predicate);
    /**
     * @brief saveRentableItemsToFileByPredicate zapisuje przedmioty spelniajace dany predykat do pliku
      * @param predicate - warunek do spelnienia
     */
    void saveRentableItemsToFileByPredicate(const RentableItemPredicate& predicate);
    /**
    * @brief saveRentsToFileByPredicate zapisuje wypozyczenia spelniajace dany predykat do pliku
    */
    unsigned int rentableItemCounts() const;
};

class ObserverR {

public:
    virtual void notify(RentableItemPtr) = 0;
};



#endif //STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_RENTABLEITEMMANAGER_H
