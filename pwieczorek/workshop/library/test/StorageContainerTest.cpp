#include <boost/test/unit_test.hpp>
#include "repositories/StorageContainer.h"
#include <boost/date_time.hpp>
#include "model/Vehicle.h"
#include "model/Address.h"
#include "model/Client.h"
#include "model/Rent.h"

namespace pt = boost::posix_time;
namespace gr = boost::gregorian;
/*
struct TestSuiteStorageContainerFixture {

    VehiclePtr testVehicle1;
    VehiclePtr testVehicle2;
    ClientPtr testClient1;
    ClientPtr testClient2;
    RentPtr testRent1;
    RentPtr testRent2;
    AddressPtr testAddress1;
    AddressPtr testAddress2;
    pt::ptime date1 = pt::ptime(gr::date(2015,5,13),pt::hours(9)+pt::minutes(25));
    //pt::ptime date2 = pt::ptime(gr::date(2015,5,13),pt::hours(9)+pt::minutes(25));

    TestSuiteStorageContainerFixture () {
        testVehicle1 = std::make_shared<Vehicle>("123",1);
        testVehicle2 = std::make_shared<Vehicle>("321",2);
        testAddress1 = std::make_shared<Address>("london","baker","10");
        testAddress2 = std::make_shared<Address>("london","baker","10");
        testClient1 = std::make_shared<Client>("jan","kowal","123",testAddress1);
        testClient2 = std::make_shared<Client>("jan","kowal","123",testAddress2);
        testRent1 = std::make_shared<Rent>(1,testClient1,testVehicle1,date1);

    }

    ~TestSuiteStorageContainerFixture () {

        //delete testVehicle1;
        //delete testVehicle2;
        //delete testClient1;
        //delete testClient2;
        //delete testRent1;
        //delete testAddress1;
        //delete testAddress2;

    }

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteStorageContainer, TestSuiteStorageContainerFixture)



    BOOST_AUTO_TEST_CASE(AddObjectsPositiveTest)
    {

        ClientRepository clientRep;
        VehicleRepository vehicleRep;
        RentRepository rentRep;

        clientRep.addClient(testClient1);
        vehicleRep.addVehicle(testVehicle1);
        rentRep.addRent(testRent1);

        StorageContainer storageCont(vehicleRep,clientRep,rentRep);

        storageCont.getClientRep().addClient(testClient2);

        BOOST_TEST(storageCont.getClientRep().getSize() == 2);
        BOOST_TEST(storageCont.getVehicleRep().getSize() == 1);
        BOOST_TEST(storageCont.getRentRep().getSize() == 1);

    }



    BOOST_AUTO_TEST_CASE(AddObjectsNegativeTest)
    {
        ClientRepository clientRep;
        VehicleRepository vehicleRep;
        RentRepository rentRep;

        clientRep.addClient(nullptr);
        vehicleRep.addVehicle(nullptr);
        rentRep.addRent(nullptr);

        StorageContainer storageCont(vehicleRep,clientRep,rentRep);

        storageCont.getRentRep().addRent(nullptr);
        storageCont.getVehicleRep().addVehicle(nullptr);
        storageCont.getClientRep().addClient(nullptr);

        BOOST_TEST(storageCont.getVehicleRep().getSize() == 0);
        BOOST_TEST(storageCont.getClientRep().getSize() == 0);
        BOOST_TEST(storageCont.getRentRep().getSize() == 0);
    }


    BOOST_AUTO_TEST_CASE(GetSize)
    {
        ClientRepository clientRep;
        VehicleRepository vehicleRep;
        RentRepository rentRep;

        clientRep.addClient(testClient1);
        vehicleRep.addVehicle(testVehicle1);
        rentRep.addRent(testRent1);

        StorageContainer storageCont(vehicleRep,clientRep,rentRep);

        BOOST_TEST(storageCont.getVehicleRep().getSize() == 1);
        BOOST_TEST(storageCont.getClientRep().getSize() == 1);
        BOOST_TEST(storageCont.getRentRep().getSize() == 1);
    }


BOOST_AUTO_TEST_SUITE_END()
*/