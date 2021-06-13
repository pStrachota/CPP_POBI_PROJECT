//
// Created by student on 27.05.2021.
//

#ifndef STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_CLIENTMANAGER_H
#define STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_CLIENTMANAGER_H


#include "typedefs.h"
#include <memory>
#include <vector>
#include <repositories/ClientRepository.h>
#include "repositories/Templates.h"


class ClientManager {
    ClientRepository clientRepo;
    std::vector<Observer2Ptr> observers;
public:
    /**
     * @brief daloczam nowego obserwatora
     * @param observer2 - obserwator
     */
    void attachObserver(Observer2Ptr observer2);

    /**
    * @brief zwraca wskaznik na przedmiot klienta na podstawie jego peselu
    * @param personalId - numer pesel
    * @return wskaznik na klienta
    */
    ClientPtr getClient(const std::string&);
    /**
     * @brief rejestruje nowego klienta
     * @param firstName - imie
     * @param lastName -nazwisko
     * @param personalID - pesel
     * @param address - wskaznik na adres
     * @param type - wskaznik na typ klienta
     * @return wskaznik na nowo utworzonego klienta
     */
    ClientPtr registerClient(const std::string& name, const std::string& surname, const std::string& personalID,
                             const AddressPtr& address, const ClientTypePtr& type);
    /**
* @brief findClients znajduje wszystkich NIEARCHIWALNYCH klientow spelniajacyh dany predykat
* @param predicate - warunek do spelnienia
* @return wektor znalezionych klientow
*/
    std::vector<ClientPtr> findClients(const ClientPredicate& predicate);

    /**
     * @brief findAllClients zwraca wskazniki wszystkich niearchiwalnych klientow
     * @return wektor niearchiwalnych klientow
     */
    std::vector<ClientPtr> findAllClients();
    /**
      * @brief unregisterRentableItem ustawiwa klienta jako archiwalnego
      * @param wskaznik na usuwanego klienta
      */
    void unregisterClient(const ClientPtr& toDel);
    /**
     * @brief saveAllClientsInfoToFile zapisuje informacje o kazdym kliencie do pliku
     */
    void saveAllClientsInfoToFile();
    /**
     * @brief saveClientsToFileByPredicate zapisuje klientow spelniajacych dany predykat do pliku
      * @param predicate - warunek do spelnienia
     */
    void saveClientsToFileByPredicate(const ClientPredicate& predicate);
    /**
    * @brief countRents zlicza wszystkie wypozyczenia wszystkich klientow
    * @return int
    */
    unsigned int countClientRent() const ;

};

class ObserverC {

public:
    virtual void notify(ClientPtr) = 0;
};




#endif //STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_CLIENTMANAGER_H
