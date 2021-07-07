#include <boost/test/unit_test.hpp>
#include "model/Vehicle.h"
#include "repositories/VehicleRepository.h"
#include "typedefs.h"

struct TestSuiteVehicleRepositoryFixture {
    const std::string numerRejestracyjny = "EPA112";
    const unsigned int cenaBazowa = 1;
    VehiclePtr testVehicle;

    TestSuiteVehicleRepositoryFixture() {
        testVehicle = std::make_shared<Vehicle>("123",1);
    }

    ~TestSuiteVehicleRepositoryFixture() {
        //delete testVehicle;
    }

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteVehicleRepository, TestSuiteVehicleRepositoryFixture)

BOOST_AUTO_TEST_CASE(AddVehicleToRepositoryPositiveTest)
        {
            VehicleRepository *rRep = new VehicleRepository;
            VehiclePtr tVehicle = std::make_shared<Vehicle>(numerRejestracyjny,cenaBazowa);
            rRep->add(tVehicle);
            BOOST_TEST(rRep->get(0) == tVehicle);
            delete rRep;

        }

BOOST_AUTO_TEST_CASE(AddVehicleToRepositoryNegativeTest)
        {
            VehicleRepository *rRep = new VehicleRepository;
            VehiclePtr tVehicle = std::make_shared<Vehicle>(numerRejestracyjny,cenaBazowa);
            rRep->add(tVehicle);
            rRep->add(nullptr);
            BOOST_TEST(rRep->getSize() == 1);
            delete rRep;
        }

BOOST_AUTO_TEST_CASE(RemoveVehicleFromRepositoryPositiveTest)
        {
            VehicleRepository *rRep = new VehicleRepository;
            VehiclePtr tVehicle = std::make_shared<Vehicle>(numerRejestracyjny,cenaBazowa);
            VehiclePtr tVehicle2 = std::make_shared<Vehicle>(numerRejestracyjny,cenaBazowa);
            rRep->add(tVehicle);
            rRep->add(tVehicle2);
            rRep->remove(tVehicle);
            BOOST_TEST(rRep->get(0) == tVehicle2);
            BOOST_TEST(rRep->getSize() == 1);
            delete rRep;
        }

BOOST_AUTO_TEST_CASE(RemoveVehicleFromRepositoryNegativeTest)
        {
            VehicleRepository *rRep = new VehicleRepository;
            VehiclePtr tVehicle = std::make_shared<Vehicle>(numerRejestracyjny,cenaBazowa);
            rRep->add(tVehicle);
            rRep->remove(nullptr);
            BOOST_TEST(rRep->getSize() == 1);
            delete rRep;
        }

BOOST_AUTO_TEST_CASE(GetVehicleRepositorySizeTest)
        {
            VehicleRepository *rRep = new VehicleRepository;
            VehiclePtr tVehicle = std::make_shared<Vehicle>(numerRejestracyjny,cenaBazowa);
            rRep->add(tVehicle);
            BOOST_TEST(rRep->getSize() == 1);
            delete rRep;
        }


BOOST_AUTO_TEST_SUITE_END()
