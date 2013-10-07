#ifndef RANDOM_LIST_NODE
#define RANDOM_LIST_NODE

#include <iostream>
using namespace std;

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) :
			label(x), next(NULL), random(NULL) {
	}
};

#endif
