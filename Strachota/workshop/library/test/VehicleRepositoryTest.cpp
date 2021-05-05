#include <boost/test/unit_test.hpp>
#include <repositories/VehicleRepository.h>

/*
struct TestSuiteVehicleRepositoryFixture {
    const std::string testPlateNumber = "WG420H";
    const unsigned int testBasePrice = 199;

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteVehicleRepository, TestSuiteVehicleRepositoryFixture)

    BOOST_AUTO_TEST_CASE(AddVehiclePositivetest) {
        auto *v = new Vehicle(testPlateNumber, testBasePrice);
        auto *vR = new VehicleRepository;
        vR->addVehicle(v);
        BOOST_TEST(vR->getVehicle(1) == v);
        delete v;
        delete vR;
    }

    BOOST_AUTO_TEST_CASE(AddVehicleNegativeTest) {
        auto *vR = new VehicleRepository;
        vR->addVehicle(nullptr);
        BOOST_TEST(vR->getVehicle(1) == nullptr);
        delete vR;
    }

    BOOST_AUTO_TEST_CASE(RemoveVehiclePositiveTest) {
        auto *v = new Vehicle(testPlateNumber, testBasePrice);
        auto *v2 = new Vehicle("WW1235L", 99);
        auto *vR = new VehicleRepository;
        vR->addVehicle(v);
        vR->addVehicle(v2);
        vR->removeVehicle(v);
        BOOST_TEST(vR->getVehicle(1) == v2);
        delete v;
        delete vR;
        }

        BOOST_AUTO_TEST_CASE(RemoveVehicleNegativeTest) {
        auto *v = new Vehicle(testPlateNumber, testBasePrice);
        auto *vR = new VehicleRepository;
        vR->addVehicle(v);
        vR->addVehicle(nullptr);
        BOOST_TEST(vR->vehicleSize() == 1);
        delete v;
        delete vR;
        }

        BOOST_AUTO_TEST_CASE(GetVehicleSize) {
        auto *v = new Vehicle(testPlateNumber, testBasePrice);
        auto *vR = new VehicleRepository;
        vR->addVehicle(v);
        BOOST_TEST(vR->vehicleSize() == 1);
        delete v;
        delete vR;
        }

BOOST_AUTO_TEST_SUITE_END()

*/