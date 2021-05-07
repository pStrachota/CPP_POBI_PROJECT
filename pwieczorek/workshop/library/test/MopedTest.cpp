#include <boost/test/unit_test.hpp>
#include "model/Moped.h"
#include "typedefs.h"

struct TestSuiteMopedFixture{
    const int initEngineDis = 1;
    const std::string initPlateNum = "ABC";
    const unsigned int initBasePri = 1;
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteMoped, TestSuiteMopedFixture)

    BOOST_AUTO_TEST_CASE(MopedActualRentalPriceTestVarEngine1)
    {
        MopedPtr tMoped = new Moped(initEngineDis,initPlateNum,initBasePri);
        BOOST_TEST(tMoped->getActualRentalPrice() == 1);
        delete tMoped;
    }

    BOOST_AUTO_TEST_CASE(MopedActualRentalPriceTestVarEngine2)
    {
    const int engDis = 1500;
        MopedPtr tMoped = new Moped(engDis,initPlateNum,initBasePri);
        BOOST_TEST(tMoped->getActualRentalPrice() == 1.25);
        delete tMoped;
    }

    BOOST_AUTO_TEST_CASE(MopedActualRentalPriceTestVarEngine3)
    {
        const int engDis = 2000;
        MopedPtr tMoped = new Moped(engDis,initPlateNum,initBasePri);
        BOOST_TEST(tMoped->getActualRentalPrice() == 1.5);
        delete tMoped;
    }



BOOST_AUTO_TEST_SUITE_END()