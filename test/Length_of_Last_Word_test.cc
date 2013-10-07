#include "common.h"
#include "Length_of_Last_Word.h"
#include <gtest/gtest.h>

TEST(Length_of_Last_Word, length){
	Solution s;
	EXPECT_EQ(5, s.lengthOfLastWord("Hello World"));
}

TEST(Length_of_Last_Word, length0){
	Solution s;
	EXPECT_EQ(0, s.lengthOfLastWord(""));
}

TEST(Length_of_Last_Word, length1){
	Solution s;
	EXPECT_EQ(0, s.lengthOfLastWord(" "));
}

TEST(Length_of_Last_Word, length2){
	Solution s;
	EXPECT_EQ(1, s.lengthOfLastWord("a"));
}


TEST(Length_of_Last_Word, length3){
	Solution s;
	EXPECT_EQ(3, s.lengthOfLastWord("abc"));
}

TEST(Length_of_Last_Word, length4){
	Solution s;
	EXPECT_EQ(3, s.lengthOfLastWord("abc   "));
}

TEST(Length_of_Last_Word, length5){
	Solution s;
	EXPECT_EQ(3, s.lengthOfLastWord("   abc   "));
}
