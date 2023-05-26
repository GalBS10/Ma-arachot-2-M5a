#include "doctest.h"
#include "sources/MagicalContainer.h"
#include <stdexcept>

// Test case for adding elements to the MagicalContainer
TEST_CASE("Adding elements to MagicalContainer") {
    MagicalContainer container;

    SUBCASE("Adding a single element") {
        container.addElement(10);
        CHECK(container.size() == 1);
    }

    SUBCASE("Adding multiple elements") {
        container.addElement(10);
        container.addElement(20);
        container.addElement(30);
        CHECK(container.size() == 3);
    }
}

// Test case for removing elements from the MagicalContainer
TEST_CASE("Removing elements from MagicalContainer") {
    MagicalContainer container;

    SUBCASE("Removing an existing element") {
        container.addElement(10);
        container.addElement(20);
        CHECK_NOTHROW(container.removeElement(10));
        CHECK(container.size() == 1);
    }

    SUBCASE("Removing a non-existing element") {
        container.addElement(10);
        container.addElement(20);
        CHECK_THROWS_AS(container.removeElement(30), std::runtime_error);
        CHECK(container.size() == 2);
    }
}

// Test case for the AscendingIterator
TEST_CASE("AscendingIterator") {
    MagicalContainer container;
    container.addElement(10);
    container.addElement(20);
    container.addElement(30);

    SUBCASE("Iterating over elements") {
        MagicalContainer::AscendingIterator it = container.beginAscending();
        CHECK(*it == 10);
        ++it;
        CHECK(*it == 20);
        ++it;
        CHECK(*it == 30);
        ++it;
        CHECK(it == container.endAscending());
    }

    SUBCASE("Iterating over an empty container") {
        MagicalContainer emptyContainer;
        MagicalContainer::AscendingIterator it = emptyContainer.beginAscending();
        CHECK(it == emptyContainer.endAscending());
    }
}

// Test case for the SideCrossIterator
TEST_CASE("SideCrossIterator") {
    MagicalContainer container;
    container.addElement(10);
    container.addElement(20);
    container.addElement(30);
    container.addElement(40);

    SUBCASE("Iterating over elements") {
        MagicalContainer::SideCrossIterator it = container.beginSideCross();
        CHECK(*it == 10);
        ++it;
        CHECK(*it == 40);
        ++it;
        CHECK(*it == 20);
        ++it;
        CHECK(*it == 30);
        ++it;
        CHECK(it == container.endSideCross());
    }

    SUBCASE("Iterating over an empty container") {
        MagicalContainer emptyContainer;
        MagicalContainer::SideCrossIterator it = emptyContainer.beginSideCross();
        CHECK(it == emptyContainer.endSideCross());
    }
}

// Test case for the PrimeIterator
TEST_CASE("PrimeIterator") {
    MagicalContainer container;
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);

    SUBCASE("Iterating over elements") {
        MagicalContainer::PrimeIterator it = container.beginPrime();
        CHECK(*it == 2);
        ++it;
        CHECK(*it == 3);
        ++it;
        CHECK(*it == 5);
        ++it;
        CHECK(it == container.endPrime());
    }

    SUBCASE("Iterating over an empty container") {
        MagicalContainer emptyContainer;
        MagicalContainer::PrimeIterator it = emptyContainer.beginPrime();
        CHECK(it == emptyContainer.endPrime());
    }
}

