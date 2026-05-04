#include "delete_middle.hpp"
#include <gtest/gtest.h>
#include "test_utils.hpp"
#include "api.hpp"

// n=1: middle = index 0 → list becomes empty
TEST(DeleteMiddle, SingleNode) {
    LinkedList ll;
    buildList(ll, {1});
    Node* result = deleteMiddle(ll.getHead());
    ll.setHead(nullptr);

    EXPECT_EQ(result, nullptr);
    freeList(result);
}

// n=2: middle = index 1 → remove second node
TEST(DeleteMiddle, TwoNodes) {
    LinkedList ll;
    buildList(ll, {1, 2});
    Node* result = deleteMiddle(ll.getHead());
    ll.setHead(nullptr);

    EXPECT_EQ(toVector(result), (std::vector<int>{1}));
    freeList(result);
}

// n=3: middle = index 1 → remove second node
TEST(DeleteMiddle, ThreeNodes) {
    LinkedList ll;
    buildList(ll, {1, 2, 3});
    Node* result = deleteMiddle(ll.getHead());
    ll.setHead(nullptr);

    EXPECT_EQ(toVector(result), (std::vector<int>{1, 3}));
    freeList(result);
}

// n=4: middle = index 2 → remove third node
TEST(DeleteMiddle, FourNodes) {
    LinkedList ll;
    buildList(ll, {1, 2, 3, 4});
    Node* result = deleteMiddle(ll.getHead());
    ll.setHead(nullptr);

    EXPECT_EQ(toVector(result), (std::vector<int>{1, 2, 4}));
    freeList(result);
}

// n=5: middle = index 2 → remove third node
TEST(DeleteMiddle, FiveNodes) {
    LinkedList ll;
    buildList(ll, {1, 2, 3, 4, 5});
    Node* result = deleteMiddle(ll.getHead());
    ll.setHead(nullptr);

    EXPECT_EQ(toVector(result), (std::vector<int>{1, 2, 4, 5}));
    freeList(result);
}
