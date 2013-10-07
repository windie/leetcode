#include<vector>

class Solution {
public:
	int maxProfit(vector<int> &prices) {
		if (prices.size() == 0 || prices.size()==1)
			return 0;

		vector<int> forward;
		int curLowest = prices[0];
		int curMaxVal = 0;
		forward.push_back(0);
		for(int i=0; i<prices.size(); i++){
			curLowest = min(prices[i], curLowest);
			curMaxVal = max(curMaxVal, prices[i]-curLowest);
			forward.push_back(max(curMaxVal, forward[forward.size()-1]));
		}

		vector<int> backward;
		int curHighest = prices[prices.size()-1];
		curMaxVal = 0;
		backward.push_back(0);
		for(int i = prices.size()-1; i>=0; i--){
			curHighest = max(prices[i], curHighest);
			curMaxVal = max(curMaxVal, curHighest-prices[i]);
			backward.push_back(max(curMaxVal, backward[backward.size()-1]));
		}

		int res=0;
		for(int i=0; i<forward.size(); i++){
			res = max(forward[i] + backward[forward.size()-i-1], res);
		}
		return res;
	}
};
