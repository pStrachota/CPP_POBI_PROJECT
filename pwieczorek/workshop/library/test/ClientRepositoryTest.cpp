#include <boost/test/unit_test.hpp>
#include "model/Client.h"
#include "repositories/ClientRepository.h"
#include "typedefs.h"

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

    BOOST_AUTO_TEST_CASE(AddClientToRepositoryPositiveTest)
    {
        ClientPtr c_test = new Client(testFirstName, testLastName, testPersonalID, testaddress1);
        ClientRepository *cRep = new ClientRepository;
        cRep->addClient(c_test);
        BOOST_TEST((cRep->getClient(0)) == c_test);
        delete c_test;
        delete cRep;
    }

    /* wymaga poprawy
    BOOST_AUTO_TEST_CASE(AddClientToRepositoryNegativeTest)
    {
        ClientPtr c_test = new Client(testFirstName, testLastName, testPersonalID, testaddress1);
        ClientRepository *cRep = new ClientRepository;
        //cRep->addClient(c_test);
        cRep->addClient(nullptr);
        BOOST_TEST((cRep->getClient(0)) == nullptr);
        delete cRep;
    }
    */
    BOOST_AUTO_TEST_CASE(RemoveClientFromRepositoryPositiveTest)
    {
        ClientPtr c_test1 = new Client(testFirstName, testLastName, testPersonalID, testaddress1);
        ClientPtr c_test2 = new Client(testFirstName, testLastName, testPersonalID, testaddress2);
        ClientRepository *cRep = new ClientRepository;
        cRep->addClient(c_test1);
        cRep->addClient(c_test2);
        //BOOST_TEST((cRep->getClient(0)) == c_test1);
        //BOOST_TEST((cRep->getClient(1)) == c_test2);
        cRep->removeClient(c_test1);
        BOOST_TEST((cRep->getClient(0)) == c_test2);
        BOOST_TEST(cRep->getSize() == 1);
        delete c_test1;
        delete c_test2;
        delete cRep;

    }

    BOOST_AUTO_TEST_CASE(RemoveClientFromRepositoryNegativeTest)
    {
        ClientPtr c_test1 = new Client(testFirstName, testLastName, testPersonalID, testaddress1);
        ClientRepository *cRep = new ClientRepository;
        cRep->addClient(c_test1);
        cRep->addClient(nullptr);
        BOOST_TEST((cRep->getSize()) == 1);
        delete c_test1;
        delete cRep;

    }

    BOOST_AUTO_TEST_CASE(GetSizeTest)
    {
            ClientPtr c_test1 = new Client(testFirstName, testLastName, testPersonalID, testaddress1);
            ClientRepository *cRep = new ClientRepository;
            BOOST_TEST((cRep->getSize()) == 0); // is empty
            cRep->addClient(c_test1);
            BOOST_TEST((cRep->getSize()) == 1);
            delete c_test1;
            delete cRep;

    }

BOOST_AUTO_TEST_SUITE_END()