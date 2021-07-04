#include <boost/test/unit_test.hpp>
#include "model/Vehicle.h"
#include "model/Client.h"
#include "model/Rent.h"
#include "typedefs.h"
#include "model/Default.h"
#include "model/Silver.h"
#include "model/Bronze.h"
#include "model/Platinum.h"
#include "model/Diamond.h"
#include "model/Gold.h"


struct TestSuiteRentFixture{
    unsigned int rentID = 3;
    ClientPtr  ptrClient;
    ClientPtr ptrClient2,ptrClient3,ptrClient4,ptrClient5;
    VehiclePtr  ptrVehicle;
    AddressPtr ptrAddress;
    pt::ptime testDate = pt::ptime(gr::date(2021,3,13), pt::hours(12) + pt::minutes(30));
    pt::ptime testDate2 = pt::ptime(gr::date(2021,3,23), pt::hours(12) + pt::minutes(30));
    ClientTypePtr CTdefault;
    ClientTypePtr CTsilver;
    ClientTypePtr CTbronze;
    ClientTypePtr CTplatinum;
    ClientTypePtr CTdiamond;
    ClientTypePtr CTgold;

    TestSuiteRentFixture() {
        CTdefault = std::make_shared<Default>();
        CTsilver = std::make_shared<Silver>();
        CTbronze = std::make_shared<Bronze>();
        CTplatinum = std::make_shared<Platinum>();
        CTdiamond = std::make_shared<Diamond>();
        CTgold = std::make_shared<Gold>();
        ptrAddress = std::make_shared<Address>("london","baker st","7");
        ptrVehicle = std::make_shared<Vehicle>("007",5);
        ptrClient = std::make_shared<Client>("adam","nowak","007",ptrAddress,CTdefault);
        ptrClient2 = std::make_shared<Client>("adam","nowak","007",ptrAddress,CTsilver);
        ptrClient3 = std::make_shared<Client>("adam","nowak","007",ptrAddress,CTbronze);
        ptrClient4 = std::make_shared<Client>("adam","nowak","007",ptrAddress,CTplatinum);
        ptrClient5 = std::make_shared<Client>("adam","nowak","007",ptrAddress,CTdiamond);
        ptrClient5 = std::make_shared<Client>("adam","nowak","007",ptrAddress,CTgold);

    }

    ~TestSuiteRentFixture() {

    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRent,TestSuiteRentFixture)


    BOOST_AUTO_TEST_CASE(ConstructorTests)
    {
    Rent r(rentID,ptrClient2,ptrVehicle,testDate);
    BOOST_TEST(r.getID() == rentID);
    BOOST_TEST(r.getVehicle() == ptrVehicle);
    BOOST_TEST(r.getClient() == ptrClient2);
    BOOST_TEST(r.getRentCost() == 0);
    }

    BOOST_AUTO_TEST_CASE(getRentDaysTests)
    {
        Rent r(rentID,ptrClient,ptrVehicle,testDate);
        r.setEndTime(testDate2);
        r.endRent(testDate2);
        BOOST_TEST(r.getRentDays() == 10);

    }

    BOOST_AUTO_TEST_CASE(ConstructorNegativeTestExceptions)
    {
        BOOST_REQUIRE_THROW(Rent r1(rentID,ptrClient, nullptr,testDate), std::logic_error);
        BOOST_REQUIRE_THROW(Rent r2(rentID,nullptr, ptrVehicle,testDate), std::logic_error);
        BOOST_REQUIRE_THROW(Rent r4(rentID,ptrClient, ptrVehicle,pt::not_a_date_time), std::logic_error);
    }

BOOST_AUTO_TEST_SUITE_END()
