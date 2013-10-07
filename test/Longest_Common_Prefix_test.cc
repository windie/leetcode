#include "common.h"
#include "Longest_Common_Prefix.h"
#include <gtest/gtest.h>
#include <vector>

TEST(Longest_Common_Prefix, longestCommonPrefix){
	Solution s;
	string str1[] = {"abc", "ab", "abdere"};
	vector<string> strs1;
	strs1.assign(str1, str1+3);
	EXPECT_EQ("ab", s.longestCommonPrefix(strs1));

	string str2[] = {"abcere", "abc", "abcere"};
	vector<string> strs2;
	strs2.assign(str2, str2+3);
	EXPECT_EQ("abc", s.longestCommonPrefix(strs2));
}

