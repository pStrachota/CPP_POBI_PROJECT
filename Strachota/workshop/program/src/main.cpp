#include <iostream>
#include "model/Client.h"
#include "model/Address.h"
#include <boost/date_time.hpp>
namespace pt = boost::posix_time;
namespace gr = boost::gregorian;
#include "model/Bicycle.h"
#include "managers/ClientManager.h"
#include "managers/VehicleManager.h"
#include "managers/RentManager.h"
#include "model/Bronze.h"
#include "typedefs.h"
#include <memory>
#include "model/Gold.h"
#include <functional>
#include "model/MotorVehicle.h"
#include "model/Silver.h"
#include "exceptions/ClientException.h"

int main() {

    ClientTypePtr testClientTypeBronze = std::make_shared<Bronze>();
    ClientTypePtr testClientTypeGold = std::make_shared<Gold>();
    ClientTypePtr testClientTypeSilver = std::make_shared<Silver>();

    AddressPtr testAddress = std::make_shared<Address>("London", "Rue Morgue", "13");
    AddressPtr testAddress2 = std::make_shared<Address>("Washington", "White House", "23");
    AddressPtr testAddress3 = std::make_shared<Address>("Garwolin", "Dluga", "8");

    ClientPtr testClient = std::make_shared<Client>("Piotr", "Strachota", "420", testAddress, testClientTypeBronze);
    ClientPtr testClient2 = std::make_shared<Client>("Joe", "Biden", "690", testAddress2, testClientTypeGold);
    ClientPtr testClient3 = std::make_shared<Client>("Robert", "Maklowicz", "12456", testAddress3, testClientTypeSilver);

    VehiclePtr testMotorVehicle = std::make_shared<MotorVehicle>(921,"LZ6789", 545);
    VehiclePtr testBicycle = std::make_shared<Bicycle>("US3333", 345);
    VehiclePtr testBicycle2 = std::make_shared<Bicycle>("WG7783", 345);

    pt::ptime testTime = pt::ptime(gr::date(2020,3,5), pt::hours(9)+pt::minutes(25));
    pt::ptime testEndTime = pt::ptime(gr::date(2020,4,15), pt::hours(9)+pt::minutes(25));
    pt::ptime testTime2 = pt::ptime(gr::date(2021,2,5), pt::hours(9)+pt::minutes(25));

    clientManager testClientManager;
    RentManager testRentManager;
    VehicleManager testVehicleManager;

    testClientManager.registerClient("Piotr", "Strachota", "420", testAddress, testClientTypeBronze);
    testClientManager.registerClient("Joe", "Biden", "690", testAddress2, testClientTypeGold);
    testClientManager.registerClient("Robert", "Maklowicz", "12456", testAddress3, testClientTypeSilver);

    testRentManager.rentVehicle(testClient, testBicycle, testTime);
    testRentManager.rentVehicle(testClient2, testBicycle2, testTime2);
    testRentManager.rentVehicle(testClient3, testMotorVehicle, testTime);

    testVehicleManager.registerBicycle("US3333", 345);
    testVehicleManager.registerBicycle("WG3333", 345);
    testVehicleManager.registerMoped(321,"WG3333", 345);

    testClientManager.unregisterClient("690");
    testRentManager.returnVehicle(testBicycle2);
    testVehicleManager.unregisterVehicle(testBicycle2);

    std::vector<ClientPtr> testClientVector = testClientManager.findAllClients();
    for(int i = 0; i < testClientVector.size(); i++) {
        std::cout << testClientVector[i]->getInfo() << std::endl;
    }
    std::cout << "-------------------------------------------------" << std::endl;
    std::vector<VehiclePtr> testVehicleVector = testVehicleManager.findAllVehicles();
    for(int i = 0; i < testVehicleVector.size(); i++) {
        std::cout << testVehicleVector[i]->getInfo() << std::endl;
    }
    std::cout << "-------------------------------------------------" << std::endl;
    std::vector<RentPtr> testRentVector = testRentManager.findAllRents();
    for(int i = 0; i < testRentVector.size(); i++) {
        std::cout << testRentVector[i]->getInfo() << std::endl;
    }




    return 0;
}
