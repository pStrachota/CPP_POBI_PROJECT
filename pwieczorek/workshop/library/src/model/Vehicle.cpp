#include "model/Vehicle.h"

Vehicle::Vehicle(const std::string &numerRejestracyjny, const unsigned int &cenaBazowa) : plateNumber(numerRejestracyjny), basePrice(cenaBazowa){

}

Vehicle::Vehicle(){
    plateNumber = "initialPlate";
    basePrice = 1;
}

Vehicle::~Vehicle() {
}

const unsigned int & Vehicle::getBasePrice() const {
    return basePrice;
}

const std::string & Vehicle::getPlateNumber() const {
    return plateNumber;
}

void Vehicle::setPlateNumber(const std::string &givenPlateNumber) {
    if (givenPlateNumber == ""){
        std::cout << "Incorrect plate number";
    }
    else plateNumber = givenPlateNumber;
}

void Vehicle::setBasePrice(const unsigned int &givenPrice) {
    basePrice = givenPrice;
}

std::string Vehicle::getVehicleInfo() {
    std::string output = "Car: " + plateNumber + std::to_string(basePrice);
    return output;
}

const bool Vehicle::isRented() const {
    return rented;
}

void Vehicle::setIsRented(bool isItRented) {
    rented = isItRented;
}