#include "common.h"
#include "Valid_Palindrome.h"
#include <gtest/gtest.h>

TEST(Valid_Palindrome, isPalindrome) {
  Solution s;
  ASSERT_TRUE(s.isPalindrome("A man, a plan, a canal: Panama"));
  ASSERT_FALSE(s.isPalindrome("race a car"));
  ASSERT_TRUE(s.isPalindrome(""));
}
