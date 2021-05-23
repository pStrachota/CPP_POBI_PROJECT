#ifndef CARRENTAL_RENTREPOSITORY_H
#define CARRENTAL_RENTREPOSITORY_H

#include <iostream>
//#include "model/Rent.h"
#include <vector>
#include "repositories/Repository.h"

/**
 * @brief RentRepository przechowuje i udostepnia informacje oraz oraz za jej pomoca zarzadca dodaje i przenosido archiwum wypozyczenia
 * jest to klasa dziedziczace z klasy szablonowej Repository.h
 */

class Rent;

class RentRepository : public Repository<Rent> {

public:
/**
     * @brief wyszukuje wypozyczenia speliajace podany predykat
     * @param predicate - predykat, na podstawie ktorego, beda wyszukiwaniu odpowiednie wypozyczenia
     * @return wektor klientow spelniajacych zadane kryteria
     */
    std::vector<RentPtr> findByPredicate(const RentPredicate& predicate);
    /**
     * @brief zwraca wszystkie aktualne wypozycznenia
     * @return wektor
     */
    std::vector<RentPtr> findAllRents();

};





#endif //CARRENTAL_RENTREPOSITORY_H
