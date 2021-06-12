
#ifndef STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_RENTABLEITEMREPOSITORY_H
#define STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_RENTABLEITEMREPOSITORY_H

#include <iostream>
#include <vector>
#include "repositories/Templates.h"


/**
 * @brief RentableItemRepository przechowuje i udostepnia informacje oraz za jej pomoca zarzadca dodaje i przenosi do archiwum obiektow wypozyczanych
 * jest to klasa dziedziczace z klasy szablonowej Repository.h
 */

class RentableItem;

class RentableItemRepository : public Repository<RentableItem> {

public:

    /**
     * @brief findByPredicate wyszukuje obiekty wypozyczane speliajace podany predykat
     * @param predicate - predykat, na podstawie ktorego, beda wyszukiwane obiekty wypozyczane
     * @return wektor obiektow wypozyczonych spelniajacych zadane kryteria
     */
    std::vector<RentableItemPtr> findByPredicate(const RentableItemPredicate& predicate);
    /**
     * @brief zwraca wszystkie obiekty wypozyczane
     * @return wektor
     */
    std::vector<RentableItemPtr> findAllRentableItems();

};




#endif //STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_RENTABLEITEMREPOSITORY_H
