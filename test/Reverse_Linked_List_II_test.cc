#include "common.h"
#include "Reverse_Linked_List_II.h"
#include <gtest/gtest.h>

TEST(test1, reverseBetween){
	Solution s;
	ListNode *head = new ListNode(3);
	ListNode *n2 = new ListNode(5);
	head->next = n2;
	s.reverseBetween(head, 1, 2);
	EXPECT_EQ(5, head->val);
	EXPECT_EQ(3, head->next->val);
}
