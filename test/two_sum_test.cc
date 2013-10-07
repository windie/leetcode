#include "common.h"
#include "two_sum.h"
#include <gtest/gtest.h>

TEST(two_sum, test1){
	Solution s;
	vector<int> gt;
	gt.push_back(1);
	gt.push_back(2);
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(1);
	nums.push_back(9);

	vector<int> res = s.twoSum(nums, 9);

	for(int i=0; i<gt.size(); i++){
		EXPECT_EQ(gt[i], res[i]);
	}
}

TEST(two_sum, test2){
	Solution s;
	vector<int> gt;
	gt.push_back(1);
	gt.push_back(2);
	vector<int> nums;
	nums.push_back(7);
	nums.push_back(2);

	vector<int> res = s.twoSum(nums, 9);

	for(int i=0; i<gt.size(); i++){
		EXPECT_EQ(gt[i], res[i]);
	}
}

TEST(two_sum, test3){
	Solution s;
	vector<int> gt;
	gt.push_back(2);
	gt.push_back(4);
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(7);
	nums.push_back(15);
	nums.push_back(20);

	vector<int> res = s.twoSum(nums, 18);

	for(int i=0; i<gt.size(); i++){
		EXPECT_EQ(gt[i], res[i]);
	}
}

