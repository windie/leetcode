#include "common.h"
#include "Remove_Duplicates_from_Sorted_List_2.h"
#include <gtest/gtest.h>

TEST(Remove_Duplicates_form_Sorted_list_2, remove1) {
	Solution s;
	ListNode one(1);
	ListNode two1(2);
	ListNode two2(2);
	ListNode two3(2);
	ListNode three(3);
	one.next = &two1;
	two1.next = &two2;
	two2.next = &two3;
	two3.next = &three;

	ListNode *remove = s.deleteDuplicates(&one);
	ASSERT_EQ(&one, remove);
	ASSERT_EQ(&three, remove->next);
}

TEST(Remove_Duplicates_form_Sorted_list_2, remove2) {
	Solution s;
	ListNode two1(2);
	ListNode two2(2);
	ListNode two3(2);
	ListNode three(3);
	two1.next = &two2;
	two2.next = &two3;
	two3.next = &three;

	ListNode *remove = s.deleteDuplicates(&two1);
	ASSERT_EQ(&three, remove);
}

TEST(Remove_Duplicates_form_Sorted_list_2, remove3) {
	Solution s;
	ListNode two1(2);
	ListNode two2(2);
	ListNode two3(2);
	two1.next = &two2;
	two2.next = &two3;

	ListNode *remove = s.deleteDuplicates(&two1);
	ASSERT_EQ(NULL, remove);
}


TEST(Remove_Duplicates_form_Sorted_list_2, remove4) {
	Solution s;
	ListNode two1(2);
	ListNode *remove = s.deleteDuplicates(&two1);
	ASSERT_EQ(&two1, remove);
}

TEST(Remove_Duplicates_form_Sorted_list_2, remove5) {
	Solution s;
	ListNode two1(2);
	ListNode two2(2);
	ListNode three1(3);
	ListNode three2(3);
	two1.next = &two2;
	two2.next = &three1;
	three1.next = &three2;

	ListNode *remove = s.deleteDuplicates(&two1);
	ASSERT_EQ(NULL, remove);
}

TEST(Remove_Duplicates_form_Sorted_list_2, remove6) {
	Solution s;
	ListNode three1(3);
	ListNode four1(4);
	ListNode four2(4);
	ListNode five1(5);
	ListNode five2(5);
	three1.next = &four1;
	four1.next = &four2;
	four2.next = &five1;
	five1.next = &five2;

	ListNode *remove = s.deleteDuplicates(&three1);
	ASSERT_EQ(&three1, remove);
}

TEST(Remove_Duplicates_form_Sorted_list_2, remove7) {
	Solution s;
	ListNode two1(2);
	ListNode two2(2);
	ListNode three(3);
	ListNode four(4);
	two1.next = &two2;
	two2.next = &three;
	three.next = &four;

	ListNode *remove = s.deleteDuplicates(&two1);
	ASSERT_EQ(&three, remove);
	ASSERT_EQ(&four, remove->next);
	ASSERT_EQ(NULL, remove->next->next);
}

TEST(Remove_Duplicates_form_Sorted_list_2, remove8) {
	Solution s;
	ListNode two1(2);
	ListNode three1(3);
	ListNode three2(3);
	ListNode four1(4);
	ListNode four2(4);
	ListNode five(5);

	two1.next = &three1;
	three1.next = &three2;
	three2.next = &four1;
	four1.next = &four2;
	four2.next = &five;

	ListNode *remove = s.deleteDuplicates(&two1);
	ASSERT_EQ(&two1, remove);
	ASSERT_EQ(&five, remove->next);
	ASSERT_EQ(NULL, remove->next->next);
}
