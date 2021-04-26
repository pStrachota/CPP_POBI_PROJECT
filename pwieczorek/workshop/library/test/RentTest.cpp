#include <boost/test/unit_test.hpp>
#include "model/Vehicle.h"
#include "model/Client.h"
#include "model/Rent.h"


struct TestSuiteRentFixture{
    unsigned int rentID = 3;
    Client*  ptrClient;
    Vehicle*  ptrVehicle;
    Address* ptrAddress;
    pt::ptime testDate = pt::ptime(gr::date(2021,3,13), pt::hours(12) + pt::minutes(30));

    TestSuiteRentFixture() {
        ptrAddress = new Address("london","baker st","7");
        ptrVehicle = new Vehicle("007",5);
        ptrClient = new Client("adam","nowak","007",nullptr);
    }

    ~TestSuiteRentFixture() {
        delete ptrVehicle;
        delete ptrClient;
    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRent,TestSuiteRentFixture)


    BOOST_AUTO_TEST_CASE(ConstructorTests)
    {
    Rent r(rentID,ptrClient,ptrVehicle,testDate);
    BOOST_TEST(r.getID() == rentID);
    BOOST_TEST(r.getVehicle() == ptrVehicle);
    BOOST_TEST(r.getClient() == ptrClient);
    }


BOOST_AUTO_TEST_SUITE_END()
