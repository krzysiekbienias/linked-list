#include <gtest/gtest.h>
#include "test_utils.hpp"
#include "api.hpp"
#include "merging_linked_list.hpp"

TEST(MergingLinkedList, NoIntersection) {
    LinkedList ll1, ll2;
    buildList(ll1, {1, 2, 3});
    buildList(ll2, {4, 5, 6});

    Node* result = mergingLinkedLists(ll1.getHead(), ll2.getHead());
    EXPECT_EQ(result, nullptr);
}

TEST(MergingLinkedList, IntersectionAtHead) {
    Node* shared = new Node(1);
    shared->next = new Node(2);

    Node* result = mergingLinkedLists(shared, shared);
    EXPECT_EQ(result, shared);
    EXPECT_EQ(result->m_val, 1);
    freeList(shared);
}

TEST(MergingLinkedList, ClassicCase) {
    // List1: 1 -> 2 -> [shared: 7 -> 8]
    // List2: 4 -> [shared: 7 -> 8]
    Node* shared = new Node(7);
    shared->next = new Node(8);

    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = shared;

    Node* head2 = new Node(4);
    head2->next = shared;

    Node* result = mergingLinkedLists(head1, head2);
    EXPECT_EQ(result, shared);
    EXPECT_EQ(result->m_val, 7);

    delete head1->next;
    delete head1;
    delete head2;
    freeList(shared);
}

TEST(MergingLinkedList, SameLengthWithIntersection) {
    // List1: 1 -> [shared: 3 -> 4]
    // List2: 2 -> [shared: 3 -> 4]
    Node* shared = new Node(3);
    shared->next = new Node(4);

    Node* head1 = new Node(1);
    head1->next = shared;

    Node* head2 = new Node(2);
    head2->next = shared;

    Node* result = mergingLinkedLists(head1, head2);
    EXPECT_EQ(result, shared);
    EXPECT_EQ(result->m_val, 3);

    delete head1;
    delete head2;
    freeList(shared);
}

TEST(MergingLinkedList, LongerFirstListWithIntersection) {
    // List1: 1 -> 2 -> 3 -> [shared: 9 -> 10]
    // List2: 5 -> [shared: 9 -> 10]
    Node* shared = new Node(9);
    shared->next = new Node(10);

    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = shared;

    Node* head2 = new Node(5);
    head2->next = shared;

    Node* result = mergingLinkedLists(head1, head2);
    EXPECT_EQ(result, shared);
    EXPECT_EQ(result->m_val, 9);

    delete head1->next->next;
    delete head1->next;
    delete head1;
    delete head2;
    freeList(shared);
}
