class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        if(height.size()==0){
            return 0;
        }
        int res =0;
        int last_start = 0;
        vector<int> S, H;
        S.push_back(0);
        H.push_back(height[0]);
        for(int i=1; i<height.size(); i++){
            if(height[i] >= H[H.size() - 1]){
                S.push_back(i);
                H.push_back(height[i]);
            }else{
                while(!H.empty() && height[i] < H[H.size()-1]){
                    int tmp = H[H.size()-1] * (i-S[S.size()-1]);
                    res = max(res, tmp);
                    last_start = S[S.size()-1];
                    S.pop_back();
                    H.pop_back();
                }
                H.push_back(height[i]);
                S.push_back(last_start);
            }
        }
        if(!H.empty()){
            for(int i = 0; i<H.size(); i++){
                res = max(res, H[i] * (int)(height.size() - S[i]) );
            }
        }
        return res;
   }
};

//class Solution {
//public:
//    int largestRectangleArea(vector<int> &height) {
//    	if(height.size()==0){
//    		return 0;
//    	}
//    	vector<int> left_lowest, right_lowest;
//    	left_lowest.push_back(-1);
//    	for(int i=1; i<height.size(); i++){
//    		bool isfound = false;
//    		for(int j=i-1; j>=0;){
//    			if(height[j] < height[i]){
//    				isfound = true;
//    				left_lowest.push_back(j);
//    				break;
//    			}else{
//    				j = left_lowest[j];
//    			}
//    		}
//    		if(!isfound){
//    			left_lowest.push_back(-1);
//    		}
//    	}
//    	right_lowest.push_back(height.size());
//    	for(int i=height.size()-2; i>=0; i--){
//    		bool isfound = false;
//    		for(int j=i+1; j<height.size();){
//    			if(height[j] < height[i]){
//    				isfound = true;
//    				right_lowest.push_back(j);
//    				break;
//    			}else{
//    				j = right_lowest[height.size()-j-1];
//    			}
//    		}
//    		if(!isfound){
//    			right_lowest.push_back(height.size());
//    		}
//    	}
//    	int res = 0;
//    	for(int i=0; i<height.size(); i++){
//    		int area = height[i] * (right_lowest[height.size()-i-1] - left_lowest[i] -1);
//    		if(area > res){
//    			res = area;
//    		}
//    	}
//    	return res;
//    }
//};
