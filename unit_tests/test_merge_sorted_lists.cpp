#include <gtest/gtest.h>
#include "test_utils.hpp"
#include "api.hpp"
#include "merge_sorted_lists.hpp"

TEST(MergeSortedLists, BothEmpty) {
    Node* result = mergeLinkedLists(nullptr, nullptr);
    EXPECT_EQ(result, nullptr);
}

TEST(MergeSortedLists, FirstListEmpty) {
    LinkedList ll;
    buildList(ll, {1, 3, 5});
    Node* head = ll.getHead();
    ll.setHead(nullptr);

    Node* result = mergeLinkedLists(nullptr, head);
    EXPECT_EQ(toVector(result), (std::vector<int>{1, 3, 5}));
    freeList(result);
}

TEST(MergeSortedLists, SecondListEmpty) {
    LinkedList ll;
    buildList(ll, {2, 4, 6});
    Node* head = ll.getHead();
    ll.setHead(nullptr);

    Node* result = mergeLinkedLists(head, nullptr);
    EXPECT_EQ(toVector(result), (std::vector<int>{2, 4, 6}));
    freeList(result);
}

TEST(MergeSortedLists, ClassicCase) {
    LinkedList ll1, ll2;
    buildList(ll1, {1, 3, 5});
    buildList(ll2, {2, 4, 6});
    Node* h1 = ll1.getHead(); ll1.setHead(nullptr);
    Node* h2 = ll2.getHead(); ll2.setHead(nullptr);

    Node* result = mergeLinkedLists(h1, h2);
    EXPECT_EQ(toVector(result), (std::vector<int>{1, 2, 3, 4, 5, 6}));
    freeList(result);
}

TEST(MergeSortedLists, DifferentLengths) {
    LinkedList ll1, ll2;
    buildList(ll1, {1, 2});
    buildList(ll2, {3, 4, 5, 6});
    Node* h1 = ll1.getHead(); ll1.setHead(nullptr);
    Node* h2 = ll2.getHead(); ll2.setHead(nullptr);

    Node* result = mergeLinkedLists(h1, h2);
    EXPECT_EQ(toVector(result), (std::vector<int>{1, 2, 3, 4, 5, 6}));
    freeList(result);
}

TEST(MergeSortedLists, WithDuplicates) {
    LinkedList ll1, ll2;
    buildList(ll1, {1, 3, 3});
    buildList(ll2, {2, 3, 4});
    Node* h1 = ll1.getHead(); ll1.setHead(nullptr);
    Node* h2 = ll2.getHead(); ll2.setHead(nullptr);

    Node* result = mergeLinkedLists(h1, h2);
    EXPECT_EQ(toVector(result), (std::vector<int>{1, 2, 3, 3, 3, 4}));
    freeList(result);
}

TEST(MergeSortedLists, SingleElementEach) {
    LinkedList ll1, ll2;
    buildList(ll1, {1});
    buildList(ll2, {2});
    Node* h1 = ll1.getHead(); ll1.setHead(nullptr);
    Node* h2 = ll2.getHead(); ll2.setHead(nullptr);

    Node* result = mergeLinkedLists(h1, h2);
    EXPECT_EQ(toVector(result), (std::vector<int>{1, 2}));
    freeList(result);
}
