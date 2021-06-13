#include <boost/test/unit_test.hpp>
#include "managers/RentManager.h"
#include <memory>
#include "model/Student.h"
#include <functional>
#include "model/Client.h"
#include "model/Address.h"
#include "model/universityEmployee.h"
#include "model/Article.h"
#include "model/Book.h"

struct TestSuiteRentManagerFixture {
    const std::string testFirstName = "Jon";
    const std::string testLastName = "Arbuckle";
    const std::string testPersonalID = "0123456789";
    ClientTypePtr testClientTypeStudent;
    ClientTypePtr testClientTypeUniversityEmployee;

    AddressPtr testaddress1;
    AddressPtr testaddress2;

    ClientPtr c1;
    ClientPtr c2;

    RentableItemPtr book;
    RentableItemPtr article;

    pt::ptime testDate1;
    pt::ptime testDate2;


    TestSuiteRentManagerFixture() {
        testClientTypeStudent = std::make_shared<Student>();
        testClientTypeUniversityEmployee = std::make_shared<universityEmployee>();

        testaddress1 = std::make_shared<Address>("London", "Accacia Avenue", "22");
        testaddress2 = std::make_shared<Address>("London", "Rue Morgue", "13");

        c1 = std::make_shared<Client>("Piotrus", "Strachota", "420", testaddress2, testClientTypeStudent);
        c2 = std::make_shared<Client>("Pawel", "Wieczorek", "007", testaddress1, testClientTypeUniversityEmployee);

        book = std::make_shared<Book>("123", "Edison", "Harry Potter","Zodiac");
        article = std::make_shared<Article>("777", "Watts", "Harry Potter 2","Harvard");

        testDate1 = pt::ptime(gr::date(2021,3,1), pt::hours(12) + pt::minutes(30));
        testDate2 = pt::ptime(gr::date(2021,3,21), pt::hours(12) + pt::minutes(30));

    }

    ~TestSuiteRentManagerFixture() {
    }

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRentManager, TestSuiteRentManagerFixture)

    BOOST_AUTO_TEST_CASE(findRentByRentableItemNegativeTest) {
        RentManager r;
        RentPtr r1 = r.rentRentableItem(c1,article,testDate1);

        RentableItemPtr i1 = book;
        RentPredicate predicate = [&i1](const RentPtr& ptr) {
            return ptr->getRentableItem()->getId() == i1->getId();
        };


        std::vector<RentPtr> result = r.findRents(predicate);
        BOOST_TEST(result.size() == 0);
    }

    BOOST_AUTO_TEST_CASE(findRentByRentableItemPositiveTest) {
        RentManager r;
        RentPtr r1 = r.rentRentableItem(c1,article,testDate1);
        RentPtr r2 = r.rentRentableItem(c2,book,testDate1);

        RentableItemPtr i1 = book;
        RentPredicate predicate = [&i1](const RentPtr& ptr) {
            return ptr->getRentableItem()->getId() == i1->getId();
        };


        std::vector<RentPtr> result = r.findRents(predicate);
        BOOST_TEST(result.size() == 1);
    }

    BOOST_AUTO_TEST_CASE(findRentsByPredicateTest) {
        RentManager r;
        RentPtr r1 = r.rentRentableItem(c1,book,testDate1);
        RentPtr r2 = r.rentRentableItem(c2,article,testDate2);

        std::string test = "Strachota";
        RentPredicate predicate = [test](const RentPtr& ptr) {
            return ptr->getClient()->getSurname() == test;
        };

        std::vector<RentPtr> result = r.findRents(predicate);
        std::vector<RentPtr> testResult;
        testResult.push_back(r1);
        BOOST_TEST(result.size() == 1);
   }


    BOOST_AUTO_TEST_CASE(getAllClientsRentsTest) {
        RentManager r;
        RentPtr r1 = r.rentRentableItem(c1,book,testDate1);
        RentPtr r2 = r.rentRentableItem(c1,article,testDate2);

        ClientPtr testC = c1;
        RentPredicate predicate = [&testC](const RentPtr& ptr) {
            return ptr->getClient()->getId() == testC->getId();
        };

        std::vector<RentPtr> result = r.findRents(predicate);
        BOOST_TEST(result.size() == 2);
    }


BOOST_AUTO_TEST_SUITE_END()