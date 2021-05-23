#ifndef CARRENTAL_VEHICLEMANAGER_H
#define CARRENTAL_VEHICLEMANAGER_H

#include "typedefs.h"
#include <memory>
#include <vector>
#include "repositories/VehicleRepository.h"
#include "model/Car.h"

/**
 * @brief VehicleManager zarzadza repozytorium pojazdow
 */

class VehicleManager {
    VehicleRepository vehicleRepo;
public:
    VehiclePtr getVehicle(const std::string &);
    /**
     * @brief registerBicycle rejestruje nowy pojazd typu rower
     * @param platenumber - tablica
     * @param baseprice - cena
     * @return obiekt pojazdu
     */
    VehiclePtr registerBicycle(const std::string& platenumber, unsigned int baseprice);
    /**
     * @brief registerMoped rejestruje nowy pojazd typu motor
     * @param capacity - pojemnosc
     * @param platenumber - tablica
     * @param baseprice -cena
     * @return obiekt pojazdu
     */
    VehiclePtr registerMoped(int capacity, const std::string &platenumber, const unsigned int &baseprice);
    /**
     * @brief - registerCar rejestruje nowy pojazd typu samochod
     * @param test - kategoria samochodu
     * @param capacity - pojemnosc
     * @param platenumber - tablica
     * @param baseprice - cena
     * @return - obiekt pojazdu
     */
    VehiclePtr registerCar(SegmentType test, int capacity, const std::string &platenumber, const unsigned int &baseprice);
    /**
     * @brief unregisterVehicle ustawiwa pojazd jako archiwalny
     * @param wskaznik na obiekt pojazdu
     */
    void unregisterVehicle(const VehiclePtr&);
    /**
     * @brief znajdz wszystkie NIEARCHIWALNE pojazdy spelniajace dany predykat
     * @param predicate - warunek do spelnienia
     * @return wektor znalezionych pojazdow
     */
    std::vector<VehiclePtr> findVehicles(const VehiclePredicate& predicate);
    /**
     * @brief zwraca wszystkie NIEARCHIWALNE pojazdy
     * @return wektor znalezioncych pojazdow
     */
    std::vector<VehiclePtr> findAllVehicles();

};






#endif //CARRENTAL_VEHICLEMANAGER_H
