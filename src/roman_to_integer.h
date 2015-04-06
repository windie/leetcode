class Solution {
    int r2n(char c){
        switch(c){
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
public:
    int romanToInt(string s) {
        int res = 0;
        for(int i = 0; i< s.size(); i++){
            if(i>0 && r2n(s[i]) > r2n(s[i-1])){
                res += (r2n(s[i]) - 2*r2n(s[i-1]));
            }else{
                res += r2n(s[i]);
            }
        }
        return res;
    }
};

//#include <iostream>
//using namespace std;
//
//class Solution {
//private:
//	int digittimes(int digitbase) {
//		if (digitbase == 0) {
//			return 1;
//		} else if (digitbase == 2) {
//			return 10;
//		} else if (digitbase == 4) {
//			return 100;
//		} else if (digitbase == 6) {
//			return 1000;
//		}
//		return 0;
//	}
//	int roman2digit(const string& s, char* map) {
//		int rs = 0;
//		int begin = 0;
//		for (int i = 6; i >= 0; i -= 2) {
//			if (s[begin] == map[i]) { // IX or IV or III
//				if (begin + 1 < s.size() && i + 2 < 7
//						&& s[begin + 1] == map[i + 2]) { // IX
//					rs += 9 * digittimes(i);
//					begin += 2;
//				} else if (begin + 1 < s.size() && i + 1 < 7
//						&& s[begin + 1] == map[i + 1]) { // IV
//					rs += 4 * digittimes(i);
//					begin += 2;
//				} else { // III, II, I
//					while (begin < s.size() && s[begin] == map[i]) {
//						rs += digittimes(i);
//						begin++;
//					}
//				}
//			} else if (i + 1 < 7 && s[begin] == map[i + 1]) { // V or VIII
//				rs += 5 * digittimes(i); // V
//				begin++;
//				while (begin < s.size() && s[begin] == map[i]) { // VIII
//					rs += digittimes(i);
//					begin++;
//				}
//			}
//		}
//		return rs;
//	}
//
//public:
//	int romanToInt(string s) {
//		//				1    5   10   50   100  500 1000
//		char map[7] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
//		return roman2digit(s, map);
//	}
//
//};
