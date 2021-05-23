#include <boost/test/unit_test.hpp>
#include "model/Rent.h"
#include "model/Client.h"
#include "typedefs.h"
#include "model/Bicycle.h"
#include "model/Address.h"
#include <memory>
#include <functional>
#include "model/Bronze.h"
#include "model/Silver.h"
#include "model/Gold.h"
#include "model/Diamond.h"



struct TestSuiteRentFixture {
    AddressPtr testAddress;
    ClientTypePtr testClientTypeGold;
    ClientTypePtr testClientTypeBronze;
    ClientTypePtr testClientTypeDiamond;
    ClientPtr testClient;
    ClientPtr testClient3;
    ClientPtr testClient4;
    ClientTypePtr testClientTypeSilver;
    ClientPtr testClient2;
    VehiclePtr testBicycle;
    pt::ptime test;


    TestSuiteRentFixture() {

        testClientTypeBronze = std::make_shared<Bronze>();
        testClientTypeDiamond = std::make_shared<Diamond>();
        testClientTypeSilver = std::make_shared<Silver>();
        testClientTypeGold = std::make_shared<Gold>();
        testAddress = std::make_shared<Address>("London", "Rue Morgue", "13");
        testClient = std::make_shared<Client>("Piotr", "Strachota", "420", testAddress, testClientTypeBronze);
        testBicycle = std::make_shared<Bicycle>("US3333", 345);
        testClient2 = std::make_shared<Client>("Piotr", "Strachota", "420", testAddress, testClientTypeSilver);
        testClient3 = std::make_shared<Client>("Piotr", "Strachota", "420", testAddress, testClientTypeGold);
        testClient4 = std::make_shared<Client>("Piotr", "Strachota", "420", testAddress, testClientTypeDiamond);
        test = pt::ptime(gr::date(2021,4,5), pt::hours(9)+pt::minutes(25));
    }

