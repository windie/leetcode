#include "common.h"
#include "Remove_Duplicates_from_Sorted_List.h"
#include <gtest/gtest.h>

TEST(Remove_Duplicates_form_Sorted_list, remove){
	Solution s;
	ListNode one(1);
	ListNode one1(1);
	ListNode two(2);
	one.next = &one1;
	one1.next = &two;

	ListNode *remove = s.deleteDuplicates(&one);
	ASSERT_EQ(&one, remove);
	ASSERT_EQ(&two, remove->next);
}
