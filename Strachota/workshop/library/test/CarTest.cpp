#include <model/Car.h>
#include <boost/test/unit_test.hpp>

struct TestSuiteCarFixture {
    const std::string testPlateNumber = "WW42420";
    const unsigned int testBasePrice = 100;
    const int testCapacity = 330;
    SegmentType testSegmentE = E;
    SegmentType testSegmentA = A;
    SegmentType testSegmentB = B;
    SegmentType testSegmentD = D;
    SegmentType testSegmentC = C;

};


BOOST_FIXTURE_TEST_SUITE(TestSuiteCar, TestSuiteCarFixture)

    BOOST_AUTO_TEST_CASE(getActualRentalPriceTestA) {
        auto *b = new Car(testSegmentA, testCapacity, testPlateNumber, testBasePrice);
        BOOST_TEST(100 == b->getActualRentalPrice());
        delete b;
    }

    BOOST_AUTO_TEST_CASE(getActualRentalPriceTestB) {
        auto *b = new Car(testSegmentB, testCapacity, testPlateNumber, testBasePrice);
        BOOST_TEST(110 == b->getActualRentalPrice());
        delete b;
    }

    BOOST_AUTO_TEST_CASE(getActualRentalPriceTestC) {
        auto *b = new Car(testSegmentC, testCapacity, testPlateNumber, testBasePrice);
        BOOST_TEST(120.00000762939453 == b->getActualRentalPrice());
        delete b;
    }

    BOOST_AUTO_TEST_CASE(getActualRentalPriceTestD) {
        auto *b = new Car(testSegmentD, testCapacity, testPlateNumber, testBasePrice);
        BOOST_TEST(130 == b->getActualRentalPrice());
        delete b;
}

    BOOST_AUTO_TEST_CASE(getActualRentalPriceTestE) {
        auto *b = new Car(testSegmentE, testCapacity, testPlateNumber, testBasePrice);
        BOOST_TEST(150 == b->getActualRentalPrice());
        delete b;
}



BOOST_AUTO_TEST_SUITE_END()
