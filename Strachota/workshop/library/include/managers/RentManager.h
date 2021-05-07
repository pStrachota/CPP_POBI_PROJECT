#ifndef CARRENTAL_RENTMANAGER_H
#define CARRENTAL_RENTMANAGER_H

#include "typedefs.h"
#include <memory>
#include <vector>
#include "repositories/RentRepository.h"

//class ClientRepository;

class RentManager {
    RentRepository currentRents;
    RentRepository archiveRents;
public:
    //RentRepository archiveRents;
    //RentRepository currentRents;
    //ClientPtr getClient(const std::string &);
    //ClientPtr registerClient(const std::string &firstName, const std::string &lastName, const std::string &personalID,
      //                       const AddressPtr &address, const ClientTypePtr &type);
    std::vector<RentPtr> getAllClientRents(ClientPtr);
    RentPtr getVehicleRent(VehiclePtr);
    std::vector<RentPtr> findAllRents();
    double checkClientRentBalance(ClientPtr cPtr);
  //  void unregisterClient(const std::string &);
    void returnVehicle(VehiclePtr );
    void changeClientType(ClientPtr);
    RentPtr rentVehicle(unsigned int, ClientPtr client, VehiclePtr vehicle, pt::ptime beginTime);
};


#endif //CARRENTAL_RENTMANAGER_H
