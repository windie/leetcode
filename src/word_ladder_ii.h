class Solution {
public:
	void AdjGraph(vector<vector<int> > &adjGraph, vector<string> &nodes,
			unordered_map<string, int> &wordIdx,
			const unordered_set<string> &dict) {
		int j = 0;
		for (auto it = dict.begin(); it != dict.end(); it++, j++) {
			nodes.push_back(*it);
			wordIdx[*it] = j;
		}
		for (int i = 0; i < nodes.size(); i++) {
			vector<int> tmp;
			adjGraph.push_back(tmp);
		}
		for (int i = 0; i < nodes.size(); i++) {
			string word = nodes[i];
			for (int j = 0; j < word.size(); j++) {
				for (char ch = 'a'; ch <= 'z'; ch++) {
					if (ch == word[j]) {
						continue;
					}
					char chtmp = word[j];
					word[j] = ch;
					auto it = wordIdx.find(word);
					if (it != wordIdx.end()) {
						adjGraph[i].push_back(it->second);
					}
					word[j] = chtmp;
				}
			}
		}
	}

	vector<vector<string> > findLadders(string start, string end,
			unordered_set<string> &dict) {
		vector < vector<int> > adjGraph;
		vector < string > nodes; // index -> string
		unordered_map<string, int> wordIdx; // string -> index
		dict.insert(start);
		dict.insert(end);
		AdjGraph(adjGraph, nodes, wordIdx, dict);

		int startIdx = wordIdx[start], endIdx = wordIdx[end];
		vector < vector<string> > res;
		vector<int> graph, path;
		unordered_set<int> used;
		graph.push_back(startIdx);
		path.push_back(-1);
		used.insert(startIdx);
		int begin = 0, size = 1;
		bool isfind = false;
		while (begin < size && !isfind) {
			for (int i = begin; i < size; i++) {
				int curWord = graph[i];
				for (int j = 0; j < adjGraph[curWord].size(); j++) {
					int adjWord = adjGraph[curWord][j];
					if (adjWord == endIdx) {
						isfind = true;
						vector < string > respath;
						respath.push_back(end);
						respath.push_back(nodes[curWord]);
						int k = path[i];
						while (k >= 0) {
							respath.push_back(nodes[graph[k]]);
							k = path[k];
						}
						reverse(respath.begin(), respath.end());
						res.push_back(respath);
					} else if (used.find(adjWord) == used.end()) {
						graph.push_back(adjWord);
						path.push_back(i);
					}
				}
			}
			used.insert(graph.begin() + size, graph.end());
			begin = size;
			size = graph.size();
		}
		return res;
	}
};
