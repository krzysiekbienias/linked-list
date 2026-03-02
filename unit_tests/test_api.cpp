#define private public
#include "api.hpp"
#undef private
#include "test_utils.hpp"
#include "node.hpp"
#include <gtest/gtest.h>





TEST(LinkedListAppend, AppendToEmptyListSetsHead) {
    LinkedList list;              // empty: head=nullptr, length=0

    list.append(10);

    ASSERT_NE(list.m_head, nullptr);
    EXPECT_EQ(list.m_head->m_val, 10);
    EXPECT_EQ(list.m_head->next, nullptr);
    EXPECT_EQ(list.m_length, 1);
}

TEST(LinkedListAppend, AppendToSingleElementListAddsSecondNode) {
    LinkedList list(1);

    list.append(2);

    ASSERT_NE(list.m_head, nullptr);
    ASSERT_NE(list.m_head->next, nullptr);
    EXPECT_EQ(list.m_head->m_val, 1);
    EXPECT_EQ(list.m_head->next->m_val, 2);
    EXPECT_EQ(list.m_head->next->next, nullptr);
    EXPECT_EQ(list.m_length, 2);
}

TEST(LinkedListAppend, MultipleAppendsPreserveOrder) {
    LinkedList list;

    list.append(1);
    list.append(2);
    list.append(3);

    EXPECT_EQ(toVector(list.m_head), (std::vector<int>{1, 2, 3}));
    EXPECT_EQ(list.m_length, 3);
}

TEST(LinkedListAppend, AppendDoesNotChangeHeadWhenNonEmpty) {
    LinkedList list;
    list.append(7);

    Node* originalHead = list.m_head;
    list.append(8);

    EXPECT_EQ(list.m_head, originalHead);           // head pointer unchanged
    EXPECT_EQ(list.m_head->m_val, 7);
    EXPECT_EQ(toVector(list.m_head), (std::vector<int>{7, 8}));
    EXPECT_EQ(list.m_length, 2);
}

TEST(LinkedListAppend, AppendManyTimesLengthMatchesNodeCount) {
    LinkedList list;
    for (int i = 1; i <= 20; ++i) {
        list.append(i);
    }

    auto v = toVector(list.m_head);
    EXPECT_EQ(static_cast<int>(v.size()), list.m_length);
    EXPECT_EQ(v.front(), 1);
    EXPECT_EQ(v.back(), 20);
}

TEST(LinkedListAppend, AppendNegativeAndZerom_vals) {
    LinkedList list;

    list.append(0);
    list.append(-5);
    list.append(12);

    EXPECT_EQ(toVector(list.m_head), (std::vector<int>{0, -5, 12}));
    EXPECT_EQ(list.m_length, 3);
}


// ---------- empty() tests ----------

TEST(LinkedListEmpty, NewListIsEmpty) {
    LinkedList list;

    EXPECT_TRUE(list.isEmpty());
    EXPECT_EQ(list.getSize(), 0);
}

TEST(LinkedListEmpty, ListCreatedWithValueIsNotEmpty) {
    LinkedList list(10);

    EXPECT_FALSE(list.isEmpty());
    EXPECT_EQ(list.getSize(), 1);
}

TEST(LinkedListEmpty, AppendMakesListNonEmpty) {
    LinkedList list;

    list.append(5);

    EXPECT_FALSE(list.isEmpty());
    EXPECT_EQ(list.getSize(), 1);
}


// ---------- size() tests ----------

TEST(LinkedListSize, SizeAfterMultipleAppends) {
    LinkedList list;

    list.append(1);
    list.append(2);
    list.append(3);

    EXPECT_EQ(list.getSize(), 3);
}

TEST(LinkedListSize, SizePreservedAfterConstructionWithInitialValue) {
    LinkedList list(42);

    list.append(100);
    list.append(200);

    EXPECT_EQ(list.getSize(), 3);
}

TEST(LinkedListSize, SizeZeroForFreshList) {
    LinkedList list;

    EXPECT_EQ(list.getSize(), 0);
}

TEST(LinkedListGetHead, EmptyListReturnsNullptr) {
    LinkedList list;
    EXPECT_EQ(list.getHead(), nullptr);
}

TEST(LinkedListGetHead, SingleElementListReturnsNonNullHeadWithValue) {
    LinkedList list;
    list.append(42);

    Node* head = list.getHead();
    ASSERT_NE(head, nullptr);
    EXPECT_EQ(head->m_val, 42);
    EXPECT_EQ(head->next, nullptr);
}

