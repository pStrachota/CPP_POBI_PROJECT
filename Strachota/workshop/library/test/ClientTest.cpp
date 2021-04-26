#include <boost/test/unit_test.hpp>
#include "model/Client.h"


struct TestSuiteClientFixture {
    const std::string testFirstName = "Jon";
    const std::string testLastName = "Arbuckle";
    const std::string testPersonalID = "0123456789";
    AddressPtr testaddress1;
    AddressPtr testaddress2;

    TestSuiteClientFixture() {
        testaddress1 = new Address("London", "Accacia Avenue", "22");
        testaddress2 = new Address("London", "Rue Morgue", "13");
    }

    ~TestSuiteClientFixture() {
        delete testaddress1;
        delete testaddress2;
    }

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClient, TestSuiteClientFixture)

    BOOST_AUTO_TEST_CASE(ParameterConstrutorTest) {

        Client c(testFirstName, testLastName, testPersonalID, testaddress1);
        BOOST_TEST(testFirstName == c.getFirstName());
        BOOST_TEST(testLastName == c.getLastName());
        BOOST_TEST(testPersonalID == c.getPersonalId());
        BOOST_TEST(testaddress1 == c.getAddress());
    }

    BOOST_AUTO_TEST_CASE(SetFirstNamePositiveTest) {
        Client c(testFirstName, testLastName, testPersonalID, testaddress1);
        c.setFirstName("Piotr");
        BOOST_TEST(c.getFirstName() == "Piotr");
}

    BOOST_AUTO_TEST_CASE(SetFirstNameNegativeTest) {
        Client c(testFirstName, testLastName, testPersonalID, testaddress1);
        c.setFirstName("");
        BOOST_TEST(c.getFirstName() == testFirstName);
    }
    BOOST_AUTO_TEST_CASE(SetLastNamePositiveTest) {
        Client c(testFirstName, testLastName, testPersonalID, testaddress1);
        c.setLastName("Strachota");
        BOOST_TEST(c.getLastName() == "Strachota");
}
    BOOST_AUTO_TEST_CASE(SetLastNameNegativeTest) {
        Client c(testFirstName, testLastName, testPersonalID, testaddress1);
        c.setLastName("");
        BOOST_TEST(c.getLastName() == testLastName);
}
    BOOST_AUTO_TEST_CASE(SetAddressPositiveTest) {
        Client c(testFirstName, testLastName, testPersonalID, testaddress1);
        c.setAddress(testaddress2);
        BOOST_TEST(c.getAddress() == testaddress2);
    }
    BOOST_AUTO_TEST_CASE(SetAddressNegativeTest) {
        Client c(testFirstName, testLastName, testPersonalID, testaddress1);
        c.setAddress(nullptr);
        BOOST_TEST(c.getAddress() == testaddress1);
}

BOOST_AUTO_TEST_SUITE_END()


















/*
BOOST_AUTO_TEST_SUITE(TestSuiteClient)

    //Address *proba = new Address("Wicie", "fajna", "2013");
    Address *test;
    Address *test2;
    BOOST_AUTO_TEST_CASE(ClientConstructorTests) {
        Client client("Piotr", "Strachota", "420", test);
        BOOST_TEST(client.getFirstName() == "Piotr");
        BOOST_TEST(client.getLastName() == "Strachota");
        BOOST_TEST(client.getPersonalId() == "420");
        BOOST_TEST(client.getAddress() == test);
    }
    BOOST_AUTO_TEST_CASE(ClientSetterTests) {
        //Address *proba2 = new Address("Wilga", "tezfajna", "2015");
        Client client("Piotr", "Strachota", "420", test);
        client.setFirstName("");
        BOOST_TEST(client.getFirstName() == "Piotr");
        client.setFirstName("Adam");
        BOOST_TEST(client.getFirstName() == "Adam");
        client.setLastName("");
        BOOST_TEST(client.getLastName() == "Strachota");
        client.setLastName("Makłowicz");
        BOOST_TEST(client.getLastName() == "Makłowicz");
        client.setAddress(nullptr);
        BOOST_TEST(client.getAddress() == test);
        client.setAddress(test2);
        BOOST_TEST(client.getAddress() == test2);
}

BOOST_AUTO_TEST_SUITE_END()
*/