#include "find_cycle_origin.hpp"
#include <gtest/gtest.h>
#include "test_utils.hpp"
#include "api.hpp"

TEST(FindCycleOrigin, TailPointsToHead) {
    // 1 -> 2 -> 3 -> 4 -> (back to 1)
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    n1->next = n2; n2->next = n3; n3->next = n4;
    n4->next = n1;

    EXPECT_EQ(findCycleOrigin(n1), n1);

    n4->next = nullptr;
    delete n4; delete n3; delete n2; delete n1;
}

TEST(FindCycleOrigin, TailPointsToMiddle) {
    // 1 -> 2 -> 3 -> 4 -> 5 -> (back to 3)
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    n1->next = n2; n2->next = n3; n3->next = n4; n4->next = n5;
    n5->next = n3;

    EXPECT_EQ(findCycleOrigin(n1), n3);

    n5->next = nullptr;
    delete n5; delete n4; delete n3; delete n2; delete n1;
}

TEST(FindCycleOrigin, SelfLoop) {
    // [1] -> (back to 1)
    Node* n1 = new Node(1);
    n1->next = n1;

    EXPECT_EQ(findCycleOrigin(n1), n1);

    n1->next = nullptr;
    delete n1;
}

TEST(FindCycleOrigin, TwoNodesCycleAtHead) {
    // 1 -> 2 -> (back to 1)
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    n1->next = n2;
    n2->next = n1;

    EXPECT_EQ(findCycleOrigin(n1), n1);

    n2->next = nullptr;
    delete n2; delete n1;
}

TEST(FindCycleOrigin, LongTailShortCycle) {
    // 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> (back to 4)
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);
    n1->next = n2; n2->next = n3; n3->next = n4; n4->next = n5; n5->next = n6;
    n6->next = n4;

    EXPECT_EQ(findCycleOrigin(n1), n4);

    n6->next = nullptr;
    delete n6; delete n5; delete n4; delete n3; delete n2; delete n1;
}