// Test case for comparing iterators from different containers
TEST_CASE("Comparing iterators from different containers") {
    MagicalContainer container1;
    for (int i = 1; i <= 10; ++i) {
        container1.addElement(i * 10);
    }

    MagicalContainer container2;
    for (int i = 1; i <= 10; ++i) {
        container2.addElement(i * 10);
    }

    SUBCASE("Comparing AscendingIterator with different containers") {
        MagicalContainer::AscendingIterator it1 = container1.beginAscending();
        MagicalContainer::AscendingIterator it2 = container2.beginAscending();
        CHECK(it1 != it2);
        CHECK(it1 < it2);
        CHECK(!(it1 > it2));
    }

    SUBCASE("Comparing SideCrossIterator with different containers") {
        MagicalContainer::SideCrossIterator it1 = container1.beginSideCross();
        MagicalContainer::SideCrossIterator it2 = container2.beginSideCross();
        CHECK(it1 != it2);
        CHECK(it1 < it2);
        CHECK(!(it1 > it2));
    }

    SUBCASE("Comparing PrimeIterator with different containers") {
        MagicalContainer::PrimeIterator it1 = container1.beginPrime();
        MagicalContainer::PrimeIterator it2 = container2.beginPrime();
        CHECK(it1 != it2);
        CHECK(it1 < it2);
        CHECK(!(it1 > it2));
    }
}
//--------------------------------------------------------------
// Test case for comparing iterators from the same container
TEST_CASE("Comparing iterators from the same container") {
    MagicalContainer container;
    for (int i = 1; i <= 10; ++i) {
        container.addElement(i * 10);
    }

    SUBCASE("Comparing AscendingIterator with itself") {
        MagicalContainer::AscendingIterator it1 = container.beginAscending();
        MagicalContainer::AscendingIterator it2 = container.beginAscending();
        CHECK(it1 == it2);
        CHECK(!(it1 != it2));
        CHECK(!(it1 < it2));
        CHECK(!(it1 > it2));
    }

    SUBCASE("Comparing SideCrossIterator with itself") {
        MagicalContainer::SideCrossIterator it1 = container.beginSideCross();
        MagicalContainer::SideCrossIterator it2 = container.beginSideCross();
        CHECK(it1 == it2);
        CHECK(!(it1 != it2));
        CHECK(!(it1 < it2));
        CHECK(!(it1 > it2));
    }

    SUBCASE("Comparing PrimeIterator with itself") {
        MagicalContainer::PrimeIterator it1 = container.beginPrime();
        MagicalContainer::PrimeIterator it2 = container.beginPrime();
        CHECK(it1 == it2);
        CHECK(!(it1 != it2));
        CHECK(!(it1 < it2));
        CHECK(!(it1 > it2));
    }
}
//------------------------------------------------------
// Test case for traversing the AscendingIterator
TEST_CASE("Traversing AscendingIterator") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(4);
    container.addElement(5);
    container.addElement(14);

    SUBCASE("Iterating in ascending order") {
        MagicalContainer::AscendingIterator it = container.beginAscending();
        CHECK(*it == 1);
        ++it;
        CHECK(*it == 2);
        ++it;
        CHECK(*it == 4);
        ++it;
        CHECK(*it == 5);
        ++it;
        CHECK(*it == 14);
        ++it;
        CHECK(it == container.endAscending());
    }
}

// Test case for traversing the PrimeIterator
TEST_CASE("Traversing PrimeIterator") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(4);
    container.addElement(5);
    container.addElement(14);

    SUBCASE("Iterating over prime elements") {
        MagicalContainer::PrimeIterator it = container.beginPrime();
        CHECK(*it == 2);
        ++it;
        CHECK(*it == 5);
        ++it;
        CHECK(it == container.endPrime());
    }
}

// Test case for the SideCrossIterator
TEST_CASE("SideCrossIterator") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(4);
    container.addElement(5);
    container.addElement(14);

    SUBCASE("Iterating in side-cross order from start to end") {
        MagicalContainer::SideCrossIterator itStart = container.beginSideCross();
        MagicalContainer::SideCrossIterator itEnd = container.endSideCross();

        CHECK(*itStart == 1);
        CHECK(*itEnd == 14);
        ++itStart;
        --itEnd;
        CHECK(*itStart == 14);
        CHECK(*itEnd == 1);
        ++itStart;
        --itEnd;
        CHECK(*itStart == 2);
        CHECK(*itEnd == 5);
        ++itStart;
        --itEnd;
        CHECK(*itStart == 5);
        CHECK(*itEnd == 2);
        ++itStart;
        --itEnd;
        CHECK(*itStart == 4);
        CHECK(*itEnd == 4);
        ++itStart;
        --itEnd;
        CHECK(itStart == itEnd);
        CHECK(itStart == container.endSideCross());
    }
}
//-------------------------------------------------------
// Test case for comparing AscendingIterator
TEST_CASE("Comparing AscendingIterator") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(4);
    container.addElement(5);
    container.addElement(14);

    SUBCASE("Comparing iterators after increments") {
        MagicalContainer::AscendingIterator it1 = container.beginAscending();
        MagicalContainer::AscendingIterator it2 = container.beginAscending();

        CHECK((it1 == it2));
        CHECK_FALSE((it1 != it2));

        ++it1;
        CHECK_FALSE((it1 == it2));
        CHECK((it1 != it2));

        ++it2;
        CHECK((it1 == it2));
        CHECK_FALSE((it1 != it2));

        ++it1;
        CHECK_FALSE((it1 == it2));
        CHECK((it1 != it2));

        ++it2;
        CHECK((it1 == it2));
        CHECK_FALSE((it1 != it2));

        ++it1;
        CHECK_FALSE((it1 == it2));
        CHECK((it1 != it2));

        ++it2;
        CHECK((it1 == it2));
        CHECK_FALSE((it1 != it2));

        ++it1;
        CHECK_FALSE((it1 == it2));
        CHECK((it1 != it2));

        ++it2;
        CHECK((it1 == container.endAscending()));
        CHECK_FALSE((it1 != container.endAscending()));

        ++it1;
        CHECK((it1 == container.endAscending()));
        CHECK_FALSE((it1 != container.endAscending()));
    }
}

