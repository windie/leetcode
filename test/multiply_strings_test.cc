#include "common.h"
#include "multiply_strings.h"
#include <gtest/gtest.h>

TEST(test1, multiply){
	Solution s;
	EXPECT_EQ("3400", s.multiply("100", "34"));
	EXPECT_EQ("6", s.multiply("2", "3"));
	EXPECT_EQ("56088", s.multiply("123", "456"));
}
