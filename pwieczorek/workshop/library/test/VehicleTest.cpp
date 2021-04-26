#include <boost/test/unit_test.hpp>
#include "model/Vehicle.h"

struct TestSuiteVehicleFixture{
    const std::string initialPlateNumber = "ABC";
    const unsigned int initialBasePrice = 5;
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteVehicle,TestSuiteVehicleFixture)


    BOOST_AUTO_TEST_CASE(ConstructorTests)
    {
        Vehicle v(initialPlateNumber, initialBasePrice);

        BOOST_TEST(v.getPlateNumber() == initialPlateNumber);
        BOOST_TEST(v.getBasePrice() == initialBasePrice);
    }

    BOOST_AUTO_TEST_CASE(plateNumberSetterTestsPositive)
    {
        Vehicle v(initialPlateNumber, initialBasePrice);
        v.setPlateNumber("001");
        BOOST_TEST(v.getPlateNumber() == "001");
    }

    BOOST_AUTO_TEST_CASE(plateNumberSetterTestsNegative)
    {
        Vehicle v(initialPlateNumber, initialBasePrice);
        v.setPlateNumber("");
        BOOST_TEST(v.getPlateNumber() != "");
    }

    BOOST_AUTO_TEST_CASE(basePriceSetterTests)
    {
        Vehicle v(initialPlateNumber, initialBasePrice);
        v.setBasePrice(5);
        BOOST_TEST(v.getBasePrice() == 5);
    }


BOOST_AUTO_TEST_SUITE_END()