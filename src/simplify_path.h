class Solution {
	string construct(vector<string> spath) {
		string res = "/";
		for (int i = 0; i < spath.size(); i++) {
			res += spath[i];
			if (i != spath.size() - 1) {
				res += "/";
			}
		}
		return res;
	}
public:
	string simplifyPath(string path) {
		vector < string > spath;
		if (path.size() == 0) {
			return construct(spath);
		}
		string folder = "";
		for (int i = 1; i < path.size(); i++) {
			if (path[i] == '/') {
				if (!folder.empty()) {
					spath.push_back(folder);
					folder = "";
				}
			} else if (path[i] == '.') {
				i++;
				if (i < path.size()) {
					if (path[i] == '/') {
						continue;
					} else if (path[i] == '.') {
						if (!spath.empty()) {
							spath.pop_back();
						}
						if ((i + 1) < path.size() && path[i + 1] == '/') {
							i++;
						}
					} else {
						folder.push_back('.');
						folder.push_back(path[i]);
					}
				}
			} else {
				folder.push_back(path[i]);
			}
		}
		if (!folder.empty()) {
			spath.push_back(folder);
		}
		return construct(spath);
	}
};

//class Solution {
//public:
//	string simplifyPath(string path) {
//		stack<string> s;
//		int i = 0;
//		while (i < path.size() && path[i] == '/') {
//			i++;
//		}
//		while (i < path.size()) {
//			int pos = path.find('/', i);
//			if (pos != string::npos) {
//				string subpath = path.substr(i, pos - i);
//				if (subpath.size() == 0) {
//					i++;
//					continue;
//				}
//				if (subpath == ".") {
//					i += 2;
//					continue;
//				} else if (subpath == "..") {
//					if (s.size() > 0) {
//						s.pop();
//					}
//					i += 3;
//					continue;
//				} else {
//					s.push(subpath);
//					i += (subpath.size() + 1);
//				}
//			} else {
//				string subpath = path.substr(i);
//				if(subpath ==".."){
//					if(!s.empty()){
//						s.pop();
//					}
//				}else if(subpath!="."){
//					s.push(subpath);
//				}
//				break;
//			}
//		}
//		string res;
//		if (s.empty()) {
//			return "/";
//		}
//		while (!s.empty()) {
//			res = s.top() + res;
//			res = "/" + res;
//			s.pop();
//		}
//		return res;
//	}
//};
