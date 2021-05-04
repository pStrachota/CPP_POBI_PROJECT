#include <boost/test/unit_test.hpp>
#include "model/Vehicle.h"
#include "repositories/VehicleRepository.h"
#include "typedefs.h"

struct TestSuiteVehicleRepositoryFixture {
    const std::string numerRejestracyjny = "EPA112";
    const unsigned int cenaBazowa = 1;
    VehiclePtr testVehicle;

    TestSuiteVehicleRepositoryFixture() {
        testVehicle = new Vehicle("123",1);
    }

    ~TestSuiteVehicleRepositoryFixture() {
        delete testVehicle;
    }

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteVehicleRepository, TestSuiteVehicleRepositoryFixture)

BOOST_AUTO_TEST_CASE(AddVehicleToRepositoryPositiveTest)
        {
            VehicleRepository *rRep = new VehicleRepository;
            VehiclePtr tVehicle = new Vehicle(numerRejestracyjny,cenaBazowa);
            rRep->addVehicle(tVehicle);
            BOOST_TEST(rRep->getVehicle(0) == tVehicle);
            delete rRep;
            delete tVehicle;
        }

BOOST_AUTO_TEST_CASE(AddVehicleToRepositoryNegativeTest)
        {
            VehicleRepository *rRep = new VehicleRepository;
            VehiclePtr tVehicle = new Vehicle(numerRejestracyjny,cenaBazowa);
            rRep->addVehicle(tVehicle);
            rRep->addVehicle(nullptr);
            BOOST_TEST(rRep->getSize() == 1);
            delete rRep;
            delete tVehicle;
        }

BOOST_AUTO_TEST_CASE(RemoveVehicleFromRepositoryPositiveTest)
        {
            VehicleRepository *rRep = new VehicleRepository;
            VehiclePtr tVehicle = new Vehicle(numerRejestracyjny,cenaBazowa);
            VehiclePtr tVehicle2 = new Vehicle(numerRejestracyjny,cenaBazowa);
            rRep->addVehicle(tVehicle);
            rRep->addVehicle(tVehicle2);
            rRep->removeVehicle(tVehicle);
            BOOST_TEST(rRep->getVehicle(0) == tVehicle2);
            BOOST_TEST(rRep->getSize() == 1);
            delete rRep;
            delete tVehicle;
            delete tVehicle2;
        }

BOOST_AUTO_TEST_CASE(RemoveVehicleFromRepositoryNegativeTest)
        {
            VehicleRepository *rRep = new VehicleRepository;
            VehiclePtr tVehicle = new Vehicle(numerRejestracyjny,cenaBazowa);
            rRep->addVehicle(tVehicle);
            rRep->removeVehicle(nullptr);
            BOOST_TEST(rRep->getSize() == 1);
            delete rRep;
            delete tVehicle;
        }

BOOST_AUTO_TEST_CASE(GetVehicleRepositorySizeTest)
        {
            VehicleRepository *rRep = new VehicleRepository;
            VehiclePtr tVehicle = new Vehicle(numerRejestracyjny,cenaBazowa);
            rRep->addVehicle(tVehicle);
            BOOST_TEST(rRep->getSize() == 1);
            delete rRep;
            delete tVehicle;
        }


BOOST_AUTO_TEST_SUITE_END()
