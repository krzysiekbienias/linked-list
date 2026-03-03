#include "reverse_linked_list.hpp"
#include <gtest/gtest.h>
#include "api.hpp"
#include "test_utils.hpp"



TEST(ReverseLinkedListTests, EmptyList_ReturnsNullptr) {
    LinkedList ll;
    EXPECT_EQ(ll.getHead(), nullptr);

    Node* revHead = reverseLinkedList(ll.getHead());

    EXPECT_EQ(revHead, nullptr);
}

TEST(ReverseLinkedListTests, SingleNode_ReversedIsSameValueAndNextNull) {
    LinkedList ll;
    buildList(ll, {42});

    Node* revHead = reverseLinkedList(ll.getHead());

    EXPECT_EQ(toVector(revHead), (std::vector<int>{42}));
    ASSERT_NE(revHead, nullptr);
    EXPECT_EQ(revHead->next, nullptr);
}

TEST(ReverseLinkedListTests, MultipleNodes_ReversesOrder) {
    LinkedList ll;
    buildList(ll, {1, 2, 3, 4});

    Node* revHead = reverseLinkedList(ll.getHead());

    EXPECT_EQ(toVector(revHead), (std::vector<int>{4, 3, 2, 1}));
}

TEST(ReverseLinkedListTests, MultipleNodes_OriginalHeadBecomesTail) {
    LinkedList ll;
    buildList(ll, {10, 20, 30});

    Node* originalHead = ll.getHead();
    ASSERT_NE(originalHead, nullptr);

    Node* revHead = reverseLinkedList(originalHead);

    // znajdź ogon w odwróconej liście
    Node* tail = revHead;
    while (tail && tail->next) tail = tail->next;

    EXPECT_EQ(tail, originalHead);      // dawny head jest teraz ogonem
    ASSERT_NE(tail, nullptr);
    EXPECT_EQ(tail->next, nullptr);     // ogon kończy się null
}