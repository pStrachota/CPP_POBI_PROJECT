#include <boost/test/unit_test.hpp>
#include <boost/exception/all.hpp>
#include "model/Client.h"
#include "model/Address.h"
#include "typedefs.h"
#include <memory>
#include <functional>
#include "model/Student.h"
#include "model/universityEmployee.h"
#include "model/Outsider.h"



struct TestSuiteClientFixture {
    const std::string testFirstName = "Piotr";
    const std::string testLastName = "Strachota";
    const std::string testPersonalID = "0123456789";
    AddressPtr testaddress1;
    AddressPtr testaddress2;
    ClientTypePtr testClientTypeStudent;
    ClientTypePtr testClientTypeUniversityEmployee;
    ClientTypePtr testClientTypeOutsider;


    TestSuiteClientFixture() {
        testaddress1 = std::make_shared<Address>("London", "Accacia Avenue", "22");
        testaddress2 = std::make_shared<Address>("London", "Rue Morgue", "13");
        testClientTypeStudent = std::make_shared<Student>();
        testClientTypeUniversityEmployee = std::make_shared<universityEmployee>();
        testClientTypeOutsider = std::make_shared<Outsider>();

    }

    ~TestSuiteClientFixture() {

    }

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClient, TestSuiteClientFixture)

    BOOST_AUTO_TEST_CASE(ParameterConstrutorTest) {

        ClientPtr c = std::make_shared<Client>(testFirstName, testLastName, testPersonalID, testaddress1, testClientTypeStudent);
        BOOST_CHECK_EQUAL(testFirstName, c->getName());
        BOOST_CHECK_EQUAL(testLastName, c->getSurname());
        BOOST_CHECK_EQUAL(testaddress1, c->getAddress());
        BOOST_CHECK_EQUAL(c->getMaxItems(), testClientTypeStudent->getMaxItems());
        BOOST_CHECK_EQUAL(c->getMaxDays(), testClientTypeStudent->getMaxDays());
        BOOST_CHECK_EQUAL(c->getPenalty(), testClientTypeStudent->getPenalty());
        BOOST_CHECK_EQUAL(testClientTypeStudent->getTypeInfo(), "STUDENT");
    }


    BOOST_AUTO_TEST_CASE(StudentClientTypeTest) {
        ClientPtr c = std::make_shared<Client>(testFirstName, testLastName, testPersonalID, testaddress1, testClientTypeStudent);
        BOOST_CHECK_EQUAL(c->getMaxItems(), 2);
        BOOST_CHECK_EQUAL(c->getMaxDays(), 20);
    }

    BOOST_AUTO_TEST_CASE(universityEmployeeClientTypeTest) {
        ClientPtr c = std::make_shared<Client>(testFirstName, testLastName, testPersonalID, testaddress1, testClientTypeUniversityEmployee);
        BOOST_CHECK_EQUAL(c->getMaxItems(), 3);
        BOOST_CHECK_EQUAL(c->getMaxDays(), 30);

    }
    BOOST_AUTO_TEST_CASE(OutsiderClientTypeTest) {
        ClientPtr c = std::make_shared<Client>(testFirstName, testLastName, testPersonalID, testaddress1, testClientTypeOutsider);
        BOOST_CHECK_EQUAL(c->getMaxItems(), 1);
        BOOST_CHECK_EQUAL(c->getMaxDays(), 10);
    }




    BOOST_AUTO_TEST_CASE(SetFirstNamePositiveTest) {
        ClientPtr c = std::make_shared<Client>(testFirstName, testLastName, testPersonalID, testaddress1, testClientTypeStudent);
        c->setName("Piotr");
        BOOST_TEST(c->getName() == "Piotr");
    }

    BOOST_AUTO_TEST_CASE(SetFirstNameNegativeTest) {
        ClientPtr c = std::make_shared<Client>(testFirstName, testLastName, testPersonalID, testaddress1, testClientTypeStudent);
        BOOST_REQUIRE_THROW(    c->setName(""), std::logic_error);
        BOOST_TEST(c->getName() == testFirstName);
    }
    BOOST_AUTO_TEST_CASE(SetLastNamePositiveTest) {
        ClientPtr c = std::make_shared<Client>(testFirstName, testLastName, testPersonalID, testaddress1, testClientTypeStudent);
        c->setSurname("Strachota");
        BOOST_TEST(c->getSurname() == "Strachota");
    }
    BOOST_AUTO_TEST_CASE(SetLastNameNegativeTest) {
        ClientPtr c = std::make_shared<Client>(testFirstName, testLastName, testPersonalID, testaddress1, testClientTypeStudent);
        BOOST_REQUIRE_THROW(c->setSurname(""), std::logic_error);
        BOOST_TEST(c->getSurname() == testLastName);
    }
    BOOST_AUTO_TEST_CASE(SetAddressPositiveTest) {
        ClientPtr c = std::make_shared<Client>(testFirstName, testLastName, testPersonalID, testaddress1, testClientTypeStudent);
        c->setAddress(testaddress2);
        BOOST_TEST(c->getAddress() == testaddress2);
    }
    BOOST_AUTO_TEST_CASE(SetAddressNegativeTest) {
        ClientPtr c = std::make_shared<Client>(testFirstName, testLastName, testPersonalID, testaddress1, testClientTypeStudent);
        BOOST_REQUIRE_THROW(c->setAddress(nullptr), std::logic_error);
        BOOST_TEST(c->getAddress() == testaddress1);
    }
    BOOST_AUTO_TEST_CASE(ClientTypeExceptionsTest) {
        ClientPtr c = std::make_shared<Client>(testFirstName, testLastName, testPersonalID, testaddress1, testClientTypeStudent);
        BOOST_REQUIRE_THROW(c->setClientType(nullptr), std::logic_error);
    }

    /*BOOST_AUTO_TEST_CASE(ClientFunctorIdTest) {
        ClientPtr c = std::make_shared<Client>(testFirstName, testLastName, testPersonalID, testaddress1, testClientTypeStudent);
        IdPredicate predicate(testPersonalID);
        bool accept = predicate(c);
        BOOST_CHECK_EQUAL(accept, true);
    }
    BOOST_AUTO_TEST_CASE(ClientFirstNameFunctorTest) {
        ClientPtr c = std::make_shared<Client>(testFirstName, testLastName, testPersonalID, testaddress1, testClientTypeStudent);
        std::regex tango("(Piot)(.*)");
        FirstNamePredicate predicate(tango);
        bool accept = predicate(c);
        BOOST_CHECK_EQUAL(accept, true);
    }*/



BOOST_AUTO_TEST_SUITE_END()







