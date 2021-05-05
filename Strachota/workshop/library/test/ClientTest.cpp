#include <boost/test/unit_test.hpp>
#include "model/Client.h"
#include "typedefs.h"
#include "model/Bronze.h"
#include <memory>
#include <functional>
#include "model/Default.h"
#include "model/Silver.h"
#include "model/Gold.h"
#include "model/Diamond.h"

struct TestSuiteClientFixture {
    const std::string testFirstName = "Jon";
    const std::string testLastName = "Arbuckle";
    const std::string testPersonalID = "0123456789";
    AddressPtr testaddress1;
    AddressPtr testaddress2;
    ClientTypePtr testClientTypeBronze;
    ClientTypePtr testClientTypeDefault;
    ClientTypePtr testClientTypeSilver;
    ClientTypePtr testClientTypeGold;
    ClientTypePtr testClientTypeDiamond;

    TestSuiteClientFixture() {
        testaddress1 = std::make_shared<Address>("London", "Accacia Avenue", "22");
        testaddress2 = std::make_shared<Address>("London", "Rue Morgue", "13");
        testClientTypeBronze = std::make_shared<Bronze>();
        testClientTypeDefault = std::make_shared<Default>();
        testClientTypeSilver = std::make_shared<Silver>();
        testClientTypeGold = std::make_shared<Gold>();
        testClientTypeDiamond = std::make_shared<Diamond>();
    }

    ~TestSuiteClientFixture() {
        //delete testaddress1;
        //delete testaddress2;
    }

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClient, TestSuiteClientFixture)

    BOOST_AUTO_TEST_CASE(ParameterConstrutorTest) {

        ClientPtr c = std::make_shared<Client>(testFirstName, testLastName, testPersonalID, testaddress1, testClientTypeBronze);
        BOOST_TEST(testFirstName == c->getFirstName());
        BOOST_TEST(testLastName == c->getLastName());
        BOOST_TEST(testPersonalID == c->getPersonalId());
        BOOST_TEST(testaddress1 == c->getAddress());
        BOOST_TEST(testClientTypeBronze->getTypeInfo() == "BRONZE");
        BOOST_TEST(testClientTypeBronze->applyDiscount(100) == 97);
        BOOST_TEST(c->getMaxVehicles() == 2);
        BOOST_TEST(c->applyDiscount(100) == 97);
    }

    BOOST_AUTO_TEST_CASE(BronzeClientTypeTest) {
        ClientPtr c = std::make_shared<Client>(testFirstName, testLastName, testPersonalID, testaddress1, testClientTypeBronze);
        BOOST_TEST(c->getMaxVehicles() == 2);
        BOOST_TEST(c->applyDiscount(100) == 97);
}

    BOOST_AUTO_TEST_CASE(DefaultClientTypeTest) {
        ClientPtr c = std::make_shared<Client>(testFirstName, testLastName, testPersonalID, testaddress1, testClientTypeDefault);
        BOOST_TEST(c->getMaxVehicles() == 1);
        BOOST_TEST(c->applyDiscount(100) == 100);

}
    BOOST_AUTO_TEST_CASE(SilverClientTypeTest) {
        ClientPtr c = std::make_shared<Client>(testFirstName, testLastName, testPersonalID, testaddress1, testClientTypeSilver);
        BOOST_TEST(c->getMaxVehicles() == 3);
        BOOST_TEST(c->applyDiscount(100) == 94);
}

    BOOST_AUTO_TEST_CASE(GoldClientTypeTest) {
        ClientPtr c = std::make_shared<Client>(testFirstName, testLastName, testPersonalID, testaddress1, testClientTypeGold);
        BOOST_TEST(c->getMaxVehicles() == 4);
        BOOST_TEST(c->applyDiscount(100) == (100*0.95));
    }

    BOOST_AUTO_TEST_CASE(DiamondClientTypeTest) {
        ClientPtr c = std::make_shared<Client>(testFirstName, testLastName, testPersonalID, testaddress1, testClientTypeDiamond);
        BOOST_TEST(c->getMaxVehicles() == 10);
        BOOST_TEST(c->applyDiscount(100) == (100*0.9));

}


    BOOST_AUTO_TEST_CASE(SetFirstNamePositiveTest) {
        ClientPtr c = std::make_shared<Client>(testFirstName, testLastName, testPersonalID, testaddress1, testClientTypeBronze);
        c->setFirstName("Piotr");
        BOOST_TEST(c->getFirstName() == "Piotr");
}

    BOOST_AUTO_TEST_CASE(SetFirstNameNegativeTest) {
        ClientPtr c = std::make_shared<Client>(testFirstName, testLastName, testPersonalID, testaddress1, testClientTypeBronze);
        c->setFirstName("");
        BOOST_TEST(c->getFirstName() == testFirstName);
    }
    BOOST_AUTO_TEST_CASE(SetLastNamePositiveTest) {
        ClientPtr c = std::make_shared<Client>(testFirstName, testLastName, testPersonalID, testaddress1, testClientTypeBronze);
        c->setLastName("Strachota");
        BOOST_TEST(c->getLastName() == "Strachota");
}
    BOOST_AUTO_TEST_CASE(SetLastNameNegativeTest) {
        ClientPtr c = std::make_shared<Client>(testFirstName, testLastName, testPersonalID, testaddress1, testClientTypeBronze);
        c->setLastName("");
        BOOST_TEST(c->getLastName() == testLastName);
}
    BOOST_AUTO_TEST_CASE(SetAddressPositiveTest) {
        ClientPtr c = std::make_shared<Client>(testFirstName, testLastName, testPersonalID, testaddress1, testClientTypeBronze);
        c->setAddress(testaddress2);
        BOOST_TEST(c->getAddress() == testaddress2);
    }
    BOOST_AUTO_TEST_CASE(SetAddressNegativeTest) {
        ClientPtr c = std::make_shared<Client>(testFirstName, testLastName, testPersonalID, testaddress1, testClientTypeBronze);
        c->setAddress(nullptr);
        BOOST_TEST(c->getAddress() == testaddress1);
}

BOOST_AUTO_TEST_SUITE_END()


















/*
BOOST_AUTO_TEST_SUITE(TestSuiteClient)

    //Address *proba = new Address("Wicie", "fajna", "2013");
    Address *test;
    Address *test2;
    BOOST_AUTO_TEST_CASE(ClientConstructorTests) {
        Client client("Piotr", "Strachota", "420", test);
        BOOST_TEST(client.getFirstName() == "Piotr");
        BOOST_TEST(client.getLastName() == "Strachota");
        BOOST_TEST(client.getPersonalId() == "420");
        BOOST_TEST(client.getAddress() == test);
    }
    BOOST_AUTO_TEST_CASE(ClientSetterTests) {
        //Address *proba2 = new Address("Wilga", "tezfajna", "2015");
        Client client("Piotr", "Strachota", "420", test);
        client.setFirstName("");
        BOOST_TEST(client.getFirstName() == "Piotr");
        client.setFirstName("Adam");
        BOOST_TEST(client.getFirstName() == "Adam");
        client.setLastName("");
        BOOST_TEST(client.getLastName() == "Strachota");
        client.setLastName("Makłowicz");
        BOOST_TEST(client.getLastName() == "Makłowicz");
        client.setAddress(nullptr);
        BOOST_TEST(client.getAddress() == test);
        client.setAddress(test2);
        BOOST_TEST(client.getAddress() == test2);
}

BOOST_AUTO_TEST_SUITE_END()
*/