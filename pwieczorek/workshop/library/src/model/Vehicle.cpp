#include "model/Vehicle.h"
#include "exceptions/VehicleException.h"
Vehicle::Vehicle(const std::string &numerRejestracyjny, const unsigned int &cenaBazowa) : plateNumber(numerRejestracyjny), basePrice(cenaBazowa){
    if (cenaBazowa < 0) throw exceptionBasePrice(" ERROR BASE PRICE");
    if (numerRejestracyjny.empty()) throw exceptionPlateNumber(" ERROR PLATE NUMBER");
}


Vehicle::~Vehicle() {
    //virtual destructor
}

const unsigned int & Vehicle::getBasePrice() const {
    return basePrice;
}

const std::string & Vehicle::getPlateNumber() const {
    return plateNumber;
}

void Vehicle::setPlateNumber(const std::string &givenPlateNumber) {
    if (givenPlateNumber == ""){
        throw exceptionPlateNumber(" ERROR PLATE NUMBER ");
    }
    else plateNumber = givenPlateNumber;
}

void Vehicle::setBasePrice(const int &givenPrice) {
    if (givenPrice < 0) throw exceptionBasePrice(" ERROR BASE PRICE ");
    basePrice = givenPrice;
}

std::string Vehicle::getVehicleInfo() {
    std::string output = "Vehicle: " + plateNumber + " base price "+ std::to_string(basePrice);
    return output;
}
/*
const bool Vehicle::isRented() const {
    return rented;
}

void Vehicle::setIsRented(bool isItRented) {
    rented = isItRented;
}
*/

double Vehicle::getActualRentalPrice() {
    return getBasePrice();
}

std::string Vehicle::getInfo(){
    return Vehicle::getVehicleInfo();
}

std::string Vehicle::getId() const {
    return Vehicle::getPlateNumber();
}