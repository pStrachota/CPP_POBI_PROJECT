#include <boost/test/unit_test.hpp>
#include "model/Book.h"
#include "typedefs.h"

BOOST_AUTO_TEST_SUITE(TestSuiteBook)

    BOOST_AUTO_TEST_CASE(ParameterConstructorTests) {
        BookPtr book = std::make_shared<Book>("123", "Edison", "Harry Potter","Zodiac");
        BOOST_TEST(book->getSerialNumber() == "123");
        BOOST_TEST(book->getAuthor() == "Edison");
        BOOST_TEST(book->getTitle() == "Harry Potter");
        BOOST_TEST(book->getPublishingHouse() == "Zodiac");

    }

BOOST_AUTO_TEST_SUITE_END()
