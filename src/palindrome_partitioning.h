class Solution {
	bool ispalinmore(string &s){
		for(int i=0; i<s.size()/2; i++){
			if(s[i] != s[s.size()-i-1]){
				return false;
			}
		}
		return true;
	}
	void recursive(string &s, int begin, vector<vector<string> >&res, vector<string> &temp){
		if(begin >=s.size()){
			res.push_back(temp);
		}
		for(int i=begin; i<s.size(); i++){
			string t=s.substr(begin, i-begin+1);
			if(ispalinmore(t)){
				temp.push_back(t);
				recursive(s, i+1, res, temp);
				temp.pop_back();
			}
		}
	}
public:
	vector<vector<string> > partition(string s) {
		vector < string > part;
		vector < vector<string> > res;
		recursive(s, 0, res, part);
		return res;
	}
};


//class Solution {
//private:
//	bool isValid(const char * s, int size) {
//		for (int i = 0; i < size / 2; i++) {
//			if (s[i] != s[size - i - 1]) {
//				return false;
//			}
//		}
//		return true;
//	}
//	void recursive(const char * s, int size, int begin,
//			vector<string> & curStrSet, vector<vector<string> >& res) {
//		if (begin == size) {
//			if (!curStrSet.empty()) {
//				res.push_back(curStrSet);
//			}
//			return;
//		}
//		for (int i = begin; i < size; i++) {
//			if (isValid(s + begin, i - begin + 1)) {
//				string str(s + begin, i - begin + 1);
//				curStrSet.push_back(str);
//				recursive(s, size, i + 1, curStrSet, res);
//				curStrSet.pop_back();
//			}
//		}
//	}
//public:
//	vector<vector<string> > partition(string s) {
//		vector < string > part;
//		vector < vector<string> > res;
//		recursive(s.c_str(), s.length(), 0, part, res);
//		return res;
//	}
//};
