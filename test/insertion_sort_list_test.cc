#include "common.h"
#include "insertion_sort_list.h"
#include <gtest/gtest.h>

TEST(test1, insertionSortList){
	Solution s;
	ListNode * head= new ListNode(3);
	head->next = new ListNode(2);
	head->next->next = new ListNode(4);
	head = s.insertionSortList(head);
}
