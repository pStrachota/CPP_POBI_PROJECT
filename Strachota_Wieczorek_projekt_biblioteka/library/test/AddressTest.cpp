#include <boost/test/unit_test.hpp>
#include "model/Address.h"
#include "typedefs.h"

BOOST_AUTO_TEST_SUITE(TestSuiteAddress)

    BOOST_AUTO_TEST_CASE(ParameterConstructorTests) {
        AddressPtr address = std::make_shared<Address>("Warszawa", "Kwiatowa", "200");
        BOOST_TEST(address->getCity() == "Warszawa");
        BOOST_TEST(address->getStreet() == "Kwiatowa");
        BOOST_TEST(address->getNumber() == "200");
    }

BOOST_AUTO_TEST_SUITE_END()
