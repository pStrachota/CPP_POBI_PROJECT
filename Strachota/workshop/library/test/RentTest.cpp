#include <boost/test/unit_test.hpp>
#include "model/Rent.h"
#include "typedefs.h"


struct TestSuiteRentFixture {
    const unsigned int testId = 1;
    ClientPtr testaddress1;
    VehiclePtr testaddress2;
    AddressPtr testaddress3;
    RentPtr r;
    pt::ptime test = pt::ptime(gr::date(2021,4,5), pt::hours(9)+pt::minutes(25));


    TestSuiteRentFixture() {

        testaddress3 = new Address("London", "Rue Morgue", "13");
        testaddress1 = new Client("Piotr", "Strachota", "420", testaddress3);
        testaddress2 = new Vehicle("US3333", 345);
    }

    ~TestSuiteRentFixture() {
        delete testaddress1;
        delete testaddress2;
        delete testaddress3;
    }

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRent, TestSuiteRentFixture)

    BOOST_AUTO_TEST_CASE(ParameterConstrutorTest) {

        RentPtr r = new Rent(testId, testaddress1, testaddress2, test);
        BOOST_TEST(testId == r->getId());
        BOOST_TEST(r == testaddress1->getRent(0));
        BOOST_TEST(testaddress1 == r->getClient());
        BOOST_TEST(testaddress2 == r->getVehicle());
        BOOST_TEST(test == r->getBeginTime());
        delete r;

    }

    BOOST_AUTO_TEST_CASE(ParameterConstrutorTestDefaultBeginTime) {

        RentPtr r = new Rent(testId, testaddress1, testaddress2, pt::not_a_date_time);

        pt::ptime now = pt::second_clock::local_time(); //hope this takes no longer than 59 secs...
        BOOST_TEST_REQUIRE(!r->getBeginTime().is_not_a_date_time()); //if this isn't met, the next check doesn't make sense...
        pt::time_period skew = pt::time_period(r->getBeginTime(), now);
        BOOST_TEST((skew.length().hours()==0 && skew.length().minutes()==0));
        delete r;
    }

    BOOST_AUTO_TEST_CASE(EndRentTestBasic) {
        RentPtr r = new Rent(testId, testaddress1, testaddress2, test);
        BOOST_TEST_REQUIRE(!r->getBeginTime().is_not_a_date_time());
        pt::ptime example = pt::ptime(gr::date(2021,4,29),pt::hours(19)+pt::minutes(25));
        r->endRent(example);
        BOOST_TEST(r->getEndTime() == example);
        delete r;
}

    BOOST_AUTO_TEST_CASE(EndRentTestSetCurrentTime) {
        RentPtr r = new Rent(testId, testaddress1, testaddress2, test);
        BOOST_TEST_REQUIRE(!r->getBeginTime().is_not_a_date_time());
        r->endRent(pt::not_a_date_time);
        BOOST_TEST(r->getEndTime() == pt::second_clock::local_time());
        delete r;
}


    BOOST_AUTO_TEST_CASE(EndRentTestSetGivenEndTimeAfterBeginTime) {
        RentPtr r = new Rent(testId, testaddress1, testaddress2, test);
        pt::ptime example = pt::ptime(gr::date(2022,3,9),pt::hours(9)+pt::minutes(25));
        r->endRent(example);
        BOOST_TEST(r->getEndTime() > r->getBeginTime());
        delete r;
}

    BOOST_AUTO_TEST_CASE(EndRentTestSetGivenEndTimeEqualsBeginTime) {
        Rent *r = new Rent(testId, testaddress1, testaddress2, test);
        pt::ptime example = test;
        r->endRent(example);
        BOOST_TEST(r->getEndTime() == r->getBeginTime());
        delete r;
}

    BOOST_AUTO_TEST_CASE(EndRentTestSetGivenEndTimeBeforeBeginTime) {
        RentPtr r = new Rent(testId, testaddress1, testaddress2, test);
        pt::ptime example = pt::ptime(gr::date(2020,3,9),pt::hours(9)+pt::minutes(25));
        r->endRent(example);
        BOOST_TEST(r->getEndTime() == r->getBeginTime());
        delete r;
}

    BOOST_AUTO_TEST_CASE(RentDaysTestRentNotEnded) {
        RentPtr r = new Rent(testId, testaddress1, testaddress2, test);
        BOOST_TEST(r->getRentDays() == 0);
        delete r;


}
    BOOST_AUTO_TEST_CASE(RentDaysTestRentEndedWithinMinute) {
        Rent *r = new Rent(testId, testaddress1, testaddress2, test);
        pt::ptime example = pt::ptime(gr::date(2021,4,5), pt::hours(9)+pt::minutes(26));
        r->endRent(example);
        BOOST_TEST(r->getRentDays() == 0);
        delete r;
}

    BOOST_AUTO_TEST_CASE(RentDaysTestRentEndedAfter1m) {
        RentPtr r = new Rent(testId, testaddress1, testaddress2, test);
        pt::ptime example = pt::ptime(gr::date(2021,4,5), pt::hours(9)+pt::minutes(27));
        r->endRent(example);
        BOOST_TEST(r->getRentDays() > 0);
        delete r;
}

    BOOST_AUTO_TEST_CASE(RentDaysTestRentEndedAfter23h59m) {
        RentPtr r = new Rent(testId, testaddress1, testaddress2, test);
        pt::ptime example = pt::ptime(gr::date(2021,4,6), pt::hours(9)+pt::minutes(24));
        r->endRent(example);
        BOOST_TEST(r->getRentDays() == 1);
        delete r;
}

    BOOST_AUTO_TEST_CASE(RentDaysTestRentEndedAfter24h0m) {
        RentPtr r = new Rent(testId, testaddress1, testaddress2, test);
        pt::ptime example = pt::ptime(gr::date(2021,4,6), pt::hours(9)+pt::minutes(25));
        r->endRent(example);
        BOOST_TEST(r->getRentDays() == 2);
        delete r;
}

    BOOST_AUTO_TEST_CASE(RentDaysTestRentTryEndRentAlreadyEnded) {
        RentPtr r = new Rent(testId, testaddress1, testaddress2, test);
        pt::ptime example = pt::ptime(gr::date(2021,4,6), pt::hours(10)+pt::minutes(27));
        r->endRent(example);
        pt::ptime example2 = pt::ptime(gr::date(2025,4,6), pt::hours(10)+pt::minutes(27));
        r->endRent(example2);
        BOOST_TEST(example == r->getEndTime());
        delete r;

}


    BOOST_AUTO_TEST_CASE(RentCostTestRentDaysis0) {
        Rent r(testId, testaddress1, testaddress2, test);
        pt::ptime then = pt::ptime(gr::date(2021,3,9),pt::hours(9)+pt::minutes(25));
        r.endRent(then);
        BOOST_TEST(r.getRentCost() == 0);

}

    BOOST_AUTO_TEST_CASE(RentCostTestRentIsPositive) {
        RentPtr r2 = new Rent(testId, testaddress1, testaddress2, test);
        pt::ptime theno = pt::ptime(gr::date(2021,5,11),pt::hours(9)+pt::minutes(25));
        r2->endRent(theno);
        BOOST_TEST(r2->getRentCost() > 0);
        delete r2;


}
    BOOST_AUTO_TEST_CASE(RentCostTestRentCostIsPermanentWhenVehiclePriceChanged) {
        Rent r(testId, testaddress1, testaddress2, test);
        pt::ptime then = pt::ptime(gr::date(2021,4,9),pt::hours(9)+pt::minutes(25));
        r.endRent(then);
        unsigned int cost = r.getRentCost();
        testaddress2->setBasePrice(1);
        BOOST_TEST(r.getRentCost() == cost);
}



BOOST_AUTO_TEST_SUITE_END()


