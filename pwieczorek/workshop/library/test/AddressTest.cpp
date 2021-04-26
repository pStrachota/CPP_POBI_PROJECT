#include <boost/test/unit_test.hpp>
#include "model/Address.h"

BOOST_AUTO_TEST_SUITE(TestSuiteAddress)


    BOOST_AUTO_TEST_CASE(ConstructorTests)
    {
        Address a1("London","Baker","7");

        BOOST_TEST(a1.getCity() == "London");
        BOOST_TEST(a1.getStreet() == "Baker");
        BOOST_TEST(a1.getNumber() == "7");

    }

BOOST_AUTO_TEST_SUITE_END()
