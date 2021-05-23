#include <boost/test/unit_test.hpp>
#include "model/Bicycle.h"
#include "typedefs.h"

struct TestSuiteBicycleFixture{
    const std::string initPlateNum = "ABC";
    const unsigned int initBasePri = 1;
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteBicycle, TestSuiteBicycleFixture)

    BOOST_AUTO_TEST_CASE(BicycleActualRentalPriceTest)
    {
    BicyclePtr tBicycle = new Bicycle(initPlateNum,initBasePri);
    BOOST_TEST(tBicycle->getActualRentalPrice() == initBasePri);
    }


BOOST_AUTO_TEST_SUITE_END()
