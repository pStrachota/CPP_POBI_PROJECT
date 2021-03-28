#include <boost/test/unit_test.hpp>
#include "model/Client.h"

BOOST_AUTO_TEST_SUITE(TestSuiteClient)

    BOOST_AUTO_TEST_CASE(ClientConstructorTests) {
        Client client("Piotr", "Strachota", "420");
        BOOST_TEST(client.getFirstName() == "Piotr");
        BOOST_TEST(client.getLastName() == "Strachota");
        BOOST_TEST(client.getPersonalID() == "420");
    }
    BOOST_AUTO_TEST_CASE(ClientSetterTests) {
        Client client("Piotr", "Strachota", "420");
        client.setFirstName("");
        BOOST_TEST(client.getFirstName() == "Piotr");
        client.setFirstName("Adam");
        BOOST_TEST(client.getFirstName() == "Adam");
        client.setLastName("");
        BOOST_TEST(client.getLastName() == "Strachota");
        client.setLastName("Makłowicz");
        BOOST_TEST(client.getLastName() == "Makłowicz");
}

BOOST_AUTO_TEST_SUITE_END()
