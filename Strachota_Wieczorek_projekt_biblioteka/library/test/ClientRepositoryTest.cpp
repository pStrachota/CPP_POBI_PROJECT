#include <boost/test/unit_test.hpp>
#include <repositories/ClientRepository.h>
#include "model/Student.h"
#include <memory>
#include <functional>
#include "model/Address.h"
#include "model/Client.h"


struct TestSuiteClientRepositoryFixture {
    const std::string testFirstName = "Jon";
    const std::string testLastName = "Arbuckle";
    const std::string testPersonalID = "0123456789";
    AddressPtr testaddress1;
    AddressPtr testaddress2;
    ClientTypePtr testClientTypeStudent;

    TestSuiteClientRepositoryFixture() {
        testClientTypeStudent = std::make_shared<Student>();
        testaddress1 = std::make_shared<Address>("London", "Accacia Avenue", "22");
        testaddress2 = std::make_shared<Address>("London", "Rue Morgue", "13");
    }

    ~TestSuiteClientRepositoryFixture() {

    }

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClientRepository, TestSuiteClientRepositoryFixture)

    BOOST_AUTO_TEST_CASE(AddClientPositivetest) {
        ClientPtr c = std::make_shared<Client>(testFirstName, testLastName, testPersonalID, testaddress1, testClientTypeStudent, nullptr);
        ClientRepository nie;
        nie.add(c);
        BOOST_TEST(nie.getObject(0) == c);
    }

    BOOST_AUTO_TEST_CASE(RemoveClientPositiveTest) {
        ClientPtr c = std::make_shared<Client>(testFirstName, testLastName, testPersonalID, testaddress1, testClientTypeStudent, nullptr);
        ClientPtr c2 = std::make_shared<Client>("Piotrus", "Strachota", "420", testaddress2, testClientTypeStudent, nullptr);
        ClientRepository nie;
        nie.add(c);
        nie.add(c2);
        nie.removeObject(c);
        BOOST_TEST(nie.getObject(0) == c2);
    }

    BOOST_AUTO_TEST_CASE(RemoveClientNegativeTest) {
        ClientPtr c = std::make_shared<Client>(testFirstName, testLastName, testPersonalID, testaddress1, testClientTypeStudent, nullptr);
        ClientRepository nie;
        nie.add(c);
        nie.add(nullptr);
        BOOST_TEST(nie.objectSize() == 1);

}

    BOOST_AUTO_TEST_CASE(GetClientSize) {
        ClientPtr c = std::make_shared<Client>(testFirstName, testLastName, testPersonalID, testaddress1, testClientTypeStudent, nullptr);
        ClientRepository nie;
        nie.add(c);
        BOOST_TEST(nie.objectSize() == 1);

}

BOOST_AUTO_TEST_SUITE_END()

