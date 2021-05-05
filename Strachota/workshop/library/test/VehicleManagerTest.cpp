#include <boost/test/unit_test.hpp>
#include "managers/VehicleManager.h"
#include <memory>
#include "model/ClientType.h"
#include "model/Bronze.h"
#include <functional>
#include "model/Car.h"


struct TestSuiteVehicleManagerFixture {
    //const unsigned int testId = 1;
    ClientTypePtr testClientTypeBronze = std::make_shared<Bronze>();
    SegmentType testSegmentA = A;
    //ClientPtr testaddress1 = std::make_shared<Client>("Piotr", "Strachota", "420", testaddress3, testClientTypeBronze);
    //ClientTypePtr testClientTypeGold = std::make_shared<Gold>();
    //ClientTypePtr testClientTypeDiamond = std::make_shared<Diamond>();
    //ClientPtr testClient2 = std::make_shared<Client>("Piotr", "Strachota", "420", nullptr, testClientTypeSilver);
    //ClientPtr testClient3 = std::make_shared<Client>("Piotr", "Strachota", "420", nullptr, testClientTypeGold);
    //ClientPtr testClient4 = std::make_shared<Client>("Piotr", "Strachota", "420", nullptr, testClientTypeDiamond);
    //ClientTypePtr testClientTypeSilver = std::make_shared<Silver>();
    //ClientPtr testClient2 = std::make_shared<Client>("Piotr", "Strachota", "420", nullptr, testClientTypeSilver);
    //VehiclePtr testaddress2 = std::make_shared<Vehicle>("US3333", 345);
    AddressPtr testaddress3 = std::make_shared<Address>("London", "Rue Morgue", "13");
    //RentPtr r;
    //pt::ptime test = pt::ptime(gr::date(2021,4,5), pt::hours(9)+pt::minutes(25));

//ClientTypePtr testClientTypeSilver = std::make_shared<Silver>();


    TestSuiteVehicleManagerFixture() {


    }

    ~TestSuiteVehicleManagerFixture() {
    }

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteVehicleManager, TestSuiteVehicleManagerFixture)

    BOOST_AUTO_TEST_CASE(findByPlateNumberPositiveTest) {

       VehicleManager v;
        VehiclePtr vehicleBike = v.registerBicycle("WG4209", 99);
       BOOST_TEST(vehicleBike == v.getVehicle("WG4209"));
        VehiclePtr vehicleMoped = v.registerMoped(330, "GA2882", 199);
        VehiclePtr vehicleCar = v.registerCar(testSegmentA, 1500, "LS8821", 999);
        BOOST_TEST(vehicleBike == v.getVehicle("WG4209"));
        BOOST_TEST(vehicleMoped == v.getVehicle("GA2882"));
        BOOST_TEST(vehicleCar == v.getVehicle("LS8821"));
        //ClientPtr client = c.registerClient("Piotr", "Strachota", "1", testaddress3, testClientTypeBronze);
        //BOOST_TEST(client = c.getClient("1"));

    }

    BOOST_AUTO_TEST_CASE(findByPlateNumberNegativeTest) {

        VehicleManager v;
        VehiclePtr vehicleBike = v.registerBicycle("WG42099", 99);
        VehiclePtr vehicleBike2 = v.registerBicycle("WG42099", 299);
        BOOST_TEST(vehicleBike == vehicleBike2);
        VehiclePtr vehicleMoped = v.registerMoped(330, "GA2882", 199);
        VehiclePtr vehicleMoped2 = v.registerMoped(1330, "GA2882", 1929);
        BOOST_TEST(vehicleMoped == vehicleMoped2);
        VehiclePtr vehicleCar = v.registerCar(testSegmentA, 1500, "LS8821", 999);
        VehiclePtr vehicleCar2 = v.registerCar(testSegmentA, 15040, "LS8821", 9929);
        BOOST_TEST(vehicleCar == vehicleCar2);

        //clientManager c;
        //ClientPtr client = c.registerClient("Piotr", "Strachota", "1", testaddress3, testClientTypeBronze);
        //ClientPtr client2 = c.registerClient("Robert", "Maklowicz", "1", testaddress3, testClientTypeBronze);
        //BOOST_TEST(client == client2);
    }


BOOST_AUTO_TEST_SUITE_END()