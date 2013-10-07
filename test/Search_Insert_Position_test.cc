#include "common.h"
#include "Search_Insert_Position.h"
#include <gtest/gtest.h>

TEST(Search_Insert_Position, test1){
	Solution s;
	int A[] = {1, 3, 4, 5};
	EXPECT_EQ(3, s.searchInsert(A, 4, 5));
	EXPECT_EQ(1, s.searchInsert(A, 4, 2));
	EXPECT_EQ(0, s.searchInsert(A, 4, 1));
	EXPECT_EQ(4, s.searchInsert(A, 4, 6));
	EXPECT_EQ(0, s.searchInsert(A, 4, 0));
}
