#include "common.h"
#include "interleaving_string.h"
#include <gtest/gtest.h>

TEST(interleaving_string, test1){
	Solution s;
	EXPECT_EQ(true, s.isInterleave("aabcc", "dbbca", "aadbbcbcac"));
	EXPECT_EQ(false, s.isInterleave("aabcc", "dbbca", "aadbbbaccc"));
	EXPECT_EQ(false, s.isInterleave("aad", "ab", "aadba"));
	EXPECT_EQ(true, s.isInterleave("aa", "ab", "aaba"));
}
