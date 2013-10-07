#include "common.h"
#include "minimum_window_substring.h"
#include <gtest/gtest.h>

TEST(minimum_window_substring, minWindow){
	Solution s;
	EXPECT_EQ("BANC", s.minWindow("ADOBECODEBANC","ABC"));
	EXPECT_EQ("", s.minWindow("ADOBECODEBANC","QE"));
}
