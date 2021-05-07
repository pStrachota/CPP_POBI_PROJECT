#include <boost/test/unit_test.hpp>
#include <repositories/StorageContainer.h>

/*
struct TestSuiteStorageContainerFixture {
    ClientPtr testClient;
    ClientPtr testClient2;
    VehiclePtr testVehicle;
    VehiclePtr testVehicle2;
    RentPtr testRent;
    RentPtr testRent2;
    AddressPtr testAddress;
    AddressPtr testAddress2;
    pt::ptime testTime = pt::ptime(gr::date(2021,4,5), pt::hours(9)+pt::minutes(25));
    pt::ptime testTime2 = pt::ptime(gr::date(2022,4,5), pt::hours(9)+pt::minutes(25));

    TestSuiteStorageContainerFixture() {

        //testRent = new Rent(1, testClient, testVehicle, testTime);
        testAddress = new Address("London", "Rue Morgue", "13");
        testAddress2 = new Address("Garwolin", "Rue Morgue", "13");
        testClient2 = new Client("Robert", "Maklowicz", "420", testAddress2);
        testClient = new Client("Piotr", "Strachota", "420", testAddress);
        testVehicle = new Vehicle("US3333", 345);
        testVehicle2 = new Vehicle("WG4233", 199);

    }

    ~TestSuiteStorageContainerFixture() {
        delete testAddress;
        delete testAddress2;
        delete testClient;
        delete testClient2;
        delete testVehicle;
        delete testVehicle2;
       // delete testRent;
        //delete testRent2;
    }

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteStorageContainer, TestSuiteStorageContainerFixture)

    BOOST_AUTO_TEST_CASE(AddPositivetest) {

    testRent = new Rent(1, testClient, testVehicle, testTime);
    ClientRepository cR; // = new ClientRepository;
    cR.addClient(testClient);
    VehicleRepository vR; // = new VehicleRepository;
    vR.addVehicle(testVehicle);
    RentRepository rR; // = new RentRepository;
    rR.addRent(testRent);
    StorageContainer sC(vR, cR, rR);

    BOOST_TEST(sC.getVehicleRepo().getVehicle(1) == testVehicle);
    BOOST_TEST(sC.getClientRepo().getClient(1) == testClient);
    BOOST_TEST(sC.getRentRepo().getRent(1) == testRent);
}

    BOOST_AUTO_TEST_CASE(AddNegativetest) {
        testRent = new Rent(1, testClient, testVehicle, testTime);
        ClientRepository cR; // = new ClientRepository;
        cR.addClient(nullptr);
        VehicleRepository vR; // = new VehicleRepository;
        vR.addVehicle(nullptr);
        RentRepository rR; // = new RentRepository;
        rR.addRent(nullptr);
        StorageContainer sC(vR, cR, rR);

        BOOST_TEST(sC.getVehicleRepo().getVehicle(1) == nullptr);
        BOOST_TEST(sC.getClientRepo().getClient(1) == nullptr);
        BOOST_TEST(sC.getRentRepo().getRent(1) == nullptr);
        delete testRent;
}


    BOOST_AUTO_TEST_CASE(RemoveClientPositiveTest) {
        testRent = new Rent(1, testClient, testVehicle, testTime);
        testRent2 = new Rent(2, testClient2, testVehicle2, testTime2);
        ClientRepository cR; // = new ClientRepository;
        cR.addClient(testClient);
        cR.addClient(testClient2);
        cR.removeClient(testClient);
        VehicleRepository vR; // = new VehicleRepository;
        vR.addVehicle(testVehicle);
        vR.addVehicle(testVehicle2);
        vR.removeVehicle(testVehicle);
        RentRepository rR; // = new RentRepository;
        rR.addRent(testRent);
        rR.addRent(testRent2);
        rR.removeRent(testRent);
        StorageContainer sC(vR, cR, rR);

        BOOST_TEST(sC.getVehicleRepo().getVehicle(1) == testVehicle2);
        BOOST_TEST(sC.getClientRepo().getClient(1) == testClient2);
        BOOST_TEST(sC.getRentRepo().getRent(1) == testRent2);
        delete testRent;
        delete testRent2;
}

    BOOST_AUTO_TEST_CASE(RemoveClientNegativeTest) {
        testRent = new Rent(1, testClient, testVehicle, testTime);
        ClientRepository cR; // = new ClientRepository;
        cR.addClient(testClient);
        cR.addClient(nullptr);
        VehicleRepository vR; // = new VehicleRepository;
        vR.addVehicle(testVehicle);
        vR.addVehicle(nullptr);
        RentRepository rR; // = new RentRepository;
        rR.addRent(testRent);
        rR.addRent(nullptr);
        StorageContainer sC(vR, cR, rR);

        BOOST_TEST(sC.getVehicleRepo().vehicleSize() == 1);
        BOOST_TEST(sC.getClientRepo().clientSize() == 1);
        BOOST_TEST(sC.getRentRepo().rentSize() == 1);
        delete testRent;

}


    BOOST_AUTO_TEST_CASE(GetSize) {
        testRent = new Rent(1, testClient, testVehicle, testTime);
        ClientRepository cR; // = new ClientRepository;
        cR.addClient(testClient);
        VehicleRepository vR; // = new VehicleRepository;
        vR.addVehicle(testVehicle);
        RentRepository rR; // = new RentRepository;
        rR.addRent(testRent);
        StorageContainer sC(vR, cR, rR);

        BOOST_TEST(sC.getVehicleRepo().vehicleSize() == 1);
        BOOST_TEST(sC.getClientRepo().clientSize() == 1);
        BOOST_TEST(sC.getRentRepo().rentSize() == 1);
        delete testRent;

}

BOOST_AUTO_TEST_SUITE_END()
 */