#include "common.h"
#include "Search_for_a_Range.h"
#include <gtest/gtest.h>

TEST(Search_for_a_Range, test1){
	Solution s;
	int A[] = {5, 7, 7, 8, 8, 10};
	vector<int> res = s.searchRange(A, 6, 8);
	EXPECT_EQ(3, res[0]);
	EXPECT_EQ(4, res[1]);
}

TEST(Search_for_a_Range, test2){
	Solution s;
	int A[] = {5, 7, 7, 8, 8, 10};
	vector<int> res = s.searchRange(A, 6, 9);
	EXPECT_EQ(-1, res[0]);
	EXPECT_EQ(-1, res[1]);
}
