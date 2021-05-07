#include <boost/test/unit_test.hpp>
#include <repositories/RentRepository.h>
#include <repositories/StorageContainer.h>

/*

struct TestSuiteRentRepositoryFixture {
    const unsigned int testId = 1;
    ClientPtr testaddress1;
    VehiclePtr testaddress2;
    AddressPtr testaddress3;
    pt::ptime test = pt::ptime(gr::date(2021,4,5), pt::hours(9)+pt::minutes(25));


    TestSuiteRentRepositoryFixture() {

        testaddress3 = new Address("London", "Rue Morgue", "13");
        testaddress1 = new Client("Piotr", "Strachota", "420", testaddress3);
        testaddress2 = new Vehicle("US3333", 345);
    }

    ~TestSuiteRentRepositoryFixture() {
        delete testaddress1;
        delete testaddress2;
        delete testaddress3;
    }

};


BOOST_FIXTURE_TEST_SUITE(TestSuiteRentRepository, TestSuiteRentRepositoryFixture)

    BOOST_AUTO_TEST_CASE(AddRentPositivetest) {
        auto r = new Rent(testId, testaddress1, testaddress2, test);
        auto *rR = new RentRepository;
        rR->addRent(r);
        BOOST_TEST(rR->getRent(1) == r);
        delete r;
        delete rR;
    }

    BOOST_AUTO_TEST_CASE(AddRentNegativeTest) {
        auto *rR = new RentRepository;
        rR->addRent(nullptr);
        BOOST_TEST(rR->rentSize() == 0);
        delete rR;
    }

    BOOST_AUTO_TEST_CASE(RemoveRentPositiveTest) {
        auto r = new Rent(testId, testaddress1, testaddress2, test);
        auto r2 = new Rent(2, testaddress1, testaddress2, test);
        auto *rR = new RentRepository;
        rR->addRent(r);
        rR->addRent(r2);
        rR->removeRent(r);
        BOOST_TEST(rR->getRent(1) == r2);
        delete r2;
        delete rR;
}
    BOOST_AUTO_TEST_CASE(RemoveRentNegativeTest) {
        auto r = new Rent(testId, testaddress1, testaddress2, test);
        auto *rR = new RentRepository;
        rR->addRent(r);
        rR->addRent(nullptr);
        BOOST_TEST(rR->rentSize() == 1);
        delete r;
        delete rR;
}

    BOOST_AUTO_TEST_CASE(GetRentSize) {
        auto r = new Rent(testId, testaddress1, testaddress2, test);
        auto *rR = new RentRepository;
        rR->addRent(r);
        BOOST_TEST(rR->rentSize() == 1);
        delete r;
        delete rR;
}


BOOST_AUTO_TEST_SUITE_END()
 */