#include <gtest/gtest.h>
#include "api.hpp"
#include "test_utils.hpp"
#include "insert_node.hpp"


TEST(InsertAtIndex, EmptyListCreatesSingleNode) {
    LinkedList ll;

    Node* out = insertAtIndex(ll.getHead(), 10, 0);

    ASSERT_NE(out, nullptr);

    std::vector<int> expected = {10};
    EXPECT_EQ(toVector(out), expected);
}

TEST(InsertAtIndex, InsertAtHeadOfNonEmptyList) {
    LinkedList ll;
    buildList(ll, {1, 2, 3});

    Node* out = insertAtIndex(ll.getHead(), 99, 0);

    ASSERT_NE(out, nullptr);

    std::vector<int> expected = {99, 1, 2, 3};
    EXPECT_EQ(toVector(out), expected);
}

TEST(InsertAtIndex, InsertInMiddle) {
    LinkedList ll;
    buildList(ll, {1, 2, 4});

    Node* out = insertAtIndex(ll.getHead(), 3, 2);

    ASSERT_NE(out, nullptr);

    std::vector<int> expected = {1, 2, 3, 4};
    EXPECT_EQ(toVector(out), expected);
}

TEST(InsertAtIndex, InsertAtTailWhenIndexEqualsLength) {
    LinkedList ll;
    buildList(ll, {1, 2, 3});

    Node* out = insertAtIndex(ll.getHead(), 4, 3);

    ASSERT_NE(out, nullptr);

    std::vector<int> expected = {1, 2, 3, 4};
    EXPECT_EQ(toVector(out), expected);
}

TEST(InsertAtIndex, IndexGreaterThanLengthAppendsAtEnd) {
    LinkedList ll;
    buildList(ll, {1, 2, 3});

    Node* out = insertAtIndex(ll.getHead(), 99, 10);

    ASSERT_NE(out, nullptr);

    std::vector<int> expected = {1, 2, 3, 99};
    EXPECT_EQ(toVector(out), expected);
}

TEST(InsertAtIndex, SingleNodeInsertAtHead) {
    LinkedList ll;
    buildList(ll, {5});

    Node* out = insertAtIndex(ll.getHead(), 10, 0);

    ASSERT_NE(out, nullptr);

    std::vector<int> expected = {10, 5};
    EXPECT_EQ(toVector(out), expected);
}

TEST(InsertAtIndex, SingleNodeInsertAfterHead) {
    LinkedList ll;
    buildList(ll, {5});

    Node* out = insertAtIndex(ll.getHead(), 10, 1);

    ASSERT_NE(out, nullptr);

    std::vector<int> expected = {5, 10};
    EXPECT_EQ(toVector(out), expected);
}

TEST(InsertAtIndex, InsertAtIndexOne) {
    LinkedList ll;
    buildList(ll, {1, 3, 4});

    Node* out = insertAtIndex(ll.getHead(), 2, 1);

    ASSERT_NE(out, nullptr);

    std::vector<int> expected = {1, 2, 3, 4};
    EXPECT_EQ(toVector(out), expected);
}