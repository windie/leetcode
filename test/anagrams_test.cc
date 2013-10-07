#include "common.h"
#include "anagrams.h"
#include <gtest/gtest.h>

TEST(anagrams, test1){
	Solution s;
	vector<string> strs;
	strs.push_back("");
	strs.push_back("");
	vector<string> res = s.anagrams(strs);

	for(int i=0; i<strs.size(); i++){
		EXPECT_EQ(strs[i], res[i]);
	}
}
