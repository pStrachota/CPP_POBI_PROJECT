#include <boost/test/unit_test.hpp>
#include <memory>
#include <functional>
#include "model/Article.h"
#include "model/Book.h"
#include "repositories/RentableItemRepository.h"

struct TestSuiteRentableItemRepositoryFixture {
    const std::string testTitle1 = "Jon Wick 1";
    const std::string testTitle2 = "Jon Wick 2";
    const std::string testSerialNumber2 = "3425432";
    const std::string testSerialNumber1 = "3242353";
    const std::string testAuthor1 = "Arbuckle";
    const std::string testAuthor2 = "Smith";
    const std::string testPublishingCompany = "Zodiac";
    const std::string testParentOrganisation= "MIT";
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRentableItemRepository, TestSuiteRentableItemRepositoryFixture)


    BOOST_AUTO_TEST_CASE(AddRentableItemPositivetest) {
        BookPtr book1 = std::make_shared<Book>(testSerialNumber1, testAuthor1, testTitle1, testPublishingCompany);
        ArticlePtr article2 = std::make_shared<Article>(testSerialNumber2, testAuthor2, testTitle2, testParentOrganisation);

        RentableItemRepository repo;
        repo.add(book1);
        repo.add(article2);
        BOOST_TEST(repo.getObject(0) == book1);
        BOOST_TEST(repo.getObject(1) == article2);
    }

    BOOST_AUTO_TEST_CASE(GetRentableItemSize) {
        BookPtr book1 = std::make_shared<Book>(testSerialNumber1, testAuthor1, testTitle1, testPublishingCompany);
        ArticlePtr article2 = std::make_shared<Article>(testSerialNumber2, testAuthor2, testTitle2, testParentOrganisation);

        RentableItemRepository repo;
        BOOST_TEST(repo.objectSize() == 0);
        repo.add(book1);
        BOOST_TEST(repo.objectSize() == 1);
        repo.add(article2);
        BOOST_TEST(repo.objectSize() == 2);

    }

    BOOST_AUTO_TEST_CASE(RemoveRentableItemPositiveTest) {
        BookPtr book1 = std::make_shared<Book>(testSerialNumber1, testAuthor1, testTitle1, testPublishingCompany);
        ArticlePtr article2 = std::make_shared<Article>(testSerialNumber2, testAuthor2, testTitle2, testParentOrganisation);
        RentableItemRepository repo;
        repo.add(book1);
        repo.add(article2);
        repo.removeObject(book1);
        BOOST_TEST(repo.getObject(0) == article2);
    }

    BOOST_AUTO_TEST_CASE(RemoveRentableItemNegativeTest) {
        BookPtr book1 = std::make_shared<Book>(testSerialNumber1, testAuthor1, testTitle1, testPublishingCompany);
        ArticlePtr article2 = std::make_shared<Article>(testSerialNumber2, testAuthor2, testTitle2, testParentOrganisation);

        RentableItemRepository repo;
        repo.add(book1);
        repo.add(article2);
        repo.removeObject(nullptr);
        BOOST_TEST(repo.objectSize() == 2);

    }

    BOOST_AUTO_TEST_CASE(AddRentableItemNegativeTest) {
        BookPtr book1 = std::make_shared<Book>(testSerialNumber1, testAuthor1, testTitle1, testPublishingCompany);
        ArticlePtr article2 = std::make_shared<Article>(testSerialNumber2, testAuthor2, testTitle2, testParentOrganisation);
        RentableItemRepository repo;
        repo.add(book1);
        repo.add(article2);
        repo.add(nullptr);
        BOOST_TEST(repo.objectSize() == 2);
    }



BOOST_AUTO_TEST_SUITE_END()


