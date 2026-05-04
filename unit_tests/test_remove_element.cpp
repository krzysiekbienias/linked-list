#include "remove_element.hpp"
#include <gtest/gtest.h>
#include "node.hpp"
#include "api.hpp"
#include "test_utils.hpp"

TEST(RemoveElement, TrivialCase) {
    LinkedList ll;
    buildList(ll, {1,2,6,3,4,5,6});
    Node* result = removeElements(ll.getHead(), 6);
    ll.setHead(nullptr);

    EXPECT_EQ(toVector(result), (std::vector<int>{1,2,3,4,5}));
    freeList(result);
}

TEST(RemoveElement, RemoveAll) {
    LinkedList ll;
    buildList(ll, {7,7,7,7,7,7});
    Node* result = removeElements(ll.getHead(), 7);
    ll.setHead(nullptr);

    EXPECT_EQ(toVector(result), (std::vector<int>{}));
    freeList(result);
}

TEST(RemoveElement, NotTouch) {
    LinkedList ll;
    buildList(ll, {7,7,7,7,7,7});
    Node* result = removeElements(ll.getHead(), 8);
    ll.setHead(nullptr);

    EXPECT_EQ(toVector(result), (std::vector<int>{7,7,7,7,7,7}));
    freeList(result);
}
