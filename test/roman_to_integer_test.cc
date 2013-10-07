#include "common.h"
#include "roman_to_integer.h"
#include <gtest/gtest.h>

TEST(roman_to_integer, romanToInt){
	Solution s;
	EXPECT_EQ(190, s.romanToInt("CXC"));
	EXPECT_EQ(1, s.romanToInt("I"));
	EXPECT_EQ(9, s.romanToInt("IX"));
	EXPECT_EQ(90, s.romanToInt("XC"));
}
