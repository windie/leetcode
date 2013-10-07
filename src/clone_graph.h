/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node,
			unordered_map<int, UndirectedGraphNode *> &map) {
		UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
		map[node->label] = newNode;
		for (int i = 0; i < node->neighbors.size(); i++) {
			auto it = map.find(node->neighbors[i]->label);
			if (it != map.end()) {
				newNode->neighbors.push_back(it->second);
			} else {
				newNode->neighbors.push_back(
						cloneGraph(node->neighbors[i], map));
			}
		}
		return newNode;
	}
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if(node==NULL){
			return NULL;
		}
		unordered_map<int, UndirectedGraphNode *> map;
		return cloneGraph(node, map);
	}
};
