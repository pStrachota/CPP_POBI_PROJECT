#include <boost/test/unit_test.hpp>
#include "model/Client.h"

struct TestSuiteClientFixture {
    const std::string testFirstName = "Jon";
    const std::string testLastName = "Arbuckle";
    const std::string testPersonalID = "0123456789";
    Address *testaddress1;
    Address *testaddress2;

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

    BOOST_AUTO_TEST_CASE(ParameterConstrutorTest)
    {

        Client c(testFirstName, testLastName, testPersonalID, testaddress1);
        BOOST_TEST(testFirstName == c.getFirstName());
        BOOST_TEST(testLastName == c.getLastName());
        BOOST_TEST(testPersonalID == c.getPersonalID());
        BOOST_TEST(testaddress1 == c.getAddress());
    }

    BOOST_AUTO_TEST_CASE(FirstNameSetterPositiveTests)
    {
        Client c(testFirstName, testLastName, testPersonalID, testaddress1);
        c.setFirstName("Alex");
        BOOST_TEST(c.getFirstName() == "Alex");

    }

    BOOST_AUTO_TEST_CASE(LastNameSetterPositiveTests)
    {
        Client c(testFirstName, testLastName, testPersonalID, testaddress1);
        c.setLastName("Nowak");
        BOOST_TEST(c.getLastName() == "Nowak");
    }

    BOOST_AUTO_TEST_CASE(AddressSetterPositiveTests)
    {
        Client c(testFirstName, testLastName, testPersonalID, testaddress1);
        c.setAddress(testaddress2);
        BOOST_TEST(c.getAddress() == testaddress2);
    }

    BOOST_AUTO_TEST_CASE(AddressSetterFailedTests)
    {
        Client c(testFirstName, testLastName, testPersonalID, testaddress1);
        c.setAddress(nullptr);
        BOOST_TEST(c.getAddress() == testaddress1);
    }

BOOST_AUTO_TEST_SUITE_END()


//korzystamy z fixture
/*
BOOST_AUTO_TEST_SUITE(TestSuiteClient)


    BOOST_AUTO_TEST_CASE(ConstructorTests)
    {
        Address a1("London","Baker","7");
        Address *a_wsk = &a1;

        Client cl("Jan","Kowalski","007", a_wsk);

        BOOST_TEST(cl.getFirstName() == "Jan");
        BOOST_TEST(cl.getLastName() == "Kowalski");
        BOOST_TEST(cl.getPersonalID() == "007");
        BOOST_TEST(cl.getAddress() == a_wsk);

    }

    BOOST_AUTO_TEST_CASE(SettersTests)
    {
        Address a1("London","Baker","7");
        Address a2("London","Baker","7");
        Address *a_wsk = &a1;

        Client cl("Jan","Kowalski","007", a_wsk);

        cl.setFirstName("");
        BOOST_TEST(cl.getFirstName() == "Jan");

        cl.setFirstName("Pawel");
        BOOST_TEST(cl.getFirstName() == "Pawel");

        cl.setLastName("");
        BOOST_TEST(cl.getLastName() == "Kowalski");

        cl.setLastName("Nowak");
        BOOST_TEST(cl.getLastName() == "Nowak");
        a_wsk = &a2;
        cl.setAddress(a_wsk);
        BOOST_TEST(cl.getAddress() == a_wsk);


    }

BOOST_AUTO_TEST_SUITE_END()
 */