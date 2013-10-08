class Solution {
    ListNode *addOne(ListNode *l){
        if(l==NULL){
            ListNode*res = new ListNode(1);
            return res;
        }
        int addone = 1;
        ListNode* p=l, *pre = NULL;
        while(p!=NULL && addone){
            int val = (p->val + addone)%10;
            addone = (p->val + 1)/10;
            p->val = val;
            pre = p;
            p = p->next;
        }
        if(addone){
            pre->next = new ListNode(1);
        }
        return l;
    }
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int addone = 0;
        ListNode* p1=l1, *p2=l2, *res=NULL, *cur = NULL;
        while(p1!=NULL && p2!=NULL){
            int val = (p1->val + p2->val + addone)%10;
            addone = (p1->val + p2->val + addone)/10;
            ListNode *p = new ListNode(val);
            if(res == NULL){
                res = p;
                cur = p;
            }else{
                cur->next = p;
                cur = cur->next;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        if(p1==NULL && addone==0){
            cur->next = p2;
            return res;
        }
        if(p2==NULL && addone==0){
            cur->next = p1;
            return res;
        }
        if(p1==NULL && addone==1){
            cur->next = addOne(p2);
            return res;
        }
        if(p2==NULL && addone == 1){
            cur->next = addOne(p1);
            return res;
        }
        return res;
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
