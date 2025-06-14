//elidnana@gmail.com
/**
 * @file test_iterators.cpp
 * @brief Contains unit tests for all custom iterators of the MyContainer class using doctest.
 *
 * @details
 * Each iterator is tested against a known expected traversal order.
 * The iterators being tested:
 *   - AscendingOrder
 *   - DescendingOrder
 *   - SideCrossOrder
 *   - ReverseOrder
 *   - Order (default insertion order)
 *   - MiddleOutOrder
 *
 * The container used in all tests contains the elements: {7, 15, 6, 1, 2}
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "MyContainer.h" 
#include <iostream>
#include "AscendingOrder.h"
#include "DescendingOrder.h"
#include "Order.h"
#include "ReverseOrder.h"
#include "MiddleOutOrder.h"
#include "SideCrossOrder.h"
using namespace MyNamespace;


/**
 * @test AscendingOrder iterator should return elements in sorted ascending order.
 * Expected: {1, 2, 6, 7, 15}
 */
TEST_CASE("AscendingOrder iterator") {
    MyContainer<int> c;
    c.add(7);
    c.add(15);
    c.add(6);
    c.add(1);
    c.add(2);

    std::vector<int> expected = {1, 2, 6, 7, 15};
    size_t i = 0;
    for (auto it = c.AscendingOrder_begin(); it != c.AscendingOrder_end(); ++it) {
        CHECK(*it == expected[i++]);
    }
}


/**
 * @test DescendingOrder iterator should return elements in sorted descending order.
 * Expected: {15, 7, 6, 2, 1}
 */
TEST_CASE("DescendingOrder iterator") {
    MyContainer<int> c;
    c.add(7);
    c.add(15);
    c.add(6);
    c.add(1);
    c.add(2);

    std::vector<int> expected = {15, 7, 6, 2, 1};
    size_t i = 0;
    for (auto it = c.DescendingOrder_begin(); it != c.DescendingOrder_end(); ++it) {
        CHECK(*it == expected[i++]);
    }
}


/**
 * @test SideCrossOrder iterator should alternate from smallest to largest side.
 * Expected (sorted): {1, 15, 2, 7, 6}
 */
TEST_CASE("SideCrossOrder iterator") {
    MyContainer<int> c;
    c.add(7);
    c.add(15);
    c.add(6);
    c.add(1);
    c.add(2);

    std::vector<int> expected = {1, 15, 2, 7, 6};
    size_t i = 0;
    for (auto it = c.SideCrossOrder_begin(); it != c.SideCrossOrder_end(); ++it) {
   
        CHECK(*it == expected[i++]);
    }
}


/**
 * @test ReverseOrder iterator should return elements in reverse insertion order.
 * Expected: {2, 1, 6, 15, 7}
 */
TEST_CASE("ReverseOrder iterator") {
    MyContainer<int> c;
    c.add(7);
    c.add(15);
    c.add(6);
    c.add(1);
    c.add(2);

    std::vector<int> expected = {2, 1, 6, 15, 7};
    size_t i = 0;
    for (auto it = c.ReverseOrder_begin(); it != c.ReverseOrder_end(); ++it) {
        CHECK(*it == expected[i++]);
    }
}


/**
 * @test Order iterator should return elements in original insertion order.
 * Expected: {7, 15, 6, 1, 2}
 */
TEST_CASE("Order iterator (default)") {
    MyContainer<int> c;
    c.add(7);
    c.add(15);
    c.add(6);
    c.add(1);
    c.add(2);

    std::vector<int> expected = {7, 15, 6, 1, 2};
    size_t i = 0;
    for (auto it = c.Order_begin(); it != c.Order_end(); ++it) {
  
        CHECK(*it == expected[i++]);
    }
}


/**
 * @test MiddleOutOrder iterator should return elements starting from middle and alternating outwards.
 * For sorted input: {1, 2, 6, 7, 15} → Output: {6, 15, 2, 7, 1}
 */
TEST_CASE("MiddleOutOrder iterator") {
    MyContainer<int> c;
    c.add(7);
    c.add(15);
    c.add(6);
    c.add(1);
    c.add(2);

    std::vector<int> expected = {6, 15, 1, 7, 2};  // לפי הדוגמה שלך
    size_t i = 0;
    for (auto it = c.MiddleOutOrder_begin(); it != c.MiddleOutOrder_end(); ++it) {
        CHECK(*it == expected[i++]);
    }
}
