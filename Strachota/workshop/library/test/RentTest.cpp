#include <boost/test/unit_test.hpp>
#include "model/Rent.h"
#include "typedefs.h"
#include <memory>
#include <functional>
#include "model/Bronze.h"
#include "model/Default.h"
#include "model/Silver.h"
#include "model/Gold.h"
#include "model/Diamond.h"

struct TestSuiteRentFixture {
    const unsigned int testId = 1;
    ClientPtr testaddress1 = std::make_shared<Client>("Piotr", "Strachota", "420", testaddress3, testClientTypeBronze);
    ClientTypePtr testClientTypeGold = std::make_shared<Gold>();
    ClientTypePtr testClientTypeDiamond = std::make_shared<Diamond>();
    //ClientPtr testClient2 = std::make_shared<Client>("Piotr", "Strachota", "420", nullptr, testClientTypeSilver);
    ClientPtr testClient3 = std::make_shared<Client>("Piotr", "Strachota", "420", nullptr, testClientTypeGold);
    ClientPtr testClient4 = std::make_shared<Client>("Piotr", "Strachota", "420", nullptr, testClientTypeDiamond);
    ClientTypePtr testClientTypeSilver = std::make_shared<Silver>();
    ClientPtr testClient2 = std::make_shared<Client>("Piotr", "Strachota", "420", nullptr, testClientTypeSilver);
    VehiclePtr testaddress2 = std::make_shared<Vehicle>("US3333", 345);
    AddressPtr testaddress3 = std::make_shared<Address>("London", "Rue Morgue", "13");
    RentPtr r;
    pt::ptime test = pt::ptime(gr::date(2021,4,5), pt::hours(9)+pt::minutes(25));
    ClientTypePtr testClientTypeBronze = std::make_shared<Bronze>();
    //ClientTypePtr testClientTypeSilver = std::make_shared<Silver>();


    TestSuiteRentFixture() {

        //testaddress3 = std::make_shared<Address>("London", "Rue Morgue", "13");
        //testaddress1 = std::make_shared<Client>("Piotr", "Strachota", "420", testaddress3, testClientTypeBronze);
        //testaddress2 = std::make_shared<Vehicle>("US3333", 345);
       // testClientTypeBronze = std::make_shared<Bronze>();
    }

