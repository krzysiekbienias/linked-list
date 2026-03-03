#include "remove_kth_node.hpp"
#include <gtest/gtest.h>

#include "api.hpp"
#include "test_utils.hpp"


TEST(RemoveKthNode,ClassicCase) {
    LinkedList ll;
    buildList(ll, {1, 2, 3, 4});
    Node* original=ll.getHead();

    Node* newList=removeKthNodeFromEnd(original,2);

}