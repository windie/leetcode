#include <sstream>
#include <iostream>

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        bool isNeg = false;
        if(numerator<0 && denominator>0 || numerator>0 && denominator<0){
            isNeg = true;
        }
        long long numerator_l = numerator;
        numerator_l = numerator_l < 0 ? -numerator_l : numerator_l;
        long long denominator_l = denominator;
        denominator_l = denominator_l < 0 ? -denominator_l : denominator_l;
        string res="";
        stringstream stream;
        stream << numerator_l/denominator_l;
        stream >> res;
        if(numerator_l%denominator_l==0){
            return isNeg ? res.insert(0, 1, '-') : res;
        }else{
            res.push_back('.');
        }
        int base = res.size();
        long long remain = numerator_l%denominator_l;
        vector<int> remains;
        remains.push_back(remain);
        while(1){
            long long new_num = remain * 10;
            if(new_num % denominator_l == 0){
                res.push_back((char)(new_num/denominator_l) + '0');
                return isNeg ? res.insert(0, 1, '-') : res;
            }else {
                long long new_remain = new_num % denominator_l;
                int i = remains.size()-1;
                for(i = remains.size()-1; i>=0; i--){
                    if(new_remain == remains[i]){
                        res.insert(base + i, 1, '(');
                        res.push_back((char)(new_num/denominator_l) + '0');
                        res.push_back(')');
                        return isNeg ? res.insert(0, 1, '-') : res;
                    }
                }
                if(i == -1){
                    remain = new_remain;
                    remains.push_back(new_remain);
                    res.push_back((char)(new_num/denominator_l) + '0');
                }
            }
        }
    }
};