#include "common.h"
#include "ZigZag_Conversion.h"
#include <gtest/gtest.h>

TEST(ZigZag_Conversion, convert){
	Solution s;

	EXPECT_EQ("PAHNAPLSIIGYIR", s.convert("PAYPALISHIRING", 3));
	EXPECT_EQ("PINALSIGYAHRPI", s.convert("PAYPALISHIRING", 4));
}
