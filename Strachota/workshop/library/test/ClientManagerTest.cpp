#include <boost/test/unit_test.hpp>
#include "managers/ClientManager.h"
#include <memory>
#include "model/Bronze.h"
#include <functional>
#include "model/Address.h"
#include "model/Client.h"

struct TestSuiteClientManagerFixture {

    ClientTypePtr testClientTypeBronze;
    AddressPtr testaddress3;

TestSuiteClientManagerFixture() {
    testClientTypeBronze = std::make_shared<Bronze>();
    testaddress3 = std::make_shared<Address>("London", "Rue Morgue", "13");
}

~TestSuiteClientManagerFixture() {
    }

    };

BOOST_FIXTURE_TEST_SUITE(TestSuiteClientManager, TestSuiteClientManagerFixture)

    BOOST_AUTO_TEST_CASE(findByPersonalIdTestPositiveTest) {
        clientManager c;
        ClientPtr client = c.registerClient("Piotr", "Strachota", "1", testaddress3, testClientTypeBronze);
        BOOST_TEST(client = c.getClient("1"));

}

    BOOST_AUTO_TEST_CASE(findByPersonalIdTestNegativeTest) {
        clientManager c;
        ClientPtr client = c.registerClient("Piotr", "Strachota", "1", testaddress3, testClientTypeBronze);
        ClientPtr client2 = c.registerClient("Robert", "Maklowicz", "1", testaddress3, testClientTypeBronze);
        BOOST_TEST(client == client2);
}
    BOOST_AUTO_TEST_CASE(findClientsTest) {
        clientManager c;
        ClientPtr client1 = c.registerClient("Piotr", "Strachota", "1", testaddress3, testClientTypeBronze);
        ClientPtr client2 = c.registerClient("Piotr", "Majdan", "2", testaddress3, testClientTypeBronze);
        ClientPtr client3 = c.registerClient("Piotr", "Janczyk", "3", testaddress3, testClientTypeBronze);
        ClientPtr client4 = c.registerClient("Piotr", "Strachota", "4", testaddress3, testClientTypeBronze);
        c.unregisterClient("2");
        c.unregisterClient("4");

        std::string test = "Strachota";
        ClientPredicate predicate = [test]( const ClientPtr& ptr) {
            return ptr->getLastName() == test;
        };
        std::vector<ClientPtr> result = c.findClients(predicate);
        std::vector<ClientPtr> testResult;
        testResult.push_back(client1);
        BOOST_CHECK_EQUAL(result.at(0), testResult.at(0));
    }


BOOST_AUTO_TEST_SUITE_END()