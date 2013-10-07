#include "common.h"
#include "add_two_numbers.h"
#include <gtest/gtest.h>

TEST(add_two_numbers, test1){
	Solution s;
	ListNode *l1 = new ListNode(1);
	ListNode *l2 = new ListNode(9);
	l2->next = new ListNode(9);
	ListNode *l = new ListNode(0);
	l->next = new ListNode(0);
	l->next->next = new ListNode(1);
	ListNode *res= s.addTwoNumbers(l1, l2);
	EXPECT_EQ(l->val, res->val);
	EXPECT_EQ(l->next->val, res->next->val);
	EXPECT_EQ(l->next->next->val, res->next->next->val);
}
