#include <boost/test/unit_test.hpp>
#include "managers/RentableItemManager.h"
#include <functional>
#include "model/RentableItem.h"


BOOST_AUTO_TEST_SUITE(TestSuiteRentableItem)

    BOOST_AUTO_TEST_CASE(findBySerialNumber) {
        RentableItemManager r;
        RentableItemPtr rItem = r.registerBook("123", "Edison", "Harry Potter","Zodiac");
        BOOST_TEST(rItem = r.getRentableItem("123"));

    }

    BOOST_AUTO_TEST_CASE(unregisterRentableItem) {
        RentableItemManager r;
        RentableItemPtr rItem = r.registerBook("123", "Edison", "Harry Potter","Zodiac");
        r.unregisterRentableItem(rItem);
        BOOST_TEST(rItem->isArchive() == true);

    }

    BOOST_AUTO_TEST_CASE(findBySerialNumberNegativeTest) {

        RentableItemManager r;
        RentableItemPtr rItem = r.registerBook("123", "Edison", "Harry Potter","Zodiac");
        RentableItemPtr rItem2 = r.registerBook("123", "Strachota", "Types of modern dance","Yona");
        BOOST_TEST(rItem == rItem2);

    }

    BOOST_AUTO_TEST_CASE(findRentableItemTest) {


        RentableItemManager r;
        RentableItemPtr rItem = r.registerBook("1", "Edison", "Harry Potter","Zodiac");
        RentableItemPtr rItem2 = r.registerBook("2", "Strachota", "Types of modern dance","Yona");
        RentableItemPtr rItem3 = r.registerBook("3", "Maklowicz", "Kuchnia NIE Polska","Zodiac");
        RentableItemPtr rItem4 = r.registerBook("4", "Strachota", "Types of modern dance, PART III","Yona");

        std::string test = "Strachota";
        RentableItemPredicate predicate = [test](const RentableItemPtr& ptr) {
            return ptr->getAuthor() == test;
        };
        std::vector<RentableItemPtr> result = r.findRentableItem(predicate);
        std::vector<RentableItemPtr> testResult;
        testResult.push_back(rItem2);
        testResult.push_back(rItem4);
        BOOST_CHECK_EQUAL(result.at(0), testResult.at(0));
        BOOST_CHECK_EQUAL(result.at(1), testResult.at(1));

}

BOOST_AUTO_TEST_SUITE_END()