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

    BookPtr book = std::make_shared<Book>("123", "Edison", "Harry Potter","Zodiac");
    ArticlePtr article = std::make_shared<Article>("777", "Watts", "Harry Potter 2","Harvard");

    AddressPtr testAddress1 = std::make_shared<Address>("London", "Rue Morgue", "13");
    AddressPtr testAddress2 = std::make_shared<Address>("London", "BakerSt", "21");

    pt::ptime testDate1 = pt::ptime(gr::date(2021,3,1), pt::hours(12) + pt::minutes(30));
    pt::ptime testDate2 = pt::ptime(gr::date(2021,3,21), pt::hours(12) + pt::minutes(30));
    pt::ptime testDate3 = pt::ptime(gr::date(2021,3,23), pt::hours(12) + pt::minutes(30));
    pt::ptime testDate4 = pt::ptime(gr::date(2021,3,28), pt::hours(12) + pt::minutes(30));
    pt::ptime testDate5 = pt::ptime(gr::date(2021,3,1), pt::hours(12) + pt::minutes(31));

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
        Rent r1(testDate1,client1,book);
        r1.setEndTime(testDate2);
        BOOST_TEST(r1.getRentPenaltyDays() == 0);
        r1.setEndTime(testDate3);
        BOOST_TEST(r1.getRentPenaltyDays() == 2);
        r1.setEndTime(testDate4);
        BOOST_TEST(r1.getRentPenaltyDays() == 7);
        r1.setEndTime(testDate5);
        BOOST_TEST(r1.getRentPenaltyDays() == 0);
    }

    BOOST_AUTO_TEST_CASE(EndRentTest)
    {
    // client student
        Rent r1(testDate1,client1,book);

        r1.endRent(testDate2);
        BOOST_TEST(r1.getRentCost() == (0 * 0.5));
        r1.endRent(testDate3);
        BOOST_TEST(r1.getRentCost() == (2 * 0.5));
        r1.endRent(testDate4);
        BOOST_TEST(r1.getRentCost() == (7 * 0.5));
        r1.endRent(testDate5);
        BOOST_TEST(r1.getRentCost() == (0 * 0.5));
    }


BOOST_AUTO_TEST_SUITE_END()
