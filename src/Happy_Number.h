class Solution {
    int next(int n){
        int sum = 0;
        while(n){
            int val = n%10;
            sum += val*val;
            n/=10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        int s = -1;
        if(n <= 0){
            return false;
        }
        int slow = next(n), fast = next(next(n));
        while(slow!=1 && slow != fast){
            slow = next(slow);
            fast = next(next(fast));
        }
        return slow == 1;
    }
};