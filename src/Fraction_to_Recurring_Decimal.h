class Solution {
    string itos(long long i){
        stringstream ss;
        ss << i;
        return ss.str();
    }
public:
    string fractionToDecimal(int num, int den) {
        bool isneg = false;
        long long numerator = num;
        long long denominator = den;
        if(numerator < 0 && denominator > 0 || numerator > 0 && denominator < 0){
            isneg = true;
        }
        if(numerator == 0){
            return "0";
        }
        if(denominator == 0){
            return "";
        }
        numerator = numerator < 0 ? -numerator : numerator;
        denominator = denominator < 0 ? -denominator : denominator;
        long long pos = numerator/denominator;
        long long remain = numerator%denominator;
        vector<long long> remains;
        remains.push_back(remain);
        if(remain == 0){
            string tmp = itos(pos);
            return isneg ? "-" + tmp : tmp;
        }
        string res = isneg ? "-" : "";
        res = res + itos(pos) + ".";
        while(1){
            remain *= 10;
            long long a = remain/denominator;
            long long b = remain%denominator;
            if(b==0){
                res.push_back(a + '0');
                return res;
            }else{
                int i;
                for(i = remains.size()-1; i>=0; i--){
                    if(b == remains[i]){
                        res.insert(res.end() - (remains.size()-1-i), 1, '(');
                        res.push_back(a + '0');
                        res.push_back(')');
                        return res;
                    }
                }
                if(i == -1){
                    remain = b;
                    remains.push_back(remain);
                    res.push_back(a + '0');
                }
            }
        }
        return res;
    }
};

//#include <sstream>
//#include <iostream>
//
//class Solution {
//public:
//    string fractionToDecimal(int numerator, int denominator) {
//        bool isNeg = false;
//        if(numerator<0 && denominator>0 || numerator>0 && denominator<0){
//            isNeg = true;
//        }
//        long long numerator_l = numerator;
//        numerator_l = numerator_l < 0 ? -numerator_l : numerator_l;
//        long long denominator_l = denominator;
//        denominator_l = denominator_l < 0 ? -denominator_l : denominator_l;
//        string res="";
//        stringstream stream;
//        stream << numerator_l/denominator_l;
//        stream >> res;
//        if(numerator_l%denominator_l==0){
//            return isNeg ? res.insert(0, 1, '-') : res;
//        }else{
//            res.push_back('.');
//        }
//        int base = res.size();
//        long long remain = numerator_l%denominator_l;
//        vector<int> remains;
//        remains.push_back(remain);
//        while(1){
//            long long new_num = remain * 10;
//            if(new_num % denominator_l == 0){
//                res.push_back((char)(new_num/denominator_l) + '0');
//                return isNeg ? res.insert(0, 1, '-') : res;
//            }else {
//                long long new_remain = new_num % denominator_l;
//                int i = remains.size()-1;
//                for(i = remains.size()-1; i>=0; i--){
//                    if(new_remain == remains[i]){
//                        res.insert(base + i, 1, '(');
//                        res.push_back((char)(new_num/denominator_l) + '0');
//                        res.push_back(')');
//                        return isNeg ? res.insert(0, 1, '-') : res;
//                    }
//                }
//                if(i == -1){
//                    remain = new_remain;
//                    remains.push_back(new_remain);
//                    res.push_back((char)(new_num/denominator_l) + '0');
//                }
//            }
//        }
//    }
//};