// Test case for comparing PrimeIterator
TEST_CASE("Comparing PrimeIterator") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(4);
    container.addElement(5);
    container.addElement(14);

    SUBCASE("Comparing iterators after increments") {
        MagicalContainer::PrimeIterator it1 = container.beginPrime();
        MagicalContainer::PrimeIterator it2 = container.beginPrime();

        CHECK((it1 == it2));
        CHECK_FALSE((it1 != it2));

        ++it1;
        CHECK_FALSE((it1 == it2));
        CHECK((it1 != it2));

        ++it2;
        CHECK((it1 == it2));
        CHECK_FALSE((it1 != it2));

        ++it1;
        CHECK_FALSE((it1 == it2));
        CHECK((it1 != it2));

        ++it2;
        CHECK((it1 == it2));
        CHECK_FALSE((it1 != it2));

        ++it1;
        CHECK((it1 == container.endPrime()));
        CHECK_FALSE((it1 != container.endPrime()));

        ++it2;
        CHECK((it2 == container.endPrime()));
        CHECK_FALSE((it2 != container.endPrime()));
    }
}

// Test case for comparing SideCrossIterator
TEST_CASE("Comparing SideCrossIterator") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(4);
    container.addElement(5);
    container.addElement(14);

    SUBCASE("Comparing iterators after increments") {
        MagicalContainer::SideCrossIterator itStart1 = container.beginSideCross();
        MagicalContainer::SideCrossIterator itStart2 = container.beginSideCross();
        MagicalContainer::SideCrossIterator itEnd1 = container.endSideCross();
        MagicalContainer::SideCrossIterator itEnd2 = container.endSideCross();

        CHECK((itStart1 == itStart2));
        CHECK_FALSE((itStart1 != itStart2));

        CHECK((itEnd1 == itEnd2));
        CHECK_FALSE((itEnd1 != itEnd2));

        ++itStart1;
        CHECK_FALSE((itStart1 == itStart2));
        CHECK((itStart1 != itStart2));

        ++itStart2;
        CHECK((itStart1 == itStart2));
        CHECK_FALSE((itStart1 != itStart2));

        --itEnd1;
        CHECK_FALSE((itEnd1 == itEnd2));
        CHECK((itEnd1 != itEnd2));

        --itEnd2;
        CHECK((itEnd1 == itEnd2));
        CHECK_FALSE((itEnd1 != itEnd2));

        ++itStart1;
        CHECK_FALSE((itStart1 == itEnd1));
        CHECK((itStart1 != itEnd1));

        ++itStart2;
        CHECK((itStart1 == itEnd2));
        CHECK_FALSE((itStart1 != itEnd2));

        --itEnd1;
        CHECK_FALSE((itEnd1 == itStart1));
        CHECK((itEnd1 != itStart1));

        --itEnd2;
        CHECK((itEnd1 == itStart2));
        CHECK_FALSE((itEnd1 != itStart2));

        ++itStart1;
        CHECK((itStart1 == itStart1));
        CHECK_FALSE((itStart1 != itStart1));

        --itEnd1;
        CHECK((itEnd1 == itEnd1));
        CHECK_FALSE((itEnd1 != itEnd1));
    }
}
//---------------------------------------------------

