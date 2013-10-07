class Solution {
public:
	vector<vector<string> > findLadders(string start, string end,
			unordered_set<string> &dict) {
		vector < vector<string> > res;
		vector < string > graph;
		vector<int> path;
		unordered_set < string > used;
		graph.push_back(start);
		used.insert(start);
		path.push_back(-1);
		int begin = 0, size = 1;
		bool isfind = false;
		while (begin < size && !isfind) {
			for (int i = begin; i < size; i++) {
				string curword = graph[i];

				for (int j = 0; j < curword.size(); j++) {
					for (int ch = 'a'; ch <= 'z'; ch++) {
						string newword = curword;
						if (newword[j] != ch) {
							newword[j] = ch;
							// add path
							if (newword == end) {
								vector < string > shortestPath;
								vector < string > each;
								each.push_back(newword);
								int k = i;
								while (k >= 0) {
									each.push_back(graph[k]);
									k = path[k];
								}
								shortestPath.assign(each.rbegin(), each.rend());
								isfind = true;
								res.push_back(shortestPath);
							}
							// new graph
							if (dict.find(newword) != dict.end()
									&& used.find(newword) == used.end()) {
								graph.push_back(newword);
								path.push_back(i);
							}
						}
					}
				}
			}
			begin = size;
			for (int ii = size; ii < graph.size(); ii++) {
				used.insert(graph[ii]);
			}
			size = graph.size();
		}
		return res;
	}
};
