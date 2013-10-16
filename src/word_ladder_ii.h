//class Solution {
//public:
//	vector<vector<string> > findLadders(string start, string end,
//			unordered_set<string> &dict) {
//		pathes.clear();
//		dict.insert(start);
//		dict.insert(end);
//		vector < string > prev;
//		unordered_map<string, vector<string> > traces;
//		for (unordered_set<string>::const_iterator citr = dict.begin();
//				citr != dict.end(); citr++) {
//			traces[*citr] = prev;
//		}
//
//		vector < unordered_set<string> > layers(2);
//		int cur = 0;
//		int pre = 1;
//		layers[cur].insert(start);
//		while (true) {
//			cur = !cur;
//			pre = !pre;
//			for (unordered_set<string>::const_iterator citr =
//					layers[pre].begin(); citr != layers[pre].end(); citr++)
//				dict.erase(*citr);
//			layers[cur].clear();
//			for (unordered_set<string>::const_iterator citr =
//					layers[pre].begin(); citr != layers[pre].end(); citr++) {
//				for (int n = 0; n < (*citr).size(); n++) {
//					string word = *citr;
//					int stop = word[n] - 'a';
//					for (int i = (stop + 1) % 26; i != stop; i = (i + 1) % 26) {
//						word[n] = 'a' + i;
//						if (dict.find(word) != dict.end()) {
//							traces[word].push_back(*citr);
//							layers[cur].insert(word);
//						}
//					}
//				}
//			}
//			if (layers[cur].size() == 0)
//				return pathes;
//			if (layers[cur].count(end))
//				break;
//		}
//		vector < string > path;
//		buildPath(traces, path, end);
//
//		return pathes;
//	}
//
//private:
//	void buildPath(unordered_map<string, vector<string> > &traces,
//			vector<string> &path, const string &word) {
//		if (traces[word].size() == 0) {
//			path.push_back(word);
//			vector < string > curPath = path;
//			reverse(curPath.begin(), curPath.end());
//			pathes.push_back(curPath);
//			path.pop_back();
//			return;
//		}
//
//		const vector<string> &prevs = traces[word];
//		path.push_back(word);
//		for (vector<string>::const_iterator citr = prevs.begin();
//				citr != prevs.end(); citr++) {
//			buildPath(traces, path, *citr);
//		}
//		path.pop_back();
//	}
//
//	vector<vector<string> > pathes;
//};

class Solution {

public:
	vector<vector<string> > findLadders(string start, string end,
			unordered_set<string> &dict) {
		vector < vector<string> > res;
		vector < string > graph;
		vector<int> path;
		graph.push_back(start);
		dict.erase(start);
		path.push_back(-1);
		int begin = 0, size = 1;
		bool isfind = false;
		int numLevel = 1;
		while (begin < size && !isfind) {
			numLevel++;
			for (int i = begin; i < size; i++) {
				for (int j = 0; j < graph[i].size(); j++) {
					for (int ch = 'a'; ch <= 'z'; ch++) {
						if (ch == graph[i][j]) {
							continue;
						}
						string newword = graph[i];
						newword[j] = ch;
						if (newword == end) {
							vector < string > shortestPath(numLevel);
							int k = i, index = numLevel - 1;
							shortestPath[index--] = newword;
							while (k >= 0) {
								shortestPath[index--] = graph[k];
								k = path[k];
							}
							isfind = true;
							res.push_back(shortestPath);
						}
						if (dict.find(newword) != dict.end()) {
							graph.push_back(newword);
							path.push_back(i);
						}
					}
				}
			}
			begin = size;
			for (int ii = size; ii < graph.size(); ii++) {
				dict.erase(graph[ii]);
			}
			size = graph.size();
		}
		return res;
	}
};
