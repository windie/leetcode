#include "common.h"
#include "Add_Binary.h"
#include <gtest/gtest.h>

TEST(Add_Binary, test1){
	Solution s;
		EXPECT_EQ("100", s.addBinary("11", "1"));
}
