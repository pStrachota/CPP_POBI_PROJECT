#include <boost/test/unit_test.hpp>
#include "model/Rent.h"
#include "model/Student.h"
#include "model/universityEmployee.h"
#include "model/Client.h"
#include "model/Address.h"
#include "model/Article.h"
#include "model/Book.h"

struct TestSuiteRentFixture{

    ClientTypePtr testClientTypeStudent = std::make_shared<Student>();
    ClientTypePtr testClientTypeEmployee = std::make_shared<universityEmployee>();

    RentableItemPtr book = std::make_shared<Book>("123", "Edison", "Harry Potter","Zodiac");
    RentableItemPtr article = std::make_shared<Article>("777", "Watts", "Harry Potter 2","Harvard");

    AddressPtr testAddress1 = std::make_shared<Address>("London", "Rue Morgue", "13");
    AddressPtr testAddress2 = std::make_shared<Address>("London", "BakerSt", "21");

    pt::ptime testDate1 = pt::ptime(gr::date(2021,3,1), pt::hours(12) + pt::minutes(30));
    pt::ptime testDate2 = pt::ptime(gr::date(2021,3,21), pt::hours(12) + pt::minutes(30));
    pt::ptime testDate3 = pt::ptime(gr::date(2021,3,23), pt::hours(12) + pt::minutes(30));
    pt::ptime testDate4 = pt::ptime(gr::date(2021,3,28), pt::hours(12) + pt::minutes(30));
    pt::ptime testDate5 = pt::ptime(gr::date(2021,3,1), pt::hours(12) + pt::minutes(31));
    pt::ptime testDate6 = pt::ptime(gr::date(2021,4,1), pt::hours(12) + pt::minutes(31));

    ClientPtr client1 = std::make_shared<Client>("Jake", "Paul", "007", testAddress1, testClientTypeStudent);
    ClientPtr client2 = std::make_shared<Client>("Walter", "White", "123", testAddress2, testClientTypeEmployee);

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRent,TestSuiteRentFixture)


    BOOST_AUTO_TEST_CASE(ConstructorTests)
    {
    Rent r1(testDate1,client1,book);
    BOOST_TEST(r1.getBeginTime() == testDate1);
    BOOST_TEST(r1.getClient() == client1);
    BOOST_TEST(r1.getRentableItem() == book);
    }

    BOOST_AUTO_TEST_CASE(EndTimeSetterTest)
    {
        Rent r1(testDate1,client1,book);
        r1.setEndTime(testDate2);
        BOOST_TEST(r1.getEndTime() == testDate2);
    }

    BOOST_AUTO_TEST_CASE(CostSetterTest)
    {
        Rent r1(testDate1,client1,book);
        r1.setRentCost(1.5);
        BOOST_TEST(r1.getRentCost() == 1.5);
    }

    BOOST_AUTO_TEST_CASE(PenaltyDaysGetterTest)
    {
        //client student, max days 20
        Rent r1(testDate1,client1,book);
        r1.setEndTime(testDate2);
        BOOST_TEST(r1.getRentPenaltyDays() == 0);
        r1.setEndTime(testDate3);
        BOOST_TEST(r1.getRentPenaltyDays() == 2);
        r1.setEndTime(testDate4);
        BOOST_TEST(r1.getRentPenaltyDays() == 7);
        r1.setEndTime(testDate5);
        BOOST_TEST(r1.getRentPenaltyDays() == 0);

        //client univ employee, max days 30
        Rent r2(testDate1,client2,book);
        r2.setEndTime(testDate2);
        BOOST_TEST(r2.getRentPenaltyDays() == 0);
        r2.setEndTime(testDate3);
        BOOST_TEST(r2.getRentPenaltyDays() == 0);
        r2.setEndTime(testDate6);
        BOOST_TEST(r2.getRentPenaltyDays() == 1);

    }

    BOOST_AUTO_TEST_CASE(EndRentTestClientStudent)
    {
        // client student, max days 20
        Rent r1(testDate1,client1,book);

        r1.endRent(testDate2);
        BOOST_TEST(r1.getRentCost() == (0 * 0.5),boost::test_tools::tolerance(0.01));
        r1.endRent(testDate3);
        BOOST_TEST(r1.getRentCost() == (2 * 0.5),boost::test_tools::tolerance(0.01));
        r1.endRent(testDate4);
        BOOST_TEST(r1.getRentCost() == (7 * 0.5),boost::test_tools::tolerance(0.01));
        r1.endRent(testDate5);
        BOOST_TEST(r1.getRentCost() == (0 * 0.5),boost::test_tools::tolerance(0.01));

        //client univ employee, max days 30
        Rent r2(testDate1,client2,book);
        r2.endRent(testDate2);
        BOOST_TEST(r2.getRentCost() == 0,boost::test_tools::tolerance(0.01));
        r2.endRent(testDate3);
        BOOST_TEST(r2.getRentCost() == 0,boost::test_tools::tolerance(0.01));
        r2.endRent(testDate6);
        BOOST_TEST(r2.getRentCost() == (1* 0.2),boost::test_tools::tolerance(0.01));
    }




BOOST_AUTO_TEST_SUITE_END()
