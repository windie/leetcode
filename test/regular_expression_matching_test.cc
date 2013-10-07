#include "common.h"
#include "regular_expression_matching.h"
#include <gtest/gtest.h>

TEST(isMatch, test1){
	Solution s;
	EXPECT_EQ(false, s.isMatch("aa", "a"));
	EXPECT_EQ(true, s.isMatch("aa", "aa"));
	EXPECT_EQ(true, s.isMatch("aa", "a*"));
	EXPECT_EQ(true, s.isMatch("aa", ".*"));
	EXPECT_EQ(true, s.isMatch("ab", ".*"));
}
