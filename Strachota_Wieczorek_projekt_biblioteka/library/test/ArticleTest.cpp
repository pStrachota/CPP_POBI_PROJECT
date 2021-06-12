#include <boost/test/unit_test.hpp>
#include "model/Article.h"
#include "typedefs.h"

BOOST_AUTO_TEST_SUITE(TestSuiteArticle)

    BOOST_AUTO_TEST_CASE(ParameterConstructorTests) {
        ArticlePtr article = std::make_shared<Article>("123", "Edison", "Harry Potter","Harvard");
        BOOST_TEST(article->getId() == "123");
        BOOST_TEST(article->getAuthor() == "Edison");
        BOOST_TEST(article->getTitle() == "Harry Potter");
        BOOST_TEST(article->getParentOrganisation() == "Harvard");

    }

BOOST_AUTO_TEST_SUITE_END()