    ~TestSuiteRentFixture() {
    }

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRent, TestSuiteRentFixture)

    BOOST_AUTO_TEST_CASE(ParameterConstrutorTest) {

        RentPtr r = std::make_shared<Rent>(testClient, testBicycle, test);
        BOOST_TEST(testClient == r->getClient());
        BOOST_TEST(testBicycle == r->getVehicle());
        BOOST_TEST(test == r->getBeginTime());
    }

    BOOST_AUTO_TEST_CASE(ParameterConstrutorTestDefaultBeginTime) {

        RentPtr r = std::make_shared<Rent>(testClient, testBicycle, pt::not_a_date_time);
        pt::ptime now = pt::second_clock::local_time(); //hope this takes no longer than 59 secs...
        BOOST_TEST_REQUIRE(!r->getBeginTime().is_not_a_date_time()); //if this isn't met, the next check doesn't make sense...
        pt::time_period skew = pt::time_period(r->getBeginTime(), now);
        BOOST_TEST((skew.length().hours()==0 && skew.length().minutes()==0));

    }

    BOOST_AUTO_TEST_CASE(EndRentTestBasic) {

        RentPtr r = std::make_shared<Rent>(testClient, testBicycle, test);
        BOOST_TEST_REQUIRE(!r->getBeginTime().is_not_a_date_time());
        pt::ptime example = pt::ptime(gr::date(2021,4,29),pt::hours(19)+pt::minutes(25));
        r->endRent(example);
        BOOST_TEST(r->getEndTime() == example);
}

    BOOST_AUTO_TEST_CASE(EndRentTestSetCurrentTime) {
        RentPtr r = std::make_shared<Rent>(testClient, testBicycle, test);
        BOOST_TEST_REQUIRE(!r->getBeginTime().is_not_a_date_time());
        r->endRent(pt::not_a_date_time);
        BOOST_TEST(r->getEndTime() == pt::second_clock::local_time());
}

    BOOST_AUTO_TEST_CASE(EndRentTestSetGivenEndTimeAfterBeginTime) {
        RentPtr r = std::make_shared<Rent>(testClient, testBicycle, test);
        pt::ptime example = pt::ptime(gr::date(2022,3,9),pt::hours(9)+pt::minutes(25));
        r->endRent(example);
        BOOST_TEST(r->getEndTime() > r->getBeginTime());

}

    BOOST_AUTO_TEST_CASE(EndRentTestSetGivenEndTimeEqualsBeginTime) {
        RentPtr r = std::make_shared<Rent>(testClient, testBicycle, test);
        pt::ptime example = test;
        r->endRent(example);
        BOOST_TEST(r->getEndTime() == r->getBeginTime());

}

    BOOST_AUTO_TEST_CASE(EndRentTestSetGivenEndTimeBeforeBeginTime) {
        RentPtr r = std::make_shared<Rent>(testClient, testBicycle, test);
        pt::ptime example = pt::ptime(gr::date(2020,3,9),pt::hours(9)+pt::minutes(25));
        r->endRent(example);
        BOOST_TEST(r->getEndTime() == r->getBeginTime());

}

    BOOST_AUTO_TEST_CASE(RentDaysTestRentNotEnded) {
        RentPtr r = std::make_shared<Rent>(testClient, testBicycle, test);
        BOOST_TEST(r->getRentDays() == 0);

}
    BOOST_AUTO_TEST_CASE(RentDaysTestRentEndedWithinMinute) {
        RentPtr r = std::make_shared<Rent>(testClient, testBicycle, test);
        pt::ptime example = pt::ptime(gr::date(2021,4,5), pt::hours(9)+pt::minutes(26));
        r->endRent(example);
        BOOST_TEST(r->getRentDays() == 0);

}

    BOOST_AUTO_TEST_CASE(RentDaysTestRentEndedAfter1m) {
        RentPtr r = std::make_shared<Rent>(testClient, testBicycle, test);
        pt::ptime example = pt::ptime(gr::date(2021,4,5), pt::hours(9)+pt::minutes(27));
        r->endRent(example);
        BOOST_TEST(r->getRentDays() > 0);

}

    BOOST_AUTO_TEST_CASE(RentDaysTestRentEndedAfter23h59m) {
        RentPtr r = std::make_shared<Rent>(testClient, testBicycle, test);
        pt::ptime example = pt::ptime(gr::date(2021,4,6), pt::hours(9)+pt::minutes(24));
        r->endRent(example);
        BOOST_TEST(r->getRentDays() == 1);

}

    BOOST_AUTO_TEST_CASE(RentDaysTestRentEndedAfter24h0m) {
        RentPtr r = std::make_shared<Rent>(testClient, testBicycle, test);
        pt::ptime example = pt::ptime(gr::date(2021,4,6), pt::hours(9)+pt::minutes(25));
        r->endRent(example);
        BOOST_TEST(r->getRentDays() == 2);

}

    BOOST_AUTO_TEST_CASE(RentDaysTestRentTryEndRentAlreadyEnded) {
        RentPtr r = std::make_shared<Rent>(testClient, testBicycle, test);
        pt::ptime example = pt::ptime(gr::date(2021,4,6), pt::hours(10)+pt::minutes(27));
        r->endRent(example);
        pt::ptime example2 = pt::ptime(gr::date(2025,4,6), pt::hours(10)+pt::minutes(27));
        r->endRent(example2);
        BOOST_TEST(example == r->getEndTime());


}


    BOOST_AUTO_TEST_CASE(RentCostTestRentDaysis0) {
        RentPtr r = std::make_shared<Rent>(testClient, testBicycle, test);
        pt::ptime then = pt::ptime(gr::date(2021,3,9),pt::hours(9)+pt::minutes(25));
        r->endRent(then);
        BOOST_TEST(r->getRentCost() == 0);

}


    BOOST_AUTO_TEST_CASE(RentCostTestRentIsPositive) {
        RentPtr r2 = std::make_shared<Rent>(testClient, testBicycle, test);
        pt::ptime theno = pt::ptime(gr::date(2021,5,11),pt::hours(9)+pt::minutes(25));
        r2->endRent(theno);
        BOOST_TEST(r2->getRentCost() > 0);

}
    BOOST_AUTO_TEST_CASE(RentCostTestRentCostIsPermanentWhenVehiclePriceChanged) {
        RentPtr r = std::make_shared<Rent>(testClient, testBicycle, test);
        pt::ptime then = pt::ptime(gr::date(2021,4,9),pt::hours(9)+pt::minutes(25));
        r->endRent(then);
        unsigned int cost = r->getRentCost();
        testBicycle->setBasePrice(1);
        BOOST_TEST(r->getRentCost() == cost);
}

    BOOST_AUTO_TEST_CASE(BronzeClientTypeTest) {
        RentPtr r = std::make_shared<Rent>(testClient, testBicycle, test);
        BOOST_TEST(testClient->getMaxVehicles() == 2);
        BOOST_TEST(testClient->applyDiscount(100) == 97);
}

    BOOST_AUTO_TEST_CASE(SilverClientTypeTest) {
        RentPtr r = std::make_shared<Rent>(testClient2, testBicycle, test);
        BOOST_TEST(testClient2->getMaxVehicles() == 3);
        BOOST_TEST(testClient2->applyDiscount(100) == 94);
}

    BOOST_AUTO_TEST_CASE(GoldClientTypeTest) {
        RentPtr r = std::make_shared<Rent>(testClient3, testBicycle, test);
        BOOST_TEST(testClient3->getMaxVehicles() == 4);
        BOOST_TEST(testClient3->applyDiscount(100) == (100*0.95));
}

    BOOST_AUTO_TEST_CASE(DiamondClientTypeTest) {
        RentPtr r = std::make_shared<Rent>(testClient4, testBicycle, test);
        BOOST_TEST(testClient4->getMaxVehicles() == 10);
        BOOST_TEST(testClient4->applyDiscount(100) == (100*0.9));
}

    BOOST_AUTO_TEST_CASE(NullClientConstructorTest) {
        BOOST_REQUIRE_THROW(RentPtr r = std::make_shared<Rent>(nullptr, testBicycle, test), std::logic_error);
}

    BOOST_AUTO_TEST_CASE(NullVehicleConstructorTest) {
        BOOST_REQUIRE_THROW(RentPtr r = std::make_shared<Rent>(testClient, nullptr, test), std::logic_error);
}


BOOST_AUTO_TEST_SUITE_END()



