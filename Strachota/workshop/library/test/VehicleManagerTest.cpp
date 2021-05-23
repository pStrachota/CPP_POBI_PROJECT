#include <boost/test/unit_test.hpp>
#include "managers/VehicleManager.h"
#include <memory>
#include "model/Bronze.h"
#include <functional>
#include "model/Car.h"
#include "model/Address.h"


struct TestSuiteVehicleManagerFixture {

    ClientTypePtr testClientTypeBronze;
    SegmentType testSegmentA;
    AddressPtr testaddress3;

    TestSuiteVehicleManagerFixture() {
        testClientTypeBronze = std::make_shared<Bronze>();
        testSegmentA = A;
        testaddress3 = std::make_shared<Address>("London", "Rue Morgue", "13");
    }

    ~TestSuiteVehicleManagerFixture() {
    }

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteVehicleManager, TestSuiteVehicleManagerFixture)

    BOOST_AUTO_TEST_CASE(findByPlateNumberPositiveTest) {

       VehicleManager v;
        VehiclePtr vehicleBike = v.registerBicycle("WG4209", 99);
        BOOST_TEST(vehicleBike == v.getVehicle("WG4209"));
        VehiclePtr vehicleMoped = v.registerMoped(330, "GA2882", 199);
        VehiclePtr vehicleCar = v.registerCar(testSegmentA, 1500, "LS8821", 999);
        BOOST_TEST(vehicleBike == v.getVehicle("WG4209"));
        BOOST_TEST(vehicleMoped == v.getVehicle("GA2882"));
        BOOST_TEST(vehicleCar == v.getVehicle("LS8821"));

    }

    BOOST_AUTO_TEST_CASE(findByPlateNumberNegativeTest) {

        VehicleManager v;
        VehiclePtr vehicleBike = v.registerBicycle("WG42099", 99);
        VehiclePtr vehicleBike2 = v.registerBicycle("WG42099", 299);
        BOOST_TEST(vehicleBike == vehicleBike2);
        VehiclePtr vehicleMoped = v.registerMoped(330, "GA2882", 199);
        VehiclePtr vehicleMoped2 = v.registerMoped(1330, "GA2882", 1929);
        BOOST_TEST(vehicleMoped == vehicleMoped2);
        VehiclePtr vehicleCar = v.registerCar(testSegmentA, 1500, "LS8821", 999);
        VehiclePtr vehicleCar2 = v.registerCar(testSegmentA, 15040, "LS8821", 9929);
        BOOST_TEST(vehicleCar == vehicleCar2);

    }


BOOST_AUTO_TEST_SUITE_END()