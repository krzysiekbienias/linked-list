#include "remove_duplicates_from_sorted_list.hpp"
#include <gtest/gtest.h>
#include "test_utils.hpp"

TEST(RemoveDuplicatesFromSortedList, NullHeadReturnsNull) {
    Node* head = nullptr;
    Node* result = removeDuplicatesFromSortedList(head);
    EXPECT_EQ(result, nullptr);
}

TEST(RemoveDuplicatesFromSortedList, SingleNodeUnchanged) {
    LinkedList ll;
    buildList(ll, {7});

    Node* head = ll.getHead();
    Node* result = removeDuplicatesFromSortedList(head);

    EXPECT_EQ(result, head);
    EXPECT_EQ(toVector(result), (std::vector<int>{7}));
}

TEST(RemoveDuplicatesFromSortedList, NoDuplicatesUnchanged) {
    LinkedList ll;
    buildList(ll, {1, 3, 5, 7});

    Node* head = ll.getHead();
    Node* result = removeDuplicatesFromSortedList(head);

    EXPECT_EQ(result, head);
    EXPECT_EQ(toVector(result), (std::vector<int>{1, 3, 5, 7}));
}

TEST(RemoveDuplicatesFromSortedList, RemovesDuplicatesInMiddle) {
    LinkedList ll;
    buildList(ll, {3, 5, 5, 5, 6});

    Node* head = ll.getHead();
    Node* result = removeDuplicatesFromSortedList(head);

    EXPECT_EQ(result, head);
    EXPECT_EQ(toVector(result), (std::vector<int>{3, 5, 6}));
}

TEST(RemoveDuplicatesFromSortedList, RemovesMultipleDuplicateGroups) {
    LinkedList ll;
    buildList(ll, {3, 5, 5, 5, 6, 8, 8, 10});

    Node* head = ll.getHead();
    Node* result = removeDuplicatesFromSortedList(head);

    EXPECT_EQ(result, head);
    EXPECT_EQ(toVector(result), (std::vector<int>{3, 5, 6, 8, 10}));
}

TEST(RemoveDuplicatesFromSortedList, AllSameValueCollapsesToSingleNode) {
    LinkedList ll;
    buildList(ll, {4, 4, 4, 4});

    Node* head = ll.getHead();
    Node* result = removeDuplicatesFromSortedList(head);

    EXPECT_EQ(result, head);
    EXPECT_EQ(toVector(result), (std::vector<int>{4}));
}

TEST(RemoveDuplicatesFromSortedList, TwoElementsDuplicateCollapsesToOne) {
    LinkedList ll;
    buildList(ll, {9, 9});

    Node* head = ll.getHead();
    Node* result = removeDuplicatesFromSortedList(head);

    EXPECT_EQ(result, head);
    EXPECT_EQ(toVector(result), (std::vector<int>{9}));
}

TEST(RemoveDuplicatesFromSortedList, DuplicatesAtEndRemoved) {
    LinkedList ll;
    buildList(ll, {1, 2, 3, 4, 4, 4});

    Node* head = ll.getHead();
    Node* result = removeDuplicatesFromSortedList(head);

    EXPECT_EQ(result, head);
    EXPECT_EQ(toVector(result), (std::vector<int>{1, 2, 3, 4}));
}

TEST(RemoveDuplicatesFromSortedList, DuplicatesAtStartRemoved) {
    // for sorted-list duplicate removal, head value remains,
    // but extra duplicates right after head should be removed
    LinkedList ll;
    buildList(ll, {5, 5, 5, 6, 7});

    Node* head = ll.getHead();
    Node* result = removeDuplicatesFromSortedList(head);

    EXPECT_EQ(result, head);
    EXPECT_EQ(toVector(result), (std::vector<int>{5, 6, 7}));
}