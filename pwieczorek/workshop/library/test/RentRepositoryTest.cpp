#include <boost/test/unit_test.hpp>
#include "model/Rent.h"
#include "repositories/RentRepository.h"
#include "typedefs.h"
/*
struct TestSuiteRentRepositoryFixture {
    const unsigned int ID = 123;
    AddressPtr testAddress;
    ClientPtr testClient;
    VehiclePtr testVehicle;
    pt::ptime date = pt::ptime(gr::date(2015,5,13),pt::hours(9)+pt::minutes(25));


    TestSuiteRentRepositoryFixture() {
        testAddress = std::make_shared<Address>("London", "Accacia Avenue", "22");
        testClient = std::make_shared<Client>("John", "smith","123",testAddress);
        testVehicle = std::make_shared<Vehicle>("EPA112",1);
    }

    ~TestSuiteRentRepositoryFixture() {
        //delete testAddress;
        //delete testClient;
        //delete testVehicle;
    }

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRentRepository, TestSuiteRentRepositoryFixture)

    BOOST_AUTO_TEST_CASE(AddRentToRepositoryPositiveTest)
    {
        RentRepository *rRep = new RentRepository;
        RentPtr tRent = std::make_shared<Rent>(ID,testClient,testVehicle,date);
        rRep->addRent(tRent);
        BOOST_TEST(rRep->getRent(0) == tRent);
        delete rRep;
    }

    BOOST_AUTO_TEST_CASE(AddRentToRepositoryNegativeTest)
    {
        RentRepository *rRep = new RentRepository;
        RentPtr tRent = std::make_shared<Rent>(ID,testClient,testVehicle,date);
        rRep->addRent(tRent);
        rRep->addRent(nullptr);
        BOOST_TEST(rRep->getSize() == 1);
        delete rRep;
    }

    BOOST_AUTO_TEST_CASE(RemoveRentFromRepositoryPositiveTest)
    {
        RentRepository *rRep = new RentRepository;
        RentPtr tRent = std::make_shared<Rent>(ID,testClient,testVehicle,date);
        RentPtr tRent2 = std::make_shared<Rent>(ID,testClient,testVehicle,date);
        rRep->addRent(tRent);
        rRep->addRent(tRent2);
        rRep->removeRent(tRent);
        BOOST_TEST(rRep->getRent(0) == tRent2);
        BOOST_TEST(rRep->getSize() == 1);
        delete rRep;
    }

    BOOST_AUTO_TEST_CASE(RemoveRentFromRepositoryNegativeTest)
    {
        RentRepository *rRep = new RentRepository;
        RentPtr tRent = std::make_shared<Rent>(ID,testClient,testVehicle,date);
        RentPtr tRent2 = std::make_shared<Rent>(ID,testClient,testVehicle,date);
        rRep->addRent(tRent);
        rRep->addRent(tRent2);
        rRep->removeRent(nullptr);
        BOOST_TEST(rRep->getSize() == 2);
        delete rRep;
    }

    BOOST_AUTO_TEST_CASE(GetRepositorySizeTest)
    {
        RentRepository *rRep = new RentRepository;
        RentPtr tRent = std::make_shared<Rent>(ID,testClient,testVehicle,date);
        rRep->addRent(tRent);
        BOOST_TEST(rRep->getSize() == 1);
        delete rRep;
    }


BOOST_AUTO_TEST_SUITE_END()

*/