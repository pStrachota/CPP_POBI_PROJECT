#include <boost/test/unit_test.hpp>
#include "model/Vehicle.h"

struct TestSuiteVehicleFixture {
    const std::string testPlateNumber = "WW42420";
    const unsigned int testBasePrice = 100;
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteVehicle, TestSuiteVehicleFixture)

    BOOST_AUTO_TEST_CASE(ParameterConstrutorTest) {

        Vehicle v(testPlateNumber, testBasePrice);
        BOOST_TEST(testPlateNumber == v.getPlateNumber());
        BOOST_TEST(testBasePrice == v.getBasePrice());
    }

    BOOST_AUTO_TEST_CASE(SetPlateNumberPositiveTest) {

        Vehicle v(testPlateNumber, testBasePrice);
        v.setPlateNumber("HA320P");
        BOOST_TEST(v.getPlateNumber() == "HA320P");
    }

    BOOST_AUTO_TEST_CASE(SetPlateNumberNegativeTest) {

        Vehicle v(testPlateNumber, testBasePrice);
        v.setPlateNumber("");
        BOOST_TEST(v.getPlateNumber() == testPlateNumber);
    }

    BOOST_AUTO_TEST_CASE(SetBasePricePositiveTest) {
        Vehicle v(testPlateNumber, testBasePrice);
        v.setBasePrice(120);
        BOOST_TEST(v.getBasePrice() == 120);
    }

BOOST_AUTO_TEST_SUITE_END()

