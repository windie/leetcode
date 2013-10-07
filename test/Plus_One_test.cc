#include "common.h"
#include "Plus_One.h"
#include <gtest/gtest.h>
#include <vector>
using namespace std;

TEST(Plus_One, plusOne){
	Solution s;
	vector<int> num;
	num.push_back(9);
	num.push_back(9);
	num.push_back(9);
	vector<int> num1;
	num1.push_back(1);
	num1.push_back(0);
	num1.push_back(0);
	num1.push_back(0);

	vector<int> res = s.plusOne(num);

	ASSERT_EQ(num1.size(), res.size());

	for (int i = 0; i < num1.size(); ++i) {
	  EXPECT_EQ(num1[i], res[i]) ;
	}
}


TEST(Plus_One, plusOneno){
	Solution s;
	vector<int> num;
	num.push_back(9);
	num.push_back(9);
	num.push_back(8);
	vector<int> num1;
	num1.push_back(9);
	num1.push_back(9);
	num1.push_back(9);

	vector<int> res = s.plusOne(num);

	ASSERT_EQ(num1.size(), res.size()) ;

	for (int i = 0; i < num1.size(); ++i) {
	  EXPECT_EQ(num1[i], res[i]);
	}
}

TEST(Plus_One, plusOne9){
	Solution s;
	vector<int> num;
	num.push_back(9);
	vector<int> num1;
	num1.push_back(1);
	num1.push_back(0);

	vector<int> res = s.plusOne(num);

	ASSERT_EQ(num1.size(), res.size()) ;

	for (int i = 0; i < num1.size(); ++i) {
	  EXPECT_EQ(num1[i], res[i]);
	}
}
