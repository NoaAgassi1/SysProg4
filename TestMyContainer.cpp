//agassinoa20@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.hpp"
#include "MyContainer.hpp"

using namespace Container;

/// @brief Auxiliary function that initializes the container with test integers
/// @param container A reference to a MyContainer to populate
void initIntContainer(MyContainer<>& container) {
    container.add(5);
    container.add(3);
    container.add(-7);
    container.add(10);
    container.add(3);
    container.add(6);
}

/// @brief Basic functional tests for MyContainer (add, remove, size)
TEST_SUITE("Basic Container Tests") {

    /// @test Test that add and size behave correctly
    TEST_CASE("Add and Size Test") {
        MyContainer<> container;
        CHECK(container.size() == 0);
        initIntContainer(container);
        CHECK(container.size() == 6);
    }

    /// @test Test correct behavior of remove and error throwing
    TEST_CASE("Remove Test") {
        MyContainer<> container;

        CHECK_THROWS_AS(container.remove(3), std::invalid_argument);

        initIntContainer(container);

        CHECK_THROWS_AS(container.remove(99), std::invalid_argument);

        container.remove(10);
        CHECK(container.size() == 5);

        container.remove(3);
        CHECK(container.size() == 3);
    }
}

/// @brief Tests for Order iterator (insertion order)
TEST_SUITE("Order Iterator Tests") {

    /// @test Order iteration over an empty container
    TEST_CASE("Empty Container Order") {
        MyContainer<> container;
        for (auto it = container.beginOrder(); it != container.endOrder(); ++it)
            CHECK(false); 
    }

    /// @test Normal iteration should match insertion order
    TEST_CASE("Normal Order") {
        MyContainer<> container;
        initIntContainer(container);
        int expected[] = {5, 3, -7, 10, 3, 6};
        int i = 0;
        for (auto it = container.beginOrder(); it != container.endOrder(); ++it)
            CHECK_EQ(*it, expected[i++]);
    }
}

/// @brief Tests for AscendingOrder iterator
TEST_CASE("Ascending iterator - varied behaviors") {
    MyContainer<> nums;

    // Empty container – should not enter loop
    for (auto it = nums.beginAscending(); it != nums.endAscending(); ++it) {
        FAIL("Iterator should not run on empty container");
    }

    // Insert values including duplicates and negatives
    nums.add(12);
    nums.add(-5);
    nums.add(0);
    nums.add(7);
    nums.add(-5);
    nums.add(1);

    std::vector<int> ascendingExpected = {-5, -5, 0, 1, 7, 12};

    size_t index = 0;
    for (auto it = nums.beginAscending(); it != nums.endAscending(); ++it) {
        CHECK_EQ(*it, ascendingExpected[index++]);
    }

    // Operator checks
    auto it = nums.beginAscending();
    CHECK_EQ(*it, -5);
    CHECK_EQ(*++it, -5);
    CHECK_EQ(*it++, -5);
    CHECK_EQ(*it, 0);
}

/// @brief Tests for DescendingOrder iterator
TEST_CASE("Descending iterator - full walk with checks") {
    MyContainer<> data;
    for (auto d : {4, 9, 1, 4, 0, -2}) {
        data.add(d);
    }

    std::vector<int> expected = {9, 4, 4, 1, 0, -2};
    int j = 0;
    for (auto it = data.beginDescending(); it != data.endDescending(); ++it) {
        CHECK_EQ(*it, expected[j++]);
    }

    auto it = data.beginDescending();
    CHECK_EQ(*it, 9);
    ++it;
    CHECK_EQ(*it, 4);
    it++;
    CHECK_EQ(*it, 4);
}

/// @brief Tests for SideCrossOrder iterator
TEST_CASE("SideCross iterator - alternating traversal") {
    MyContainer<> seq;
    for (int v : {3, 1, 9, 7, 5, 2}) {
        seq.add(v);
    }

    std::vector<int> expected = {1, 9, 2, 7, 3, 5};
    int i = 0;
    for (auto it = seq.beginSideCross(); it != seq.endSideCross(); ++it) {
        CHECK_EQ(*it, expected[i++]);
    }

    seq.remove(5);
    std::vector<int> newExpected = {1, 9, 2, 7, 3};
    i = 0;
    for (auto it = seq.beginSideCross(); it != seq.endSideCross(); ++it) {
        CHECK_EQ(*it, newExpected[i++]);
    }
}

/// @brief Tests for ReverseOrder iterator
TEST_CASE("Reverse iterator - from end to start") {
    MyContainer<> values;
    values.add(100);
    values.add(-3);
    values.add(20);

    int reversed[] = {20, -3, 100};
    int i = 0;

    for (auto rit = values.reverse_begin(); rit != values.reverse_end(); ++rit) {
        CHECK_EQ(*rit, reversed[i++]);
    }

    auto it = values.reverse_begin();
    CHECK_EQ(*it, 20);
    ++it;
    CHECK_EQ(*it, -3);
}

/// @brief Tests for MiddleOutOrder iterator
TEST_CASE("MiddleOut iterator - center-based traversal and operator checks") {
    MyContainer<> c;

    for (auto it = c.beginMiddleOut(); it != c.endMiddleOut(); ++it)
        CHECK(false);

    for (int v : {11, 8, 15, 2, 4}) {
        c.add(v);
    }

    std::vector<int> expected = {15, 8, 2, 11, 4};
    size_t idx = 0;
    for (auto it = c.beginMiddleOut(); it != c.endMiddleOut(); ++it) {
        CHECK_EQ(*it, expected[idx++]);
    }

    c.remove(15);
    std::vector<int> expected2 = {8,11,2,4};
    idx = 0;
    for (auto it = c.beginMiddleOut(); it != c.endMiddleOut(); ++it) {
        CHECK_EQ(*it, expected2[idx++]);
    }

    auto it = c.beginMiddleOut();
    CHECK_EQ(*it, 8);
    CHECK_EQ(*++it, 11);
    CHECK_EQ(*it++, 11);
    CHECK_EQ(*it, 2);
}
