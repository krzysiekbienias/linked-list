
#include <gtest/gtest.h>
#include "test_utils.hpp"
#include "remove_duplicates_unsorted.hpp"
#include "api.hpp"


TEST(PurgeRepeateNodesFromUnlortedLL,AllUnique) {
    LinkedList ll;
    buildList(ll,{1,2,3,4,5});

    Node *res=deleteDuplicatesUnsorted(ll.getHead());
    std::vector<int>actualVec=toVector(res);
    std::vector<int> expected={1,2,3,4,5};
    EXPECT_EQ(actualVec,expected);

}

TEST(PurgeRepeateNodesFromUnlortedLL,TwoDuplicates) {
    LinkedList ll;
    buildList(ll,{2,1,1,2});

    Node *actual=deleteDuplicatesUnsorted(ll.getHead());
    EXPECT_EQ(actual,nullptr);
    ll.setHead(nullptr);
}

TEST(PurgeRepeateNodesFromUnlortedLL,OnlyDuplicates) {
    LinkedList ll;
    buildList(ll,{4,4,4,4});

    Node *actual=deleteDuplicatesUnsorted(ll.getHead());
    EXPECT_EQ(actual,nullptr);
    ll.setHead(nullptr);

}

TEST(PurgeRepeateNodesFromUnlortedLL,DuplicatesOnBegginig) {
    LinkedList ll;
    buildList(ll,{2,2,3,3,4,5,5,6});

    Node *actual=deleteDuplicatesUnsorted(ll.getHead());
    ll.setHead(nullptr);
    std::vector<int>actualVec=toVector(actual);
    std::vector<int> expected={4,6};
    EXPECT_EQ(actualVec,expected);
    freeList(actual);
}