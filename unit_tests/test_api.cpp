
#include <gtest/gtest.h>

// --- test-only hack: expose private members ---
#define private public
#include "api.hpp"
#undef private

// Helper: collect values from list into a std::vector<int>
static std::vector<int> toVector(Node* head) {
    std::vector<int> out;
    Node* cur = head;
    while (cur) {
        out.push_back(cur->m_val);
        cur = cur->next;
    }
    return out;
}

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

    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.getSize(), 0);
}

TEST(LinkedListEmpty, ListCreatedWithValueIsNotEmpty) {
    LinkedList list(10);

    EXPECT_FALSE(list.empty());
    EXPECT_EQ(list.getSize(), 1);
}

TEST(LinkedListEmpty, AppendMakesListNonEmpty) {
    LinkedList list;

    list.append(5);

    EXPECT_FALSE(list.empty());
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