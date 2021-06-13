#include <boost/test/unit_test.hpp>
#include "managers/ClientManager.h"
#include <memory>
#include "model/Student.h"
#include <functional>
#include "model/Client.h"
#include "model/Address.h"


struct TestSuiteClientManagerFixture {

    ClientTypePtr testClientTypeStudent;
    AddressPtr testAddress;

    TestSuiteClientManagerFixture() {

        testClientTypeStudent = std::make_shared<Student>();
        testAddress = std::make_shared<Address>("London", "Rue Morgue", "13");
    }

    ~TestSuiteClientManagerFixture() {
    }

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClientManager, TestSuiteClientManagerFixture)

    BOOST_AUTO_TEST_CASE(findByPersonalIdTestPositiveTest) {
        ClientManager c;
        ClientPtr client = c.registerClient("Piotr", "Strachota", "1", testAddress, testClientTypeStudent);
        BOOST_TEST(client = c.getClient("1"));

    }

    BOOST_AUTO_TEST_CASE(unregisterClientTest) {
        ClientManager c;
        ClientPtr client = c.registerClient("Piotr", "Strachota", "1", testAddress, testClientTypeStudent);
        c.unregisterClient(client);
        BOOST_TEST(client->isArchive() == true);

    }

    BOOST_AUTO_TEST_CASE(findByPersonalIdTestNegativeTest) {
        ClientManager c;
        ClientPtr client = c.registerClient("Piotr", "Strachota", "1", testAddress, testClientTypeStudent);
        ClientPtr client2 = c.registerClient("Robert", "Maklowicz", "1", testAddress, testClientTypeStudent);
        BOOST_TEST(client == client2);
    }

    BOOST_AUTO_TEST_CASE(findClientsTest) {
        ClientManager c;
        ClientPtr client1 = c.registerClient("Piotr", "Strachota", "1", testAddress, testClientTypeStudent);
        ClientPtr client2 = c.registerClient("Piotr", "Majdan", "2", testAddress, testClientTypeStudent);
        ClientPtr client3 = c.registerClient("Piotr", "Janczyk", "3", testAddress, testClientTypeStudent);
        ClientPtr client4 = c.registerClient("Piotr", "Strachota", "4", testAddress, testClientTypeStudent);
        c.unregisterClient(client2);
        c.unregisterClient(client4);

        BOOST_CHECK_EQUAL(c.countClientRent(), 4);
        std::string test = "Strachota";
        ClientPredicate predicate = [test](const ClientPtr& ptr) {
            return ptr->getSurname() == test;
        };
        std::vector<ClientPtr> result = c.findClients(predicate);
        std::vector<ClientPtr> testResult;
        testResult.push_back(client1);
        BOOST_CHECK_EQUAL(result.at(0), testResult.at(0));
}


BOOST_AUTO_TEST_SUITE_END()