TEST(LinkedListGetHead, AppendKeepsHeadPointingToFirstNode) {
    LinkedList list;
    buildList(list, {3, 5, 6});

    Node* head = list.getHead();
    ASSERT_NE(head, nullptr);

    EXPECT_EQ(head->m_val, 3);  // head stays the first inserted value
    EXPECT_EQ(toVector(head), (std::vector<int>{3, 5, 6}));
}

TEST(LinkedListGetHead, ConstructorWithValueSetsHead) {
    LinkedList list(7);

    Node* head = list.getHead();
    ASSERT_NE(head, nullptr);
    EXPECT_EQ(head->m_val, 7);
    EXPECT_EQ(head->next, nullptr);
}


TEST(LinkedListContains, EmptyListReturnsFalse) {
    LinkedList list;
    EXPECT_FALSE(list.contains(10));
}

TEST(LinkedListContains, SingleElementFound) {
    LinkedList list;
    buildList(list, {42});

    EXPECT_TRUE(list.contains(42));
}

TEST(LinkedListContains, SingleElementNotFound) {
    LinkedList list;
    buildList(list, {42});

    EXPECT_FALSE(list.contains(99));
}

TEST(LinkedListContains, FindsValueAtBeginning) {
    LinkedList list;
    buildList(list, {3, 5, 7, 9});

    EXPECT_TRUE(list.contains(3));
}

TEST(LinkedListContains, FindsValueInMiddle) {
    LinkedList list;
    buildList(list, {3, 5, 7, 9});

    EXPECT_TRUE(list.contains(7));
}

TEST(LinkedListContains, FindsValueAtEnd) {
    LinkedList list;
    buildList(list, {3, 5, 7, 9});

    EXPECT_TRUE(list.contains(9));
}

TEST(LinkedListContains, ReturnsFalseIfValueNotPresent) {
    LinkedList list;
    buildList(list, {1, 2, 3, 4});

    EXPECT_FALSE(list.contains(8));
}

TEST(LinkedListContains, WorksWithDuplicates) {
    LinkedList list;
    buildList(list, {1, 2, 3, 2, 4});

    EXPECT_TRUE(list.contains(2));
}

TEST(LinkedListContains, DoesNotModifyList) {
    LinkedList list;
    buildList(list, {1, 2, 3});

    EXPECT_TRUE(list.contains(2));

    // ensure list structure unchanged
    EXPECT_EQ(toVector(list.getHead()), (std::vector<int>{1, 2, 3}));
}

TEST(LinkedListCountNodes, EmptyListReturnsZero) {
    LinkedList list;
    EXPECT_EQ(list.countNodes(5), 0);
}

TEST(LinkedListCountNodes, SingleNodeMatchReturnsOne) {
    LinkedList list;
    buildList(list, {7});
    EXPECT_EQ(list.countNodes(7), 1);
}

TEST(LinkedListCountNodes, SingleNodeNoMatchReturnsZero) {
    LinkedList list;
    buildList(list, {7});
    EXPECT_EQ(list.countNodes(3), 0);
}

TEST(LinkedListCountNodes, CountsMultipleOccurrences) {
    LinkedList list;
    buildList(list, {3, 5, 5, 5, 6, 8, 8, 10});

    EXPECT_EQ(list.countNodes(5), 3);
    EXPECT_EQ(list.countNodes(8), 2);
    EXPECT_EQ(list.countNodes(3), 1);
    EXPECT_EQ(list.countNodes(10), 1);
}

TEST(LinkedListCountNodes, ValueNotPresentReturnsZero) {
    LinkedList list;
    buildList(list, {1, 2, 3, 4});
    EXPECT_EQ(list.countNodes(99), 0);
}

TEST(LinkedListCountNodes, WorksWithNegativeAndZeroValues) {
    LinkedList list;
    buildList(list, {0, -1, -1, 2, 0});

    EXPECT_EQ(list.countNodes(0), 2);
    EXPECT_EQ(list.countNodes(-1), 2);
    EXPECT_EQ(list.countNodes(2), 1);
}

TEST(LinkedListCountNodes, DoesNotModifyList) {
    LinkedList list;
    buildList(list, {1, 2, 2, 3});

    EXPECT_EQ(list.countNodes(2), 2);
    EXPECT_EQ(toVector(list.getHead()), (std::vector<int>{1, 2, 2, 3}));
}