#include <boost/test/unit_test.hpp>
#include "model/Bicycle.h"



struct TestSuiteBicycleFixture {
    const std::string testPlateNumber = "WW42420";
    const unsigned int testBasePrice = 100;
};


BOOST_FIXTURE_TEST_SUITE(TestSuiteBicycle, TestSuiteBicycleFixture)

    BOOST_AUTO_TEST_CASE(getActualRentalPriceTest) {

        auto *b = new Bicycle(testPlateNumber, testBasePrice);
        BOOST_TEST(testBasePrice == b->getActualRentalPrice());
        delete b;
    }

BOOST_AUTO_TEST_SUITE_END()
