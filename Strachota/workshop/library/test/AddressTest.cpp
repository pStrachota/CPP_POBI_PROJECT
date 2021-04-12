#include <boost/test/unit_test.hpp>
#include "model/Address.h"

BOOST_AUTO_TEST_SUITE(TestSuiteAddress)

    BOOST_AUTO_TEST_CASE(ParameterConstructorTests) {
        Address address("Wicie", "Fajna", "420");
        BOOST_TEST(address.getCity() == "Wicie");
        BOOST_TEST(address.getStreet() == "Fajna");
        BOOST_TEST(address.getNumber() == "420");
    }

BOOST_AUTO_TEST_SUITE_END()
