#include <boost/test/unit_test.hpp>
#include <repositories/RentRepository.h>
#include "model/Student.h"
#include "model/universityEmployee.h"
#include <memory>
#include <functional>
#include "model/Address.h"
#include "model/Client.h"
#include "model/Article.h"
#include "model/Book.h"
#include "model/Rent.h"

struct TestSuiteRentRepositoryFixture {
    const std::string testFirstName = "Jon";
    const std::string testLastName = "Arbuckle";
    const std::string testPersonalID = "0123456789";


    ClientTypePtr testClientTypeStudent = std::make_shared<Student>();
    ClientTypePtr  testClientTypeUniversityEmployee = std::make_shared<universityEmployee>();

    RentableItemPtr book;
    RentableItemPtr article;

    pt::ptime testDate1;
    pt::ptime testDate2;

    AddressPtr testaddress1 = std::make_shared<Address>("London", "Accacia Avenue", "22");
    AddressPtr testaddress2 = std::make_shared<Address>("London", "Rue Morgue", "13");

    ClientPtr c1 = std::make_shared<Client>("Piotrus", "Strachota", "420", testaddress2, testClientTypeStudent);
    ClientPtr c2 = std::make_shared<Client>("Pawel", "Wieczorek", "007", testaddress1, testClientTypeUniversityEmployee);


    TestSuiteRentRepositoryFixture() {

        testDate1 = pt::ptime(gr::date(2021,3,1), pt::hours(12) + pt::minutes(30));
        testDate2 = pt::ptime(gr::date(2021,3,21), pt::hours(12) + pt::minutes(30));

        book = std::make_shared<Book>("123", "Edison", "Harry Potter","Zodiac");
        article = std::make_shared<Article>("777", "Watts", "Harry Potter 2","Harvard");

    }

    ~TestSuiteRentRepositoryFixture() {

    }

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRentRepository, TestSuiteRentRepositoryFixture)

    BOOST_AUTO_TEST_CASE(GetRentSize) {
        TestSuiteRentRepositoryFixture f;
        RentPtr r1 = std::make_shared<Rent>(testDate1,c1,book);
        RentPtr r2 = std::make_shared<Rent>(testDate2,c2,article);
        RentPtr r3 = std::make_shared<Rent>(testDate1,c2,book);
        RentRepository repo;
        BOOST_TEST(repo.objectSize() == 0);
        repo.add(r1);
        BOOST_TEST(repo.objectSize() == 1);
        repo.add(r2);
        BOOST_TEST(repo.objectSize() == 2);
        repo.add(r3);
        BOOST_TEST(repo.objectSize() == 3);

    }

    BOOST_AUTO_TEST_CASE(AddRentPositivetest) {
        RentPtr r1 = std::make_shared<Rent>(testDate1,c1,book);
        RentPtr r2 = std::make_shared<Rent>(testDate2,c2,article);
        RentRepository repo;
        repo.add(r1);
        repo.add(r2);
        BOOST_TEST(repo.getObject(0) == r1);
        BOOST_TEST(repo.getObject(1) == r2);
    }

    BOOST_AUTO_TEST_CASE(RemoveRentPositiveTest) {
        RentPtr r1 = std::make_shared<Rent>(testDate1,c1,book);
        RentPtr r2 = std::make_shared<Rent>(testDate2,c2,article);
        RentRepository repo;
        repo.add(r1);
        repo.add(r2);
        repo.removeObject(r1);
        BOOST_TEST(repo.getObject(0) == r2);
    }

    BOOST_AUTO_TEST_CASE(RemoveRentNegativeTest) {
        RentPtr r1 = std::make_shared<Rent>(testDate1,c1,book);
        RentPtr r2 = std::make_shared<Rent>(testDate2,c2,article);
        RentRepository repo;
        repo.add(r1);
        repo.add(r2);
        repo.removeObject(nullptr);
        BOOST_TEST(repo.objectSize() == 2);

    }

    BOOST_AUTO_TEST_CASE(AddRentNegativeTest) {
        RentPtr r1 = std::make_shared<Rent>(testDate1,c1,book);
        RentPtr r2 = std::make_shared<Rent>(testDate2,c2,article);
        RentRepository repo;
        repo.add(r1);
        repo.add(r2);
        repo.add(nullptr);
        BOOST_TEST(repo.objectSize() == 2);

    }



BOOST_AUTO_TEST_SUITE_END()

