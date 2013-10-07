#include "common.h"
#include "Best_Time_to_Buy_and_Sell_Stock.h"
#include <gtest/gtest.h>


TEST(Best_Time_to_Buy_and_Sell_Stock, test1){
	Solution s;
	vector<int> prices;
	prices.push_back(0);
	prices.push_back(1);
	prices.push_back(4);
	EXPECT_EQ(4, s.maxProfit(prices));
}

TEST(Best_Time_to_Buy_and_Sell_Stock, test2){
	Solution s;
	vector<int> prices;
	prices.push_back(3);
	prices.push_back(4);
	prices.push_back(2);
	prices.push_back(1);
	prices.push_back(6);
	prices.push_back(7);
	EXPECT_EQ(6, s.maxProfit(prices));
}
