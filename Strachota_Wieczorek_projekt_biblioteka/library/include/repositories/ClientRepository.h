//
// Created by student on 27.05.2021.
//

#ifndef STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_CLIENTREPOSITORY_H
#define STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_CLIENTREPOSITORY_H


#include <iostream>
#include <vector>
#include "repositories/Templates.h"


/**
 * @brief ClientRepository przechowuje i udostepnia informacje oraz za jej pomoca zarzadca dodaje i przenosi do archiwum klientow
 * jest to klasa dziedziczace z klasy szablonowej Repository.h
 */

class Client;

class ClientRepository : public Repository<Client> {

public:

    /**
     * @brief findByPredicate wyszukuje klientow speliajacych podany predykat
     * @param predicate - predykat, na podstawie ktorego, beda wyszukiwaniu odpowiedni klienci
     * @return wektor klientow spelniajacych zadane kryteria
     */
    std::vector<ClientPtr> findByPredicate(const ClientPredicate& predicate);
    /**
     * @brief zwraca wszystkich klientow
     * @return wektor
     */
    std::vector<ClientPtr> findAllClients();

};




#endif //STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_CLIENTREPOSITORY_H
