#ifndef CARRENTAL_TYPEDEFS_H
#define CARRENTAL_TYPEDEFS_H

#include <memory>

class Client;
class Address;
class Vehicle;
class Rent;
class Bicycle;
class Car;
class Moped;
class ClientType;

/*
typedef Client* ClientPtr;
typedef Address* AddressPtr;
typedef Vehicle* VehiclePtr;
typedef Rent* RentPtr;
*/

typedef Bicycle* BicyclePtr;
typedef Car* CarPtr;
typedef Moped* MopedPtr;

typedef  std::shared_ptr<Client> ClientPtr;
typedef  std::shared_ptr<Vehicle> VehiclePtr;
typedef  std::shared_ptr<Address> AddressPtr;
typedef  std::shared_ptr<Rent> RentPtr;
typedef  std::shared_ptr<ClientType> ClientTypePtr;

typedef bool (*ClientPredicate)(ClientPtr);
typedef bool (*VehiclePredicate)(VehiclePtr);
typedef bool (*AddressPredicate)(AddressPtr);
typedef bool (*RentPredicate)(RentPtr);

#endif //CARRENTAL_TYPEDEFS_H
