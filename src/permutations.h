class Solution {
    void rec(vector<vector<int> > &res, int index, vector<int> & nums){
        if(index == nums.size()){
            return;
        }
        vector<vector<int> > cur;
        for(int i = 0; i<res.size(); i++){
            for(int j = 0; j<=res[i].size(); j++){
                vector<int> tmp = res[i];
                tmp.insert(tmp.begin() + j, 1, nums[index]);
                cur.push_back(tmp);
            }
        }
        res = cur;
        rec(res, index+1, nums);
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> tmp;
        vector<vector<int> > res;
        res.push_back(tmp);  // !!!
        rec(res, 0, nums);
        return res;
    }
};

// LintCode
class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    void rec(vector<vector<int> > &curres, vector<bool> visited, vector<int> &cur, vector<int> nums){
        if(cur.size() == nums.size()){
            curres.push_back(cur);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(visited[i]){
                continue;
            }
            visited[i] = true;
            cur.push_back(nums[i]);
            rec(curres, visited, cur, nums);
            cur.pop_back();
            visited[i] = false;
        }
    }

    vector<vector<int> > permute(vector<int> nums) {
        vector<vector<int> > res;
        vector<int> tmp;
        if(nums.size() == 0){
            return res;
        }
        vector<bool> visited(nums.size(), false);
        rec(res, visited, tmp, nums);
        return res;
    }
};

//#include<algorithm>
//using namespace std;
//
//class Solution {
//	vector<vector<int> > recursive(vector<vector<int> > &cur, int index, vector<int> &num){
//		if(index == num.size()){
//			return cur;
//		}
//		vector< vector<int> > res;
//		for(int i= 0; i<cur.size(); i++){
//			for(int j=0; j<=cur[i].size(); j++){
//				vector<int> tmp = cur[i];
//				tmp.insert(tmp.begin() + j, 1, num[index]);
//				res.push_back(tmp);
//			}
//		}
//		return recursive(res, index+1, num);
//	}
//public:
//	vector<vector<int> > permute(vector<int> &num) {
//		vector<vector<int> > res;
//		vector<int> tmp;
//		res.push_back(tmp);
//		res = recursive(res, 0, num);
//		return res;
//	}
//};

//class Solution {
//	void swap(vector<int> &num, int i, int k) {
//		int tmp = num[i];
//		num[i] = num[k];
//		num[k] = tmp;
//	}
//	void recursive(vector<int> &num, int n, int k, vector<vector<int> > & res) {
//		if (k == n - 1) {
//			res.push_back(num);
//		} else {
//			for (int i = k; i < n; i++) {
//				swap(num, k, i);
//				recursive(num, n, k + 1, res);
//				swap(num, k, i);
//			}
//		}
//	}
//public:
//	vector<vector<int> > permute(vector<int> &num) {
//		vector<vector<int> > res;
//		recursive(num, num.size(), 0, res);
//		return res;
//	}
//};


//class Solution {
//public:
//    vector<vector<int> > permute(vector<int> &num) {
//    	vector<vector<int> > res;
//    	sort(num.begin(), num.end());
//    	res.push_back(num);
//    	while (next_permutation(num.begin(), num.end())){
//    		res.push_back(num);
//    	}
//    	return res;
//    }
//};

