#include<algorithm>
using namespace std;

class Solution {
    void swap(string &s, int i, int j){
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
    void reverse(string &s, int begin, int end){
        while(begin < end){
            char tmp = s[begin];
            s[begin] = s[end];
            s[end] = tmp;
            begin++;
            end--;
        }
    }
    void nextPermutation(string &s){
        int i = s.size()-1;
        int partitionNum, changeNum;
        while(i>0){
            if(s[i-1]<s[i]){
                break;
            }
            i--;
        }
        if(i>0){
            partitionNum = --i;
            i = s.size()-1;
            while(i>0){
                if(s[i] > s[partitionNum]){
                    break;
                }
                i--;
            }
            changeNum = i;
            swap(s, partitionNum, changeNum);
            reverse(s, partitionNum+1, s.size()-1);
        }else{
            reverse(s, 0, s.size()-1);
        }
    }
public:
    string getPermutation(int n, int k) {
        string s;
        for(int i = 1; i<=n; i++){
            s.push_back('0' + i);
        }
        for(int i =0;i<k-1; i++){
            nextPermutation(s);
        }
        return s;
    }
};


//class Solution {
//public:
//	string getPermutation(int n, int k) {
//		char str[10] = "123456789";
//		vector<bool> used(10, false);
//		str[n] = '\0';
//		int i = 1, p = 1;
//		while (i <= n) {
//			p *= i;
//			i++;
//		}
//		k--;
//		string res = "";
//		for (i = 0; i < n ; i++) {
//			p = p / (n-i);
//			int th = k / p;
//			k = k % p;
//			int j, cnt = -1;
//			for (j = 0; j < n; j++) {
//				if (!used[j]) {
//					cnt++;
//				}
//				if (cnt == th) {
//					break;
//				}
//			}
//			res.push_back(str[j]);
//			used[j] = true;
//		}
//		return res;
//	}
//};
