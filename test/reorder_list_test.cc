#include "common.h"
#include "reorder_list.h"
#include <gtest/gtest.h>

TEST(test1, reorderList){
	Solution s;
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);

	s.reorderList(head);

	EXPECT_EQ(1, head->val);
	EXPECT_EQ(4, head->next->val);
	EXPECT_EQ(2, head->next->next->val);
	EXPECT_EQ(3, head->next->next->next->val);
	EXPECT_EQ(NULL, head->next->next->next->next);
}
