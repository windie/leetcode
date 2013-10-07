#include "common.h"
#include "four_sum.h"
#include <gtest/gtest.h>

TEST(four_sum, test1){
	Solution s;
	vector<int> input;
	input.push_back(1);
	input.push_back(0);
	input.push_back(-1);
	input.push_back(0);
	input.push_back(-2);
	input.push_back(2);

	vector<int> t1;
	t1.push_back(-1);
	t1.push_back(0);
	t1.push_back(0);
	t1.push_back(1);

	vector<int> t2;
	t2.push_back(-2);
	t2.push_back(-1);
	t2.push_back(1);
	t2.push_back(2);

	vector<int> t3;
	t3.push_back(-2);
	t3.push_back(0);
	t3.push_back(0);
	t3.push_back(2);

	vector<vector<int> > gt;
	gt.push_back(t2);
	gt.push_back(t3);
	gt.push_back(t1);

	vector<vector<int> > rs = s.fourSum(input, 0);

	EXPECT_EQ(gt.size(), rs.size());
	for(int i=0; i<gt.size(); i++){
		EXPECT_EQ(gt[i].size(), rs[i].size());
		for(int j=0; j<gt.size(); j++){
			EXPECT_EQ(gt[i][j], rs[i][j]);
		}
	}
}