    ~TestSuiteRentFixture() {
    }

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRent, TestSuiteRentFixture)

    BOOST_AUTO_TEST_CASE(ParameterConstrutorTest) {

        RentPtr r = std::make_shared<Rent>(testId, testaddress1, testaddress2, test);
        BOOST_TEST(testId == r->getId());
        //BOOST_TEST(r == testaddress1->getRent(0));
        BOOST_TEST(testaddress1 == r->getClient());
        BOOST_TEST(testaddress2 == r->getVehicle());
        BOOST_TEST(test == r->getBeginTime());
    }

    BOOST_AUTO_TEST_CASE(ParameterConstrutorTestDefaultBeginTime) {

        RentPtr r = std::make_shared<Rent>(testId, testaddress1, testaddress2, pt::not_a_date_time);

        pt::ptime now = pt::second_clock::local_time(); //hope this takes no longer than 59 secs...
        BOOST_TEST_REQUIRE(!r->getBeginTime().is_not_a_date_time()); //if this isn't met, the next check doesn't make sense...
        pt::time_period skew = pt::time_period(r->getBeginTime(), now);
        BOOST_TEST((skew.length().hours()==0 && skew.length().minutes()==0));

    }

    BOOST_AUTO_TEST_CASE(EndRentTestBasic) {

        RentPtr r = std::make_shared<Rent>(testId, testaddress1, testaddress2, test);
        BOOST_TEST_REQUIRE(!r->getBeginTime().is_not_a_date_time());
        pt::ptime example = pt::ptime(gr::date(2021,4,29),pt::hours(19)+pt::minutes(25));
        r->endRent(example);
        BOOST_TEST(r->getEndTime() == example);

}

    BOOST_AUTO_TEST_CASE(EndRentTestSetCurrentTime) {
        RentPtr r = std::make_shared<Rent>(testId, testaddress1, testaddress2, test);
        BOOST_TEST_REQUIRE(!r->getBeginTime().is_not_a_date_time());
        r->endRent(pt::not_a_date_time);
        BOOST_TEST(r->getEndTime() == pt::second_clock::local_time());

}


    BOOST_AUTO_TEST_CASE(EndRentTestSetGivenEndTimeAfterBeginTime) {
        RentPtr r = std::make_shared<Rent>(testId, testaddress1, testaddress2, test);
        pt::ptime example = pt::ptime(gr::date(2022,3,9),pt::hours(9)+pt::minutes(25));
        r->endRent(example);
        BOOST_TEST(r->getEndTime() > r->getBeginTime());

}

    BOOST_AUTO_TEST_CASE(EndRentTestSetGivenEndTimeEqualsBeginTime) {
        RentPtr r = std::make_shared<Rent>(testId, testaddress1, testaddress2, test);
        pt::ptime example = test;
        r->endRent(example);
        BOOST_TEST(r->getEndTime() == r->getBeginTime());

}

    BOOST_AUTO_TEST_CASE(EndRentTestSetGivenEndTimeBeforeBeginTime) {
        RentPtr r = std::make_shared<Rent>(testId, testaddress1, testaddress2, test);
        pt::ptime example = pt::ptime(gr::date(2020,3,9),pt::hours(9)+pt::minutes(25));
        r->endRent(example);
        BOOST_TEST(r->getEndTime() == r->getBeginTime());

}

    BOOST_AUTO_TEST_CASE(RentDaysTestRentNotEnded) {
        RentPtr r = std::make_shared<Rent>(testId, testaddress1, testaddress2, test);
        BOOST_TEST(r->getRentDays() == 0);



}
    BOOST_AUTO_TEST_CASE(RentDaysTestRentEndedWithinMinute) {
        RentPtr r = std::make_shared<Rent>(testId, testaddress1, testaddress2, test);
        pt::ptime example = pt::ptime(gr::date(2021,4,5), pt::hours(9)+pt::minutes(26));
        r->endRent(example);
        BOOST_TEST(r->getRentDays() == 0);

}

    BOOST_AUTO_TEST_CASE(RentDaysTestRentEndedAfter1m) {
        RentPtr r = std::make_shared<Rent>(testId, testaddress1, testaddress2, test);
        pt::ptime example = pt::ptime(gr::date(2021,4,5), pt::hours(9)+pt::minutes(27));
        r->endRent(example);
        BOOST_TEST(r->getRentDays() > 0);

}

    BOOST_AUTO_TEST_CASE(RentDaysTestRentEndedAfter23h59m) {
        RentPtr r = std::make_shared<Rent>(testId, testaddress1, testaddress2, test);
        pt::ptime example = pt::ptime(gr::date(2021,4,6), pt::hours(9)+pt::minutes(24));
        r->endRent(example);
        BOOST_TEST(r->getRentDays() == 1);

}

    BOOST_AUTO_TEST_CASE(RentDaysTestRentEndedAfter24h0m) {
        RentPtr r = std::make_shared<Rent>(testId, testaddress1, testaddress2, test);
        pt::ptime example = pt::ptime(gr::date(2021,4,6), pt::hours(9)+pt::minutes(25));
        r->endRent(example);

        //testaddress1->getMaxVehicles() == 4;
        //BOOST_TEST(testaddress1->getMaxVehicles() == 4);
        //BOOST_TEST(testClientTypeBronze->applyDiscount(100) == 42);
        BOOST_TEST(r->getRentDays() == 2);
        //BOOST_TEST(r->getRentCost() == );

}

    BOOST_AUTO_TEST_CASE(RentDaysTestRentTryEndRentAlreadyEnded) {
        RentPtr r = std::make_shared<Rent>(testId, testaddress1, testaddress2, test);
        pt::ptime example = pt::ptime(gr::date(2021,4,6), pt::hours(10)+pt::minutes(27));
        r->endRent(example);
        pt::ptime example2 = pt::ptime(gr::date(2025,4,6), pt::hours(10)+pt::minutes(27));
        r->endRent(example2);
        BOOST_TEST(example == r->getEndTime());


}


    BOOST_AUTO_TEST_CASE(RentCostTestRentDaysis0) {
        RentPtr r = std::make_shared<Rent>(testId, testaddress1, testaddress2, test);
        pt::ptime then = pt::ptime(gr::date(2021,3,9),pt::hours(9)+pt::minutes(25));
        r->endRent(then);
        //BOOST_TEST(testaddress1->applyDiscount(100)) == 42;
        BOOST_TEST(r->getRentCost() == 0);

}


    BOOST_AUTO_TEST_CASE(RentCostTestRentIsPositive) {
        RentPtr r2 = std::make_shared<Rent>(testId, testaddress1, testaddress2, test);
        pt::ptime theno = pt::ptime(gr::date(2021,5,11),pt::hours(9)+pt::minutes(25));
        r2->endRent(theno);
        BOOST_TEST(r2->getRentCost() > 0);



}
    BOOST_AUTO_TEST_CASE(RentCostTestRentCostIsPermanentWhenVehiclePriceChanged) {
        RentPtr r = std::make_shared<Rent>(testId, testaddress1, testaddress2, test);
        pt::ptime then = pt::ptime(gr::date(2021,4,9),pt::hours(9)+pt::minutes(25));
        r->endRent(then);
        unsigned int cost = r->getRentCost();
        testaddress2->setBasePrice(1);
        BOOST_TEST(r->getRentCost() == cost);
}

    BOOST_AUTO_TEST_CASE(BronzeClientTypeTest) {
        RentPtr r = std::make_shared<Rent>(testId, testaddress1, testaddress2, test);
        BOOST_TEST(testaddress1->getMaxVehicles() == 2);
        BOOST_TEST(testaddress1->applyDiscount(100) == 97);
}

    BOOST_AUTO_TEST_CASE(SilverClientTypeTest) {
       // ClientTypePtr testClientTypeSilver = std::make_shared<Silver>();
        //ClientPtr testClient2 = std::make_shared<Client>("Piotr", "Strachota", "420", nullptr, testClientTypeSilver);
        RentPtr r = std::make_shared<Rent>(testId, testClient2, testaddress2, test);
        BOOST_TEST(testClient2->getMaxVehicles() == 3);
        BOOST_TEST(testClient2->applyDiscount(100) == 94);
}

    BOOST_AUTO_TEST_CASE(GoldClientTypeTest) {
        RentPtr r = std::make_shared<Rent>(testId, testClient3, testaddress2, test);
        BOOST_TEST(testClient3->getMaxVehicles() == 4);
        BOOST_TEST(testClient3->applyDiscount(100) == (100*0.95));
}

    BOOST_AUTO_TEST_CASE(DiamondClientTypeTest) {
        RentPtr r = std::make_shared<Rent>(testId, testClient4, testaddress2, test);
        BOOST_TEST(testClient4->getMaxVehicles() == 10);
        BOOST_TEST(testClient4->applyDiscount(100) == (100*0.9));
}


BOOST_AUTO_TEST_SUITE_END()


