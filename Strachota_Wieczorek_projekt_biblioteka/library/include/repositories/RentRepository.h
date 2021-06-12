#ifndef STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_RENTREPOSITORY_H
#define STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_RENTREPOSITORY_H

#include <iostream>
#include <vector>
#include "repositories/Templates.h"


/**
 * @brief RentRepository przechowuje i udostepnia informacje oraz za jej pomoca zarzadca dodaje i przenosi do archiwum wypożyczen
 * jest to klasa dziedziczace z klasy szablonowej Repository.h
 */

class Rent;

class RentRepository : public Repository<Rent> {

public:

    /**
     * @brief findByPredicate wyszukuje wypozyczenia speliajace podany predykat
     * @param predicate - predykat, na podstawie ktorego, beda wyszukiwane odpowiednie wypozyczenia
     * @return wektor wypozyczen spelniajacych zadane kryteria
     */
    std::vector<RentPtr> findByPredicate(const RentPredicate& predicate);
    /**
     * @brief zwraca wszystkie wypozyczenia
     * @return wektor
     */
    std::vector<RentPtr> findAllRents();

};

#endif //STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_RENTREPOSITORY_H
