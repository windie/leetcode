#include<vector>
using namespace std;

bool mycmp(int i, int j){ return i<j; }

class Solution {
private:
	vector<vector<int> > twoSum(vector<int> &numbers, int begin, int target) {
		vector<vector<int> > res;
		for (int i = begin, j = numbers.size() - 1; i < j;) {
			int sum = numbers[i] + numbers[j];
			if (sum == target) {
				vector<int> tmp;
				tmp.push_back(numbers[i]);
				tmp.push_back(numbers[j]);
				if(target<0){
					tmp.push_back(-target);
				}else{
					tmp.insert(tmp.begin(), -target);
				}
				j--;
				i++;
				if(res.size()>0 && res[res.size()-1][0] == tmp[0]
				&& res[res.size()-1][1] == tmp[1] && res[res.size()-1][2] == tmp[2]){
					continue;
				}
				res.push_back(tmp);
			} else if (sum > target) {
				j--;
			} else if (sum < target) {
				i++;
			}
		}
		return res;
	}

public:
    vector<vector<int> > threeSum(vector<int> &num) {
    	vector<vector<int> > tmp, res;
    	if(num.size()<3) return res;
    	sort(num.begin(), num.end(), mycmp);
    	int pretarget=0;
    	for(int i=0; i<num.size()-2; i++){
    		if(i==0){
    			pretarget = num[i];
    		}else if(pretarget == num[i]){
    			continue;
    		}else{
    			pretarget = num[i];
    		}
    		tmp = twoSum(num, i+1, -num[i]);
    		for(int j=0; j<tmp.size(); j++){
    			res.push_back(tmp[j]);
    		}
    	}
    	return res;
    }
};
