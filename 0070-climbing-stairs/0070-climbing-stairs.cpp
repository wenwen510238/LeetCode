class Solution {
public:
    int climbStairs(int n) {
        if(n == 1)  return 1;
        else if(n == 2) return 2;
        int prev = 2, prevPrev = 1;
        for(int i=3; i<=n; i++){
            int tmp = prev;
            prev = prevPrev + prev;
            prevPrev = tmp;
        }
        return prev;
    }
};