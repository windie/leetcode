#include "common.h"
#include "Gray_code.h"
#include <gtest/gtest.h>

TEST(Gray_code, test0){
	Solution s;
	vector<int> res;
	res.push_back(0);
	vector<int> test = s.grayCode(0);
	EXPECT_EQ(res.size(), test.size());
	EXPECT_EQ(res[0], test[0]);
}

TEST(Gray_code, test1){
	Solution s;
	vector<int> res;
	res.push_back(0);
	res.push_back(1);
	vector<int> test = s.grayCode(1);
	EXPECT_EQ(res.size(), test.size());

	for(int i = 0; i<res.size(); i++){
		EXPECT_EQ(res[i], test[i]);
	}
}

TEST(Gray_code, test2){
	Solution s;
	vector<int> res;
	res.push_back(0);
	res.push_back(1);
	res.push_back(3);
	res.push_back(2);
	vector<int> test = s.grayCode(2);
	EXPECT_EQ(res.size(), test.size());

	for(int i = 0; i<res.size(); i++){
		EXPECT_EQ(res[i], test[i]);
	}
}

TEST(Gray_code, test3){
	Solution s;
	vector<int> res;
	res.push_back(0);
	res.push_back(1);
	res.push_back(3);
	res.push_back(2);
	res.push_back(6);
	res.push_back(7);
	res.push_back(5);
	res.push_back(4);
	vector<int> test = s.grayCode(3);
	EXPECT_EQ(res.size(), test.size());

	for(int i = 0; i<res.size(); i++){
		EXPECT_EQ(res[i], test[i]);
	}
}

