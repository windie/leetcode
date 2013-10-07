class Solution {
public:
	int ladderLength(string start, string end, unordered_set<string> &dict) {
		vector < string > graph;
		unordered_set<string> used;
		graph.push_back(start);
		used.insert(start);
		int begin = 0, size = 1, level = 0;
		while (begin < size) {
			for (int i = begin; i < size; i++) {
				string curword = graph[i];
				if (curword == end) {
					return level+1;
				}
				for (int j = 0; j < curword.size(); j++) {
					for (int ch = 'a'; ch <= 'z'; ch++) {
						string newword = curword;
						if (newword[j] != ch) {
							newword[j] = ch;
							if (dict.find(newword) != dict.end() && used.find(newword) == used.end()) {
								graph.push_back(newword);
								used.insert(newword);
							}
						}
					}
				}
			}
			level++;
			begin = size;
			size = graph.size();
		}
		return 0;
	}
};
