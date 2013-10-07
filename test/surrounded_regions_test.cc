#include "common.h"
#include "surrounded_regions.h"
#include <gtest/gtest.h>

TEST(surrounded_regions, test1){
	Solution s;
	vector< vector<char> > res (3, vector<char>(3, 'X'));
	vector< vector<char> > input (3, vector<char>(3, 'X'));
	input[1][1] = 'O';
	s.solve(input);
	for(int i=0; i<3;i++){
		for(int j =0; j< 3; j++){
		//	printf("%d %d\n", i, j);
			EXPECT_EQ(res[i][j], input[i][j]);
		}
	}
}
