#include "remove_element.hpp"
#include <gtest/gtest.h>
#include "node.hpp"
#include "api.hpp"
#include "test_utils.hpp"

TEST(RemoveElement,TrivalCase) {
    LinkedList ll;
    buildList(ll,{1,2,6,3,4,5,6});
    removeElements(ll.getHead(),6);
    Node* newHead= ll.getHead();

    EXPECT_EQ(toVector(newHead),(std::vector<int>{1,2,3,4,5}));

}

TEST(RemoveElement,RemoveAll) {
    LinkedList ll;
    buildList(ll,{7,7,7,7,7,7});
    removeElements(ll.getHead(),7);
    Node* newHead= ll.getHead();

    EXPECT_EQ(toVector(newHead),(std::vector<int>{}));

}

TEST(RemoveElement,NotTouch) {
    LinkedList ll;
    buildList(ll,{7,7,7,7,7,7});
    removeElements(ll.getHead(),8);
    Node* newHead= ll.getHead();

    EXPECT_EQ(toVector(newHead),(std::vector<int>{7,7,7,7,7,7}));

}