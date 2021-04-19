//
// Created by student
//

#include <boost/test/unit_test.hpp>
#include "model/Client.h"

BOOST_AUTO_TEST_SUITE(TestSuiteClient)
    /*
    BOOST_AUTO_TEST_CASE(AssertionsTests)
    {
        BOOST_TEST(1.0/3.0 == 0.333,boost::test_tools::tolerance(0.1));
        BOOST_TEST(true);
    }
    */

    BOOST_AUTO_TEST_CASE(ConstructorTests)
    {
        Client cl("Jan","Kowalski","007");

        BOOST_TEST(cl.getFirstName() == "Jan");
        BOOST_TEST(cl.getLastName() == "Kowalski");
        BOOST_TEST(cl.getPersonalID() == "007");
    }

    BOOST_AUTO_TEST_CASE(SettersTests)
    {
        Client cl("Jan","Kowalski","007");

        cl.setFirstName("");
        BOOST_TEST(cl.getFirstName() == "Jan");

        cl.setFirstName("Pawel");
        BOOST_TEST(cl.getFirstName() == "Pawel");

        cl.setLastName("");
        BOOST_TEST(cl.getLastName() == "Kowalski");

        cl.setLastName("Nowak");
        BOOST_TEST(cl.getLastName() == "Nowak");


    }

BOOST_AUTO_TEST_SUITE_END()