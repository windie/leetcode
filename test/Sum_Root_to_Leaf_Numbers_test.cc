#include "common.h"
#include "Sum_Root_to_Leaf_Numbers.h"
#include <gtest/gtest.h>

TEST(Sum_Root_to_Leaf_Numbers, sumNumbers){
	Solution s;

	TreeNode *l = new TreeNode(2);
	TreeNode *r = new TreeNode(4);
	TreeNode *n = NULL;
	TreeNode *l1 = new TreeNode(0);
	l1->left = new TreeNode(1);
	l1->right = NULL;

	EXPECT_EQ(2, s.sumNumbers(l));
	EXPECT_EQ(4, s.sumNumbers(r));
	EXPECT_EQ(0, s.sumNumbers(n));
	EXPECT_EQ(1, s.sumNumbers(l1));

}
