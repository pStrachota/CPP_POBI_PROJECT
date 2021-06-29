#include <boost/test/unit_test.hpp>
#include "model/Client.h"
#include "model/Default.h"
#include "model/Silver.h"
#include "model/Bronze.h"
#include "model/Platinum.h"
#include "model/Diamond.h"
#include "model/Gold.h"

struct TestSuiteClientFixture {
    const std::string testFirstName = "Jon";
    const std::string testLastName = "Arbuckle";
    const std::string testPersonalID = "0123456789";
    AddressPtr testaddress1;
    AddressPtr testaddress2;
    ClientTypePtr CTdefault;
    ClientTypePtr CTsilver;
    ClientTypePtr CTbronze;
    ClientTypePtr CTplatinum;
    ClientTypePtr CTdiamond;
    ClientTypePtr CTgold;


    TestSuiteClientFixture() {
        testaddress1 = std::make_shared<Address>("London", "Accacia Avenue", "22");
        testaddress2 = std::make_shared<Address>("London", "Rue Morgue", "13");
        CTdefault = std::make_shared<Default>();
        CTsilver = std::make_shared<Silver>();
        CTbronze = std::make_shared<Bronze>();
        CTplatinum = std::make_shared<Platinum>();
        CTdiamond = std::make_shared<Diamond>();
        CTgold = std::make_shared<Gold>();
    }

    ~TestSuiteClientFixture() {

    }

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClient, TestSuiteClientFixture)

    BOOST_AUTO_TEST_CASE(ParameterConstrutorTest)
    {

        Client c(testFirstName, testLastName, testPersonalID, testaddress1,CTdefault);
        BOOST_TEST(testFirstName == c.getFirstName());
        BOOST_TEST(testLastName == c.getLastName());
        BOOST_TEST(testPersonalID == c.getPersonalID());
        BOOST_TEST(testaddress1 == c.getAddress());
    }

    BOOST_AUTO_TEST_CASE(FirstNameSetterPositiveTests)
    {
        Client c(testFirstName, testLastName, testPersonalID, testaddress1,CTdefault);
        c.setFirstName("Alex");
        BOOST_TEST(c.getFirstName() == "Alex");

    }

    BOOST_AUTO_TEST_CASE(LastNameSetterPositiveTests)
    {
        Client c(testFirstName, testLastName, testPersonalID, testaddress1,CTdefault);
        c.setLastName("Nowak");
        BOOST_TEST(c.getLastName() == "Nowak");
    }

    BOOST_AUTO_TEST_CASE(AddressSetterPositiveTests)
    {
        Client c(testFirstName, testLastName, testPersonalID, testaddress1,CTdefault);
        c.setAddress(testaddress2);
        BOOST_TEST(c.getAddress() == testaddress2);
    }

    BOOST_AUTO_TEST_CASE(AddressSetterFailedTests)
    {
        Client c(testFirstName, testLastName, testPersonalID, testaddress1,CTdefault);
        c.setAddress(nullptr);
        BOOST_TEST(c.getAddress() == testaddress1);
    }

    BOOST_AUTO_TEST_CASE(DefaultClientTest)
    {
        Client c(testFirstName, testLastName, testPersonalID, testaddress1,CTdefault);
        BOOST_TEST(c.getMaxVehicles() == 1);
        BOOST_TEST(c.applyDiscount(100) == 0);
    }

    BOOST_AUTO_TEST_CASE(BronzeClientTest)
    {
        Client c(testFirstName, testLastName, testPersonalID, testaddress1,CTbronze);
        BOOST_TEST(c.getMaxVehicles() == 2);
        BOOST_TEST(c.applyDiscount(100) == 3);
    }

    BOOST_AUTO_TEST_CASE(SilverClientTest)
    {
        Client c(testFirstName, testLastName, testPersonalID, testaddress1,CTsilver);
        BOOST_TEST(c.getMaxVehicles() == 3);
        BOOST_TEST(c.applyDiscount(100) == 6);
    }

    BOOST_AUTO_TEST_CASE(GoldClientTest)
    {
        Client c(testFirstName, testLastName, testPersonalID, testaddress1,CTgold);
        BOOST_TEST(c.getMaxVehicles() == 4);
        BOOST_TEST(c.applyDiscount(100) == 5);
    }

    BOOST_AUTO_TEST_CASE(PlatinumClientTest)
    {
        Client c(testFirstName, testLastName, testPersonalID, testaddress1,CTplatinum);
        BOOST_TEST(c.getMaxVehicles() == 5);
        BOOST_TEST(c.applyDiscount(100) == 10);
    }

    BOOST_AUTO_TEST_CASE(DiamondClientTest)
    {
        Client c(testFirstName, testLastName, testPersonalID, testaddress1,CTdiamond);
        BOOST_TEST(c.getMaxVehicles() == 10);
        BOOST_TEST(c.applyDiscount(100) == 10);
        BOOST_TEST(c.applyDiscount(200) == 40);
        BOOST_TEST(c.applyDiscount(300) == 90);
        BOOST_TEST(c.applyDiscount(600) == 240);
    }

BOOST_AUTO_TEST_SUITE_END()

