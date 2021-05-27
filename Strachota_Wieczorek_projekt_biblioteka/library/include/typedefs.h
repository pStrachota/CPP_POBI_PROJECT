//
// Created by student on 27.05.2021.
//

#ifndef STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_TYPEDEFS_H
#define STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_TYPEDEFS_H



#include <memory>
#include <functional>

class Client;
class Vehicle;
class Rent;
class Address;
class ClientRepository;
class ClientType;
class VehicleRepository;
class RentRepository;
class StorageContainer;


typedef std::shared_ptr<Client> ClientPtr;
typedef std::shared_ptr<ClientType> ClientTypePtr;
typedef std::shared_ptr<Rent> RentPtr;
typedef std::shared_ptr<Vehicle> VehiclePtr;
typedef std::shared_ptr<Address> AddressPtr;
typedef std::shared_ptr<StorageContainer> ContainerPtr;

//typedef std::shared_ptr<VehicleRepository> VehicleRepoPtr;
//typedef std::shared_ptr<RentRepository> RentRepoPtr;


typedef std::function<bool(ClientPtr)> ClientPredicate;
typedef std::function<bool(RentPtr)> RentPredicate;
typedef std::function<bool(VehiclePtr)> VehiclePredicate;
typedef std::function<bool(AddressPtr)> AddressPredicate;




#endif //STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_TYPEDEFS_H
