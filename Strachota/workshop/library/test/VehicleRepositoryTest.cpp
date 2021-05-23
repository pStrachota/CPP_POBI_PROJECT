#include <boost/test/unit_test.hpp>
#include <repositories/VehicleRepository.h>
#include "model/Bicycle.h"

struct TestSuiteVehicleRepositoryFixture {
    const std::string testPlateNumber = "WG420H";
    const unsigned int testBasePrice = 199;

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteVehicleRepository, TestSuiteVehicleRepositoryFixture)

    BOOST_AUTO_TEST_CASE(AddVehiclePositivetest) {
        VehiclePtr v = std::make_shared<Bicycle>(testPlateNumber, testBasePrice);
        VehicleRepository vR;
        vR.add(v);
        BOOST_TEST(vR.getObject(0) == v);
    }

    BOOST_AUTO_TEST_CASE(RemoveVehiclePositiveTest) {
        VehiclePtr v = std::make_shared<Bicycle>(testPlateNumber, testBasePrice);
        VehiclePtr v2 = std::make_shared<Bicycle>("WW1235L", 99);
        VehicleRepository vR;
        vR.add(v);
        vR.add(v2);
        vR.removeObject(v);
        BOOST_TEST(vR.getObject(0) == v2);
        }

        BOOST_AUTO_TEST_CASE(RemoveVehicleNegativeTest) {
        VehiclePtr v = std::make_shared<Bicycle>(testPlateNumber, testBasePrice);
        VehicleRepository vR;
        vR.add(v);
        vR.add(nullptr);
        BOOST_TEST(vR.objectSize() == 1);
        }

        BOOST_AUTO_TEST_CASE(GetVehicleSize) {
        VehiclePtr v = std::make_shared<Bicycle>(testPlateNumber, testBasePrice);
        VehicleRepository vR;
        vR.add(v);
        BOOST_TEST(vR.objectSize() == 1);
        }

BOOST_AUTO_TEST_SUITE_END()

