class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int res = 0;
        if(prices.size()<=1){
            return 0;
        }
        int curmin = prices[0];
        for(int i = 1; i<prices.size(); i++){
            if(prices[i] < curmin){
                curmin = prices[i];
            }else{
                res = max(res, prices[i]-curmin);
            }
        }
        return res;
    }
};

//#include<vector>
//
//class Solution {
//public:
//    int maxProfit(vector<int> &prices) {
//    	if(prices.size()==0)
//    		return 0;
//    	int curLowest= prices[0];
//    	int curMaxVal = 0;
//    	for(int i =0; i<prices.size(); i++){
//    		curLowest = min( prices[i] , curLowest);
//    		curMaxVal = max(prices[i] - curLowest , curMaxVal);
//    	}
//    	return curMaxVal;
//    }
//};
