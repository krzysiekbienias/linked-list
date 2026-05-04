#include "remove_kth_node.hpp"
#include <gtest/gtest.h>

#include "api.hpp"
#include "test_utils.hpp"

TEST(RemoveKthNode, ClassicCase) {
    LinkedList ll;
    buildList(ll, {1, 2, 3, 4});
    Node* head = ll.getHead();
    ll.setHead(nullptr);

    Node* result = removeKthNodeFromEnd(head, 2);
    EXPECT_EQ(toVector(result), (std::vector<int>{1, 2, 4}));
    freeList(result);
}

TEST(RemoveKthNode, RemoveHead) {
    LinkedList ll;
    buildList(ll, {1, 2, 3, 4});
    Node* head = ll.getHead();
    ll.setHead(nullptr);

    Node* result = removeKthNodeFromEnd(head, 4);
    EXPECT_EQ(toVector(result), (std::vector<int>{2, 3, 4}));
    freeList(result);
}

TEST(RemoveKthNode, RemoveLast) {
    LinkedList ll;
    buildList(ll, {1, 2, 3, 4});
    Node* head = ll.getHead();
    ll.setHead(nullptr);

    Node* result = removeKthNodeFromEnd(head, 1);
    EXPECT_EQ(toVector(result), (std::vector<int>{1, 2, 3}));
    freeList(result);
}

TEST(RemoveKthNode, TwoElementsRemoveLast) {
    LinkedList ll;
    buildList(ll, {1, 2});
    Node* head = ll.getHead();
    ll.setHead(nullptr);

    Node* result = removeKthNodeFromEnd(head, 1);
    EXPECT_EQ(toVector(result), (std::vector<int>{1}));
    freeList(result);
}

TEST(RemoveKthNode, TwoElementsRemoveHead) {
    LinkedList ll;
    buildList(ll, {1, 2});
    Node* head = ll.getHead();
    ll.setHead(nullptr);

    Node* result = removeKthNodeFromEnd(head, 2);
    EXPECT_EQ(toVector(result), (std::vector<int>{2}));
    freeList(result);
}
