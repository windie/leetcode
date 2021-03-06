class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int res=0;
        for(int i =1; i<prices.size(); i++){
            if(prices[i]>prices[i-1]){
                res += prices[i]-prices[i-1];
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
//    	if(prices.size()<=1)
//    		return 0;
//    	int profit = 0;
//    	for(int i=1; i<prices.size(); i++){
//    		if(prices[i]-prices[i-1]>0){
//    			profit += prices[i]-prices[i-1];
//    		}
//    	}
//    	return profit;
//    }
//};
