class Solution {
public:
	char *strStr(char *haystack, char *needle) {
		if (needle == NULL || *needle == NULL) {
			return haystack;
		}
		if (haystack == NULL || *haystack == NULL) {
			return NULL;
		}
		char *p = haystack;
		while (*p) {
			if (*p != *needle) {
				p++;
			} else {
				char *p1 = p;
				char *p2 = needle;
				while (*p1 && *p2 && *p1 == *p2) {
					p1++;
					p2++;
				}
				if (*p2 == NULL) {
					return p;
				}
				if (*p1 == NULL) {
					return NULL;
				}
				p++;
			}
		}
		return NULL;
	}
};

//class Solution {
//public:
//	char *strStr(char *haystack, char *needle) {
//		if(*needle==NULL){
//			return haystack;
//		}
//		while (*haystack != NULL) {
//			if(*haystack != *needle){
//				haystack++;
//			}else{
//				////////////////////
//				char *p1 = haystack;
//				char *p2 = needle;
//				bool isFind=true;
//				while(*p1!=NULL && *p2!=NULL){
//					if(*p1==*p2){
//						p1++;
//						p2++;
//					}else{
//						isFind = false;
//						break;
//					}
//				}
//				if(*p2!=NULL){
//					isFind=false;
//				}
//				if(*p1==NULL && *p2!=NULL){
//					return NULL;
//				}
//				////////////////////
//				if(isFind){
//					return haystack;
//				}else{
//					haystack++;
//				}
//			}
//		}
//		if(*haystack==NULL){
//			return NULL;
//		}
//	}
//};
