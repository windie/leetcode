// 从左到右算一遍，ratings递增时candy也递增，否则都只给一块糖。
// 再从右到左修正一遍：如果左比右rating高但却没有拿更多的糖，修正。
class Solution {
public:
    int candy(vector<int> &ratings) {
        vector<int> val(ratings.size(),0);
        if(ratings.size() == 0){
            return 0;
        }
        if(ratings.size() == 1){
            return 1;
        }
        val[0] = 1;
        for(int i = 1; i<ratings.size(); i++){
            if(ratings[i] > ratings[i-1]){
                val[i] = val[i-1] + 1;
            }else{
                val[i] = 1;
            }
        }
        for(int i = ratings.size()-1; i>=1; i--){
            if(ratings[i-1] > ratings[i] && val[i-1] <= val[i]){
                val[i-1] = val[i]+1;
            }
        }
        int sum = 0;
        for(int i = 0; i<val.size(); i++){
            sum += val[i];
        }
        return sum;
    }
};


//// key: 1 2 2 2 1: 7, 1 2 3 3 3: 8
//class Solution {
//public:
//	int candy(vector<int> &ratings) {
//		vector<int> val(ratings.size(), 0);
//		for (int i = 0; i < ratings.size() - 1; i++) {
//			if (ratings[i + 1] < ratings[i]) {
//				val[i + 1] = val[i] - 1;
//			}
//		}
//		for (int i = ratings.size() - 1; i >= 0; i--) {
//			if (val[i] < 0) {
//				int minus = -val[i] + 1;
//				for (int j = 0; j < minus; j++) {
//					val[i--] += minus;
//				}
//				i++;
//			}
//		}
//		for (int i = 0; i < ratings.size(); i++) {
//			if (val[i] > 0) {
//				continue;
//			}
//			if (i > 0 && ratings[i] > ratings[i - 1]) {
//				val[i] = val[i - 1] + 1;
//			} else {
//				val[i] = 1;
//			}
//			int j;
//			for (j = i + 1; j < ratings.size() && val[j] == 0; j++) {
//				if (ratings[j] == ratings[j - 1]) {
//					val[j] = 1;
//				} else {
//					val[j] = val[j - 1] + 1;
//				}
//			}
//			if (j < ratings.size()) {
//				if (ratings[j] > ratings[j - 1]) {
//					val[j] = max(val[j], val[j - 1] + 1);
//				}
//			}
//			i = j;
//		}
//		int sum = 0;
//		for (int i = 0; i < val.size(); i++) {
//			sum += val[i];
//		}
//		return sum;
//	}
//};
