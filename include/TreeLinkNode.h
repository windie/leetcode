#ifndef TREE_LINK_NODE
#define TREE_LINK_NODE
#include <iostream>
using namespace std;

struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
  };

#endif
