#include "common.h"
#include "Decode_Ways.h"
#include <gtest/gtest.h>

TEST(Decode_Ways, test1){
	Solution s;
	EXPECT_EQ(2, s.numDecodings("12"));
}

TEST(Decode_Ways, test2){
	Solution s;
	EXPECT_EQ(0, s.numDecodings("02"));
}
