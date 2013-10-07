#include "common.h"
#include "threesum.h"
#include <gtest/gtest.h>

TEST(threesum, test1){
	Solution s;
	vector<int> t1;
	t1.push_back(-1);
	t1.push_back(0);
	t1.push_back(1);
	vector<int> t2;
	t2.push_back(-1);
	t2.push_back(-1);
	t2.push_back(2);
	vector<int> in;
	in.push_back(-1);
	in.push_back(0);
	in.push_back(1);
	in.push_back(2);
	in.push_back(-1);
	in.push_back(-4);

	vector<vector<int> > res = s.threeSum(in);
	vector<vector<int> > gt;
	gt.push_back(t2);
	gt.push_back(t1);
	EXPECT_EQ(gt.size(), res.size());
	for(int i=0; i<gt.size(); i++){
		EXPECT_EQ(gt[i].size(),res[i].size());
		for(int j=0; j<gt[i].size(); j++){
			EXPECT_EQ(gt[i][j], res[i][j]);
		}
	}
}

TEST(threesum, test2) {
	Solution s;
	vector<int> t1;
	t1.push_back(0);
	t1.push_back(0);
	t1.push_back(0);

	vector<int> in;
	in.push_back(0);
	in.push_back(0);
	in.push_back(0);

	vector<vector<int> > res = s.threeSum(in);
	vector<vector<int> > gt;
	gt.push_back(t1);
	EXPECT_EQ(gt.size(), res.size());
	for (int i = 0; i < gt.size(); i++) {
		EXPECT_EQ(gt[i].size(), res[i].size());
		for (int j = 0; j < gt[i].size(); j++) {
			EXPECT_EQ(gt[i][j], res[i][j]);
		}
	}
}

TEST(threesum, test3) {
	Solution s;
	vector<int> t1;
	t1.push_back(-3);
	t1.push_back(1);
	t1.push_back(2);

	vector<int> in;
	in.push_back(-3);
	in.push_back(1);
	in.push_back(2);

	vector<vector<int> > res = s.threeSum(in);
	vector<vector<int> > gt;
	gt.push_back(t1);
	EXPECT_EQ(gt.size(), res.size());
	for (int i = 0; i < gt.size(); i++) {
		EXPECT_EQ(gt[i].size(), res[i].size());
		for (int j = 0; j < gt[i].size(); j++) {
			EXPECT_EQ(gt[i][j], res[i][j]);
		}
	}
}

TEST(threesum, test4) {
	Solution s;
	vector<int> t1;
	t1.push_back(-3);
	t1.push_back(1);
	t1.push_back(2);

	vector<int> in;
	in.push_back(-3);
	in.push_back(1);
	in.push_back(1);
	in.push_back(0);
	in.push_back(2);
	in.push_back(2);

	vector<vector<int> > res = s.threeSum(in);
	vector<vector<int> > gt;
	gt.push_back(t1);
	EXPECT_EQ(gt.size(), res.size());
	for (int i = 0; i < gt.size(); i++) {
		EXPECT_EQ(gt[i].size(), res[i].size());
		for (int j = 0; j < gt[i].size(); j++) {
			EXPECT_EQ(gt[i][j], res[i][j]);
		}
	}
}
