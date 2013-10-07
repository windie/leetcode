#include "common.h"
#include "candy.h"
#include <gtest/gtest.h>

TEST(candy, test1) {
	Solution s;
	vector<int> c;
	c.push_back(1);
	c.push_back(2);
	c.push_back(3);
	EXPECT_EQ(6, s.candy(c));
}

TEST(candy, test2) {
	Solution s;
	vector<int> c2;
	c2.push_back(2);
	c2.push_back(2);
	EXPECT_EQ(2, s.candy(c2));

}

TEST(candy, test3) {
	Solution s;
	vector<int> c2;
	c2.push_back(1);
	c2.push_back(0);
	c2.push_back(2);
	EXPECT_EQ(5, s.candy(c2));

}

TEST(candy, test4) {
	Solution s;
	int c[100] = {  58, 21, 72, 77, 48, 9, 38, 71, 68, 77, 82, 47, 25, 94,
			89, 54, 26, 54, 54, 99, 64, 71, 76, 63, 81, 82, 60, 64, 29, 51, 87,
			87, 72, 12, 16, 20, 21, 54, 43, 41, 83, 77, 41, 61, 72, 82, 15, 50,
			36, 69, 49, 53, 92, 77, 16, 73, 12, 28, 37, 41, 79, 25, 80, 3, 37,
			48, 23, 10, 55, 19, 51, 38, 96, 92, 99, 68, 75, 14, 18, 63, 35, 19,
			68, 28, 49, 36, 53, 61, 64, 91, 2, 43, 68, 34, 46, 57, 82, 22, 67,
			89 };
	vector<int> cc;
	for(int i=0; i<100; i++){
		cc.push_back(c[i]);
	}
	EXPECT_EQ(208, s.candy(cc));
}
