#ifndef CARRENTAL_VEHICLEREPOSITORY_H
#define CARRENTAL_VEHICLEREPOSITORY_H

#include <iostream>
/*#include "model/Vehicle.h"
#include "model/Client.h"*/
#include <vector>
#include "repositories/Repository.h"

/**
 * @brief VehicleRepository przechowuje i udostepnia informacje oraz doraz za jej pomoca zarzadca dodaje i przenosi do archiwum pojazdy
 * jest to klasa dziedziczace z klasy szablonowej Repository.h
 */

class Vehicle;

class VehicleRepository : public Repository <Vehicle> {

public:
/**
     * @brief wyszukuje pojazdy speliajace podany predykat
     * @param predicate - predykat, na podstawie ktorego, beda wyszukiwaniu odpowiednie pojazdt
     * @return wektor klientow spelniajacych zadane kryteria
     */
    std::vector<VehiclePtr> findByPredicate(const VehiclePredicate& predicate);
    /**
    * @brief zwraca wszystkie aktualne pojazdy
    * @return wektor
    */
    std::vector<VehiclePtr> findAllVehicles();

};




#endif //CARRENTAL_VEHICLEREPOSITORY_H
