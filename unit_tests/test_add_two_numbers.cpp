#include "add_two_numbers.hpp"
#include <gtest/gtest.h>

#include "test_utils.hpp"

TEST(AddNumbers,Classic) {
    LinkedList ll1;
    LinkedList ll2;
    buildList(ll1 ,{2,4,7,1});
    buildList(ll2,{9,4,5});

    Node* resultHead=addTwoNumbers(ll1.getHead(),ll2.getHead());
    // If you already have a helper like toVector(Node* head) used in other tests:
    EXPECT_EQ(toVector(resultHead), (std::vector<int>{1,9,2,2}));
    freeList(resultHead);
}

TEST(AddNumbers, SecondListLonger) {
    LinkedList ll1;
    LinkedList ll2;
    buildList(ll1, {9,9});
    buildList(ll2, {1,0,0}); // 99 + 001 = 100 (reverse digits)
    Node* resultHead = addTwoNumbers(ll1.getHead(), ll2.getHead());
    EXPECT_EQ(toVector(resultHead), (std::vector<int>{0,0,1}));
    freeList(resultHead);
}

TEST(AddNumbers, FirstListLonger) {
    LinkedList ll1;
    LinkedList ll2;
    buildList(ll1, {1,0,0}); // 001
    buildList(ll2, {9,9});   // 99
    Node* resultHead = addTwoNumbers(ll1.getHead(), ll2.getHead());
    EXPECT_EQ(toVector(resultHead), (std::vector<int>{0,0,1}));
    freeList(resultHead);
}

TEST(AddNumbers, CarryPropagatesAcrossMultipleDigits) {
    LinkedList ll1;
    LinkedList ll2;
    buildList(ll1, {9,9,9}); // 999
    buildList(ll2, {1});     // 1
    Node* resultHead = addTwoNumbers(ll1.getHead(), ll2.getHead());
    EXPECT_EQ(toVector(resultHead), (std::vector<int>{0,0,0,1})); // 1000
    freeList(resultHead);
}

TEST(AddNumbers, NoCarrySimpleAddition) {
    LinkedList ll1;
    LinkedList ll2;
    buildList(ll1, {2,3});   // 32
    buildList(ll2, {4,5});   // 54
    Node* resultHead = addTwoNumbers(ll1.getHead(), ll2.getHead());
    EXPECT_EQ(toVector(resultHead), (std::vector<int>{6,8})); // 86
    freeList(resultHead);
}

TEST(AddNumbers, ManyZeros) {
    LinkedList ll1;
    LinkedList ll2;
    buildList(ll1, {0,0,0}); // 000
    buildList(ll2, {0});     // 0
    Node* resultHead = addTwoNumbers(ll1.getHead(), ll2.getHead());
    EXPECT_EQ(toVector(resultHead), (std::vector<int>{0,0,0})); // preserves ll1 length per your build
    freeList(resultHead);
}

TEST(AddNumbers, OneDigitPlusOneDigitCarry) {
    LinkedList ll1;
    LinkedList ll2;
    buildList(ll1, {5});
    buildList(ll2, {5});
    Node* resultHead = addTwoNumbers(ll1.getHead(), ll2.getHead());
    EXPECT_EQ(toVector(resultHead), (std::vector<int>{0,1})); // 10
    freeList(resultHead);
}

TEST(AddNumbers, DifferentLengthsWithInternalCarry) {
    LinkedList ll1;
    LinkedList ll2;
    buildList(ll1, {8,9,9}); // 998
    buildList(ll2, {7,1});   // 17
    Node* resultHead = addTwoNumbers(ll1.getHead(), ll2.getHead());
    EXPECT_EQ(toVector(resultHead), (std::vector<int>{5,1,0,1})); // 998 + 17 = 1015
    freeList(resultHead);
}