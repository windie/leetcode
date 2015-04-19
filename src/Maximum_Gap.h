class Solution {
    int ceil(int x, int y){
        if(x%y){
            return x/y+1;
        }else{
            return x/y;
        }
    }
public:
    int maximumGap(vector<int> &num) {
        if(num.size() < 2){
            return 0;
        }
        int maxval = *max_element(num.begin(), num.end());
        int minval = *min_element(num.begin(), num.end());
        int size = ceil(maxval - minval, num.size()-1); // the size of each bucket
        vector<int> ma((maxval - minval)/size+1, -1);   // the number of buckets
        vector<int> mi((maxval - minval)/size+1, -1);
        for(int i = 0; i<num.size(); i++){
            int idx = num[i] == maxval ? ma.size()-1 : (num[i] - minval)/size;
            mi[idx] = (mi[idx] == -1 ? num[i] : min(mi[idx], num[i]));
            ma[idx] = (ma[idx] == -1 ? num[i] : max(ma[idx], num[i]));
        }
        int res = 0;
        for(int i = 0; i<ma.size()-1; ){ // for ma, only look to the ma[ma.size()-2]
            if(ma[i] == -1){
                i++;
                continue;
            }
            int j = i+1;
            for(j = i+1; j<mi.size() && mi[j] == -1; j++){ // for mi, need to look to the mi[mi.size()-1]
            }
            res = max(res, mi[j] - ma[i]);
            i = j;
        }
        return res;
    }
};

//class Solution {
//    int ceil(int x, int y){
//        if(x%y){
//            return x/y+1;
//        }else{
//            return x/y;
//        }
//    }
//public:
//    int maximumGap(vector<int> &num) {
//        if(num.size()<2){
//            return 0;
//        }
//        int ma_v = *max_element(num.begin(), num.end());
//        int mi_v = *min_element(num.begin(), num.end());
//        int gap = ceil((ma_v - mi_v), (num.size()-1));
//        int size = (ma_v - mi_v)/gap+1;
//        vector<int> mi(size), ma(size);
//        for(int i = 0; i<size; i++){
//            mi[i] = -1;
//            ma[i] = -1;
//        }
//        for(int i = 0; i<num.size(); i++){
//            int index = num[i]==ma_v ? size-1 : (num[i]-mi_v)/gap;
//            if(mi[index] == -1){
//                mi[index] = num[i];
//            }else{
//                mi[index] = min(mi[index], num[i]);
//            }
//            if(ma[index] == -1){
//                ma[index] = num[i];
//            }else{
//                ma[index] = max(ma[index], num[i]);
//            }
//        }
//        int res = 0;
//        for(int i = 0; i<size-1;){
//            if(ma[i]==-1){
//                continue;
//            }
//            int j = i+1;
//            while(j<size && mi[j] == -1){
//                j++;
//            }
//            res = max(mi[j] - ma[i], res);
//            i = j;
//        }
//        return res;
//    }
//};