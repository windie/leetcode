#include "common.h"
#include "Edit_Distance.h"
#include <gtest/gtest.h>

TEST(Edit_Distance, minDistance){
	Solution s;
	EXPECT_EQ(0, s.minDistance("",""));
	EXPECT_EQ(1, s.minDistance("a","n"));
	EXPECT_EQ(5, s.minDistance("intention", "execution"));
	EXPECT_EQ(4, s.minDistance("prosperity", "properties"));
}
