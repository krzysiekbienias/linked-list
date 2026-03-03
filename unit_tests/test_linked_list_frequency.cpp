#include "linked_list_frequency.hpp"
#include <gtest/gtest.h>
#include "api.hpp"
#include "test_utils.hpp"

TEST(FrequenciesOfElements, EmptyListReturnsNull) {
    LinkedList ll; // pusta

    Node* out = frequenciesOfElements(ll.getHead());

    EXPECT_EQ(out, nullptr);
}

TEST(FrequenciesOfElements, SingleElementReturnsOne) {
    LinkedList ll;
    buildList(ll, {42});

    Node* out = frequenciesOfElements(ll.getHead());

    ASSERT_NE(out, nullptr);

    auto got = toVector(out);
    std::sort(got.begin(), got.end());

    std::vector<int> expected = {1};
    EXPECT_EQ(got, expected);
}

TEST(FrequenciesOfElements, AllUniqueReturnsAllOnes) {
    LinkedList ll;
    buildList(ll, {1, 2, 3, 4});

    Node* out = frequenciesOfElements(ll.getHead());

    ASSERT_NE(out, nullptr);

    auto got = toVector(out);
    std::sort(got.begin(), got.end());

    std::vector<int> expected = {1, 1, 1, 1};
    EXPECT_EQ(got, expected);
}

TEST(FrequenciesOfElements, AllSameValueReturnsSingleFrequency) {
    LinkedList ll;
    buildList(ll, {7, 7, 7, 7, 7});

    Node* out = frequenciesOfElements(ll.getHead());

    ASSERT_NE(out, nullptr);

    auto got = toVector(out);
    std::sort(got.begin(), got.end());

    std::vector<int> expected = {5};
    EXPECT_EQ(got, expected);
}

TEST(FrequenciesOfElements, MixedDuplicatesReturnsCorrectCounts) {
    // 1 -> 3, 2 -> 2, 3 -> 1
    LinkedList ll;
    buildList(ll, {1, 2, 1, 3, 2, 1});

    Node* out = frequenciesOfElements(ll.getHead());

    ASSERT_NE(out, nullptr);

    auto got = toVector(out);
    std::sort(got.begin(), got.end());

    std::vector<int> expected = {1, 2, 3};
    EXPECT_EQ(got, expected);
}

TEST(FrequenciesOfElements, NegativeAndZeroValuesWorkCorrectly) {
    // -1 -> 2, 0 -> 3, 5 -> 1
    LinkedList ll;
    buildList(ll, {0, -1, 0, 5, -1, 0});

    Node* out = frequenciesOfElements(ll.getHead());

    ASSERT_NE(out, nullptr);

    auto got = toVector(out);
    std::sort(got.begin(), got.end());

    std::vector<int> expected = {1, 2, 3};
    EXPECT_EQ(got, expected);
}

TEST(FrequenciesOfElements, MultipleKeysWithSameFrequencyArePreserved) {
    // 10 -> 2, 20 -> 2, 30 -> 2, 40 -> 1
    LinkedList ll;
    buildList(ll, {10, 20, 10, 30, 20, 30, 40});

    Node* out = frequenciesOfElements(ll.getHead());

    ASSERT_NE(out, nullptr);

    auto got = toVector(out);
    std::sort(got.begin(), got.end());

    std::vector<int> expected = {1, 2, 2, 2};
    EXPECT_EQ(got, expected);
}