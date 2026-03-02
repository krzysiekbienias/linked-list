#include "middle_node.hpp"
#include <gtest/gtest.h>
#include "api.hpp"
#include "test_utils.hpp"

TEST(MiddleNode, EmptyListThrowsInvalidArgument) {
    Node* head = nullptr;
    EXPECT_THROW(middleNode(head), std::invalid_argument);
}

TEST(MiddleNode, SingleNodeReturnsThatNode) {
    LinkedList ll;
    buildList(ll, {42});

    Node* head = ll.getHead();
    Node* mid = middleNode(head);

    ASSERT_NE(mid, nullptr);
    EXPECT_EQ(mid->m_val, 42);
    EXPECT_EQ(mid, head);
}

TEST(MiddleNode, TwoNodesReturnsSecondNode) {
    LinkedList ll;
    buildList(ll, {1, 2});

    Node* mid = middleNode(ll.getHead());

    ASSERT_NE(mid, nullptr);
    EXPECT_EQ(mid->m_val, 2);
}

TEST(MiddleNode, ThreeNodesReturnsMiddle) {
    LinkedList ll;
    buildList(ll, {1, 2, 3});

    Node* mid = middleNode(ll.getHead());

    ASSERT_NE(mid, nullptr);
    EXPECT_EQ(mid->m_val, 2);
}

TEST(MiddleNode, FourNodesReturnsSecondMiddle) {
    // With slow/fast starting at head, for even length this returns the "second" middle.
    // [1,2,3,4] -> 3
    LinkedList ll;
    buildList(ll, {1, 2, 3, 4});

    Node* mid = middleNode(ll.getHead());

    ASSERT_NE(mid, nullptr);
    EXPECT_EQ(mid->m_val, 3);
}

TEST(MiddleNode, FiveNodesReturnsMiddle) {
    LinkedList ll;
    buildList(ll, {10, 20, 30, 40, 50});

    Node* mid = middleNode(ll.getHead());

    ASSERT_NE(mid, nullptr);
    EXPECT_EQ(mid->m_val, 30);
}

TEST(MiddleNode, LongerOddListReturnsCorrectMiddle) {
    LinkedList ll;
    buildList(ll, {1,2,3,4,5,6,7});

    Node* mid = middleNode(ll.getHead());

    ASSERT_NE(mid, nullptr);
    EXPECT_EQ(mid->m_val, 4);
}