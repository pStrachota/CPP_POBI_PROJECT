#include <model/Moped.h>
#include <boost/test/unit_test.hpp>


struct TestSuiteMopedFixture {
    const std::string testPlateNumber = "WW42420";
    const unsigned int testBasePrice = 100;
    const int testCapacity1 = 3300;
    const int testCapacity2 = 900;
    const int testCapacity3 = 1900;
};


BOOST_FIXTURE_TEST_SUITE(TestSuiteMoped, TestSuiteMopedFixture)

    BOOST_AUTO_TEST_CASE(getActualRentalPriceTestAbove2000) {

        auto *b = new Moped(testCapacity1, testPlateNumber, testBasePrice);
        BOOST_TEST(150 == b->getActualRentalPrice());
        delete b;
    }
    BOOST_AUTO_TEST_CASE(getActualRentalPriceTestBelow1000) {
        auto *b = new Moped(testCapacity2, testPlateNumber, testBasePrice);
        BOOST_TEST(100 == b->getActualRentalPrice());
        delete b;
}

    BOOST_AUTO_TEST_CASE(getActualRentalPriceTestBetween1000and2000) {
        auto *b = new Moped(testCapacity3, testPlateNumber, testBasePrice);
        float base = 1000;
        float multip = 0.5;
        float wage = static_cast<double>((this->testCapacity3 - base) / base);
        wage *= multip;
        float add = 1;
        wage += add;
        float price = wage * testBasePrice;
        BOOST_TEST(price == b->getActualRentalPrice());
        delete b;
}

BOOST_AUTO_TEST_SUITE_END()
