#include "has_cycle.hpp"
#include <gtest/gtest.h>
#include "test_utils.hpp"
#include "api.hpp"

TEST(HasCycle, EmptyList) {
    EXPECT_FALSE(hasCycle(nullptr));
}

TEST(HasCycle, SingleNodeNoCycle) {
    Node* n = new Node(1);
    EXPECT_FALSE(hasCycle(n));
    delete n;
}

TEST(HasCycle, SingleNodeSelfLoop) {
    Node* n = new Node(1);
    n->next = n;
    EXPECT_TRUE(hasCycle(n));
    n->next = nullptr;
    delete n;
}

TEST(HasCycle, NoCycle) {
    LinkedList ll;
    buildList(ll, {1, 2, 3, 4, 5});
    EXPECT_FALSE(hasCycle(ll.getHead()));
}

TEST(HasCycle, CycleAtTailToHead) {
    // 1 -> 2 -> 3 -> 4 -> (back to 1)
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    n1->next = n2; n2->next = n3; n3->next = n4;
    n4->next = n1;

    EXPECT_TRUE(hasCycle(n1));

    n4->next = nullptr;
    delete n4; delete n3; delete n2; delete n1;
}

TEST(HasCycle, CycleInMiddle) {
    // 1 -> 2 -> 3 -> 4 -> (back to 2)
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    n1->next = n2; n2->next = n3; n3->next = n4;
    n4->next = n2;

    EXPECT_TRUE(hasCycle(n1));

    n4->next = nullptr;
    delete n4; delete n3; delete n2; delete n1;
}

TEST(HasCycle, TwoNodesCycle) {
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    n1->next = n2;
    n2->next = n1;

    EXPECT_TRUE(hasCycle(n1));

    n2->next = nullptr;
    delete n2; delete n1;
}
