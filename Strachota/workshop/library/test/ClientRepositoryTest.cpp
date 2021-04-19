#include <boost/test/unit_test.hpp>
#include <repositories/ClientRepository.h>


struct TestSuiteClientRepositoryFixture {
    const std::string testFirstName = "Jon";
    const std::string testLastName = "Arbuckle";
    const std::string testPersonalID = "0123456789";
    AddressPtr testaddress1;
    AddressPtr testaddress2;

    TestSuiteClientRepositoryFixture() {
        testaddress1 = new Address("London", "Accacia Avenue", "22");
        testaddress2 = new Address("London", "Rue Morgue", "13");
    }

    ~TestSuiteClientRepositoryFixture() {
        delete testaddress1;
        delete testaddress2;
    }

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClientRepository, TestSuiteClientRepositoryFixture)

    BOOST_AUTO_TEST_CASE(AddClientPositivetest) {
        Client *c = new Client(testFirstName, testLastName, testPersonalID, testaddress1);
        ClientRepository *nie = new ClientRepository;
        nie->addClient(c);
        BOOST_TEST(nie->getClient(1) == c);
        delete c;
        delete nie;
    }

    BOOST_AUTO_TEST_CASE(AddClientNegativeTest) {
        ClientRepository *nie = new ClientRepository;
        nie->addClient(nullptr);
        BOOST_TEST(nie->getClient(1) == nullptr);
        delete nie;
}

    BOOST_AUTO_TEST_CASE(RemoveClientPositiveTest) {
        Client *c = new Client(testFirstName, testLastName, testPersonalID, testaddress1);
        Client *c2 = new Client("Piotrus", "Strachota", "420", testaddress2);
        ClientRepository *nie = new ClientRepository;
        nie->addClient(c);
        nie->addClient(c2);
        nie->removeClient(c);
        BOOST_TEST(nie->getClient(1) == c2);
        delete c2;
        delete nie;
    }

    BOOST_AUTO_TEST_CASE(RemoveClientNegativeTest) {
        Client *c = new Client(testFirstName, testLastName, testPersonalID, testaddress1);
        ClientRepository *nie = new ClientRepository;
        nie->addClient(c);
        nie->addClient(nullptr);
        BOOST_TEST(nie->clientSize() == 1);
        delete c;
        delete nie;

}

    BOOST_AUTO_TEST_CASE(GetClientSize) {
        Client *c = new Client(testFirstName, testLastName, testPersonalID, testaddress1);
        ClientRepository *nie = new ClientRepository;
        nie->addClient(c);
        BOOST_TEST(nie->clientSize() == 1);
        delete c;
        delete nie;
}



BOOST_AUTO_TEST_SUITE_END()
