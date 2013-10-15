class Solution {
public:
    int maxProfit(vector<int> &prices) {
        vector<int> leftmax(prices.size(), 0);
        vector<int> rightmax(prices.size(), 0);
        if(prices.size()<=1){
            return 0;
        }
        int minV = prices[0];
        for(int i =1 ; i<prices.size(); i++){
            if(prices[i] > minV){
                leftmax[i] = max(leftmax[i-1], prices[i] - minV);
            }else{
                leftmax[i] = leftmax[i-1];
                minV = prices[i];
            }
        }
        int maxV = prices[prices.size()-1];
        for(int i = prices.size()-2; i>=0; i--){
            if(prices[i] < maxV){
                rightmax[i] = max(rightmax[i+1], maxV - prices[i]);
            }else{
                rightmax[i] = rightmax[i+1];
                maxV = prices[i];
            }
        }
        int res = 0;
        for(int i =0; i<prices.size(); i++){
            res = max(res, leftmax[i] + rightmax[i]);
        }
        return res;
    }
};

//#include<vector>
//
//class Solution {
//public:
//	int maxProfit(vector<int> &prices) {
//		if (prices.size() == 0 || prices.size()==1)
//			return 0;
//
//		vector<int> forward;
//		int curLowest = prices[0];
//		int curMaxVal = 0;
//		forward.push_back(0);
//		for(int i=0; i<prices.size(); i++){
//			curLowest = min(prices[i], curLowest);
//			curMaxVal = max(curMaxVal, prices[i]-curLowest);
//			forward.push_back(max(curMaxVal, forward[forward.size()-1]));
//		}
//
//		vector<int> backward;
//		int curHighest = prices[prices.size()-1];
//		curMaxVal = 0;
//		backward.push_back(0);
//		for(int i = prices.size()-1; i>=0; i--){
//			curHighest = max(prices[i], curHighest);
//			curMaxVal = max(curMaxVal, curHighest-prices[i]);
//			backward.push_back(max(curMaxVal, backward[backward.size()-1]));
//		}
//
//		int res=0;
//		for(int i=0; i<forward.size(); i++){
//			res = max(forward[i] + backward[forward.size()-i-1], res);
//		}
//		return res;
//	}
//};
