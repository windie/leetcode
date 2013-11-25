class Solution{
	ListNode * addTwoNumbers(ListNode *n1, ListNode *n2, int carry){
		if(n1 == NULL && n2 == NULL && carry==0){
			return NULL;
		}
		int val = carry;
		if(n1!=NULL){
			val+=n1->val;
		}
		if(n2!=NULL){
			val+=n2->val;
		}
		ListNode * cur = new ListNode(val%10);
		cur->next = addTwoNumbers(n1==NULL? NULL : n1->next, n2==NULL? NULL: n2->next, val/10);
		return cur;
	}
public:
	ListNode * addTwoNumbers(ListNode* n1, ListNode *n2){
		return addTwoNumbers(n1, n2, 0);
	}
};


//class Solution {
//
//private:
//	ListNode *addone(ListNode *l) {
//		ListNode* pre, * pos = l;
//		int add = 1, digit = 0;
//		while (pos != NULL) {
//			digit = (pos->val + add) % 10;
//			add = (pos->val + add) / 10;
//			pos->val = digit;
//			if (add == 0) {
//				break;
//			}
//			pre = pos;
//			pos = pos->next;
//		}
//		if(pos==NULL && add == 1){
//			pre->next = new ListNode(1);
//		}
//		return l;
//	}
//public:
//	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
//		if (l1 == NULL) {
//			return l2;
//		}
//		if (l2 == NULL) {
//			return l1;
//		}
//		ListNode *pos1 = l1, *pos2 = l2, *res = NULL, *curpos = NULL;
//		int add = 0, digit = 0;
//		while ((pos1 != NULL) && (pos2 != NULL)) {
//			digit = (pos1->val + pos2->val + add) % 10;
//			add = (pos1->val + pos2->val + add) / 10;
//			if (res == NULL) {
//				res = new ListNode(digit);
//				curpos = res;
//			} else {
//				curpos->next = new ListNode(digit);
//				curpos = curpos->next;
//			}
//			pos1 = pos1->next;
//			pos2 = pos2->next;
//		}
//		if (pos1 == NULL && pos2 == NULL) {
//			if (add == 1) {
//				curpos->next = new ListNode(1);
//			}
//			return res;
//		}
//		if (pos1 != NULL) {
//			if(add == 1){
//				curpos->next = addone(pos1);
//			}else{
//				curpos->next = pos1;
//			}
//		} else {
//			if(add==1){
//				curpos->next = addone(pos2);
//			}else{
//				curpos->next = pos2;
//			}
//		}
//		return res;
//	}
//};
