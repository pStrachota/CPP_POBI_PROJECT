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
    AddressPtr testaddress1;
    AddressPtr testaddress2;
    ClientTypePtr testClientTypeStudent;
    ClientTypePtr testClientTypeUniversityEmployee;
    BookPtr book;
    ArticlePtr article;
    ClientPtr c1;
    ClientPtr c2;
    pt::ptime testDate1;
    pt::ptime testDate2;


    TestSuiteRentManagerFixture() {
        testClientTypeStudent = std::make_shared<Student>();
        testClientTypeUniversityEmployee = std::make_shared<universityEmployee>();

        pt::ptime testDate1 = pt::ptime(gr::date(2021,3,1), pt::hours(12) + pt::minutes(30));
        pt::ptime testDate2 = pt::ptime(gr::date(2021,3,21), pt::hours(12) + pt::minutes(30));

        testaddress1 = std::make_shared<Address>("London", "Accacia Avenue", "22");
        testaddress2 = std::make_shared<Address>("London", "Rue Morgue", "13");

        ClientPtr c1 = std::make_shared<Client>("Piotrus", "Strachota", "420", testaddress2, testClientTypeStudent,
                                                nullptr);
        ClientPtr c2 = std::make_shared<Client>("Pawel", "Wieczorek", "007", testaddress1, testClientTypeUniversityEmployee,
                                                nullptr);

        BookPtr book = std::make_shared<Book>("123", "Edison", "Harry Potter","Zodiac");
        ArticlePtr article = std::make_shared<Article>("777", "Watts", "Harry Potter 2","Harvard");

    }

    ~TestSuiteRentManagerFixture() {
    }

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRentManager, TestSuiteRentManagerFixture)




BOOST_AUTO_TEST_SUITE_END()