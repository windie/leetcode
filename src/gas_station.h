class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int sum = 0;
        int begin = 0;
        for(int i = 0; i<gas.size(); i++){
            sum+=gas[i];
            if(sum >= cost[i]){
                sum-=cost[i];
            }else{
                sum = 0;
                begin = i+1;
            }
        }
        if(begin == gas.size()){
            return -1;
        }
        sum = 0;
        for(int i = begin; i<gas.size(); i++){
            sum += gas[i];
            if(sum >= cost[i]){
                sum-=cost[i];
            }else{
                return -1;
            }
        }
        for(int i = 0; i<begin; i++){
            sum += gas[i];
            if(sum >= cost[i]){
                sum-=cost[i];
            }else{
                return -1;
            }
        }
        return begin;
    }
};

//class Solution {
//public:
//    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
//        int gassum=0, costsum = 0, begin =0;
//        for(int i =0; i<gas.size(); i++){
//            gassum+=gas[i];
//            costsum+=cost[i];
//            if(gassum<costsum){
//                gassum=0;
//                costsum = 0;
//                begin = i+1;
//            }
//        }
//        if(begin == gas.size()){
//            return -1;
//        }
//        int sum=0;
//        for(int i=begin; i<gas.size(); i++){
//            sum += gas[i];
//            if(sum<cost[i]){
//                return -1;
//            }else{
//                sum-=cost[i];
//            }
//        }
//        for(int i=0; i<begin; i++){
//            sum +=gas[i];
//            if(sum<cost[i]){
//                return -1;
//            }else{
//                sum-=cost[i];
//            }
//        }
//        return begin;
//    }
//};
