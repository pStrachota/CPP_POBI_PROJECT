#ifndef CARRENTAL_TYPEDEFS_H
#define CARRENTAL_TYPEDEFS_H

class Client;
class Vehicle;
class Rent;
class Address;

typedef Client *ClientPtr;
typedef Vehicle *VehiclePtr;
typedef Rent *RentPtr;
typedef Address *AddressPtr;

typedef bool (*ClientPredicate)(ClientPtr);
typedef bool (*VehiclePredicate)(VehiclePtr);
typedef bool (*RentPredicate)(RentPtr);
typedef bool (*AddressPredicate)(AddressPtr);


#endif //CARRENTAL_TYPEDEFS_H
