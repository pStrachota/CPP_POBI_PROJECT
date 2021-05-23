#include <boost/test/unit_test.hpp>
#include <memory>
#include "model/Bronze.h"
#include <functional>
#include "managers/RentManager.h"
#include "model/Bicycle.h"
#include "model/MotorVehicle.h"
#include "model/Client.h"
#include "model/Address.h"

struct TestSuiteRentManagerFixture {

    ClientTypePtr testClientTypeBronze;
    ClientPtr testClient1;
    VehiclePtr testVehicle2;
    VehiclePtr testVehicle;
    AddressPtr testaddress3;
    pt::ptime test;
    pt::ptime testEnd;
    pt::ptime test2;


    TestSuiteRentManagerFixture() {
        testClientTypeBronze = std::make_shared<Bronze>();
        testaddress3 = std::make_shared<Address>("London", "Rue Morgue", "13");
        testClient1 = std::make_shared<Client>("Piotr", "Strachota", "420", testaddress3, testClientTypeBronze);
        testVehicle2 = std::make_shared<MotorVehicle>(321,"WG3333", 345);
        testVehicle = std::make_shared<Bicycle>("US3333", 345);
        test = pt::ptime(gr::date(2020,3,5), pt::hours(9)+pt::minutes(25));
        testEnd = pt::ptime(gr::date(2020,4,15), pt::hours(9)+pt::minutes(25));
        test2 = pt::ptime(gr::date(2021,2,5), pt::hours(9)+pt::minutes(25));
    }

    ~TestSuiteRentManagerFixture() {
    }

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRentManager, TestSuiteRentManagerFixture)

    BOOST_AUTO_TEST_CASE(getAllClientRentsTest) {

        RentManager r;
        r.rentVehicle(testClient1, testVehicle, test);
        r.rentVehicle(testClient1, testVehicle2, test2);
        std::vector<RentPtr> rents = r.getAllClientRents(testClient1);
        BOOST_TEST(rents.size() == 2);

    }
    BOOST_AUTO_TEST_CASE(getVehicleRent) {
        RentManager r;
        RentPtr dance = r.rentVehicle(testClient1, testVehicle, test);
        r.returnVehicle(testVehicle);
        double priceEnd = r.checkClientRentBalance(testClient1);
       BOOST_TEST(priceEnd > 0);
}
    BOOST_AUTO_TEST_CASE(returnVehicleTest) {
        RentManager r;
        RentPtr dance = r.rentVehicle(testClient1, testVehicle, test);
        int number1 = testClient1->getMaxVehicles();
        r.returnVehicle(testVehicle);
        BOOST_TEST(testClient1->getMaxVehicles() > number1);

}

BOOST_AUTO_TEST_SUITE_END()

