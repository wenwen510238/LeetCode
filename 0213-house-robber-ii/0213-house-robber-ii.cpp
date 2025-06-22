class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)  return nums[0];
        else if(n == 2) return max(nums[0], nums[1]);
        return max(robLinear(0, n-2, nums), robLinear(1, n-1, nums));
    }
    int robLinear(int start, int end, vector<int>& nums){
        int prev1 = 0, prev2 = 0;
        for(int i=start; i<=end; i++){
            int current = max(prev2 + nums[i], prev1);
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }
};