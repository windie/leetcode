#include "common.h"
#include "palindrome_number.h"
#include <gtest/gtest.h>

TEST(Palindrome_number, isPalindrome) {
  Solution s;
  ASSERT_TRUE(s.isPalindrome(121));
  ASSERT_FALSE(s.isPalindrome(124));
  ASSERT_TRUE(s.isPalindrome(1331));
  ASSERT_FALSE(s.isPalindrome(1234));

  ASSERT_TRUE(s.isPalindrome(-121));
  ASSERT_FALSE(s.isPalindrome(-124));
  ASSERT_TRUE(s.isPalindrome(-1331));
  ASSERT_FALSE(s.isPalindrome(-1234));
}
