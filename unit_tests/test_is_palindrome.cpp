#include "is_palindrome.hpp"
#include <gtest/gtest.h>
#include "test_utils.hpp"


TEST(IsPalindromeTests, EmptyList_IsPalindrome) {
    LinkedList ll;
    EXPECT_TRUE(isPalindrome(ll.getHead()));
}

TEST(IsPalindromeTests, SingleNode_IsPalindrome) {
    LinkedList ll;
    buildList(ll, {7});
    EXPECT_TRUE(isPalindrome(ll.getHead()));
}

TEST(IsPalindromeTests, TwoNodesEqual_IsPalindrome) {
    LinkedList ll;
    buildList(ll, {5, 5});
    EXPECT_TRUE(isPalindrome(ll.getHead()));
}

TEST(IsPalindromeTests, TwoNodesDifferent_IsNotPalindrome) {
    LinkedList ll;
    buildList(ll, {5, 6});
    EXPECT_FALSE(isPalindrome(ll.getHead()));
}

TEST(IsPalindromeTests, OddLengthPalindrome) {
    LinkedList ll;
    buildList(ll, {1, 2, 3, 2, 1});
    EXPECT_TRUE(isPalindrome(ll.getHead()));
}

TEST(IsPalindromeTests, EvenLengthPalindrome) {
    LinkedList ll;
    buildList(ll, {1, 2, 2, 1});
    EXPECT_TRUE(isPalindrome(ll.getHead()));
}

TEST(IsPalindromeTests, OddLengthNotPalindrome) {
    LinkedList ll;
    buildList(ll, {1, 2, 3, 4, 1});
    EXPECT_FALSE(isPalindrome(ll.getHead()));
}

TEST(IsPalindromeTests, EvenLengthNotPalindrome) {
    LinkedList ll;
    buildList(ll, {1, 2, 3, 1});
    EXPECT_FALSE(isPalindrome(ll.getHead()));
}

TEST(IsPalindromeTests, NegativeValuesPalindrome) {
    LinkedList ll;
    buildList(ll, {-1, 0, 7, 0, -1});
    EXPECT_TRUE(isPalindrome(ll.getHead()));
}

TEST(IsPalindromeTests, RepeatedValuesNotPalindrome) {
    LinkedList ll;
    buildList(ll, {2, 2, 2, 3, 2});
    EXPECT_FALSE(isPalindrome(ll.getHead()));
}