class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1 = 0, prev2 = 0;
        for(int i=0; i<nums.size(); i++){
            int current = max(prev2 + nums[i], prev1);
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }
};

// 12  1  1  1 1  12
// 12 12 13 13 14 25

// 2 1 1 2
// 2 2 3 4