#ifndef CARRENTAL_TYPEDEFS_H
#define CARRENTAL_TYPEDEFS_H

class Client;
class Address;
class Vehicle;
class Rent;

typedef Client* ClientPtr;
typedef Address* AddressPtr;
typedef Vehicle* VehiclePtr;
typedef Rent* RentPtr;

typedef bool (*ClientPredicate)(ClientPtr);
typedef bool (*VehiclePredicate)(VehiclePtr);
typedef bool (*AddressPredicate)(AddressPtr);
typedef bool (*RentPredicate)(RentPtr);

#endif //CARRENTAL_TYPEDEFS_H
