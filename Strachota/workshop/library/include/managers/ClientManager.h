#ifndef CARRENTAL_CLIENTMANAGER_H
#define CARRENTAL_CLIENTMANAGER_H
#include "typedefs.h"
#include <memory>
#include <vector>
#include <repositories/ClientRepository.h>
#include "repositories/Repository.h"

/**
 * @brief clientManger zarzadza repozytorium klientow
 */

class clientManager {
    ClientRepository clientRepo;
public:
    ClientPtr getClient(const std::string&);
    /**
     * @brief register Client pozwala zarejestrow nowego klienta
     * @param firstName - imie
     * @param lastName - nawisko
     * @param personalID - pesel
     * @param address - adres
     * @param type - typ klienta
     * @return wskaznik na nowo utworzonego klienta
     */
    ClientPtr registerClient(const std::string &firstName, const std::string &lastName, const std::string& personalID,
                             const AddressPtr &address, const ClientTypePtr &type);
    /**
     * @brief zwraca wektor wszystkich NIEARCHIWALNYCH klientow spelniajacych podany predykat
     * @param predykat na podsawie ktorego bedziemy szukac
     * @return wektor znalezionych klientow
     */
    std::vector<ClientPtr> findClients(const ClientPredicate&);
    /**
     * @brief zwraca wektor wszystkich NIEARCHIWALNYCH aktualnych klientow
     * @return wektor znalezionych klientow
     */
    std::vector<ClientPtr> findAllClients();
    /**
     * @brief unregisterClient - wyrestowanie klienta, na podstawie jego peselu
     */
    void unregisterClient(const std::string &);
};




#endif //CARRENTAL_CLIENTMANAGER_H
