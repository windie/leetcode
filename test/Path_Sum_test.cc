#include "common.h"
#include "Path_Sum.h"
#include <gtest/gtest.h>

TEST(Path_Sum, test1){
	Solution s;

	TreeNode *r = new TreeNode(5);
	TreeNode *l11 = new TreeNode(4);
	TreeNode *l12 = new TreeNode(8);
	TreeNode *l21 = new TreeNode(11);
	TreeNode *l22 = new TreeNode(13);
	TreeNode *l23 = new TreeNode(4);
	TreeNode *l31 = new TreeNode(7);
	TreeNode *l32 = new TreeNode(2);
	TreeNode *l33 = new TreeNode(1);
	r->left = l11;
	r->right =l12;
	l11->left = l21;
	l12->left= l22;
	l12->right =l23;
	l21->left = l31;
	l21->right = l32;
	l23->right = l33;

	EXPECT_EQ(true, s.hasPathSum(r, 22));
}

TEST(Path_Sum, test2){
	Solution s;
	TreeNode *r = NULL;
	EXPECT_EQ(false, s.hasPathSum(r, 22));
}
