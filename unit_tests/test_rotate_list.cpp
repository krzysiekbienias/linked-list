#include "rotate_list.hpp"
#include <gtest/gtest.h>
#include "api.hpp"
#include "test_utils.hpp"

TEST(RotateListTests, EmptyList_ReturnsNullptr) {
    LinkedList ll;
    Node* result = rotateRight(ll.getHead(), 1);
    EXPECT_EQ(result, nullptr);
}

TEST(RotateListTests, SingleNode_Unchanged) {
    LinkedList ll;
    buildList(ll, {7});

    Node* result = rotateRight(ll.getHead(), 3);

    EXPECT_EQ(toVector(result), (std::vector<int>{7}));
    ASSERT_NE(result, nullptr);
    EXPECT_EQ(result->next, nullptr);
}

TEST(RotateListTests, KZero_Unchanged) {
    LinkedList ll;
    buildList(ll, {1, 2, 3});

    Node* result = rotateRight(ll.getHead(), 0);

    EXPECT_EQ(toVector(result), (std::vector<int>{1, 2, 3}));
}

TEST(RotateListTests, RotateByOne) {
    LinkedList ll;
    buildList(ll, {1, 2, 3, 4, 5});

    Node* result = rotateRight(ll.getHead(), 1);

    // 1 2 3 4 5  ->  5 1 2 3 4
    EXPECT_EQ(toVector(result), (std::vector<int>{5, 1, 2, 3, 4}));
}

TEST(RotateListTests, RotateByTwo) {
    LinkedList ll;
    buildList(ll, {1, 2, 3, 4, 5});

    Node* result = rotateRight(ll.getHead(), 2);

    // 1 2 3 4 5  ->  4 5 1 2 3
    EXPECT_EQ(toVector(result), (std::vector<int>{4, 5, 1, 2, 3}));
}

TEST(RotateListTests, KEqualsLength_Unchanged) {
    LinkedList ll;
    buildList(ll, {1, 2, 3});

    Node* result = rotateRight(ll.getHead(), 3);

    // k % len == 0
    EXPECT_EQ(toVector(result), (std::vector<int>{1, 2, 3}));
}

TEST(RotateListTests, KGreaterThanLength_UsesModulo) {
    LinkedList ll;
    buildList(ll, {1, 2, 3, 4, 5});

    Node* result = rotateRight(ll.getHead(), 7);

    // 7 % 5 == 2  ->  4 5 1 2 3
    EXPECT_EQ(toVector(result), (std::vector<int>{4, 5, 1, 2, 3}));
}

TEST(RotateListTests, TwoNodes_RotateByOne) {
    LinkedList ll;
    buildList(ll, {10, 20});

    Node* result = rotateRight(ll.getHead(), 1);

    EXPECT_EQ(toVector(result), (std::vector<int>{20, 10}));
}

TEST(RotateListTests, NewTailEndsWithNullptr) {
    LinkedList ll;
    buildList(ll, {1, 2, 3, 4});

    Node* result = rotateRight(ll.getHead(), 2);

    // 1 2 3 4  ->  3 4 1 2
    ASSERT_NE(result, nullptr);
    Node* tail = result;
    while (tail->next) {
        tail = tail->next;
    }
    EXPECT_EQ(tail->m_val, 2);
    EXPECT_EQ(tail->next, nullptr);
}
