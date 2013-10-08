#include<string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '{' || s[i] == '[' || s[i] == '('){
                stack.push_back(s[i]);
            }else if(stack.size()==0){
                return false;
            }else{
                if(s[i] == '}'){
                    if(stack[stack.size()-1] != '{'){
                        return false;
                    }else{
                        stack.pop_back();
                    }
                }else if(s[i] == ')'){
                    if(stack[stack.size()-1] != '('){
                        return false;
                    }else{
                        stack.pop_back();
                    }
                }else {
                    if(stack[stack.size() -1 ] != '['){
                        return false;
                    }else{
                        stack.pop_back();
                    }
                }
            }
        }
        return stack.empty();
    }
};
