#include <boost/test/unit_test.hpp>
#include <repositories/RentRepository.h>
#include <model/Client.h>
#include "model/Bicycle.h"
#include "model/Gold.h"
#include "model/Address.h"
#include "model/Rent.h"


struct TestSuiteRentRepositoryFixture {
    ClientTypePtr testClientTypeGold;;
    ClientPtr testClient;
    VehiclePtr testBicycle;
    AddressPtr testAddress;
    pt::ptime test = pt::ptime(gr::date(2021,4,5), pt::hours(9)+pt::minutes(25));

    TestSuiteRentRepositoryFixture() {

       testAddress = std::make_shared<Address>("London", "Rue Morgue", "13");
       testClientTypeGold = std::make_shared<Gold>();
       testClient = std::make_shared<Client>("Piotr", "Strachota", "420", testAddress, testClientTypeGold);
       testBicycle = std::make_shared<Bicycle>("US3333", 345);

    }

    ~TestSuiteRentRepositoryFixture() {
    }

};


BOOST_FIXTURE_TEST_SUITE(TestSuiteRentRepository, TestSuiteRentRepositoryFixture)

    BOOST_AUTO_TEST_CASE(AddRentPositivetest) {
        RentPtr r = std::make_shared<Rent>(testClient, testBicycle, test);
        RentRepository rR;
        rR.add(r);
        BOOST_TEST(rR.getObject(0) == r);
    }


    BOOST_AUTO_TEST_CASE(AddRentNegativeTest) {
        RentRepository rR;
        rR.add(nullptr);
        BOOST_TEST(rR.objectSize() == 0);
    }

    BOOST_AUTO_TEST_CASE(RemoveRentPositiveTest) {
        RentPtr r = std::make_shared<Rent>(testClient, testBicycle, test);
        RentPtr r2 = std::make_shared<Rent>(testClient, testBicycle, test);
        RentRepository rR;
        rR.add(r);
        rR.add(r2);
        rR.removeObject(r);
        BOOST_TEST(rR.getObject(0) == r2);
}
    BOOST_AUTO_TEST_CASE(RemoveRentNegativeTest) {
        RentPtr r = std::make_shared<Rent>(testClient, testBicycle, test);
        RentRepository rR;
        rR.add(r);
        rR.add(nullptr);
        BOOST_TEST(rR.objectSize() == 1);
}

    BOOST_AUTO_TEST_CASE(GetRentSize) {
        RentPtr r = std::make_shared<Rent>(testClient, testBicycle, test);
        RentRepository rR;
        rR.add(r);
        BOOST_TEST(rR.objectSize() == 1);
}


BOOST_AUTO_TEST_SUITE_END()
